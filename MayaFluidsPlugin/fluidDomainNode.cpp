#include "fluidDomainNode.h"

// Maya node ID.
MTypeId FluidDomainNode::id(0x00000100);

// Attributes.
MObject FluidDomainNode::aVoxelCount;
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
    tAttr.setWritable(false);
    tAttr.setStorable(false);
    addAttribute(aDensity);

    aVelocityU = tAttr.create("velocityU", "velocityU", MFnData::kFloatArray);
    tAttr.setWritable(false);
    tAttr.setStorable(false);
    addAttribute(aVelocityU);

    aVelocityV = tAttr.create("velocityV", "velocityV", MFnData::kFloatArray);
    tAttr.setWritable(false);
    tAttr.setStorable(false);
    addAttribute(aVelocityV);

    aVelocityW = tAttr.create("velocityW", "velocityW", MFnData::kFloatArray);
    tAttr.setWritable(false);
    tAttr.setStorable(false);
    addAttribute(aVelocityW);

    aVoxelCount = nAttr.create("voxelCount", "voxelCount", MFnNumericData::kInt, 10);
    nAttr.setKeyable(true);
    addAttribute(aVoxelCount);
    attributeAffects(aVoxelCount, aDensity);
    attributeAffects(aVoxelCount, aVelocityU);
    attributeAffects(aVoxelCount, aVelocityV);
    attributeAffects(aVoxelCount, aVelocityW);

    return MS::kSuccess;
}

// Perform node computations.
MStatus FluidDomainNode::compute(const MPlug& plug, MDataBlock& data)
{
    // Status to be returned.
    MStatus status;


    return MS::kSuccess;
}