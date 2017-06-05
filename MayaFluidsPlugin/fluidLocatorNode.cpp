#include "fluidLocatorNode.h"

MTypeId FluidLocatorNode::id(0x00000102);
MObject FluidLocatorNode::aOutValue;
MObject FluidLocatorNode::aVoxelCount;
MObject FluidLocatorNode::aHeight;
MObject FluidLocatorNode::aWidth;
MObject FluidLocatorNode::aLength;
MObject FluidLocatorNode::aTime;
MObject FluidLocatorNode::aDensity;
MObject FluidLocatorNode::aVelocityU;
MObject FluidLocatorNode::aVelocityV;
MObject FluidLocatorNode::aVelocityW;

FluidLocatorNode::FluidLocatorNode()
{
}

FluidLocatorNode::~FluidLocatorNode()
{
}

MStatus FluidLocatorNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;
	float output;

	if (plug != aOutValue)
	{
		return MS::kUnknownParameter;
	}

	float timeIn = data.inputValue(aTime, &status).asFloat();
	float height = data.inputValue(aHeight, &status).asFloat();
	float width = data.inputValue(aWidth, &status).asFloat();
	float length = data.inputValue(aLength, &status).asFloat();

	output = sin(timeIn);

	MDataHandle hOutput = data.outputValue(aOutValue, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);
	hOutput.setFloat(output);
	hOutput.setClean();
	data.setClean(plug);

	return MS::kSuccess;
}

void FluidLocatorNode::draw(M3dView& view, const MDagPath& DGpath, M3dView::DisplayStyle  style, M3dView::DisplayStatus stat)
{
	MStatus status;
	float height;
	float width;
	float length;

	MFnDependencyNode dFn(thisMObject(), &status);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to initialize dependency node");
		return;
	}

	MPlug valPlug = dFn.findPlug(aHeight, &status);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to get height plug");
		return;
	}
	status = valPlug.getValue(height);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to get height value");
		return;
	}

	valPlug = dFn.findPlug(aWidth, &status);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to get width plug");
		return;
	}
	status = valPlug.getValue(width);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to get width value");
		return;
	}

	valPlug = dFn.findPlug(aLength, &status);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to get length plug");
		return;
	}
	status = valPlug.getValue(length);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to get length value");
		return;
	}
	view.beginGL();

	glBegin(GL_LINE_LOOP);
	glVertex3f(width, height, length);
	glVertex3f(-width, height, length);
	glVertex3f(-width, height, -length);
	glVertex3f(width, height, -length);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(width, -height, length);
	glVertex3f(-width, -height, length);
	glVertex3f(-width, -height, -length);
	glVertex3f(width, -height, -length);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(width, height, length);
	glVertex3f(width, -height, length);

	glVertex3f(-width, height, length);
	glVertex3f(-width, -height, length);

	glVertex3f(-width, height, -length);
	glVertex3f(-width, -height, -length);

	glVertex3f(width, height, -length);
	glVertex3f(width, -height, -length);
	glEnd();

	view.endGL();

}

void* FluidLocatorNode::creator()
{
	return new FluidLocatorNode();
}

MStatus FluidLocatorNode::initialize()
{
	MStatus status;
    MFnUnitAttribute uAttr;
	MFnNumericAttribute nAttr;
    MFnTypedAttribute tAttr;

	aOutValue = nAttr.create("outValue", "outValue", MFnNumericData::kFloat);
	nAttr.setWritable(false);
	nAttr.setStorable(false);
	addAttribute(aOutValue);

	aTime = uAttr.create("time", "time", MTime(1.0));
	nAttr.setKeyable(true);
	addAttribute(aTime);
	attributeAffects(aTime, aOutValue);

    aVoxelCount = nAttr.create("voxelCount", "voxelCount", MFnNumericData::kInt);
    nAttr.setKeyable(true);
    addAttribute(aVoxelCount);
    attributeAffects(aVoxelCount, aOutValue);

	aHeight = nAttr.create("height", "height", MFnNumericData::kFloat);
	nAttr.setKeyable(true);
	addAttribute(aHeight);
	attributeAffects(aHeight, aOutValue);

	aWidth = nAttr.create("width", "width", MFnNumericData::kFloat);
	nAttr.setKeyable(true);
	addAttribute(aWidth);
	attributeAffects(aWidth, aOutValue);

	aLength = nAttr.create("length", "length", MFnNumericData::kFloat);
	nAttr.setKeyable(true);
	addAttribute(aLength);
	attributeAffects(aLength, aOutValue);

    MFloatArray defaultMArr(100, 0.0f);
    MFnFloatArrayData fnDefaultMArr;
    MFnData defaultArrData = fnDefaultMArr.create(defaultMArr, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MObject defaultArr = defaultArrData.object();

    aDensity = tAttr.create("density", "density", MFnData::kFloatArray, defaultArr);
    tAttr.setKeyable(true);
    addAttribute(aDensity);
    attributeAffects(aDensity, aDensity);

    aVelocityU = tAttr.create("velocityU", "velocityU", MFnData::kFloatArray, defaultArr);
    tAttr.setKeyable(true);
    addAttribute(aVelocityU);
    attributeAffects(aVelocityU, aOutValue);

    aVelocityW = tAttr.create("velocityV", "velocityV", MFnData::kFloatArray, defaultArr);
    tAttr.setKeyable(true);
    addAttribute(aVelocityW);
    attributeAffects(aVelocityW, aOutValue);

    aVelocityW = tAttr.create("velocityW", "velocityW", MFnData::kFloatArray, defaultArr);
    tAttr.setKeyable(true);
    addAttribute(aVelocityW);
    attributeAffects(aVelocityW, aOutValue);

	return MS::kSuccess;
}