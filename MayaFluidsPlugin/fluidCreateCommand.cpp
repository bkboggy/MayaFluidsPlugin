#include "fluidCreateCommand.h"


const char* helpFlag = "-h";
const char* helpFlagLong = "-help";

const char* helpText = "This will create and link all necessary nodes for the Fluid Simulation.";

FluidCreateCommand::FluidCreateCommand()
{
}

MStatus FluidCreateCommand::doIt(const MArgList& argList)
{
	MStatus status;

	MArgDatabase argData(syntax(), argList, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	if (argData.isFlagSet(helpFlag))
	{
		setResult(helpText);
		return MS::kSuccess;
	}

	return redoIt();
}

MStatus FluidCreateCommand::redoIt()
{
	MStatus status;

	//get the currently selected objects to retore at end of this function
	MSelectionList previous_list;
	status = MGlobal::getActiveSelectionList(previous_list);

	//*** start of complicated method of creating connection
	//create FrameReaderNode
	MFnDependencyNode fn;
	fn.create(FluidTimeNode::id);
	fTimeName = fn.name();

	//get the time1 node
	status = MGlobal::selectByName("time1", MGlobal::kReplaceList);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	MSelectionList sl;
	status = MGlobal::getActiveSelectionList(sl);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	MObject oTime;
	status = sl.getDependNode(0, oTime);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	//get the outTime plug from time1 Node
	MFnDependencyNode fnTime(oTime);
	MPlug outTime = fnTime.findPlug("outTime", &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	//get the inValue plug from the FrameReaderNode
	MPlug input = fn.findPlug("inValue", &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	//connect the two plugs
	MDagModifier dagMod;
	dagMod.connect(outTime, input);
	status = dagMod.doIt();
	CHECK_MSTATUS_AND_RETURN_IT(status);

	//*** end of complicated method of creating connection
	//*** below shows easy way to connect nodes

	//create Locator Node
	//this creates a transformNode
	MFnDependencyNode locatorTransFn;
	locatorTransFn.create(FluidLocatorNode::id);
	fLocatorTransformName = locatorTransFn.name();

	//need to get the LocatorName from child of transformNode
	status = MGlobal::selectByName(fLocatorTransformName, MGlobal::kReplaceList);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	MDagPath transDagPath;
	status = MGlobal::getActiveSelectionList(sl);
	CHECK_MSTATUS_AND_RETURN_IT(status);
	sl.getDagPath(0, transDagPath);
	MFnDependencyNode locatorFn(transDagPath.child(0));
	fLocatorName = locatorFn.name();

	//create Domain Node
	MFnDependencyNode domainFn;
	domainFn.create(FluidDomainNode::id);
	fDomainName = domainFn.name();

	//create Solver Node
	MFnDependencyNode solverFn;
	solverFn.create(FluidSolverNode::id);
	fSolverName = solverFn.name();

	//connect fTime to fSolver
	MGlobal::executeCommand("connectAttr " + fTimeName + ".outValue " + fSolverName + ".time");

	//connect fDomain to fSolver
	MGlobal::executeCommand("connectAttr " + fDomainName + ".N " + fSolverName + ".N");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".diff " + fSolverName + ".diff");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".dt " + fSolverName + ".dt");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".force " + fSolverName + ".force");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".source " + fSolverName + ".source");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".visc " + fSolverName + ".visc");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".u " + fSolverName + ".u0");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".v " + fSolverName + ".v0");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".w " + fSolverName + ".w0");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".x " + fSolverName + ".x0");

	//connect fSolver to fLocator
	//TODO

	//restore the selection list
	status = MGlobal::setActiveSelectionList(previous_list);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	setResult(fTimeName+", "+fDomainName+", "+fSolverName+", "+fLocatorName+", "+fLocatorTransformName);

	return MS::kSuccess;
}

MStatus FluidCreateCommand::undoIt()
{
	MStatus status;
	MSelectionList pl;

	status = MGlobal::getActiveSelectionList(pl);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	//delete fluidTimeNode
	status = MGlobal::selectByName(fTimeName, MGlobal::kReplaceList);
	MGlobal::executeCommand("delete");

	//delete fluidDomainNode
	status = MGlobal::selectByName(fDomainName, MGlobal::kReplaceList);
	MGlobal::executeCommand("delete");

	//delete fluidSolverNode
	status = MGlobal::selectByName(fSolverName, MGlobal::kReplaceList);
	MGlobal::executeCommand("delete");

	//delete fluidLocatorNode
	status = MGlobal::selectByName(fLocatorName, MGlobal::kReplaceList);
	MGlobal::executeCommand("delete");

	//delete transformNode
	status = MGlobal::selectByName(fLocatorTransformName, MGlobal::kReplaceList);
	MGlobal::executeCommand("delete");

	status = MGlobal::setActiveSelectionList(pl);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	return MS::kSuccess;
}

bool FluidCreateCommand::isUndoable() const
{
	return true;
}

void* FluidCreateCommand::creator()
{
	return new FluidCreateCommand();
}

MSyntax FluidCreateCommand::newSyntax()
{
	MSyntax syntax;

	syntax.addFlag(helpFlag, helpFlagLong);

	return syntax;
}