#ifndef FLUIDTIMENODE_H
#define FLUIDTIMENODE_H

#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MTime.h>
#include <maya/MFnUnitAttribute.h>

class FluidTimeNode : public MPxNode
{
public:
	FluidTimeNode();
	virtual	~FluidTimeNode();
	static void* creator();

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);
	static  MStatus initialize();

	static MTypeId id;

	static MObject aInValue;
	static MObject aOutValue;
	static MObject aMin;
	static MObject aMax;
	static MObject aScale;
};

#endif
