#ifndef FRAMEREADERNODE_H
#define FRAMEREADERNODE_H

#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>

class FrameReaderNode : public MPxNode
{
public:
	FrameReaderNode();
	virtual	~FrameReaderNode();
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