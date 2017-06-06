#include "fluidDomainNode.h"

// Maya node ID.
MTypeId FluidDomainNode::id(0x00000100);

// Attributes.
MObject FluidDomainNode::aVoxelCount;
MObject FluidDomainNode::aShowVoxels;
MObject FluidDomainNode::aVoxelAlpha;
MObject FluidDomainNode::aTimestep;
MObject FluidDomainNode::aDiffusion;
MObject FluidDomainNode::aViscosity;
MObject FluidDomainNode::aForceMultiplier;
MObject FluidDomainNode::aSourceMultiplier;
MObject FluidDomainNode::aDensity;
MObject FluidDomainNode::aVelocityU;
MObject FluidDomainNode::aVelocityV;
MObject FluidDomainNode::aVelocityW;
MObject FluidDomainNode::aWidth; 
MObject FluidDomainNode::aHeight;
MObject FluidDomainNode::aLength;
MObject FluidDomainNode::aMinTime;   
MObject FluidDomainNode::aMaxTime;   
MObject FluidDomainNode::aTimeScale; 

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

    // Attributes.
    aTimestep = nAttr.create("timestep", "timestep", MFnNumericData::kFloat, 0.001f);
    nAttr.setKeyable(true);
    addAttribute(aTimestep);

    aDiffusion = nAttr.create("diffusion", "diffusion", MFnNumericData::kFloat, 0.0f);
    nAttr.setKeyable(true);
    addAttribute(aDiffusion);

    aViscosity = nAttr.create("viscosity", "viscosity", MFnNumericData::kFloat, 0.0f);
    nAttr.setKeyable(true);
    addAttribute(aViscosity);

    aForceMultiplier = nAttr.create("forceMultiplier", "forceMultiplier", MFnNumericData::kFloat, 5.0f);
    nAttr.setKeyable(true);
    addAttribute(aForceMultiplier);

    aSourceMultiplier = nAttr.create("sourceMultiplier", "sourceMultiplier", MFnNumericData::kFloat, 200.0f);
    nAttr.setKeyable(true);
    addAttribute(aSourceMultiplier);

    aWidth = nAttr.create("width", "width", MFnNumericData::kFloat, 5.0f);
    nAttr.setKeyable(true);
    addAttribute(aWidth);

    aHeight = nAttr.create("height", "height", MFnNumericData::kFloat, 5.0f);
    nAttr.setKeyable(true);
    addAttribute(aHeight);

    aLength = nAttr.create("length", "length", MFnNumericData::kFloat, 5.0f);
    nAttr.setKeyable(true);
    addAttribute(aLength);

    aDensity = tAttr.create("density", "density", MFnData::kFloatArray);
    nAttr.setKeyable(true);
    addAttribute(aDensity);

    aVelocityU = tAttr.create("velocityU", "velocityU", MFnData::kFloatArray);
    nAttr.setKeyable(true);
    addAttribute(aVelocityU);

    aVelocityV = tAttr.create("velocityV", "velocityV", MFnData::kFloatArray);
    nAttr.setKeyable(true);
    addAttribute(aVelocityV);

    aVelocityW = tAttr.create("velocityW", "velocityW", MFnData::kFloatArray);
    nAttr.setKeyable(true);
    addAttribute(aVelocityW);

    aVoxelCount = nAttr.create("voxelCount", "voxelCount", MFnNumericData::kInt, 10);
    nAttr.setKeyable(true);
    addAttribute(aVoxelCount);
    attributeAffects(aVoxelCount, aDensity);
    attributeAffects(aVoxelCount, aVelocityU);
    attributeAffects(aVoxelCount, aVelocityV);
    attributeAffects(aVoxelCount, aVelocityW);

    aShowVoxels = nAttr.create("showVoxels", "showVoxels", MFnNumericData::kBoolean, false);
    nAttr.setKeyable(true);
    addAttribute(aShowVoxels);

    aVoxelAlpha = nAttr.create("voxelAlpha", "voxelAlpha", MFnNumericData::kFloat, 0.3f);
    nAttr.setMin(0.0f);
    nAttr.setMax(1.0f);
    nAttr.setKeyable(true);
    addAttribute(aVoxelAlpha);

    aMinTime = nAttr.create("minTime", "minTime", MFnNumericData::kDouble, 1.0);
    nAttr.setMin(1.0);
    nAttr.setKeyable(true);
    addAttribute(aMinTime);

    aMaxTime = nAttr.create("maxTime", "maxTime", MFnNumericData::kDouble, 200.0);
    nAttr.setMin(1.0);
    nAttr.setKeyable(true);
    addAttribute(aMaxTime);

    aTimeScale = nAttr.create("timeScale", "timeScale", MFnNumericData::kDouble, 1.0);
    nAttr.setMin(0.0);
    nAttr.setKeyable(true);
    addAttribute(aTimeScale);

    return MS::kSuccess;
}

// Perform node computations.
MStatus FluidDomainNode::compute(const MPlug& plug, MDataBlock& data)
{
    // Status to be returned.
    MStatus status;


    return MS::kSuccess;
}