#include "addSourceNode.h"

MTypeId AddSourceNode::id(0x00000031);

MObject AddSourceNode::aOutValue;
MObject AddSourceNode::aInValue;

AddSourceNode::AddSourceNode() {}

AddSourceNode::~AddSourceNode() {}

void* AddSourceNode::creator()
{
	return new AddSourceNode();
}

MStatus AddSourceNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;

	if (plug != aOutValue)
	{
		return MS::kUnknownParameter;
	}

	// TODO: Add compute logic.

	return MS::kSuccess;
}

MStatus AddSourceNode::initialize()
{
	MStatus status;

	MFnNumericAttribute nAttr;

	aOutValue = nAttr.create("outValue", "outValue", MFnNumericData::kFloat);
	nAttr.setWritable(false);
	nAttr.setStorable(false);
	addAttribute(aOutValue);

	return MS::kSuccess;
}
