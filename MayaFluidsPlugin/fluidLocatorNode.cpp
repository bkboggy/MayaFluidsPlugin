#include "fluidLocatorNode.h"

MTypeId FluidLocatorNode::id(0x00000102);
MObject FluidLocatorNode::aOutValue;
MObject FluidLocatorNode::aHeight;
MObject FluidLocatorNode::aWidth;
MObject FluidLocatorNode::aLength;
MObject FluidLocatorNode::aTimeIn;

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

	float timeIn = data.inputValue(aTimeIn, &status).asFloat();
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
	MFnNumericAttribute nAttr;

	aOutValue = nAttr.create("outValue", "outValue", MFnNumericData::kFloat);
	nAttr.setWritable(false);
	nAttr.setStorable(false);
	addAttribute(aOutValue);

	aTimeIn = nAttr.create("timeIn", "timeIn", MFnNumericData::kFloat);
	nAttr.setKeyable(true);
	addAttribute(aTimeIn);
	attributeAffects(aTimeIn, aOutValue);

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

	return MS::kSuccess;
}