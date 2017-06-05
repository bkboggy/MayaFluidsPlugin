#include "FluidTimeNode.h"

MTypeId FluidTimeNode::id(0x00000103);
MObject FluidTimeNode::aInValue;
MObject FluidTimeNode::aOutValue;
MObject FluidTimeNode::aMin;
MObject FluidTimeNode::aMax;
MObject FluidTimeNode::aScale;

FluidTimeNode::FluidTimeNode()
{
}

FluidTimeNode::~FluidTimeNode()
{
}

void* FluidTimeNode::creator()
{
	return new FluidTimeNode();
}

MStatus FluidTimeNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;

	if (plug != aOutValue)
	{
		return MS::kUnknownParameter;
	}

	MTime input = data.inputValue(aInValue, &status).asTime();
	double min = data.inputValue(aMin, &status).asDouble();
	double max = data.inputValue(aMax, &status).asDouble();
	double scale = data.inputValue(aScale, &status).asDouble();

	if (scale <= 0.0f)
	{
		scale = 0.01f;
	}

	MTime output;
	if (input > max)
	{
		output = ((input + max) - input) / scale;
	}
	else if (input < min)
	{
		output = MTime(0.0);
	}
	else
	{
		output = (input - min) / scale;
	}

	MDataHandle hOutput = data.outputValue(aOutValue, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);
	hOutput.set(output);
	hOutput.setClean();
	data.setClean(plug);

	return MS::kSuccess;
}

MStatus FluidTimeNode::initialize()
{
	MStatus status;
	MFnUnitAttribute uAttr;
	MFnNumericAttribute nAttr;

	aOutValue = uAttr.create("outValue", "outValue", MTime(0.0));
	nAttr.setWritable(false);
	nAttr.setStorable(false);
	addAttribute(aOutValue);

	aInValue = uAttr.create("inValue", "inValue",MTime(0.0));
	nAttr.setKeyable(true);
	addAttribute(aInValue);
	attributeAffects(aInValue, aOutValue);

	aMin = nAttr.create("min", "min", MFnNumericData::kDouble);
	nAttr.setKeyable(true);
	addAttribute(aMin);
	attributeAffects(aMin, aOutValue);

	aMax = nAttr.create("max", "max", MFnNumericData::kDouble);
	nAttr.setKeyable(true);
	addAttribute(aMax);
	attributeAffects(aMax, aOutValue);

	aScale = nAttr.create("scale", "scale", MFnNumericData::kDouble);
	nAttr.setKeyable(true);
	addAttribute(aScale);
	attributeAffects(aScale, aOutValue);

	return MS::kSuccess;
}