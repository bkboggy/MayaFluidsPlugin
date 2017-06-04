#include "fluidDomainNode.h"
#include "fluidSolverNode.h"
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

    status = fnPlugin.registerNode(
        "fluidSolver",
        FluidSolverNode::id,
        FluidSolverNode::creator,
        FluidSolverNode::initialize);

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

	return MS::kSuccess;
}
