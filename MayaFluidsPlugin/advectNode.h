#ifndef ADVECT_NODE_H
#define ADVECT_NODE_H

#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>
#include <math.h>

class AdvectNode : public MPxNode
{
public:
	                AdvectNode();
	virtual         ~AdvectNode();
	static void*    creator();

    static MStatus  initialize();

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);	
    static void     advect(int N, int b, float* d, float* d0, float* u, float* v, float dt);

	static MTypeId  id;

	static MObject  aOutValue;
	static MObject  aInValue;

	static MObject  aN;
	static MObject  ab;
	static MObject  ad;
	static MObject  ad0;
	static MObject  au;
	static MObject  av;
	static MObject  adt;
};

#endif
