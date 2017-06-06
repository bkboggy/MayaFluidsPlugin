#include "fluidLocatorNode.h"

MTypeId FluidLocatorNode::id(0x00000102);
MObject FluidLocatorNode::aOutValue;
MObject FluidLocatorNode::aShowVoxels;
MObject FluidLocatorNode::aVoxelAlpha;
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

void FluidLocatorNode::postConstructor()
{
    MFnDependencyNode nodeFn(thisMObject());
    nodeFn.setName("fluidLocatorShape#");
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
    int voxelCount = data.inputValue(aLength, &status).asInt();
    bool showVoxels = data.inputValue(aShowVoxels, &status).asBool();
    float voxelAlpha = data.inputValue(aVoxelAlpha, &status).asFloat();

	output = sin(timeIn);

	MDataHandle hOutput = data.outputValue(aOutValue, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);
	hOutput.setFloat(output);
	hOutput.setClean();
	data.setClean(plug);

	return MS::kSuccess;
}

void FluidLocatorNode::draw(M3dView& view, const MDagPath& DGpath, M3dView::DisplayStyle style, M3dView::DisplayStatus stat)
{
	MStatus status;
	float height;
	float width;
	float length;
    int voxelCount;
    bool showVoxels;
    float voxelAlpha;

	MFnDependencyNode dFn(thisMObject(), &status);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to initialize dependency node.");
		return;
	}

	MPlug valPlug = dFn.findPlug(aHeight, &status);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to get height plug.");
		return;
	}
	status = valPlug.getValue(height);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to get height value.");
		return;
	}

	valPlug = dFn.findPlug(aWidth, &status);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to get width plug.");
		return;
	}
	status = valPlug.getValue(width);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to get width value.");
		return;
	}

	valPlug = dFn.findPlug(aLength, &status);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to get length plug.");
		return;
	}
	status = valPlug.getValue(length);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to get length value.");
		return;
	}

    valPlug = dFn.findPlug(aVoxelCount, &status);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get voxelCount plug.");
        return;
    }
    status = valPlug.getValue(voxelCount);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get voxelCount value.");
        return;
    }

    valPlug = dFn.findPlug(aShowVoxels, &status);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get showVoxel plug.");
        return;
    }
    status = valPlug.getValue(showVoxels);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get showVoxel value.");
        return;
    }

    valPlug = dFn.findPlug(aVoxelAlpha, &status);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get voxelAlpha plug.");
        return;
    }
    status = valPlug.getValue(voxelAlpha);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get voxelAlpha value.");
        return;
    }

	view.beginGL();
    glPushAttrib(GL_CURRENT_BIT);

    if (showVoxels)
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        MColor col = colorRGB(stat);
        if (stat == M3dView::kLead)
        {
            glColor4f(0.26f, 1.0f, 0.64f, voxelAlpha);
        }
        else
        {
            glColor4f(col.r, col.g, col.b, voxelAlpha);
        }

        float wIncrement = width / voxelCount;
        float hIncrement = height / voxelCount;
        float lIncrement = length / voxelCount;

        glBegin(GL_LINES);
        for (int i = 0; i <= voxelCount; i++)
        {
            for (int j = 0; j <= voxelCount; j++)
            {
                glVertex3f(wIncrement*i, 0, lIncrement*j);
                glVertex3f(wIncrement*i, height, lIncrement*j);

                glVertex3f(wIncrement*i, hIncrement*j, 0);
                glVertex3f(wIncrement*i, hIncrement*j, length);

                glVertex3f(0, hIncrement*i, lIncrement*j);
                glVertex3f(width, hIncrement*i, lIncrement*j);
            }
        }
        glEnd();
    }
    else
    {
        glBegin(GL_LINE_LOOP);
        glVertex3f(0, 0, 0);
        glVertex3f(0, height, 0);
        glVertex3f(width, height, 0);
        glVertex3f(width, 0, 0);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glVertex3f(0, 0, length);
        glVertex3f(0, height, length);
        glVertex3f(width, height, length);
        glVertex3f(width, 0, length);
        glEnd();

        glBegin(GL_LINES);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, length);

        glVertex3f(width, 0, 0);
        glVertex3f(width, 0, length);

        glVertex3f(0, height, 0);
        glVertex3f(0, height, length);

        glVertex3f(width, height, 0);
        glVertex3f(width, height, length);
        glEnd();
    }

    glPopAttrib();
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

    aShowVoxels = nAttr.create("showVoxels", "showVoxels", MFnNumericData::kBoolean, false);
    nAttr.setKeyable(true);
    addAttribute(aShowVoxels);

    aVoxelAlpha = nAttr.create("voxelAlpha", "voxelAlpha", MFnNumericData::kFloat, 0.3f);
    nAttr.setMin(0.0f);
    nAttr.setMax(1.0f);
    nAttr.setKeyable(true);
    addAttribute(aVoxelAlpha);

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