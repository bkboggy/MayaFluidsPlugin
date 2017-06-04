#ifndef ROOTNODE_H
#define ROOTNODE_H

#include <maya/MTypeId.h>
#include <maya/MStatus.h>
#include <maya/M3dView.h>
#include <maya/MGlobal.h>
#include <maya/MPxLocatorNode.h>
#include <maya/MFnDependencyNode.h>
#include <maya/MFnNumericAttribute.h>

class RootNode : public MPxLocatorNode
{
public:
	RootNode();
	virtual ~RootNode();

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);
	virtual void draw(M3dView&, const MDagPath&, M3dView::DisplayStyle, M3dView::DisplayStatus);

	static void* creator();
	static MStatus initialize();

	static MObject aOutValue;
	static MObject aFrameIn;
	static MObject aHeight;
	static MObject aWidth;
	static MObject aLength;

	static MTypeId id;
};

#endif