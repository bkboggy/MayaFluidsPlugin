#ifndef ADD_SOURCE_NODE_H
#define ADD_SOURCE_NODE_H

#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>
#include <math.h>

class AddSourceNode : public MPxNode
{
public:
	                AddSourceNode();
	virtual         ~AddSourceNode();
	static void*    creator();

    static MStatus  initialize();

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);
    static void     add_source(int N, float* x, float* s, float dt);

	static MTypeId  id;

	static MObject  aOutValue;
	static MObject  aInValue;

	static MObject  aN;
	static MObject  ax;
	static MObject  as;
	static MObject  adt;
};

#endif
