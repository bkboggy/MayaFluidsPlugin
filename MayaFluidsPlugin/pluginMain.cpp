#include "fluidDomainNode.h"
#include "fluidSolverNode.h"
#include "fluidTimeNode.h"
#include "fluidLocatorNode.h"
#include "generateFluidCommand.h"
#include "createFluidUiCommand.h"
#include <maya/MFnPlugin.h>

MStatus initializePlugin(MObject obj)
{
	MStatus status;
	MFnPlugin fnPlugin(obj, "Bogdan Kravtsov & Raymond Aceves", "1.0.0", "Any");

    cout.rdbuf(cerr.rdbuf());
    cout << "Fluid Solver Plugin loaded." << endl;

    status = fnPlugin.registerNode(
        "fluidDomain",
        FluidDomainNode::id,
        FluidDomainNode::creator,
        FluidDomainNode::initialize);
	CHECK_MSTATUS_AND_RETURN_IT(status);

    status = fnPlugin.registerNode(
        "fluidSolver",
        FluidSolverNode::id,
        FluidSolverNode::creator,
        FluidSolverNode::initialize);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.registerNode(
		"fluidTime",
		FluidTimeNode::id,
		FluidTimeNode::creator,
		FluidTimeNode::initialize);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.registerNode(
		"fluidLocator",
		FluidLocatorNode::id,
		FluidLocatorNode::creator,
		FluidLocatorNode::initialize,
		MPxNode::kLocatorNode);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.registerCommand(
		"generateFluidSimulation",
		GenerateFluidCommand::creator,
		GenerateFluidCommand::newSyntax);
	CHECK_MSTATUS_AND_RETURN_IT(status);

    status = fnPlugin.registerCommand(
        "createFluidUI",
        CreateFluidUiCommand::creator);
    CHECK_MSTATUS_AND_RETURN_IT(status);

	return MS::kSuccess;
}

MStatus uninitializePlugin(MObject obj)
{
	MStatus status;
	MFnPlugin fnPlugin(obj);

    status = fnPlugin.deregisterNode(FluidSolverNode::id);
    CHECK_MSTATUS_AND_RETURN_IT(status);

    status = fnPlugin.deregisterNode(FluidDomainNode::id);
    CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.deregisterNode(FluidTimeNode::id);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.deregisterNode(FluidLocatorNode::id);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.deregisterCommand("generateFluidSimulation");
	CHECK_MSTATUS_AND_RETURN_IT(status);

    status = fnPlugin.deregisterCommand("createFluidUI");
    CHECK_MSTATUS_AND_RETURN_IT(status);

	return MS::kSuccess;
}
