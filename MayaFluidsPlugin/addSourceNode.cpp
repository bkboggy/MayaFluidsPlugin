#include "addSourceNode.h"

MTypeId AddSourceNode::id(0x00000031);

MObject AddSourceNode::aN;
MObject AddSourceNode::ax;
MObject AddSourceNode::as;
MObject AddSourceNode::adt;

MObject AddSourceNode::aNOut;
MObject AddSourceNode::axOut;
MObject AddSourceNode::adtOut;

AddSourceNode::AddSourceNode() {}

AddSourceNode::~AddSourceNode() {}

void* AddSourceNode::creator()
{
	return new AddSourceNode();
}

MStatus AddSourceNode::initialize()
{
    MStatus status;
    MFnNumericAttribute nAttr;
    MFnTypedAttribute tAttr;

    aN = nAttr.create("N", "N", MFnNumericData::kInt);
    nAttr.setWritable(false);
    nAttr.setStorable(false);  
    addAttribute(aN);
    attributeAffects(aN, aNOut);
    attributeAffects(aN, axOut);

    adt = nAttr.create("dt", "dt", MFnNumericData::kFloat);
    nAttr.setWritable(false);
    nAttr.setStorable(false);
    addAttribute(adt);
    attributeAffects(adt, adtOut);
    attributeAffects(adt, axOut); 

    ax = tAttr.create("x", "x", MFnTypedAttribute::kReset);
    addAttribute(ax);
    attributeAffects(ax, axOut);  

    as = tAttr.create("s", "s", MFnTypedAttribute::kReset);
    tAttr.setKeyable(true);
    addAttribute(as);
    attributeAffects(as, axOut); 

    aNOut = nAttr.create("NOut", "NOut", MFnNumericData::kInt);
    nAttr.setWritable(false);
    nAttr.setStorable(false);
    addAttribute(aNOut);

    axOut = tAttr.create("xOut", "xOut", MFnTypedAttribute::kReset);
    tAttr.setWritable(false);
    tAttr.setStorable(false);
    addAttribute(axOut);

    adtOut = nAttr.create("dtOut", "dtOut", MFnNumericData::kFloat);
    nAttr.setWritable(false);
    nAttr.setStorable(false);
    addAttribute(adtOut);

    return MS::kSuccess;
}

MStatus AddSourceNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;

    if (plug != aNOut && plug != axOut && plug != adtOut)
	{
		return MS::kUnknownParameter;
	}

    int NValue = data.inputValue(aN, &status).asInt();
    CHECK_MSTATUS_AND_RETURN_IT(status);
    float dtValue = data.inputValue(adt, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);
    //xValue =
    CHECK_MSTATUS_AND_RETURN_IT(status);
    //sValue =
    CHECK_MSTATUS_AND_RETURN_IT(status);

    int size = (NValue + 2)*(NValue + 2);
    for (int i = 0; i < size; i++)
    {
        //xValue[i] += dtValue*sValue[i];
    }

    MDataHandle hOutput = data.outputValue(aNOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.setInt(NValue);
    hOutput.setClean();

    MArrayDataHandle hArrOutput = data.outputArrayValue(axOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    //hArrOutput.set(xValue);
    hArrOutput.setClean();

    hOutput = data.outputValue(adtOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.setFloat(dtValue);
    hOutput.setClean();

	return MS::kSuccess;
}

void AddSourceNode::add_source(int N, float* x, float* s, float dt)
{
    // Size of the simluation, including the boundaries.
    int size = (N + 2)*(N + 2);

    for (int i = 0; i < size; i++)
    {
        x[i] += dt*s[i];
    }
}
