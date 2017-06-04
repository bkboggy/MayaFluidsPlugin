#include "addSourceNode.h"

MTypeId AddSourceNode::id(0x00000031);

MObject AddSourceNode::axOut;

MObject AddSourceNode::aN;
MObject AddSourceNode::ax;
MObject AddSourceNode::as;
MObject AddSourceNode::adt;

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
    
    axOut = tAttr.create("xOut", "xOut", MFnData::kDoubleArray);
    tAttr.setWritable(false);
    tAttr.setStorable(false);
    addAttribute(axOut);

    aN = nAttr.create("N", "N", MFnNumericData::kInt);
    nAttr.setKeyable(true);
    addAttribute(aN);
    attributeAffects(aN, axOut);

    adt = nAttr.create("dt", "dt", MFnNumericData::kDouble);
    nAttr.setKeyable(true);
    addAttribute(adt);
    attributeAffects(adt, axOut); 

    ax = tAttr.create("x", "x", MFnData::kDoubleArray);
    tAttr.setKeyable(true);
    addAttribute(ax);
    attributeAffects(ax, axOut);  

    as = tAttr.create("s", "s", MFnData::kDoubleArray);
    tAttr.setKeyable(true);
    addAttribute(as);
    attributeAffects(as, axOut); 

    return MS::kSuccess;
}

MStatus AddSourceNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;

    if (plug != axOut)
	{
		return MS::kUnknownParameter;
	}

    int NValue = data.inputValue(aN, &status).asInt();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    double dtValue = data.inputValue(adt, &status).asDouble();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    MDataHandle xDataHandle = data.inputValue(ax, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnDoubleArrayData xFnData(xDataHandle.data());
    MDoubleArray xArr = xFnData.array();

    MDataHandle sDataHandle = data.inputValue(as, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnDoubleArrayData sFnData(xDataHandle.data());
    MDoubleArray sArr = sFnData.array();
 
    MDoubleArray xArrOut(xArr);
  
    int size = (NValue + 2)*(NValue + 2);
    for (int i = 0; i < size; i++)
    {
        xArrOut.set(dtValue*sArr[i], i);
    }  

    MDataHandle hOutput = data.outputValue(axOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnDoubleArrayData xFnDataOut;
    MObject xOut = xFnDataOut.create(xArrOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(xOut);
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
