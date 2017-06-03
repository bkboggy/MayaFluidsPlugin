#include "addSourceNode.h"

MTypeId AddSourceNode::id(0x00000031);

MObject AddSourceNode::aOutValue;
MObject AddSourceNode::aInValue;
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

    // TODO: Add attribute initialization logic.

    return MS::kSuccess;
}

MStatus AddSourceNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;

	if (plug != aOutValue)
	{
		return MS::kUnknownParameter;
	}

	// TODO: Add compute logic.

    /*
    float inputValue = data.inputValue(aInValue, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);
    float magnitude = data.inputValue(aMagnitude, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);
    float mean = data.inputValue(aMean, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);
    float variance = data.inputValue(aVariance, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    if (variance <= 0.0f)
    {
        variance = 0.00001f;
    }

    float xMinusB = inputValue - mean;
    float output = magnitude * exp(-(xMinusB*xMinusB) / (2.0f*variance));

    MDataHandle hOutput = data.outputValue(aOutValue, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.setFloat(output);
    hOutput.setClean();
    */

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
