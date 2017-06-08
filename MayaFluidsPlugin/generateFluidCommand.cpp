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
	MPlug input = fn.findPlug("timeIn", &status);
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
	MGlobal::executeCommand("connectAttr " + fTimeName + ".timeOut " + fSolverName + ".time");

	//connect fDomain to fSolver
    MGlobal::executeCommand("connectAttr " + fDomainName + ".velocityU " + fSolverName + ".prevVelocityU");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".velocityV " + fSolverName + ".prevVelocityV");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".velocityW " + fSolverName + ".prevVelocityW");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".densityOut " + fSolverName + ".prevDensity");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".voxelCountWidthOut " + fSolverName + ".voxelCountWidth");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".voxelCountHeightOut " + fSolverName + ".voxelCountHeight");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".voxelCountLengthOut " + fSolverName + ".voxelCountLength");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".diffusionRateOut " + fSolverName + ".diffusionRate");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".timestepOut " + fSolverName + ".timestep");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".forceMultiplierOut " + fSolverName + ".forceMultiplier");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".sourceMultiplierOut " + fSolverName + ".sourceMultiplier");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".viscosityOut " + fSolverName + ".viscosity");

    // Connect fDomain to fLocator.
    MGlobal::executeCommand("connectAttr " + fDomainName + ".domainHeightOut " + fLocatorName + ".domainHeightIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".domainWidthOut " + fLocatorName + ".domainWidthIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".domainLengthOut " + fLocatorName + ".domainLengthIn");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".domainOriginOut0 " + fLocatorName + ".domainOriginIn0");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".domainOriginOut1 " + fLocatorName + ".domainOriginIn1");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".domainOriginOut2 " + fLocatorName + ".domainOriginIn2");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".showFluidOut " + fLocatorName + ".showFluidIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".showVoxelsOut " + fLocatorName + ".showVoxelsIn");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".sourceHeightOut " + fLocatorName + ".sourceHeightIn");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".sourceLengthOut " + fLocatorName + ".sourceLengthIn");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".sourceOriginOut0 " + fLocatorName + ".sourceOriginIn0");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".sourceOriginOut1 " + fLocatorName + ".sourceOriginIn1");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".sourceOriginOut2 " + fLocatorName + ".sourceOriginIn2");
	MGlobal::executeCommand("connectAttr " + fDomainName + ".sourceWidthOut " + fLocatorName + ".sourceWidthIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".voxelAlphaOut " + fLocatorName + ".voxelAlphaIn");

    // Connect fDomain to fTime
    MGlobal::executeCommand("connectAttr " + fDomainName + ".minTimeOut " + fTimeName + ".minTime");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".maxTimeOut " + fTimeName + ".maxTime");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".timeScaleOut " + fTimeName + ".timeScale");

	// Connect fSolver to fLocator.
    MGlobal::executeCommand("connectAttr " + fSolverName + ".velocityU " + fLocatorName + ".velocityUIn");
    MGlobal::executeCommand("connectAttr " + fSolverName + ".velocityV " + fLocatorName + ".velocityVIn");
    MGlobal::executeCommand("connectAttr " + fSolverName + ".velocityW " + fLocatorName + ".velocityWIn");
    MGlobal::executeCommand("connectAttr " + fSolverName + ".density " + fLocatorName + ".densityIn");
    MGlobal::executeCommand("connectAttr " + fSolverName + ".voxelCountHeight " + fLocatorName + ".voxelCountHeightIn");
	MGlobal::executeCommand("connectAttr " + fSolverName + ".voxelCountLength " + fLocatorName + ".voxelCountLengthIn");
	MGlobal::executeCommand("connectAttr " + fSolverName + ".voxelCountWidth " + fLocatorName + ".voxelCountWidthIn");

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