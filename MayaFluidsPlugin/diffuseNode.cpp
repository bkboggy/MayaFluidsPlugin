#include "diffuseNode.h"
#include "linearSolveNode.h"

MTypeId DiffuseNode::id(0x00000034);

MObject DiffuseNode::aOutValue;
MObject DiffuseNode::aInValue;
MObject DiffuseNode::aN;
MObject DiffuseNode::ab;
MObject DiffuseNode::ax;
MObject DiffuseNode::ax0;
MObject DiffuseNode::adiff;
MObject DiffuseNode::adt;

DiffuseNode::DiffuseNode() {}

DiffuseNode::~DiffuseNode() {}

void* DiffuseNode::creator()
{
	return new DiffuseNode();
}

MStatus DiffuseNode::initialize()
{
    MStatus status;

    // TODO: Add attribute initialization logic.

    return MS::kSuccess;
}

MStatus DiffuseNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;

	if (plug != aOutValue)
	{
		return MS::kUnknownParameter;
	}

	// TODO: Add compute logic.

	return MS::kSuccess;
}

void DiffuseNode::diffuse(int N, int b, float* x, float* x0, float diff, float dt)
{
    float a = dt*diff*N*N;
    LinearSolveNode::lin_solve(N, b, x, x0, a, 1 + 4*a);
}
