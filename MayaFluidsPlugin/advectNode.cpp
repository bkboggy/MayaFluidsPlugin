#include "advectNode.h"

MTypeId AdvectNode::id(0x00000035);

MObject AdvectNode::aOutValue;
MObject AdvectNode::aInValue;

AdvectNode::AdvectNode() {}

AdvectNode::~AdvectNode() {}

void* AdvectNode::creator()
{
	return new AdvectNode();
}

MStatus AdvectNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;

	if (plug != aOutValue)
	{
		return MS::kUnknownParameter;
	}

	// TODO: Add compute logic.

	return MS::kSuccess;
}

MStatus AdvectNode::initialize()
{
	MStatus status;

	// TODO: Add attribute initialization logic.

	return MS::kSuccess;
}
