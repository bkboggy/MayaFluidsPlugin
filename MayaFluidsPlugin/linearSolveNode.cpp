#include "linearSolveNode.h"
#include "setBoundariesNode.h"

MTypeId LinearSolveNode::id(0x00000033);

MObject LinearSolveNode::aOutValue;
MObject LinearSolveNode::aInValue;
MObject LinearSolveNode::aN;
MObject LinearSolveNode::ab;
MObject LinearSolveNode::ax;
MObject LinearSolveNode::ax0;
MObject LinearSolveNode::aa;
MObject LinearSolveNode::ac;

LinearSolveNode::LinearSolveNode() {}

LinearSolveNode::~LinearSolveNode() {}

void* LinearSolveNode::creator()
{
	return new LinearSolveNode();
}

MStatus LinearSolveNode::initialize()
{
    MStatus status;

    // TODO: Add attribute initialization logic.

    return MS::kSuccess;
}

MStatus LinearSolveNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;

	if (plug != aOutValue)
	{
		return MS::kUnknownParameter;
	}

	// TODO: Add compute logic.

	return MS::kSuccess;
}

void LinearSolveNode::lin_solve(int N, int b, float* x, float* x0, float a, float c)
{
    int i, j, k;

    for (k = 0; k < 20; k++)
    {
        for (i = 1; i <= N; i++)
        {
            for (j = 1; j <= N; j++)
            {
                x[i + (N + 2)*j] = (x0[i + (N + 2)*j] + a*(x[(i - 1) + (N + 2)*j] + x[(i + 1) + (N + 2)*j] + x[i + (N + 2)*(j - 1)] + x[i + (N + 2)*(j + 1)])) / c;
            }
        }
        SetBoundariesNode::set_bnd(N, b, x);
    }
}
