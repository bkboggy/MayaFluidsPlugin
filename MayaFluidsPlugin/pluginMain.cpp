#include "addSourceNode.h"
#include "advectNode.h"
#include "densityStepNode.h"
#include "diffuseNode.h"
#include "linearSolveNode.h"
#include "projectNode.h"
#include "setBoundariesNode.h"
#include "velocityStepNode.h"
#include <maya/MFnPlugin.h>

MStatus initializePlugin(MObject obj)
{
	MStatus status;
	MFnPlugin fnPlugin(obj, "Bogdan Kravtsov & Raymond Aceves", "1.0.0", "Any");

	status = fnPlugin.registerNode(
		"fd_addSource",
		AddSourceNode::id,
		AddSourceNode::creator,
		AddSourceNode::initialize);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.registerNode(
		"fd_setBoundaries",
		SetBoundariesNode::id,
		SetBoundariesNode::creator,
		SetBoundariesNode::initialize);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.registerNode(
		"fd_linearSolve",
		LinearSolveNode::id,
		LinearSolveNode::creator,
		LinearSolveNode::initialize);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.registerNode(
		"fd_diffuse",
		DiffuseNode::id,
		DiffuseNode::creator,
		DiffuseNode::initialize);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.registerNode(
		"fd_advect",
		AdvectNode::id,
		AdvectNode::creator,
		AdvectNode::initialize);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.registerNode(
		"fd_project",
		ProjectNode::id,
		ProjectNode::creator,
		ProjectNode::initialize);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.registerNode(
		"fd_densityStep",
		DensityStepNode::id,
		DensityStepNode::creator,
		DensityStepNode::initialize);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.registerNode(
		"fd_velocityStep",
		VelocityStepNode::id,
		VelocityStepNode::creator,
		VelocityStepNode::initialize);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	return MS::kSuccess;
}

MStatus uninitializePlugin(MObject obj)
{
	MStatus status;
	MFnPlugin fnPlugin(obj);

	status = fnPlugin.deregisterNode(AddSourceNode::id);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.deregisterNode(SetBoundariesNode::id);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.deregisterNode(LinearSolveNode::id);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.deregisterNode(DiffuseNode::id);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.deregisterNode(AdvectNode::id);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.deregisterNode(ProjectNode::id);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.deregisterNode(DensityStepNode::id);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.deregisterNode(VelocityStepNode::id);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	return MS::kSuccess;
}
