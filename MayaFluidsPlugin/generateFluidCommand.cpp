#include "generateFluidCommand.h"

const char* helpFlag = "-h";
const char* helpFlagLong = "-help";
const char* helpText = "This will create and link all necessary nodes for the Fluid Simulation.";

// Default constructor.
GenerateFluidCommand::GenerateFluidCommand()
{
}

// Executes the command.
MStatus GenerateFluidCommand::doIt(const MArgList& argList)
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

// Attempts to restore previous execution of the command.
MStatus GenerateFluidCommand::redoIt()
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

	// Get the outTime plug from time1 Node.
	MFnDependencyNode fnTime(oTime);
	MPlug outTime = fnTime.findPlug("outTime", &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	// Get the inTime plug from the fluidTimeNode.
	MPlug input = fn.findPlug("inTime", &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	// Connect the two plugs.
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
	MGlobal::executeCommand("connectAttr " + fTimeName + ".outTime " + fSolverName + ".time");

	//connect fDomain to fSolver
    MGlobal::executeCommand("connectAttr " + fDomainName + ".velocityU " + fSolverName + ".prevVelocityU");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".velocityV " + fSolverName + ".prevVelocityV");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".velocityW " + fSolverName + ".prevVelocityW");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".density " + fSolverName + ".prevDensity");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".voxelCount " + fSolverName + ".voxelCount");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".diffusion " + fSolverName + ".diffusion");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".timestep " + fSolverName + ".timestep");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".forceMultiplier " + fSolverName + ".forceMultiplier");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".sourceMultiplier " + fSolverName + ".sourceMultiplier");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".viscosity " + fSolverName + ".viscosity");

    // Connect fDomain to fLocator.
    MGlobal::executeCommand("connectAttr " + fDomainName + ".height " + fLocatorName + ".height");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".width " + fLocatorName + ".width");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".length " + fLocatorName + ".length");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".showVoxels " + fLocatorName + ".showVoxels");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".voxelAlpha " + fLocatorName + ".voxelAlpha");

    // Connect fDomain to fTime
    MGlobal::executeCommand("connectAttr " + fDomainName + ".minTime " + fTimeName + ".minTime");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".maxTime " + fTimeName + ".maxTime");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".timeScale " + fTimeName + ".timeScale");

	// Connect fSolver to fLocator.
    MGlobal::executeCommand("connectAttr " + fSolverName + ".velocityU " + fLocatorName + ".velocityU");
    MGlobal::executeCommand("connectAttr " + fSolverName + ".velocityV " + fLocatorName + ".velocityV");
    MGlobal::executeCommand("connectAttr " + fSolverName + ".velocityW " + fLocatorName + ".velocityW");
    MGlobal::executeCommand("connectAttr " + fSolverName + ".density " + fLocatorName + ".density");
    MGlobal::executeCommand("connectAttr " + fSolverName + ".voxelCount " + fLocatorName + ".voxelCount");

	// Restore the selection list.
	status = MGlobal::setActiveSelectionList(previous_list);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	setResult(fTimeName + ", " + fDomainName + ", " + fSolverName + ", " + fLocatorName + ", " + fLocatorTransformName);

	return MS::kSuccess;
}

// Attempts to undo actions completed by the command.
MStatus GenerateFluidCommand::undoIt()
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

// Flags indicating whether the command is undoable.
bool GenerateFluidCommand::isUndoable() const
{
	return true;
}

// Maya command creator method.
void* GenerateFluidCommand::creator()
{
	return new GenerateFluidCommand;
}

// Command syntax.
MSyntax GenerateFluidCommand::newSyntax()
{
	MSyntax syntax;

	syntax.addFlag(helpFlag, helpFlagLong);

	return syntax;
}