#include "setBoundariesNode.h"

MTypeId SetBoundariesNode::id(0x00000032);

MObject SetBoundariesNode::aOutValue;
MObject SetBoundariesNode::aInValue;
MObject SetBoundariesNode::aN;
MObject SetBoundariesNode::ab;
MObject SetBoundariesNode::ax;

SetBoundariesNode::SetBoundariesNode() {}

SetBoundariesNode::~SetBoundariesNode() {}

void* SetBoundariesNode::creator()
{
	return new SetBoundariesNode();
}

MStatus SetBoundariesNode::initialize()
{
    MStatus status;

    // TODO: Add attribute initialization logic.

    return MS::kSuccess;
}

MStatus SetBoundariesNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;

	if (plug != aOutValue)
	{
		return MS::kUnknownParameter;
	}

	// TODO: Add compute logic.

	return MS::kSuccess;
}

void SetBoundariesNode::set_bnd(int N, int b, float* x)
{
    // Set boundary specifications on edges, without including the corners.
    for (int i = 1; i <= N; i++)
    {
        x[0 + (N + 2)*i] = b == 1 ? -x[1 + (N + 2)*i] : x[1 + (N + 2)*i];
        x[(N + 1) + (N + 2)*i] = b == 1 ? -x[N + (N + 2)*i] : x[N + (N + 2)*i];
        x[i + (N + 2)*0] = b == 2 ? -x[i + (N + 2)*1] : x[i + (N + 2)*1];
        x[i + (N + 2)*(N + 1)] = b == 2 ? -x[i + (N + 2)*N] : x[i + (N + 2)*N];
    }

    // Set top-left corner.
    x[0 + (N + 2) * 0] = 0.5f*(x[1 + (N + 2) * 0] + x[0, +(N + 2) * 1]);

    // Set top-right corner.
    x[0 + (N + 2)*(N + 1)] = 0.5f*(x[1 + (N + 2)*(N + 1)] + x[0 + (N + 2)*N]);

    // Set bottom-left corner.
    x[(N + 1) + (N + 2) * 0] = 0.5f*(x[N + (N + 2) * 0] + x[(N + 1) + (N + 2) * 1]);

    // Set bottom-right corner.
    x[(N + 1) + (N + 2)*(N + 1)] = 0.5f*(x[N + (N + 2)*(N + 1)] + x[(N + 1) + (N + 2)*N]);
}
