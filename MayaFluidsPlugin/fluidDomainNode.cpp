#include "fluidDomainNode.h"

// Maya node ID.
MTypeId FluidDomainNode::id(0x00000100);

// Attributes.
MObject FluidDomainNode::aVoxelCountWidthIn;
MObject FluidDomainNode::aVoxelCountHeightIn;
MObject FluidDomainNode::aVoxelCountLengthIn;
MObject FluidDomainNode::aShowVoxelsIn;
MObject FluidDomainNode::aShowFluidIn;
MObject FluidDomainNode::aVoxelAlphaIn;
MObject FluidDomainNode::aTimestepIn;
MObject FluidDomainNode::aDiffusionRateIn;
MObject FluidDomainNode::aViscosityIn;
MObject FluidDomainNode::aForceMultiplierIn;
MObject FluidDomainNode::aSourceMultiplierIn;
MObject FluidDomainNode::aDomainDensity;
MObject FluidDomainNode::aSourceDensity;
MObject FluidDomainNode::aDomainVelocity;
MObject FluidDomainNode::aDomainOriginIn;
MObject FluidDomainNode::aDomainWidthIn;
MObject FluidDomainNode::aDomainHeightIn;
MObject FluidDomainNode::aDomainLengthIn;
MObject FluidDomainNode::aSourceOriginIn;
MObject FluidDomainNode::aSourceWidthIn;
MObject FluidDomainNode::aSourceHeightIn;
MObject FluidDomainNode::aSourceLengthIn;
MObject FluidDomainNode::aSourceVelocity;
MObject FluidDomainNode::aMinTimeIn;
MObject FluidDomainNode::aMaxTimeIn;
MObject FluidDomainNode::aTimeScaleIn;

MObject FluidDomainNode::aVoxelCountWidthOut;
MObject FluidDomainNode::aVoxelCountHeightOut;
MObject FluidDomainNode::aVoxelCountLengthOut;
MObject FluidDomainNode::aShowVoxelsOut;
MObject FluidDomainNode::aShowFluidOut;
MObject FluidDomainNode::aVoxelAlphaOut;
MObject FluidDomainNode::aTimestepOut;
MObject FluidDomainNode::aDiffusionRateOut;
MObject FluidDomainNode::aViscosityOut;
MObject FluidDomainNode::aForceMultiplierOut;
MObject FluidDomainNode::aSourceMultiplierOut;
MObject FluidDomainNode::aDensityOut;
MObject FluidDomainNode::aVelocityU;
MObject FluidDomainNode::aVelocityV;
MObject FluidDomainNode::aVelocityW;
MObject FluidDomainNode::aDomainOriginOut;
MObject FluidDomainNode::aDomainWidthOut;
MObject FluidDomainNode::aDomainHeightOut;
MObject FluidDomainNode::aDomainLengthOut;
MObject FluidDomainNode::aSourceOriginOut;
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

    aVelocityU = tAttr.create("velocityU", "velocityU", MFnData::kFloatArray);
    tAttr.setKeyable(false);
    tAttr.setWritable(false);
    addAttribute(aVelocityU);

    aVelocityV = tAttr.create("velocityV", "velocityV", MFnData::kFloatArray);
    tAttr.setKeyable(false);
    tAttr.setWritable(false);
    addAttribute(aVelocityV);

    aVelocityW = tAttr.create("velocityW", "velocityW", MFnData::kFloatArray);
    tAttr.setKeyable(false);
    tAttr.setWritable(false);
    addAttribute(aVelocityW);

    aDomainOriginOut = nAttr.create("domainOriginOut", "domainOriginOut", MFnNumericData::k3Float);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aDomainOriginOut);

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

    aSourceOriginOut = nAttr.create("sourceOriginOut", "sourceOriginOut", MFnNumericData::k3Float);
    nAttr.setKeyable(false);
    nAttr.setWritable(false);
    addAttribute(aSourceOriginOut);

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
    aVoxelCountWidthIn = nAttr.create("voxelCountWidthIn", "voxelCountWidthIn", MFnNumericData::kInt);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aVoxelCountWidthIn);
    attributeAffects(aVoxelCountWidthIn, aVoxelCountWidthOut);
    attributeAffects(aVoxelCountWidthIn, aDensityOut);
    attributeAffects(aVoxelCountWidthIn, aVelocityU);
    attributeAffects(aVoxelCountWidthIn, aVelocityV);
    attributeAffects(aVoxelCountWidthIn, aVelocityW);

    aVoxelCountHeightIn = nAttr.create("voxelCountHeightIn", "voxelCountHeightIn", MFnNumericData::kInt);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aVoxelCountHeightIn);
    attributeAffects(aVoxelCountHeightIn, aVoxelCountHeightOut);
    attributeAffects(aVoxelCountHeightIn, aDensityOut);
    attributeAffects(aVoxelCountHeightIn, aVelocityU);
    attributeAffects(aVoxelCountHeightIn, aVelocityV);
    attributeAffects(aVoxelCountHeightIn, aVelocityW);

    aVoxelCountLengthIn = nAttr.create("voxelCountLengthIn", "voxelCountLengthIn", MFnNumericData::kInt);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aVoxelCountLengthIn);
    attributeAffects(aVoxelCountLengthIn, aVoxelCountLengthOut);
    attributeAffects(aVoxelCountLengthIn, aDensityOut);
    attributeAffects(aVoxelCountLengthIn, aVelocityU);
    attributeAffects(aVoxelCountLengthIn, aVelocityV);
    attributeAffects(aVoxelCountLengthIn, aVelocityW);

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

    aVoxelAlphaIn = nAttr.create("voxelAlphaIn", "voxelAlphaIn", MFnNumericData::kFloat, 0.3f);
    nAttr.setMin(0.0f);
    nAttr.setMax(1.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aVoxelAlphaIn);
    attributeAffects(aVoxelAlphaIn, aVoxelAlphaOut);

    aTimestepIn = nAttr.create("timestepIn", "timestepIn", MFnNumericData::kFloat, 0.001f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aTimestepIn);
    attributeAffects(aTimestepIn, aTimestepOut);

    aDiffusionRateIn = nAttr.create("diffusionRateIn", "diffusionRateIn", MFnNumericData::kFloat, 0.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDiffusionRateIn);
    attributeAffects(aDiffusionRateIn, aDiffusionRateOut);

    aViscosityIn = nAttr.create("viscosityIn", "viscosityIn", MFnNumericData::kFloat, 0.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aViscosityIn);
    attributeAffects(aViscosityIn, aViscosityOut);

    aForceMultiplierIn = nAttr.create("forceMultiplierIn", "forceMultiplierIn", MFnNumericData::kFloat, 5.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aForceMultiplierIn);
    attributeAffects(aForceMultiplierIn, aForceMultiplierOut);

    aSourceMultiplierIn = nAttr.create("sourceMultiplierIn", "sourceMultiplierIn", MFnNumericData::kFloat, 200.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceMultiplierIn);
    attributeAffects(aSourceMultiplierIn, aSourceMultiplierOut);

    aDomainDensity = nAttr.create("domainDensity", "domainDensity", MFnNumericData::kFloat, 0.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainDensity);
    attributeAffects(aDomainDensity, aDensityOut);

    aSourceDensity = nAttr.create("sourceDensity", "sourceDensity", MFnNumericData::kFloat, 0.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceDensity);
    attributeAffects(aSourceDensity, aDensityOut);

    aDomainVelocity = nAttr.create("domainVelocity", "domainVelocity", MFnNumericData::k3Float);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainVelocity);
    attributeAffects(aDomainVelocity, aVelocityU);
    attributeAffects(aDomainVelocity, aVelocityV);
    attributeAffects(aDomainVelocity, aVelocityW);

    aDomainOriginIn = nAttr.create("domainOriginIn", "domainOriginIn", MFnNumericData::k3Float);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainOriginIn);
    attributeAffects(aDomainOriginIn, aDomainOriginOut);
    attributeAffects(aDomainOriginIn, aSourceOriginOut);

    aDomainWidthIn = nAttr.create("domainWidthIn", "domainWidthIn", MFnNumericData::kFloat, 5.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainWidthIn);
    attributeAffects(aDomainWidthIn, aDomainWidthOut);
    attributeAffects(aDomainWidthIn, aSourceWidthOut);
    attributeAffects(aDomainWidthIn, aSourceOriginOut);

    aDomainHeightIn = nAttr.create("domainHeightIn", "domainHeightIn", MFnNumericData::kFloat, 5.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainHeightIn);
    attributeAffects(aDomainHeightIn, aDomainHeightOut);
    attributeAffects(aDomainHeightIn, aSourceHeightOut);
    attributeAffects(aDomainHeightIn, aSourceOriginOut);

    aDomainLengthIn = nAttr.create("domainLengthIn", "domainLengthIn", MFnNumericData::kFloat, 5.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainLengthIn);
    attributeAffects(aDomainLengthIn, aDomainLengthOut);
    attributeAffects(aDomainLengthIn, aSourceLengthOut);
    attributeAffects(aDomainLengthIn, aSourceOriginOut);

    aSourceOriginIn = nAttr.create("sourceOriginIn", "sourceOriginIn", MFnNumericData::k3Float);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceOriginIn);
    attributeAffects(aSourceOriginIn, aSourceOriginOut);
    attributeAffects(aSourceOriginIn, aSourceHeightOut);
    attributeAffects(aSourceOriginIn, aSourceWidthOut);
    attributeAffects(aSourceOriginIn, aSourceLengthOut);

    aSourceWidthIn = nAttr.create("sourceWidthIn", "sourceWidthIn", MFnNumericData::kFloat, 5.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceWidthIn);
    attributeAffects(aSourceWidthIn, aSourceWidthOut);
    attributeAffects(aSourceWidthIn, aSourceOriginOut);

    aSourceHeightIn = nAttr.create("sourceHeightIn", "sourceHeightIn", MFnNumericData::kFloat, 5.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceHeightIn);
    attributeAffects(aSourceHeightIn, aSourceHeightOut);
    attributeAffects(aSourceHeightIn, aSourceOriginOut);

    aSourceLengthIn = nAttr.create("sourceLengthIn", "sourceLengthIn", MFnNumericData::kFloat, 5.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceLengthIn);
    attributeAffects(aSourceLengthIn, aSourceLengthOut);
    attributeAffects(aSourceLengthIn, aSourceOriginOut);

    aSourceVelocity = nAttr.create("sourceVelocity", "sourceVelocity", MFnNumericData::k3Float);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceVelocity);
    attributeAffects(aSourceVelocity, aVelocityU);
    attributeAffects(aSourceVelocity, aVelocityV);
    attributeAffects(aSourceVelocity, aVelocityW);

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
        plug != aVoxelAlphaOut &&
        plug != aTimestepOut &&
        plug != aDiffusionRateOut &&
        plug != aViscosityOut &&
        plug != aForceMultiplierOut &&
        plug != aSourceMultiplierOut &&
        plug != aDensityOut &&
        plug != aVelocityU &&
        plug != aVelocityV &&
        plug != aVelocityW &&
        plug != aDomainOriginOut &&
        plug != aDomainWidthOut &&
        plug != aDomainHeightOut &&
        plug != aDomainLengthOut &&
        plug != aSourceOriginOut &&
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

    float sourceDensity = data.inputValue(aSourceDensity, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float3& domainVelocity = data.inputValue(aDomainVelocity, &status).asFloat3();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float3& domainOrigin = data.inputValue(aDomainOriginIn, &status).asFloat3();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float domainWidth = data.inputValue(aDomainWidthIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float domainHeight = data.inputValue(aDomainHeightIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float domainLength = data.inputValue(aDomainLengthIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float3& sourceOrigin = data.inputValue(aSourceOriginIn, &status).asFloat3();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float sourceWidth = data.inputValue(aSourceWidthIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float sourceHeight = data.inputValue(aSourceHeightIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float sourceLength = data.inputValue(aSourceLengthIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float3& sourceVelocity = data.inputValue(aSourceVelocity, &status).asFloat3();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    double minTime = data.inputValue(aMinTimeIn, &status).asDouble();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    double maxTime = data.inputValue(aMaxTimeIn, &status).asDouble();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    double timeScale = data.inputValue(aTimeScaleIn, &status).asDouble();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    // Make sure that the source is constrained within the domain. Adjust values accordingly.
    if (sourceOrigin[0] < 0)
    {
        sourceOrigin[0] = 0;
    }
    else if (sourceOrigin[0] > domainWidth)
    {
        sourceOrigin[0] = domainWidth;
    }
    if (sourceOrigin[1] < 0)
    {
        sourceOrigin[1] = 0;
    }
    else if (sourceOrigin[1] > domainHeight)
    {
        sourceOrigin[1] = domainHeight;
    }
    if (sourceOrigin[2] < 0)
    {
        sourceOrigin[2] = 0;
    }
    else if (sourceOrigin[2] > domainLength)
    {
        sourceOrigin[2] = domainLength;
    }

    if (sourceOrigin[0] + sourceWidth > domainWidth)
    {
        sourceWidth -= (sourceOrigin[0] + sourceWidth - domainWidth);
    }
    if (sourceOrigin[1] + sourceHeight > domainHeight)
    {
        sourceHeight -= (sourceOrigin[1] + sourceHeight - domainHeight);
    }
    if (sourceOrigin[2] + sourceLength > domainLength)
    {
        sourceLength -= (sourceOrigin[2] + sourceLength - domainLength);
    }

    // Calculate number of voxels in each dimension for the source.
    int sourceVoxelsWidth = (sourceWidth / domainWidth) * voxelCountWidth;
    int sourceVoxelsHeight = (sourceHeight / domainHeight) * voxelCountHeight;
    int sourceVoxelsLength = (sourceLength / domainLength) * voxelCountLength;

    // Create output velocity fields. Set default velocity for each vector to the specified domain
    // velocity value (default is 0.0f).
    MFloatArray velocityU(voxelCountWidth*voxelCountHeight*voxelCountLength, domainVelocity[0]);
    MFloatArray velocityV(voxelCountWidth*voxelCountHeight*voxelCountLength, domainVelocity[1]);
    MFloatArray velocityW(voxelCountWidth*voxelCountHeight*voxelCountLength, domainVelocity[2]);

    // Create an output density array. Set default density at each coordinate to the
    // specified domain density (default is 0.0f).
    MFloatArray density(voxelCountWidth*voxelCountHeight*voxelCountLength, domainDensity);

    // Add source density to domain density, without exceeding 1.0 limit. In addition,
    // add source velocity to domain velocity, without exceeding 1.0 limit.
    for (int x = sourceOrigin[0]; x < sourceVoxelsWidth && x < voxelCountWidth; x++)
    {
        for (int y = sourceOrigin[1]; y < sourceVoxelsHeight && x < voxelCountHeight; y++)
        {
            for (int z = sourceOrigin[2]; y < sourceVoxelsLength && z < voxelCountLength; z++)
            {
                int i = x + (y * voxelCountWidth) + (z * voxelCountWidth * voxelCountHeight);

                float dValue = domainDensity + sourceDensity;
                if (dValue > 1.0f)
                {
                    dValue = 1.0f;
                }
                density.set(dValue, i);

                float vUValue = domainVelocity[0] + sourceVelocity[0];
                if (vUValue > 1.0f)
                {
                    vUValue = 1.0f;
                }
                velocityU.set(vUValue, i);

                float vVValue = domainVelocity[1] + sourceVelocity[1];
                if (vVValue > 1.0f)
                {
                    vVValue = 1.0f;
                }
                velocityV.set(vVValue, i);

                float vWValue = domainVelocity[2] + sourceVelocity[2];
                if (vWValue > 1.0f)
                {
                    vWValue = 1.0f;
                }
                velocityW.set(vWValue, i);
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

    hOutput = data.outputValue(aVelocityU, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData vUFnDataOut;
    dataOut = vUFnDataOut.create(velocityU, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(dataOut);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aVelocityV, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData vVFnDataOut;
    dataOut = vVFnDataOut.create(velocityV, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(dataOut);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aVelocityW, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData vWFnDataOut;
    dataOut = vWFnDataOut.create(velocityW, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(dataOut);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aDomainOriginOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(domainOrigin);
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

    hOutput = data.outputValue(aSourceOriginOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(sourceOrigin);
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
