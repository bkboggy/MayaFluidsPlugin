#include "advectNode.h"
#include "setBoundariesNode.h"

MTypeId AdvectNode::id(0x00000035);

MObject AdvectNode::aOutValue;
MObject AdvectNode::aInValue;
MObject AdvectNode::aN;
MObject AdvectNode::ab;
MObject AdvectNode::ad;
MObject AdvectNode::ad0;
MObject AdvectNode::au;
MObject AdvectNode::av;
MObject AdvectNode::adt;

AdvectNode::AdvectNode() {}

AdvectNode::~AdvectNode() {}

void* AdvectNode::creator()
{
	return new AdvectNode();
}

MStatus AdvectNode::initialize()
{
    MStatus status;

    // TODO: Add attribute initialization logic.

    return MS::kSuccess;
}

MStatus AdvectNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;

	if (plug != aOutValue)
	{
		return MS::kUnknownParameter;
	}

	// TODO: Add compute logic.

	return MS::kSuccess;
}

void AdvectNode::advect(int N, int b, float* d, float* d0, float* u, float* v, float dt)
{
    int i, j, i0, j0, i1, j1;
    float x, y, s0, t0, s1, t1, dt0;

    dt0 = dt*N;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            x = i - dt0*u[i + (N + 2)*j]; y = j - dt0*v[i + (N + 2)*j];
            if (x < 0.5f) x = 0.5f; if (x > N + 0.5f) x = N + 0.5f; i0 = (int)x; i1 = i0 + 1;
            if (y < 0.5f) y = 0.5f; if (y > N + 0.5f) y = N + 0.5f; j0 = (int)y; j1 = j0 + 1;
            s1 = x - i0; s0 = 1 - s1; t1 = y - j0; t0 = 1 - t1;
            d[i + (N + 2)*j] = s0*(t0*d0[i0 + (N + 2)*j0] + t1*d0[i0 + (N + 2)*j1]) + s1*(t0*d0[i1 + (N + 2)*j0] + t1*d0[i1 + (N + 2)*j1]);
        }
    }
    SetBoundariesNode::set_bnd(N, b, d);
}
