#include "densityStepNode.h"
#include "addSourceNode.h"
#include "diffuseNode.h"
#include "advectNode.h"

MTypeId DensityStepNode::id(0x00000037);

MObject DensityStepNode::aOutValue;
MObject DensityStepNode::aInValue;
MObject DensityStepNode::aN;
MObject DensityStepNode::ax;
MObject DensityStepNode::ax0;
MObject DensityStepNode::au;
MObject DensityStepNode::av;
MObject DensityStepNode::adiff;
MObject DensityStepNode::adt;

DensityStepNode::DensityStepNode() {}

DensityStepNode::~DensityStepNode() {}

void* DensityStepNode::creator()
{
	return new DensityStepNode();
}

MStatus DensityStepNode::initialize()
{
    MStatus status;

    // TODO: Add attribute initialization logic.

    return MS::kSuccess;
}

MStatus DensityStepNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;

	if (plug != aOutValue)
	{
		return MS::kUnknownParameter;
	}

	// TODO: Add compute logic.

	return MS::kSuccess;
}

void DensityStepNode::dens_step(int N, float* x, float* x0, float* u, float* v, float diff, float dt)
{
    AddSourceNode::add_source(N, x, x0, dt);
    {
        float * tmp = x0; x0 = x; x = tmp;
    }
    DiffuseNode::diffuse(N, 0, x, x0, diff, dt);
    {
        float * tmp = x0; x0 = x; x = tmp;
    }
    AdvectNode::advect(N, 0, x, x0, u, v, dt);
}
