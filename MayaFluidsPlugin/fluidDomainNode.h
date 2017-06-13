#ifndef FLUID_DOMAIN_NODE_H
#define FLUID_DOMAIN_NODE_H

#include <maya/MFloatArray.h>
#include <maya/MFnFloatArrayData.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnTypedAttribute.h>
#include <maya/MFnUnitAttribute.h>
#include <maya/MPxNode.h>

// Defines fluid domain in terms of velocity and density fields.
class FluidDomainNode : public MPxNode
{
public:
    // Default constructor.
    FluidDomainNode();
    // Destructor.
    virtual ~FluidDomainNode();
    // Maya API node creator.
    static void* creator();

    // Initializes node attributes.
    static MStatus initialize();
    // Performs node computation.
    virtual MStatus compute(const MPlug& plug, MDataBlock& data);

    // Maya node ID.
    static MTypeId id;

    // Input attributes.
    static MObject aVoxelCountWidthIn;
    static MObject aVoxelCountHeightIn;
    static MObject aVoxelCountLengthIn;
    static MObject aShowVoxelsIn;
    static MObject aShowFluidIn;
    static MObject aMinParticleSizeIn;
    static MObject aVoxelAlphaIn;
    static MObject aTimestepIn;
    static MObject aDiffusionRateIn;
    static MObject aViscosityIn;
    static MObject aForceMultiplierIn;
    static MObject aSourceMultiplierIn;
    static MObject aDomainDensity;
    static MObject aDomainVelocityU;
    static MObject aDomainVelocityV;
    static MObject aDomainVelocityW;
    static MObject aDomainOriginXIn;
    static MObject aDomainOriginYIn;
    static MObject aDomainOriginZIn;
    static MObject aDomainWidthIn;
    static MObject aDomainHeightIn;
    static MObject aDomainLengthIn;
    static MObject aActiveSourceIn;
    static MObject aActiveSourceRateIn;
    static MObject aSourceDensityIn;
    static MObject aSourceOriginXIn;
    static MObject aSourceOriginYIn;
    static MObject aSourceOriginZIn;
    static MObject aSourceWidthIn;
    static MObject aSourceHeightIn;
    static MObject aSourceLengthIn;
    static MObject aSourceVelocityU;
    static MObject aSourceVelocityV;
    static MObject aSourceVelocityW;
    static MObject aMinTimeIn;
    static MObject aMaxTimeIn;
    static MObject aTimeScaleIn;

    // Output attributes.
    static MObject aVoxelCountWidthOut;
    static MObject aVoxelCountHeightOut;
    static MObject aVoxelCountLengthOut;
    static MObject aShowVoxelsOut;
    static MObject aShowFluidOut;
    static MObject aMinParticleSizeOut;
    static MObject aVoxelAlphaOut;
    static MObject aTimestepOut;
    static MObject aDiffusionRateOut;
    static MObject aViscosityOut;
    static MObject aForceMultiplierOut;
    static MObject aSourceMultiplierOut;
    static MObject aDensityOut;
    static MObject aVelocityUOut;
    static MObject aVelocityVOut;
    static MObject aVelocityWOut;
    static MObject aDomainOriginXOut;
    static MObject aDomainOriginYOut;
    static MObject aDomainOriginZOut;
    static MObject aDomainWidthOut;
    static MObject aDomainHeightOut;
    static MObject aDomainLengthOut;
    static MObject aActiveSourceOut;
    static MObject aActiveSourceRateOut;
    static MObject aSourceDensityOut;
    static MObject aSourceOriginXOut;
    static MObject aSourceOriginYOut;
    static MObject aSourceOriginZOut;
    static MObject aSourceWidthOut;
    static MObject aSourceHeightOut;
    static MObject aSourceLengthOut;
    static MObject aMinTimeOut;
    static MObject aMaxTimeOut;
    static MObject aTimeScaleOut;
};

#endif
