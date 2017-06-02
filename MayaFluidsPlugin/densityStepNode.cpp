#include "densityStepNode.h"

MTypeId DensityStepNode::id(0x00000037);

MObject DensityStepNode::aOutValue;
MObject DensityStepNode::aInValue;

DensityStepNode::DensityStepNode() {}

DensityStepNode::~DensityStepNode() {}

void* DensityStepNode::creator()
{
	return new DensityStepNode();
}

MStatus DensityStepNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;

	if (plug != aOutValue)
	{
		return MS::kUnknownParameter;
	}

	// TODO: Add compute logic.

	return MS::kSuccess;
}

MStatus DensityStepNode::initialize()
{
	MStatus status;

	// TODO: Add attribute initialization logic.

	return MS::kSuccess;
}
