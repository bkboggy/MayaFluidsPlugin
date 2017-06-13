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

    // Simulated fluid by drawing spheres in the Maya viewport.
    static void simulateFluid(MString locatorName, MStringArray &fluid, int minParticleSize, MFloatArray &density,
        float domainWidth, float domainHeight, float domainLength, int voxelCountWidth, int voxelCountHeight, int voxelCountLength);

    // Clears fluid by deleting spheres and setting the desired size.
    static void resetFluid(MStringArray &fluid, int size);

    static MTypeId id;

    // Output attributes.
    static MObject aFluid;
    static MObject aDensityOut;
    static MObject aVelocityUOut;
    static MObject aVelocityVOut;
    static MObject aVelocityWOut;
    static MObject aShowFluidOut;
    static MObject aMinParticleSizeOut;
    static MObject aShowVoxelsOut;
    static MObject aVoxelAlphaOut;
    static MObject aVoxelCountWidthOut;
    static MObject aVoxelCountHeightOut;
    static MObject aVoxelCountLengthOut;
    static MObject aDomainOriginXOut;
    static MObject aDomainOriginYOut;
    static MObject aDomainOriginZOut;
    static MObject aDomainHeightOut;
    static MObject aDomainWidthOut;
    static MObject aDomainLengthOut;
    static MObject aSourceOriginXOut;
    static MObject aSourceOriginYOut;
    static MObject aSourceOriginZOut;
    static MObject aSourceWidthOut;
    static MObject aSourceHeightOut;
    static MObject aSourceLengthOut;

    // Input attributes.
    static MObject aDensityIn;
    static MObject aVelocityUIn;
    static MObject aVelocityVIn;
    static MObject aVelocityWIn;
    static MObject aShowFluidIn;
    static MObject aMinParticleSizeIn;
    static MObject aShowVoxelsIn;   
    static MObject aVoxelAlphaIn;
    static MObject aVoxelCountWidthIn;
    static MObject aVoxelCountHeightIn;
    static MObject aVoxelCountLengthIn;
    static MObject aDomainOriginXIn;
    static MObject aDomainOriginYIn;
    static MObject aDomainOriginZIn;
	static MObject aDomainHeightIn;
	static MObject aDomainWidthIn;
	static MObject aDomainLengthIn;
    static MObject aSourceOriginXIn;
    static MObject aSourceOriginYIn;
    static MObject aSourceOriginZIn;
    static MObject aSourceWidthIn;
    static MObject aSourceHeightIn;
    static MObject aSourceLengthIn;
};

#endif
