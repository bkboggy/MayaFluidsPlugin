#ifndef VELOCITY_STEP_NODE_H
#define VELOCITY_STEP_NODE_H

#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>
#include <math.h>

class VelocityStepNode : public MPxNode
{
public:
	                VelocityStepNode();
	virtual         ~VelocityStepNode();
	static void*    creator();

    static MStatus  initialize();

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);
    static void     vel_step(int N, float* u, float* v, float* u0, float* v0, float visc, float dt);

	static MTypeId  id;

	static MObject  aOutValue;
	static MObject  aInValue;
	
	static MObject  aN;
	static MObject  au;
	static MObject  av;
	static MObject  au0;
	static MObject  av0;
	static MObject  avisc;
	static MObject  adt;
};

#endif
