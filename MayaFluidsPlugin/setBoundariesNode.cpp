#include "setBoundariesNode.h"

MTypeId SetBoundariesNode::id(0x00000032);

MObject SetBoundariesNode::aOutValue;
MObject SetBoundariesNode::aInValue;

SetBoundariesNode::SetBoundariesNode() {}

SetBoundariesNode::~SetBoundariesNode() {}

void* SetBoundariesNode::creator()
{
	return new SetBoundariesNode();
}

MStatus SetBoundariesNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;

	if (plug != aOutValue)
	{
		return MS::kUnknownParameter;
	}

	// TODO: Add compute logic.

	return MS::kSuccess;
}

MStatus SetBoundariesNode::initialize()
{
	MStatus status;

	// TODO: Add attribute initialization logic.

	return MS::kSuccess;
}
