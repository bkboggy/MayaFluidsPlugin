#ifndef FLUID_LOCATOR_NODE_H
#define FLUID_LOCATOR_NODE_H

#include <maya/MFloatArray.h>
#include <maya/MStringArray.h>
#include <maya/MTypeId.h>
#include <maya/MStatus.h>
#include <maya/M3dView.h>
#include <maya/MGlobal.h>
#include <maya/MPxLocatorNode.h>
#include <maya/MFnDependencyNode.h>
#include <maya/MFnFloatArrayData.h>
#include <maya/MFnStringArrayData.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnTypedAttribute.h>
#include <maya/MFnUnitAttribute.h>
#include <maya/MSelectionList.h>
#include <maya/MString.h>
#include <maya/MArrayDataHandle.h>
#include <maya/MTime.h>
#include <math.h>
#include "utilities.h"

class FluidLocatorNode : public MPxLocatorNode
{
public:
	FluidLocatorNode();
	virtual ~FluidLocatorNode();

    virtual void postConstructor();
	virtual MStatus compute(const MPlug& plug, MDataBlock& data);
	virtual void draw(M3dView&, const MDagPath&, M3dView::DisplayStyle, M3dView::DisplayStatus);

	static void* creator(); 
	static MStatus initialize();

    static MTypeId id;

    static MObject aFluid;
	static MObject aTime;
    static MObject aShowVoxels;
    static MObject aVoxelAlpha;
    static MObject aVoxelCount;
	static MObject aHeight;
	static MObject aWidth;
	static MObject aLength;
    static MObject aDensity;
    static MObject aVelocityU;
    static MObject aVelocityV;
    static MObject aVelocityW;	

    // Temporary
    static MObject aRadius;
};

#endif