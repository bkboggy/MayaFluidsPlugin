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

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);
	static MStatus  initialize();

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
