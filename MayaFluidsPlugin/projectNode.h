#ifndef PROJECT_NODE_H
#define PROJECT_NODE_H

#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>
#include <math.h>

class ProjectNode : public MPxNode
{
public:
	                ProjectNode();
	virtual         ~ProjectNode();
	static void*    creator();

    static MStatus  initialize();

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);
    static void     project(int N, float* u, float* v, float* p, float* div);
	
	static MTypeId  id;

	static MObject  aOutValue;
	static MObject  aInValue;
	
	static MObject  aN;
	static MObject  au;
	static MObject  av;
	static MObject  ap;
	static MObject  adiv;
};

#endif
