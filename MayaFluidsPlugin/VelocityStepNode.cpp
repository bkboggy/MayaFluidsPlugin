#include "velocityStepNode.h"

MTypeId VelocityStepNode::id(0x00000038);

MObject VelocityStepNode::aOutValue;
MObject VelocityStepNode::aInValue;

VelocityStepNode::VelocityStepNode() {}

VelocityStepNode::~VelocityStepNode() {}

void* VelocityStepNode::creator()
{
	return new VelocityStepNode();
}

MStatus VelocityStepNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;

	if (plug != aOutValue)
	{
		return MS::kUnknownParameter;
	}

	// TODO: Add compute logic.

	return MS::kSuccess;
}

MStatus VelocityStepNode::initialize()
{
	MStatus status;
	
	// TODO: Add attribute initialization logic.

	return MS::kSuccess;
}
