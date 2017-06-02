#ifndef VELOCITY_STEP_NODE_H
#define VELOCITY_STEP_NODE_H

#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>
#include <math.h>

class VelocityStepNode : public MPxNode
{
public:
					VelocityStepNode();
	virtual			~VelocityStepNode();
	static void*	creator();

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);
	static MStatus	initialize();

	static MTypeId	id;

	static MObject	aOutValue;
	static MObject	aInValue;
	
	static MObject	aN;
	static MObject	au;
	static MObject	av;
	static MObject	au0;
	static MObject	av0;
	static MObject	avisc;
	static MObject	adt;
};

#endif
