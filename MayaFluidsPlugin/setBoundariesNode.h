#ifndef SET_BOUNDARIES_NODE_H
#define SET_BOUNDARIES_NODE_H

#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>
#include <math.h>

class SetBoundariesNode : public MPxNode
{
public:
	                SetBoundariesNode();
	virtual         ~SetBoundariesNode();
	static void*    creator();

    static MStatus  initialize();

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);
    static void     set_bnd(int N, int b, float* x);

	static MTypeId  id;

	static MObject  aOutValue;
	static MObject  aInValue;
	
	static MObject  aN;
	static MObject  ab;
	static MObject  ax;
};

#endif
