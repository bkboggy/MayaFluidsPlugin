#ifndef DIFFUSE_NODE_H
#define DIFFUSE_NODE_H

#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>
#include <math.h>

class DiffuseNode : public MPxNode
{
public:
	                DiffuseNode();
	virtual         ~DiffuseNode();
	static void*    creator();

    static MStatus  initialize();

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);
    static void     diffuse(int N, int b, float* x, float* x0, float diff, float dt);

	static MTypeId  id;

	static MObject  aOutValue;
	static MObject  aInValue;
	
	static MObject  aN;
	static MObject  ab;
	static MObject  ax;
	static MObject  ax0;
	static MObject  adiff;
	static MObject  adt;
};

#endif
