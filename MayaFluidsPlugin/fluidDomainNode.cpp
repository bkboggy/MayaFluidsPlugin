#include "fluidDomainNode.h"

// Maya node ID.
MTypeId FluidDomainNode::id(0x00000100);

// Input attributes.
MObject FluidDomainNode::aVoxelCountWidthIn;
MObject FluidDomainNode::aVoxelCountHeightIn;
MObject FluidDomainNode::aVoxelCountLengthIn;
MObject FluidDomainNode::aShowVoxelsIn;
MObject FluidDomainNode::aShowFluidIn;
MObject FluidDomainNode::aMinParticleSizeIn;
MObject FluidDomainNode::aMaxParticleSizeIn;
MObject FluidDomainNode::aVoxelAlphaIn;
MObject FluidDomainNode::aTimestepIn;
MObject FluidDomainNode::aDiffusionRateIn;
MObject FluidDomainNode::aViscosityIn;
MObject FluidDomainNode::aForceMultiplierIn;
MObject FluidDomainNode::aSourceMultiplierIn;
MObject FluidDomainNode::aDomainDensity;
MObject FluidDomainNode::aDomainVelocityU;
MObject FluidDomainNode::aDomainVelocityV;
MObject FluidDomainNode::aDomainVelocityW;
MObject FluidDomainNode::aDomainOriginXIn;
MObject FluidDomainNode::aDomainOriginYIn;
MObject FluidDomainNode::aDomainOriginZIn;
MObject FluidDomainNode::aDomainWidthIn;
MObject FluidDomainNode::aDomainHeightIn;
MObject FluidDomainNode::aDomainLengthIn;
MObject FluidDomainNode::aActiveSourceIn;
MObject FluidDomainNode::aActiveSourceRateIn;
MObject FluidDomainNode::aSourceDensityIn;
MObject FluidDomainNode::aSourceOriginXIn;
MObject FluidDomainNode::aSourceOriginYIn;
MObject FluidDomainNode::aSourceOriginZIn;
MObject FluidDomainNode::aSourceWidthIn;
MObject FluidDomainNode::aSourceHeightIn;
MObject FluidDomainNode::aSourceLengthIn;
MObject FluidDomainNode::aSourceVelocityU;
MObject FluidDomainNode::aSourceVelocityV;
MObject FluidDomainNode::aSourceVelocityW;
MObject FluidDomainNode::aMinTimeIn;
MObject FluidDomainNode::aMaxTimeIn;
MObject FluidDomainNode::aTimeScaleIn;

// Output attributes.
MObject FluidDomainNode::aVoxelCountWidthOut;
MObject FluidDomainNode::aVoxelCountHeightOut;
MObject FluidDomainNode::aVoxelCountLengthOut;
MObject FluidDomainNode::aShowVoxelsOut;
MObject FluidDomainNode::aShowFluidOut;
MObject FluidDomainNode::aMinParticleSizeOut;
MObject FluidDomainNode::aMaxParticleSizeOut;
MObject FluidDomainNode::aVoxelAlphaOut;
MObject FluidDomainNode::aTimestepOut;
MObject FluidDomainNode::aDiffusionRateOut;
MObject FluidDomainNode::aViscosityOut;
MObject FluidDomainNode::aForceMultiplierOut;
MObject FluidDomainNode::aSourceMultiplierOut;
MObject FluidDomainNode::aDensityOut;
MObject FluidDomainNode::aVelocityUOut;
MObject FluidDomainNode::aVelocityVOut;
MObject FluidDomainNode::aVelocityWOut;
MObject FluidDomainNode::aDomainOriginXOut;
MObject FluidDomainNode::aDomainOriginYOut;
MObject FluidDomainNode::aDomainOriginZOut;
MObject FluidDomainNode::aDomainWidthOut;
MObject FluidDomainNode::aDomainHeightOut;
MObject FluidDomainNode::aDomainLengthOut;
MObject FluidDomainNode::aActiveSourceOut;
MObject FluidDomainNode::aActiveSourceRateOut;
MObject FluidDomainNode::aSourceDensityOut;
MObject FluidDomainNode::aSourceOriginXOut;
MObject FluidDomainNode::aSourceOriginYOut;
MObject FluidDomainNode::aSourceOriginZOut;
MObject FluidDomainNode::aSourceWidthOut;
MObject FluidDomainNode::aSourceHeightOut;
MObject FluidDomainNode::aSourceLengthOut;
MObject FluidDomainNode::aMinTimeOut;
MObject FluidDomainNode::aMaxTimeOut;
MObject FluidDomainNode::aTimeScaleOut;

// Default constructor.
FluidDomainNode::FluidDomainNode() {}

// Destructor.
FluidDomainNode::~FluidDomainNode() {}

// Maya API node creator.
void* FluidDomainNode::creator()
{
    return new FluidDomainNode();
}

// Initialize node attributes.
MStatus FluidDomainNode::initialize()
{
    // Status to be returned.
    MStatus status;

    // Attribute functions.
    MFnNumericAttribute nAttr;
    MFnTypedAttribute tAttr;

    // Output attributes.
    aVoxelCountWidthOut = nAttr.create("voxelCountWidthOut", "voxelCountWidthOut", MFnNumericData::kInt);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aVoxelCountWidthOut);

    aVoxelCountHeightOut = nAttr.create("voxelCountHeightOut", "voxelCountHeightOut", MFnNumericData::kInt);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aVoxelCountHeightOut);

    aVoxelCountLengthOut = nAttr.create("voxelCountLengthOut", "voxelCountLengthOut", MFnNumericData::kInt);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aVoxelCountLengthOut);

    aShowVoxelsOut = nAttr.create("showVoxelsOut", "showVoxelsOut", MFnNumericData::kBoolean);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aShowVoxelsOut);

    aShowFluidOut = nAttr.create("showFluidOut", "showFluidOut", MFnNumericData::kBoolean);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aShowFluidOut);

    aMinParticleSizeOut = nAttr.create("minParticleSizeOut", "minParticleSizeOut", MFnNumericData::kFloat);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aMinParticleSizeOut);

	aMaxParticleSizeOut = nAttr.create("maxParticleSizeOut", "maxParticleSizeOut", MFnNumericData::kFloat);
	nAttr.setKeyable(false);
	nAttr.setWritable(false);
	addAttribute(aMaxParticleSizeOut);

    aVoxelAlphaOut = nAttr.create("voxelAlphaOut", "voxelAlphaOut", MFnNumericData::kFloat);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aVoxelAlphaOut);

    aTimestepOut = nAttr.create("timestepOut", "timestepOut", MFnNumericData::kFloat);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aTimestepOut);

    aDiffusionRateOut = nAttr.create("diffusionRateOut", "diffusionRateOut", MFnNumericData::kFloat);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aDiffusionRateOut);

    aViscosityOut = nAttr.create("viscosityOut", "viscosityOut", MFnNumericData::kFloat);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aViscosityOut);

    aForceMultiplierOut = nAttr.create("forceMultiplierOut", "forceMultiplierOut", MFnNumericData::kFloat);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aForceMultiplierOut);

    aSourceMultiplierOut = nAttr.create("sourceMultiplierOut", "sourceMultiplierOut", MFnNumericData::kFloat);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aSourceMultiplierOut);

    aDensityOut = tAttr.create("densityOut", "densityOut", MFnData::kFloatArray);
    tAttr.setKeyable(false);
    tAttr.setWritable(false);
    addAttribute(aDensityOut);

    aVelocityUOut = tAttr.create("velocityUOut", "velocityUOut", MFnData::kFloatArray);
    tAttr.setKeyable(false);
    tAttr.setWritable(false);
    addAttribute(aVelocityUOut);

    aVelocityVOut = tAttr.create("velocityVOut", "velocityVOut", MFnData::kFloatArray);
    tAttr.setKeyable(false);
    tAttr.setWritable(false);
    addAttribute(aVelocityVOut);

    aVelocityWOut = tAttr.create("velocityWOut", "velocityWOut", MFnData::kFloatArray);
    tAttr.setKeyable(false);
    tAttr.setWritable(false);
    addAttribute(aVelocityWOut);

    aDomainOriginXOut = nAttr.create("domainOriginXOut", "domainOriginXOut", MFnNumericData::kFloat);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aDomainOriginXOut);

    aDomainOriginYOut = nAttr.create("domainOriginYOut", "domainOriginYOut", MFnNumericData::kFloat);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aDomainOriginYOut);

    aDomainOriginZOut = nAttr.create("domainOriginZOut", "domainOriginZOut", MFnNumericData::kFloat);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aDomainOriginZOut);

    aDomainWidthOut = nAttr.create("domainWidthOut", "domainWidthOut", MFnNumericData::kFloat);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aDomainWidthOut);

    aDomainHeightOut = nAttr.create("domainHeightOut", "domainHeightOut", MFnNumericData::kFloat);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aDomainHeightOut);

    aDomainLengthOut = nAttr.create("domainLengthOut", "domainLengthOut", MFnNumericData::kFloat);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aDomainLengthOut);

    aActiveSourceOut = nAttr.create("activeSourceOut", "activeSourceOut", MFnNumericData::kBoolean);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aActiveSourceOut);

    aActiveSourceRateOut = nAttr.create("activeSourceRateOut", "activeSourceRateOut", MFnNumericData::kInt);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aActiveSourceRateOut);

    aSourceDensityOut = tAttr.create("sourceDensityOut", "sourceDensityOut", MFnData::kFloatArray);
    tAttr.setKeyable(false);
    tAttr.setWritable(false);
    addAttribute(aSourceDensityOut);

    aSourceOriginXOut = nAttr.create("sourceOriginXOut", "sourceOriginXOut", MFnNumericData::kFloat);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aSourceOriginXOut);

    aSourceOriginYOut = nAttr.create("sourceOriginYOut", "sourceOriginYOut", MFnNumericData::kFloat);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aSourceOriginYOut);

    aSourceOriginZOut = nAttr.create("sourceOriginZOut", "sourceOriginZOut", MFnNumericData::kFloat);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aSourceOriginZOut);

    aSourceWidthOut = nAttr.create("sourceWidthOut", "sourceWidthOut", MFnNumericData::kFloat);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aSourceWidthOut);

    aSourceHeightOut = nAttr.create("sourceHeightOut", "sourceHeightOut", MFnNumericData::kFloat);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aSourceHeightOut);

    aSourceLengthOut = nAttr.create("sourceLengthOut", "sourceLengthOut", MFnNumericData::kFloat);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aSourceLengthOut);
    
    aMinTimeOut = nAttr.create("minTimeOut", "minTimeOut", MFnNumericData::kDouble);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aMinTimeOut);

    aMaxTimeOut = nAttr.create("maxTimeOut", "maxTimeOut", MFnNumericData::kDouble);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aMaxTimeOut);

    aTimeScaleOut = nAttr.create("timeScaleOut", "timeScaleOut", MFnNumericData::kDouble);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aTimeScaleOut);

    // Input attributes.
    aVoxelCountWidthIn = nAttr.create("voxelCountWidthIn", "voxelCountWidthIn", MFnNumericData::kInt, 10);
    nAttr.setMin(1);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aVoxelCountWidthIn);
    attributeAffects(aVoxelCountWidthIn, aVoxelCountWidthOut);
    attributeAffects(aVoxelCountWidthIn, aDensityOut);
    attributeAffects(aVoxelCountWidthIn, aVelocityUOut);
    attributeAffects(aVoxelCountWidthIn, aVelocityVOut);
    attributeAffects(aVoxelCountWidthIn, aVelocityWOut);

    aVoxelCountHeightIn = nAttr.create("voxelCountHeightIn", "voxelCountHeightIn", MFnNumericData::kInt, 10);
    nAttr.setMin(1);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aVoxelCountHeightIn);
    attributeAffects(aVoxelCountHeightIn, aVoxelCountHeightOut);
    attributeAffects(aVoxelCountHeightIn, aDensityOut);
    attributeAffects(aVoxelCountHeightIn, aVelocityUOut);
    attributeAffects(aVoxelCountHeightIn, aVelocityVOut);
    attributeAffects(aVoxelCountHeightIn, aVelocityWOut);

    aVoxelCountLengthIn = nAttr.create("voxelCountLengthIn", "voxelCountLengthIn", MFnNumericData::kInt, 10);
    nAttr.setMin(1);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aVoxelCountLengthIn);
    attributeAffects(aVoxelCountLengthIn, aVoxelCountLengthOut);
    attributeAffects(aVoxelCountLengthIn, aDensityOut);
    attributeAffects(aVoxelCountLengthIn, aVelocityUOut);
    attributeAffects(aVoxelCountLengthIn, aVelocityVOut);
    attributeAffects(aVoxelCountLengthIn, aVelocityWOut);

    aShowVoxelsIn = nAttr.create("showVoxelsIn", "showVoxelsIn", MFnNumericData::kBoolean, false);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aShowVoxelsIn);
    attributeAffects(aShowVoxelsIn, aShowVoxelsOut);

    aShowFluidIn = nAttr.create("showFluidIn", "showFluidIn", MFnNumericData::kBoolean, false);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aShowFluidIn);
    attributeAffects(aShowFluidIn, aShowFluidOut);

    aMinParticleSizeIn = nAttr.create("minParticleSizeIn", "minParticleSizeIn", MFnNumericData::kFloat, 0.01f);
    nAttr.setMin(0.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aMinParticleSizeIn);
    attributeAffects(aMinParticleSizeIn, aMinParticleSizeOut);

	aMaxParticleSizeIn = nAttr.create("maxParticleSizeIn", "maxParticleSizeIn", MFnNumericData::kFloat, 1.0f);
	nAttr.setMin(0.0f);
	nAttr.setKeyable(true);
	nAttr.setWritable(true);
	addAttribute(aMaxParticleSizeIn);
	attributeAffects(aMaxParticleSizeIn, aMaxParticleSizeOut);

    aVoxelAlphaIn = nAttr.create("voxelAlphaIn", "voxelAlphaIn", MFnNumericData::kFloat, 0.3f);
    nAttr.setMin(0.0f);
    nAttr.setMax(1.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aVoxelAlphaIn);
    attributeAffects(aVoxelAlphaIn, aVoxelAlphaOut);

    aTimestepIn = nAttr.create("timestepIn", "timestepIn", MFnNumericData::kFloat, 1.0f);
    nAttr.setMin(0.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aTimestepIn);
    attributeAffects(aTimestepIn, aTimestepOut);
    attributeAffects(aTimestepIn, aDomainDensity);
    attributeAffects(aTimestepIn, aVelocityUOut);
    attributeAffects(aTimestepIn, aVelocityVOut);
    attributeAffects(aTimestepIn, aVelocityWOut);

    aDiffusionRateIn = nAttr.create("diffusionRateIn", "diffusionRateIn", MFnNumericData::kFloat, 0.0f);
    nAttr.setMin(0.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDiffusionRateIn);
    attributeAffects(aDiffusionRateIn, aDiffusionRateOut);
    attributeAffects(aDiffusionRateIn, aDomainDensity);
    attributeAffects(aDiffusionRateIn, aVelocityUOut);
    attributeAffects(aDiffusionRateIn, aVelocityVOut);
    attributeAffects(aDiffusionRateIn, aVelocityWOut);

    aViscosityIn = nAttr.create("viscosityIn", "viscosityIn", MFnNumericData::kFloat, 0.0f);
    nAttr.setMin(0.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aViscosityIn);
    attributeAffects(aViscosityIn, aViscosityOut);
    attributeAffects(aViscosityIn, aDomainDensity);
    attributeAffects(aViscosityIn, aVelocityUOut);
    attributeAffects(aViscosityIn, aVelocityVOut);
    attributeAffects(aViscosityIn, aVelocityWOut);

    aForceMultiplierIn = nAttr.create("forceMultiplierIn", "forceMultiplierIn", MFnNumericData::kFloat, 10.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aForceMultiplierIn);
    attributeAffects(aForceMultiplierIn, aForceMultiplierOut);
    attributeAffects(aForceMultiplierIn, aDomainDensity);
    attributeAffects(aForceMultiplierIn, aVelocityUOut);
    attributeAffects(aForceMultiplierIn, aVelocityVOut);
    attributeAffects(aForceMultiplierIn, aVelocityWOut);

    aSourceMultiplierIn = nAttr.create("sourceMultiplierIn", "sourceMultiplierIn", MFnNumericData::kFloat, 200.0f);
    nAttr.setMin(0.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceMultiplierIn);
    attributeAffects(aSourceMultiplierIn, aSourceMultiplierOut);
    attributeAffects(aSourceMultiplierIn, aDomainDensity);
    attributeAffects(aSourceMultiplierIn, aVelocityUOut);
    attributeAffects(aSourceMultiplierIn, aVelocityVOut);
    attributeAffects(aSourceMultiplierIn, aVelocityWOut);

    aDomainDensity = nAttr.create("domainDensity", "domainDensity", MFnNumericData::kFloat, 0.0f);
    nAttr.setMin(0.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainDensity);
    attributeAffects(aDomainDensity, aDensityOut);

    aDomainVelocityU = nAttr.create("domainVelocityU", "domainVelocityU", MFnNumericData::kFloat);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainVelocityU);
    attributeAffects(aDomainVelocityU, aVelocityUOut);

    aDomainVelocityV = nAttr.create("domainVelocityV", "domainVelocityV", MFnNumericData::kFloat);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainVelocityV);
    attributeAffects(aDomainVelocityV, aVelocityVOut);

    aDomainVelocityW = nAttr.create("domainVelocityW", "domainVelocityW", MFnNumericData::kFloat);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainVelocityW);
    attributeAffects(aDomainVelocityW, aVelocityWOut);

    aDomainOriginXIn = nAttr.create("domainOriginXIn", "domainOriginXIn", MFnNumericData::kFloat);
    nAttr.setMin(0.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainOriginXIn);
    attributeAffects(aDomainOriginXIn, aDomainOriginXOut);
    attributeAffects(aDomainOriginXIn, aSourceOriginXOut);
    attributeAffects(aDomainOriginXIn, aDomainDensity);
    attributeAffects(aDomainOriginXIn, aVelocityUOut);
    attributeAffects(aDomainOriginXIn, aVelocityVOut);
    attributeAffects(aDomainOriginXIn, aVelocityWOut);

    aDomainOriginYIn = nAttr.create("domainOriginYIn", "domainOriginYIn", MFnNumericData::kFloat);
    nAttr.setMin(0.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainOriginYIn);
    attributeAffects(aDomainOriginYIn, aDomainOriginYOut);
    attributeAffects(aDomainOriginYIn, aSourceOriginYOut);
    attributeAffects(aDomainOriginYIn, aDomainDensity);
    attributeAffects(aDomainOriginYIn, aVelocityUOut);
    attributeAffects(aDomainOriginYIn, aVelocityVOut);
    attributeAffects(aDomainOriginYIn, aVelocityWOut);

    aDomainOriginZIn = nAttr.create("domainOriginZIn", "domainOriginZIn", MFnNumericData::kFloat);
    nAttr.setMin(0.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainOriginZIn);
    attributeAffects(aDomainOriginZIn, aDomainOriginZOut);
    attributeAffects(aDomainOriginZIn, aSourceOriginZOut);
    attributeAffects(aDomainOriginZIn, aDomainDensity);
    attributeAffects(aDomainOriginZIn, aVelocityUOut);
    attributeAffects(aDomainOriginZIn, aVelocityVOut);
    attributeAffects(aDomainOriginZIn, aVelocityWOut);

    aDomainWidthIn = nAttr.create("domainWidthIn", "domainWidthIn", MFnNumericData::kFloat, 10.0f);
    nAttr.setMin(0.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainWidthIn);
    attributeAffects(aDomainWidthIn, aDomainWidthOut);
    attributeAffects(aDomainWidthIn, aSourceWidthOut);
    attributeAffects(aDomainWidthIn, aSourceOriginXOut);
    attributeAffects(aDomainWidthIn, aSourceOriginYOut);
    attributeAffects(aDomainWidthIn, aSourceOriginZOut);
    attributeAffects(aDomainWidthIn, aDomainDensity);
    attributeAffects(aDomainWidthIn, aVelocityUOut);
    attributeAffects(aDomainWidthIn, aVelocityVOut);
    attributeAffects(aDomainWidthIn, aVelocityWOut);

    aDomainHeightIn = nAttr.create("domainHeightIn", "domainHeightIn", MFnNumericData::kFloat, 10.0f);
    nAttr.setMin(0.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainHeightIn);
    attributeAffects(aDomainHeightIn, aDomainHeightOut);
    attributeAffects(aDomainHeightIn, aSourceHeightOut);
    attributeAffects(aDomainHeightIn, aSourceOriginXOut);
    attributeAffects(aDomainHeightIn, aSourceOriginYOut);
    attributeAffects(aDomainHeightIn, aSourceOriginZOut);
    attributeAffects(aDomainHeightIn, aDomainDensity);
    attributeAffects(aDomainHeightIn, aVelocityUOut);
    attributeAffects(aDomainHeightIn, aVelocityVOut);
    attributeAffects(aDomainHeightIn, aVelocityWOut);

    aDomainLengthIn = nAttr.create("domainLengthIn", "domainLengthIn", MFnNumericData::kFloat, 10.0f);
    nAttr.setMin(0.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainLengthIn);
    attributeAffects(aDomainLengthIn, aDomainLengthOut);
    attributeAffects(aDomainLengthIn, aSourceLengthOut);
    attributeAffects(aDomainLengthIn, aSourceOriginXOut);
    attributeAffects(aDomainLengthIn, aSourceOriginYOut);
    attributeAffects(aDomainLengthIn, aSourceOriginZOut);
    attributeAffects(aDomainLengthIn, aDomainDensity);
    attributeAffects(aDomainLengthIn, aVelocityUOut);
    attributeAffects(aDomainLengthIn, aVelocityVOut);
    attributeAffects(aDomainLengthIn, aVelocityWOut);

    aActiveSourceIn = nAttr.create("activeSourceIn", "activeSourceIn", MFnNumericData::kBoolean, false);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aActiveSourceIn);
    attributeAffects(aActiveSourceIn, aActiveSourceOut);

    aActiveSourceRateIn = nAttr.create("activeSourceRateIn", "activeSourceRateIn", MFnNumericData::kInt, 1);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aActiveSourceRateIn);
    attributeAffects(aActiveSourceIn, aActiveSourceOut);

    aSourceDensityIn = nAttr.create("sourceDensityIn", "sourceDensityIn", MFnNumericData::kFloat, 1.0f);
    nAttr.setMin(0.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceDensityIn);
    attributeAffects(aSourceDensityIn, aDensityOut);
    attributeAffects(aSourceDensityIn, aSourceDensityOut);

    aSourceOriginXIn = nAttr.create("sourceOriginXIn", "sourceOriginXIn", MFnNumericData::kFloat);
    nAttr.setMin(0.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceOriginXIn);
    attributeAffects(aSourceOriginXIn, aSourceOriginXOut);
    attributeAffects(aSourceOriginXIn, aSourceHeightOut);
    attributeAffects(aSourceOriginXIn, aSourceWidthOut);
    attributeAffects(aSourceOriginXIn, aSourceLengthOut);
    attributeAffects(aSourceOriginXIn, aDomainDensity);
    attributeAffects(aSourceOriginXIn, aVelocityUOut);
    attributeAffects(aSourceOriginXIn, aVelocityVOut);
    attributeAffects(aSourceOriginXIn, aVelocityWOut);

    aSourceOriginYIn = nAttr.create("sourceOriginYIn", "sourceOriginYIn", MFnNumericData::kFloat);
    nAttr.setMin(0.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceOriginYIn);
    attributeAffects(aSourceOriginYIn, aSourceOriginYOut);
    attributeAffects(aSourceOriginYIn, aSourceHeightOut);
    attributeAffects(aSourceOriginYIn, aSourceWidthOut);
    attributeAffects(aSourceOriginYIn, aSourceLengthOut);
    attributeAffects(aSourceOriginYIn, aDomainDensity);
    attributeAffects(aSourceOriginYIn, aVelocityUOut);
    attributeAffects(aSourceOriginYIn, aVelocityVOut);
    attributeAffects(aSourceOriginYIn, aVelocityWOut);

    aSourceOriginZIn = nAttr.create("sourceOriginZIn", "sourceOriginZIn", MFnNumericData::kFloat);
    nAttr.setMin(0.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceOriginZIn);
    attributeAffects(aSourceOriginZIn, aSourceOriginZOut);
    attributeAffects(aSourceOriginZIn, aSourceHeightOut);
    attributeAffects(aSourceOriginZIn, aSourceWidthOut);
    attributeAffects(aSourceOriginZIn, aSourceLengthOut);
    attributeAffects(aSourceOriginZIn, aDomainDensity);
    attributeAffects(aSourceOriginZIn, aVelocityUOut);
    attributeAffects(aSourceOriginZIn, aVelocityVOut);
    attributeAffects(aSourceOriginZIn, aVelocityWOut);

    aSourceWidthIn = nAttr.create("sourceWidthIn", "sourceWidthIn", MFnNumericData::kFloat, 1.0f);
    nAttr.setMin(0.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceWidthIn);
    attributeAffects(aSourceWidthIn, aSourceWidthOut);
    attributeAffects(aSourceWidthIn, aSourceOriginXOut);
    attributeAffects(aSourceWidthIn, aDomainDensity);
    attributeAffects(aSourceWidthIn, aVelocityUOut);
    attributeAffects(aSourceWidthIn, aVelocityVOut);
    attributeAffects(aSourceWidthIn, aVelocityWOut);

    aSourceHeightIn = nAttr.create("sourceHeightIn", "sourceHeightIn", MFnNumericData::kFloat, 1.0f);
    nAttr.setMin(0.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceHeightIn);
    attributeAffects(aSourceHeightIn, aSourceHeightOut);
    attributeAffects(aSourceHeightIn, aSourceOriginYOut);
    attributeAffects(aSourceHeightIn, aDomainDensity);
    attributeAffects(aSourceHeightIn, aVelocityUOut);
    attributeAffects(aSourceHeightIn, aVelocityVOut);
    attributeAffects(aSourceHeightIn, aVelocityWOut);

    aSourceLengthIn = nAttr.create("sourceLengthIn", "sourceLengthIn", MFnNumericData::kFloat, 1.0f);
    nAttr.setMin(0.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceLengthIn);
    attributeAffects(aSourceLengthIn, aSourceLengthOut);
    attributeAffects(aSourceLengthIn, aSourceOriginZOut);
    attributeAffects(aSourceLengthIn, aDomainDensity);
    attributeAffects(aSourceLengthIn, aVelocityUOut);
    attributeAffects(aSourceLengthIn, aVelocityVOut);
    attributeAffects(aSourceLengthIn, aVelocityWOut);

    aSourceVelocityU = nAttr.create("sourceVelocityU", "sourceVelocityU", MFnNumericData::kFloat, 1.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceVelocityU);
    attributeAffects(aSourceVelocityU, aVelocityUOut);

    aSourceVelocityV = nAttr.create("sourceVelocityV", "sourceVelocityV", MFnNumericData::kFloat, 1.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceVelocityV);
    attributeAffects(aSourceVelocityV, aVelocityVOut);

    aSourceVelocityW = nAttr.create("sourceVelocityW", "sourceVelocityW", MFnNumericData::kFloat, 1.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceVelocityW);
    attributeAffects(aSourceVelocityW, aVelocityWOut);

    aMinTimeIn = nAttr.create("minTimeIn", "minTimeIn", MFnNumericData::kDouble, 1.0);
    nAttr.setMin(1.0);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aMinTimeIn);
    attributeAffects(aMinTimeIn, aMinTimeOut);

    aMaxTimeIn = nAttr.create("maxTimeIn", "maxTimeIn", MFnNumericData::kDouble, 200.0);
    nAttr.setMin(1.0);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aMaxTimeIn);
    attributeAffects(aMaxTimeIn, aMaxTimeOut);

    aTimeScaleIn = nAttr.create("timeScaleIn", "timeScaleIn", MFnNumericData::kDouble, 1.0);
    nAttr.setMin(0.0);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aTimeScaleIn);
    attributeAffects(aTimeScaleIn, aTimeScaleOut);

    return MS::kSuccess;
}

// Perform node computations.
MStatus FluidDomainNode::compute(const MPlug& plug, MDataBlock& data)
{
    // Status to be returned.
    MStatus status;

    // Check if node is working on an appropriate plug.
    if (plug != aVoxelCountWidthOut &&
        plug != aVoxelCountHeightOut &&
        plug != aVoxelCountLengthOut &&
        plug != aShowVoxelsOut &&
        plug != aShowFluidOut &&
        plug != aMinParticleSizeOut &&
        plug != aMaxParticleSizeOut &&
        plug != aVoxelAlphaOut &&
        plug != aTimestepOut &&
        plug != aDiffusionRateOut &&
        plug != aViscosityOut &&
        plug != aForceMultiplierOut &&
        plug != aSourceMultiplierOut &&
        plug != aDensityOut &&
        plug != aVelocityUOut &&
        plug != aVelocityVOut &&
        plug != aVelocityWOut &&
        plug != aDomainOriginXOut &&
        plug != aDomainOriginYOut &&
        plug != aDomainOriginZOut &&
        plug != aDomainWidthOut &&
        plug != aDomainHeightOut &&
        plug != aDomainLengthOut &&
        plug != aActiveSourceOut &&
        plug != aActiveSourceRateOut &&
        plug != aSourceOriginXOut &&
        plug != aSourceOriginYOut &&
        plug != aSourceOriginZOut &&
        plug != aSourceWidthOut &&
        plug != aSourceHeightOut &&
        plug != aSourceLengthOut &&
        plug != aMinTimeOut &&
        plug != aMaxTimeOut &&
        plug != aTimeScaleOut)
    {
        return MS::kUnknownParameter;
    }

    int voxelCountWidth = data.inputValue(aVoxelCountWidthIn, &status).asInt();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    int voxelCountHeight = data.inputValue(aVoxelCountHeightIn, &status).asInt();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    int voxelCountLength = data.inputValue(aVoxelCountLengthIn, &status).asInt();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    bool showVoxels = data.inputValue(aShowVoxelsIn, &status).asBool();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    bool showFluid = data.inputValue(aShowFluidIn, &status).asBool();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float minParticleSize = data.inputValue(aMinParticleSizeIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

	float maxParticleSize = data.inputValue(aMaxParticleSizeIn, &status).asFloat();
	CHECK_MSTATUS_AND_RETURN_IT(status);

    float voxelAlpha = data.inputValue(aVoxelAlphaIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float timestep = data.inputValue(aTimestepIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float diffusionRate = data.inputValue(aDiffusionRateIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float viscosity = data.inputValue(aViscosityIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float forceMultiplier = data.inputValue(aForceMultiplierIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float sourceMultiplier = data.inputValue(aSourceMultiplierIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float domainDensity = data.inputValue(aDomainDensity, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float domainVelocityU = data.inputValue(aDomainVelocityU, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float domainVelocityV = data.inputValue(aDomainVelocityV, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float domainVelocityW = data.inputValue(aDomainVelocityW, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float domainOriginX = data.inputValue(aDomainOriginXIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float domainOriginY = data.inputValue(aDomainOriginYIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float domainOriginZ = data.inputValue(aDomainOriginZIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float domainWidth = data.inputValue(aDomainWidthIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float domainHeight = data.inputValue(aDomainHeightIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float domainLength = data.inputValue(aDomainLengthIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    bool activeSource = data.inputValue(aActiveSourceIn, &status).asBool();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    int activeSourceRate = data.inputValue(aActiveSourceRateIn, &status).asInt();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float sourceDensity = data.inputValue(aSourceDensityIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float sourceOriginX = data.inputValue(aSourceOriginXIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float sourceOriginY = data.inputValue(aSourceOriginYIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float sourceOriginZ = data.inputValue(aSourceOriginZIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float sourceWidth = data.inputValue(aSourceWidthIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float sourceHeight = data.inputValue(aSourceHeightIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float sourceLength = data.inputValue(aSourceLengthIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float sourceVelocityU = data.inputValue(aSourceVelocityU, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float sourceVelocityV = data.inputValue(aSourceVelocityV, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float sourceVelocityW = data.inputValue(aSourceVelocityW, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    double minTime = data.inputValue(aMinTimeIn, &status).asDouble();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    double maxTime = data.inputValue(aMaxTimeIn, &status).asDouble();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    double timeScale = data.inputValue(aTimeScaleIn, &status).asDouble();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    // Make sure that the source is constrained within the domain. Adjust values accordingly.
    if (sourceOriginX > domainWidth)
    {
        sourceOriginX = domainWidth;
    }
    if (sourceOriginY > domainHeight)
    {
        sourceOriginY = domainHeight;
    }
    if (sourceOriginZ > domainLength)
    {
        sourceOriginZ = domainHeight;
    }

    if (sourceOriginX + sourceWidth > domainWidth)
    {
        sourceWidth -= (sourceOriginX + sourceWidth - domainWidth);
    }
    if (sourceOriginY + sourceHeight > domainHeight)
    {
        sourceHeight -= (sourceOriginY + sourceHeight - domainHeight);
    }
    if (sourceOriginZ + sourceLength > domainLength)
    {
        sourceLength -= (sourceOriginZ + sourceLength - domainLength);
    }

    // Calculate number of voxels in each dimension for the source.
    int sourceVoxelsWidth = (sourceWidth / domainWidth) * voxelCountWidth;
    int sourceVoxelsHeight = (sourceHeight / domainHeight) * voxelCountHeight;
    int sourceVoxelsLength = (sourceLength / domainLength) * voxelCountLength;

    // Flattened 3D array size with +2 padding in each dimension to account for boundary
    // used by the solver.
    int size = (voxelCountWidth + 2) * (voxelCountHeight + 2) * (voxelCountLength + 2);

    // Create output velocity fields. Set default velocity for each vector to the specified domain
    // velocity value (default is 0.0f).
    MFloatArray velocityUOut(size, domainVelocityU);
    MFloatArray velocityVOut(size, domainVelocityV);
    MFloatArray velocityWOut(size, domainVelocityW);

    // Create an output density array. Set default density at each coordinate to the
    // specified domain density (default is 0.0f).
    MFloatArray density(size, domainDensity);

    // Source array to be used in an active source scenario. Optimize out in the future
    // by extracing the combining operation below into a utility function so that both solver
    // and domain nodes may add source without having to store 3D arrays.
    MFloatArray source(size, 0.0f);

    // TODO: ADD PROPER STARTING X Y Z BASED ON SOURCE ORIGIN.
    //
    // Add source density to domain density, without exceeding 1.0 limit. In addition,
    // add source velocity to domain velocity, without exceeding 1.0 limit.
    for (int x = 0; x < sourceVoxelsWidth && x < voxelCountWidth; x++)
    {
        for (int y = 0; y < sourceVoxelsHeight && y < voxelCountHeight; y++)
        {
            for (int z = 0; z < sourceVoxelsLength && z < voxelCountLength; z++)
            {
                int i = (x + 1) + ((y + 1) * (voxelCountWidth + 2)) + ((z + 1) * (voxelCountWidth + 2) * (voxelCountHeight + 2));

                float dValue = domainDensity + sourceDensity * sourceMultiplier;
                density.set(dValue, i);
                //source.set(dValue, i);

                float vUValue = domainVelocityU + sourceVelocityU * forceMultiplier;
                velocityUOut.set(vUValue, i);

                float vVValue = domainVelocityV + sourceVelocityV * forceMultiplier;
                velocityVOut.set(vVValue, i);

                float vWValue = domainVelocityW + sourceVelocityW * forceMultiplier;
                velocityWOut.set(vWValue, i);
            }
        }
    }
    
    MDataHandle hOutput = data.outputValue(aVoxelCountWidthOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(voxelCountWidth);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aVoxelCountHeightOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(voxelCountHeight);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aVoxelCountLengthOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(voxelCountLength);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aShowVoxelsOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(showVoxels);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aShowFluidOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(showFluid);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aMinParticleSizeOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(minParticleSize);
    hOutput.setClean();
    data.setClean(plug);

	hOutput = data.outputValue(aMaxParticleSizeOut, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);
	hOutput.set(maxParticleSize);
	hOutput.setClean();
	data.setClean(plug);

    hOutput = data.outputValue(aVoxelAlphaOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(voxelAlpha);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aTimestepOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(timestep);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aDiffusionRateOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(diffusionRate);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aViscosityOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(viscosity);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aForceMultiplierOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(forceMultiplier);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aSourceMultiplierOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(sourceMultiplier);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aDensityOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData densityFnDataOut;
    MObject dataOut = densityFnDataOut.create(density, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(dataOut);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aVelocityUOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData vUFnDataOut;
    dataOut = vUFnDataOut.create(velocityUOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(dataOut);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aVelocityVOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData vVFnDataOut;
    dataOut = vVFnDataOut.create(velocityVOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(dataOut);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aVelocityWOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData vWFnDataOut;
    dataOut = vWFnDataOut.create(velocityWOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(dataOut);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aDomainOriginXOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(domainOriginX);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aDomainOriginYOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(domainOriginY);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aDomainOriginZOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(domainOriginZ);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aDomainWidthOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(domainWidth);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aDomainHeightOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(domainHeight);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aDomainLengthOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(domainLength);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aActiveSourceOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(activeSource);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aActiveSourceRateOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(activeSourceRate);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aSourceDensityOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData sourceDensityFnDataOut;
    dataOut = sourceDensityFnDataOut.create(source, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(dataOut);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aSourceOriginXOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(sourceOriginX);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aSourceOriginYOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(sourceOriginY);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aSourceOriginZOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(sourceOriginZ);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aSourceWidthOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(sourceWidth);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aSourceHeightOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(sourceHeight);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aSourceLengthOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(sourceLength);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aMinTimeOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(minTime);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aMaxTimeOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(maxTime);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aTimeScaleOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(timeScale);
    hOutput.setClean();
    data.setClean(plug);

    return MS::kSuccess;
}
