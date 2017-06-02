#ifndef DENSITY_STEP_NODE_H
#define DENSITY_STEP_NODE_H

#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>
#include <math.h>

class DensityStepNode : public MPxNode
{
public:
	                DensityStepNode();
	virtual         ~DensityStepNode();
	static void*    creator();

    static MStatus  initialize();

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);	
    static void     dens_step(int N, float* x, float* x0, float* u, float* v, float diff, float dt);

	static MTypeId  id;

	static MObject  aOutValue;
	static MObject  aInValue;
	
	static MObject  aN;
	static MObject  ax;
	static MObject  ax0;
	static MObject  au;
	static MObject  av;
	static MObject  adiff;
	static MObject  adt;
};

#endif
