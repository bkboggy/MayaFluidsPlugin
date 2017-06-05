#ifndef FLUIDLOCATORNODE_H
#define FLUIDLOCATORNODE_H

#include <maya/MTypeId.h>
#include <maya/MStatus.h>
#include <maya/M3dView.h>
#include <maya/MGlobal.h>
#include <maya/MPxLocatorNode.h>
#include <maya/MFnDependencyNode.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MSelectionList.h>
#include <math.h>

class FluidLocatorNode : public MPxLocatorNode
{
public:
	FluidLocatorNode();
	virtual ~FluidLocatorNode();

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);
	virtual void draw(M3dView&, const MDagPath&, M3dView::DisplayStyle, M3dView::DisplayStatus);

	static void* creator();
	static MStatus initialize();

	static MObject aOutValue;
	static MObject aTimeIn;
	static MObject aHeight;
	static MObject aWidth;
	static MObject aLength;

	static MTypeId id;
};

#endif