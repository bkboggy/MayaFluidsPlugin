#include "linearSolveNode.h"

MTypeId LinearSolveNode::id(0x00000033);

MObject LinearSolveNode::aOutValue;
MObject LinearSolveNode::aInValue;

LinearSolveNode::LinearSolveNode() {}

LinearSolveNode::~LinearSolveNode() {}

void* LinearSolveNode::creator()
{
	return new LinearSolveNode();
}

MStatus LinearSolveNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;

	if (plug != aOutValue)
	{
		return MS::kUnknownParameter;
	}

	// TODO: Add compute logic.

	return MS::kSuccess;
}

MStatus LinearSolveNode::initialize()
{
	MStatus status;

	// TODO: Add attribute initialization logic.

	return MS::kSuccess;
}
