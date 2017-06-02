#include "diffuseNode.h"

MTypeId DiffuseNode::id(0x00000034);

MObject DiffuseNode::aOutValue;
MObject DiffuseNode::aInValue;

DiffuseNode::DiffuseNode() {}

DiffuseNode::~DiffuseNode() {}

void* DiffuseNode::creator()
{
	return new DiffuseNode();
}

MStatus DiffuseNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;

	if (plug != aOutValue)
	{
		return MS::kUnknownParameter;
	}

	// TODO: Add compute logic.

	return MS::kSuccess;
}

MStatus DiffuseNode::initialize()
{
	MStatus status;

	// TODO: Add attribute initialization logic.

	return MS::kSuccess;
}
