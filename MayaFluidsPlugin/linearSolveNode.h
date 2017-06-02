#ifndef LINEAR_SOLVE_NODE_H
#define LINEAR_SOLVE_NODE_H

#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>
#include <math.h>

class LinearSolveNode : public MPxNode
{
public:
					LinearSolveNode();
	virtual			~LinearSolveNode();
	static void*	creator();

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);
	static MStatus	initialize();

	static MTypeId	id;

	static MObject	aOutValue;
	static MObject	aInValue;
	// TODO: ADD PARAMETERS
};

#endif
