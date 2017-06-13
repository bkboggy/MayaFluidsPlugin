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

    // Connect fDomain to fTime.
    MGlobal::executeCommand("connectAttr " + fDomainName + ".minTimeOut " + fTimeName + ".minTime");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".maxTimeOut " + fTimeName + ".maxTime");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".timeScaleOut " + fTimeName + ".timeScale");

    //connect fDomain to fSolver
    MGlobal::executeCommand("connectAttr " + fDomainName + ".voxelCountWidthOut " + fSolverName + ".voxelCountWidthIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".voxelCountHeightOut " + fSolverName + ".voxelCountHeightIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".voxelCountLengthOut " + fSolverName + ".voxelCountLengthIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".velocityUOut " + fSolverName + ".velocityUIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".velocityVOut " + fSolverName + ".velocityVIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".velocityWOut " + fSolverName + ".velocityWIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".densityOut " + fSolverName + ".densityIn");   
    MGlobal::executeCommand("connectAttr " + fDomainName + ".sourceDensityOut " + fSolverName + ".sourceDensityIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".activeSourceOut " + fSolverName + ".activeSourceIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".activeSourceRateOut " + fSolverName + ".activeSourceRateIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".diffusionRateOut " + fSolverName + ".diffusionRateIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".timestepOut " + fSolverName + ".timestepIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".forceMultiplierOut " + fSolverName + ".forceMultiplierIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".sourceMultiplierOut " + fSolverName + ".sourceMultiplierIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".viscosityOut " + fSolverName + ".viscosityIn");


    // Connect fDomain to fLocator.
    MGlobal::executeCommand("connectAttr " + fDomainName + ".showVoxelsOut " + fLocatorName + ".showVoxelsIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".voxelAlphaOut " + fLocatorName + ".voxelAlphaIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".showFluidOut " + fLocatorName + ".showFluidIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".minParticleSizeOut " + fLocatorName + ".minParticleSizeIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".voxelCountWidthOut " + fLocatorName + ".voxelCountWidthIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".voxelCountHeightOut " + fLocatorName + ".voxelCountHeightIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".voxelCountLengthOut " + fLocatorName + ".voxelCountLengthIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".domainOriginXOut " + fLocatorName + ".domainOriginXIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".domainOriginYOut " + fLocatorName + ".domainOriginYIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".domainOriginZOut " + fLocatorName + ".domainOriginZIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".domainHeightOut " + fLocatorName + ".domainHeightIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".domainWidthOut " + fLocatorName + ".domainWidthIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".domainLengthOut " + fLocatorName + ".domainLengthIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".sourceOriginXOut " + fLocatorName + ".sourceOriginXIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".sourceOriginYOut " + fLocatorName + ".sourceOriginYIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".sourceOriginZOut " + fLocatorName + ".sourceOriginZIn");   
    MGlobal::executeCommand("connectAttr " + fDomainName + ".sourceHeightOut " + fLocatorName + ".sourceHeightIn");
    MGlobal::executeCommand("connectAttr " + fDomainName + ".sourceLengthOut " + fLocatorName + ".sourceLengthIn"); 
    MGlobal::executeCommand("connectAttr " + fDomainName + ".sourceWidthOut " + fLocatorName + ".sourceWidthIn");
    
	// Connect fTime to fSolver.
	MGlobal::executeCommand("connectAttr " + fTimeName + ".timeOut " + fSolverName + ".timeIn");  

	// Connect fSolver to fLocator.
    MGlobal::executeCommand("connectAttr " + fSolverName + ".densityOut " + fLocatorName + ".densityIn");
    MGlobal::executeCommand("connectAttr " + fSolverName + ".velocityUOut " + fLocatorName + ".velocityUIn");
    MGlobal::executeCommand("connectAttr " + fSolverName + ".velocityVOut " + fLocatorName + ".velocityVIn");
    MGlobal::executeCommand("connectAttr " + fSolverName + ".velocityWOut " + fLocatorName + ".velocityWIn");

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
