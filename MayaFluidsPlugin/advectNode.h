#ifndef ADVECT_NODE_H
#define ADVECT_NODE_H

#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>
#include <math.h>

class AdvectNode : public MPxNode
{
public:
					AdvectNode();
	virtual			~AdvectNode();
	static void*	creator();

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);
	static MStatus	initialize();

	static MTypeId	id;

	static MObject	aOutValue;
	static MObject	aInValue;
	// TODO: ADD PARAMETERS
};

#endif
