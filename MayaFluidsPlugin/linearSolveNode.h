#ifndef LINEAR_SOLVE_NODE_H
#define LINEAR_SOLVE_NODE_H

#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>
#include <math.h>

class LinearSolveNode : public MPxNode
{
public:
	                LinearSolveNode();
	virtual         ~LinearSolveNode();
	static void*    creator();

    static MStatus  initialize();

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);	
    static void     lin_solve(int N, int b, float* x, float* x0, float a, float c);

	static MTypeId  id;

	static MObject  aOutValue;
	static MObject  aInValue;
	
	static MObject  aN;
	static MObject  ab;
	static MObject  ax;
	static MObject  ax0;
	static MObject  aa;
	static MObject  ac;
};

#endif
