#ifndef GAUSSIANNODE_H
#define GAUSSIANNODE_H

#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>
#include <math.h>

class GaussianNode : public MPxNode
{
public:
					GaussianNode();
	virtual			~GaussianNode();
	static void*	creator();

    static MStatus	initialize();

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);

	static MTypeId	id;

	static MObject	aOutValue;
	static MObject	aInValue;
	static MObject	aMagnitude;
	static MObject	aMean;
	static MObject	aVariance;
};

#endif
