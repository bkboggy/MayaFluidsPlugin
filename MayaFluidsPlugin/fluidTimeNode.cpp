#include "FluidTimeNode.h"

MTypeId FluidTimeNode::id(0x00000103);
MObject FluidTimeNode::aInTime;
MObject FluidTimeNode::aOutTime;
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

	if (plug != aOutTime)
	{
		return MS::kUnknownParameter;
	}

	MTime input = data.inputValue(aInTime, &status).asTime();
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

	MDataHandle hOutput = data.outputValue(aOutTime, &status);
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

	aOutTime = uAttr.create("outTime", "outTime", MTime(1.0));
	nAttr.setWritable(false);
	nAttr.setStorable(false);
	addAttribute(aOutTime);

	aInTime = uAttr.create("inTime", "inTime", MTime(1.0));
	nAttr.setKeyable(true);
	addAttribute(aInTime);
	attributeAffects(aInTime, aOutTime);

	aMin = nAttr.create("minTime", "minTime", MFnNumericData::kDouble, 1.0);
    nAttr.setMin(1.0);
	nAttr.setKeyable(true);
	addAttribute(aMin);
	attributeAffects(aMin, aOutTime);

	aMax = nAttr.create("maxTime", "maxTime", MFnNumericData::kDouble, 200.0);
    nAttr.setMin(1.0);
	nAttr.setKeyable(true);
	addAttribute(aMax);
	attributeAffects(aMax, aOutTime);

	aScale = nAttr.create("timeScale", "timeScale", MFnNumericData::kDouble, 1.0);
    nAttr.setMin(0.0);
	nAttr.setKeyable(true);
	addAttribute(aScale);
	attributeAffects(aScale, aOutTime);

	return MS::kSuccess;
}