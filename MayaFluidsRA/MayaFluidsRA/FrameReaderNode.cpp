#include "FrameReaderNode.h"

MTypeId FrameReaderNode::id(0x00000100);
MObject FrameReaderNode::aInValue;
MObject FrameReaderNode::aOutValue;
MObject FrameReaderNode::aMin;
MObject FrameReaderNode::aMax;
MObject FrameReaderNode::aScale;

FrameReaderNode::FrameReaderNode()
{
}

FrameReaderNode::~FrameReaderNode()
{
}

void* FrameReaderNode::creator()
{
	return new FrameReaderNode();
}

MStatus FrameReaderNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;

	if (plug != aOutValue)
	{
		return MS::kUnknownParameter;
	}

	float input = data.inputValue(aInValue, &status).asFloat();
	float min = data.inputValue(aMin, &status).asFloat();
	float max = data.inputValue(aMax, &status).asFloat();
	float scale = data.inputValue(aScale, &status).asFloat();

	if (scale <= 0.0f)
	{
		scale = 0.01f;
	}

	cout << "FrameReader: reading " << input << endl;
	float output;
	if (input > max)
	{
		output = (max - min) / scale;
	}
	else if (input < min)
	{
		output = 0.0f;
	}
	else
	{
		output = (input - min) / scale;
	}

	MDataHandle hOutput = data.outputValue(aOutValue, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);
	hOutput.setFloat(output);
	hOutput.setClean();
	data.setClean(plug);

	return MS::kSuccess;
}

MStatus FrameReaderNode::initialize()
{
	MStatus status;
	MFnNumericAttribute nAttr;

	aOutValue = nAttr.create("outValue", "outValue", MFnNumericData::kFloat);
	nAttr.setWritable(false);
	nAttr.setStorable(false);
	addAttribute(aOutValue);

	aInValue = nAttr.create("inValue", "inValue", MFnNumericData::kFloat);
	nAttr.setKeyable(true);
	addAttribute(aInValue);
	attributeAffects(aInValue, aOutValue);

	aMin = nAttr.create("min", "min", MFnNumericData::kFloat);
	nAttr.setKeyable(true);
	addAttribute(aMin);
	attributeAffects(aMin, aOutValue);

	aMax = nAttr.create("max", "max", MFnNumericData::kFloat);
	nAttr.setKeyable(true);
	addAttribute(aMax);
	attributeAffects(aMax, aOutValue);

	aScale = nAttr.create("scale", "scale", MFnNumericData::kFloat);
	nAttr.setKeyable(true);
	addAttribute(aScale);
	attributeAffects(aScale, aOutValue);

	return MS::kSuccess;
}