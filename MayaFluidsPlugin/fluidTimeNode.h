#ifndef FLUID_TIME_NODE_H
#define FLUID_TIME_NODE_H

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

	static MObject aInTime;
	static MObject aOutTime;
	static MObject aMin;
	static MObject aMax;
	static MObject aScale;
};

#endif
