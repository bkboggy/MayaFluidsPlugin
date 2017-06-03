#include "projectNode.h"

MTypeId ProjectNode::id(0x00000036);

MObject ProjectNode::aOutValue;
MObject ProjectNode::aInValue;
MObject ProjectNode::aN;
MObject ProjectNode::au;
MObject ProjectNode::av;
MObject ProjectNode::ap;
MObject ProjectNode::adiv;

ProjectNode::ProjectNode() {}

ProjectNode::~ProjectNode() {}

void* ProjectNode::creator()
{
	return new ProjectNode();
}

MStatus ProjectNode::initialize()
{
    MStatus status;

    // TODO: Add attribute initialization logic.

    return MS::kSuccess;
}

MStatus ProjectNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;

	if (plug != aOutValue)
	{
		return MS::kUnknownParameter;
	}

	// TODO: Add compute logic.

	return MS::kSuccess;
}
