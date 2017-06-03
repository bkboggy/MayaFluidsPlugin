#include "velocityStepNode.h"
#include "addSourceNode.h"
#include "projectNode.h"
#include "advectNode.h"
#include "diffuseNode.h"

MTypeId VelocityStepNode::id(0x00000038);

MObject VelocityStepNode::aOutValue;
MObject VelocityStepNode::aInValue;
MObject VelocityStepNode::aN;
MObject VelocityStepNode::au;
MObject VelocityStepNode::av;
MObject VelocityStepNode::au0;
MObject VelocityStepNode::av0;
MObject VelocityStepNode::avisc;
MObject VelocityStepNode::adt;

VelocityStepNode::VelocityStepNode() {}

VelocityStepNode::~VelocityStepNode() {}

void* VelocityStepNode::creator()
{
	return new VelocityStepNode();
}

MStatus VelocityStepNode::initialize()
{
    MStatus status;

    // TODO: Add attribute initialization logic.

    return MS::kSuccess;
}

MStatus VelocityStepNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;

	if (plug != aOutValue)
	{
		return MS::kUnknownParameter;
	}

	// TODO: Add compute logic.

	return MS::kSuccess;
}

void VelocityStepNode::vel_step(int N, float* u, float* v, float* u0, float* v0, float visc, float dt)
{
    AddSourceNode::add_source(N, u, u0, dt);
    AddSourceNode::add_source(N, v, v0, dt);
    {
        float* tmp = u0;
        u0 = u;
        u = tmp;
    }
    DiffuseNode::diffuse(N, 1, u, u0, visc, dt);
    {
        float * tmp = v0;
        v0 = v;
        v = tmp;
    }
    DiffuseNode::diffuse(N, 2, v, v0, visc, dt);
    ProjectNode::project(N, u, v, u0, v0);
    {
        float* tmp = u0;
        u0 = u;
        u = tmp;
    }
    {
        float* tmp = v0;
        v0 = v;
        v = tmp;
    }
    AdvectNode::advect(N, 1, u, u0, u0, v0, dt);
    AdvectNode::advect(N, 2, v, v0, u0, v0, dt);
    ProjectNode::project(N, u, v, u0, v0);
}
