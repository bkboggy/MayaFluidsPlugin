#include "projectNode.h"
#include "linearSolveNode.h"
#include "setBoundariesNode.h"

MTypeId ProjectNode::id(0x00000036);

MObject ProjectNode::aOutValue;
MObject ProjectNode::aInValue;
MObject ProjectNode::aN;
MObject ProjectNode::au;
MObject ProjectNode::av;
MObject ProjectNode::ap;
MObject ProjectNode::adiv;

ProjectNode::ProjectNode() {}

ProjectNode::~ProjectNode() {}

void* ProjectNode::creator()
{
	return new ProjectNode();
}

MStatus ProjectNode::initialize()
{
    MStatus status;

    // TODO: Add attribute initialization logic.

    return MS::kSuccess;
}

MStatus ProjectNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;

	if (plug != aOutValue)
	{
		return MS::kUnknownParameter;
	}

	// TODO: Add compute logic.

	return MS::kSuccess;
}

void ProjectNode::project(int N, float* u, float* v, float* p, float* div)
{
    int i, j;

    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            div[i + (N + 2)*j] = -0.5f*(u[(i + 1) + (N + 2)*j] - u[(i - 1) + (N + 2)*j] + v[i + (N + 2)*(j + 1)] - v[i + (N + 2)*(j - 1)]) / N;
            p[i + (N + 2)*j] = 0;
        }
    }

    SetBoundariesNode::set_bnd(N, 0, div); 
    SetBoundariesNode::set_bnd(N, 0, p);
    LinearSolveNode::lin_solve(N, 0, p, div, 1, 4);

    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            u[i + (N + 2)*j] -= 0.5f*N*(p[(i + 1) + (N + 2)*j] - p[(i - 1) + (N + 2)*j]);
            v[i + (N + 2)*j] -= 0.5f*N*(p[i + (N + 2)*(j + 1)] - p[i + (N + 2)*(j - 1)]);
        }
    }
    SetBoundariesNode::set_bnd(N, 1, u); 
    SetBoundariesNode::set_bnd(N, 2, v);
}