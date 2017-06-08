#include "FluidTimeNode.h"

MTypeId FluidTimeNode::id(0x00000103);
MObject FluidTimeNode::aTimeIn;
MObject FluidTimeNode::aTimeOut;
MObject FluidTimeNode::aMinTime;
MObject FluidTimeNode::aMaxTime;
MObject FluidTimeNode::aTimeScale;

FluidTimeNode::FluidTimeNode() {}

FluidTimeNode::~FluidTimeNode() {}

void* FluidTimeNode::creator()
{
	return new FluidTimeNode();
}

MStatus FluidTimeNode::initialize()
{
    MStatus status;
    MFnUnitAttribute uAttr;
    MFnNumericAttribute nAttr;

    aTimeOut = uAttr.create("timeOut", "timeOut", MTime(1.0));
    nAttr.setWritable(false);
    nAttr.setStorable(false);
    addAttribute(aTimeOut);

    aTimeIn = uAttr.create("timeIn", "timeIn", MTime(1.0));
    nAttr.setKeyable(true);
    addAttribute(aTimeIn);
    attributeAffects(aTimeIn, aTimeOut);

    aMinTime = nAttr.create("minTime", "minTime", MFnNumericData::kDouble, 1.0);
    nAttr.setMin(1.0);
    nAttr.setKeyable(true);
    addAttribute(aMinTime);
    attributeAffects(aMinTime, aTimeOut);

    aMaxTime = nAttr.create("maxTime", "maxTime", MFnNumericData::kDouble, 200.0);
    nAttr.setMin(1.0);
    nAttr.setKeyable(true);
    addAttribute(aMaxTime);
    attributeAffects(aMaxTime, aTimeOut);

    aTimeScale = nAttr.create("timeScale", "timeScale", MFnNumericData::kDouble, 1.0);
    nAttr.setMin(0.0);
    nAttr.setKeyable(true);
    addAttribute(aTimeScale);
    attributeAffects(aTimeScale, aTimeOut);

    return MS::kSuccess;
}

MStatus FluidTimeNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;

	if (plug != aTimeOut)
	{
		return MS::kUnknownParameter;
	}

	MTime inTime = data.inputValue(aTimeIn, &status).asTime();
	double minTime = data.inputValue(aMinTime, &status).asDouble();
	double maxTime = data.inputValue(aMaxTime, &status).asDouble();
	double timeScale = data.inputValue(aTimeScale, &status).asDouble();

	if (timeScale <= 0.0f)
	{
		timeScale = 0.01f;
	}

	MTime outTime;
	if (inTime > maxTime)
	{
		outTime = ((inTime + maxTime) - inTime) / timeScale;
	}
	else if (inTime < minTime)
	{
		outTime = MTime(0.0);
	}
	else
	{
		outTime = (inTime - minTime) / timeScale;
	}

	MDataHandle hOutput = data.outputValue(aTimeOut, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);
	hOutput.set(outTime);
	hOutput.setClean();
	data.setClean(plug);

	return MS::kSuccess;
}
