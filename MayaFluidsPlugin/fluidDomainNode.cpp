#include "fluidDomainNode.h"

// Maya node ID.
MTypeId FluidDomainNode::id(0x00000100);

// Outputs.
MObject FluidDomainNode::aN;
MObject FluidDomainNode::aDt;
MObject FluidDomainNode::aDiff;
MObject FluidDomainNode::aVisc;
MObject FluidDomainNode::aForce;
MObject FluidDomainNode::aSource;
MObject FluidDomainNode::aX;
MObject FluidDomainNode::aU;
MObject FluidDomainNode::aV;
MObject FluidDomainNode::aW;

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

    // Outputs.
    aN = nAttr.create("N", "N", MFnNumericData::kInt);
    nAttr.setKeyable(true);
    addAttribute(aN);
    attributeAffects(aN, aX);
    attributeAffects(aN, aU);
    attributeAffects(aN, aV);
    attributeAffects(aN, aW);

    aDt = nAttr.create("dt", "dt", MFnNumericData::kFloat);
    nAttr.setKeyable(true);
    addAttribute(aDt);

    aDiff = nAttr.create("diff", "diff", MFnNumericData::kFloat);
    nAttr.setKeyable(true);
    addAttribute(aDiff);

    aVisc = nAttr.create("visc", "visc", MFnNumericData::kFloat);
    nAttr.setKeyable(true);
    addAttribute(aVisc);

    aForce = nAttr.create("force", "force", MFnNumericData::kFloat);
    nAttr.setKeyable(true);
    addAttribute(aForce);

    aSource = nAttr.create("source", "source", MFnNumericData::kFloat);
    nAttr.setKeyable(true);
    addAttribute(aSource);

    aX = tAttr.create("x", "x", MFnData::kFloatArray);
    tAttr.setWritable(false);
    tAttr.setStorable(false);
    addAttribute(aX);

    aU = tAttr.create("u", "u", MFnData::kFloatArray);
    tAttr.setWritable(false);
    tAttr.setStorable(false);
    addAttribute(aU);

    aV = tAttr.create("v", "v", MFnData::kFloatArray);
    tAttr.setWritable(false);
    tAttr.setStorable(false);
    addAttribute(aV);

    aW = tAttr.create("w", "w", MFnData::kFloatArray);
    tAttr.setWritable(false);
    tAttr.setStorable(false);
    addAttribute(aW);

    return MS::kSuccess;
}

// Perform node computations.
MStatus FluidDomainNode::compute(const MPlug& plug, MDataBlock& data)
{
    // Status to be returned.
    MStatus status;


    return MS::kSuccess;
}