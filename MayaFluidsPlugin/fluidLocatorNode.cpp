#include "fluidLocatorNode.h"

MTypeId FluidLocatorNode::id(0x00000102);

// Output attributes.
MObject FluidLocatorNode::aFluid;
MObject FluidLocatorNode::aDensityOut;
MObject FluidLocatorNode::aVelocityUOut;
MObject FluidLocatorNode::aVelocityVOut;
MObject FluidLocatorNode::aVelocityWOut;
MObject FluidLocatorNode::aShowFluidOut;
MObject FluidLocatorNode::aShowVoxelsOut;
MObject FluidLocatorNode::aVoxelAlphaOut;
MObject FluidLocatorNode::aVoxelCountWidthOut;
MObject FluidLocatorNode::aVoxelCountHeightOut;
MObject FluidLocatorNode::aVoxelCountLengthOut;
MObject FluidLocatorNode::aDomainOriginXOut;
MObject FluidLocatorNode::aDomainOriginYOut;
MObject FluidLocatorNode::aDomainOriginZOut;
MObject FluidLocatorNode::aDomainHeightOut;
MObject FluidLocatorNode::aDomainWidthOut;
MObject FluidLocatorNode::aDomainLengthOut;
MObject FluidLocatorNode::aSourceOriginXOut;
MObject FluidLocatorNode::aSourceOriginYOut;
MObject FluidLocatorNode::aSourceOriginZOut;
MObject FluidLocatorNode::aSourceWidthOut;
MObject FluidLocatorNode::aSourceHeightOut;
MObject FluidLocatorNode::aSourceLengthOut;

// Input attributes.
MObject FluidLocatorNode::aDensityIn;
MObject FluidLocatorNode::aVelocityUIn;
MObject FluidLocatorNode::aVelocityVIn;
MObject FluidLocatorNode::aVelocityWIn;
MObject FluidLocatorNode::aShowFluidIn;
MObject FluidLocatorNode::aShowVoxelsIn;
MObject FluidLocatorNode::aVoxelAlphaIn;
MObject FluidLocatorNode::aVoxelCountWidthIn;
MObject FluidLocatorNode::aVoxelCountHeightIn;
MObject FluidLocatorNode::aVoxelCountLengthIn;
MObject FluidLocatorNode::aDomainOriginXIn;
MObject FluidLocatorNode::aDomainOriginYIn;
MObject FluidLocatorNode::aDomainOriginZIn;
MObject FluidLocatorNode::aDomainHeightIn;
MObject FluidLocatorNode::aDomainWidthIn;
MObject FluidLocatorNode::aDomainLengthIn;
MObject FluidLocatorNode::aSourceOriginXIn;
MObject FluidLocatorNode::aSourceOriginYIn;
MObject FluidLocatorNode::aSourceOriginZIn;
MObject FluidLocatorNode::aSourceWidthIn;
MObject FluidLocatorNode::aSourceHeightIn;
MObject FluidLocatorNode::aSourceLengthIn;

FluidLocatorNode::FluidLocatorNode() {}

FluidLocatorNode::~FluidLocatorNode() {}

void FluidLocatorNode::postConstructor()
{
    MFnDependencyNode nodeFn(thisMObject());
    nodeFn.setName("fluidLocatorShape#");
}

void* FluidLocatorNode::creator()
{
    return new FluidLocatorNode();
}

MStatus FluidLocatorNode::initialize()
{
    MStatus status;
    MFnUnitAttribute uAttr;
    MFnNumericAttribute nAttr;
    MFnTypedAttribute tAttr;

    // Output attributes.
    aFluid = tAttr.create("fluid", "fluid", MFnData::kStringArray);
    tAttr.setWritable(false);
    tAttr.setStorable(false);
    addAttribute(aFluid);

    aDensityOut = tAttr.create("densityOut", "densityOut", MFnData::kFloatArray);
    tAttr.setWritable(false);
    tAttr.setStorable(false);
    addAttribute(aDensityOut);

    aVelocityUOut = tAttr.create("velocityUOut", "velocityUOut", MFnData::kFloatArray);
    tAttr.setWritable(false);
    tAttr.setStorable(false);
    addAttribute(aVelocityUOut);

    aVelocityVOut = tAttr.create("velocityVOut", "velocityVOut", MFnData::kFloatArray);
    tAttr.setWritable(false);
    tAttr.setStorable(false);
    addAttribute(aVelocityVOut);

    aVelocityWOut = tAttr.create("velocityWOut", "velocityWOut", MFnData::kFloatArray);
    tAttr.setWritable(false);
    tAttr.setStorable(false);
    addAttribute(aVelocityWOut);

    aShowFluidOut = nAttr.create("showFluidOut", "showFluidOut", MFnNumericData::kBoolean);
    nAttr.setWritable(false);
    nAttr.setStorable(false);
    addAttribute(aShowFluidOut);

    aShowVoxelsOut = nAttr.create("showVoxelsOut", "showVoxelsOut", MFnNumericData::kBoolean);
    nAttr.setWritable(false);
    nAttr.setStorable(false);
    addAttribute(aShowVoxelsOut);

    aVoxelAlphaOut = nAttr.create("voxelAlphaOut", "voxelAlphaOut", MFnNumericData::kFloat);
    nAttr.setWritable(false);
    nAttr.setStorable(false);
    addAttribute(aVoxelAlphaOut);

    aVoxelCountWidthOut = nAttr.create("voxelCountWidthOut", "voxelCountWidthOut", MFnNumericData::kInt);
    nAttr.setWritable(false);
    nAttr.setStorable(false);
    addAttribute(aVoxelCountWidthOut);

    aVoxelCountHeightOut = nAttr.create("voxelCountHeightOut", "voxelCountHeightOut", MFnNumericData::kInt);
    nAttr.setWritable(false);
    nAttr.setStorable(false);
    addAttribute(aVoxelCountHeightOut);

    aVoxelCountLengthOut = nAttr.create("voxelCountLengthOut", "voxelCountLengthOut", MFnNumericData::kInt);
    nAttr.setWritable(false);
    nAttr.setStorable(false);
    addAttribute(aVoxelCountLengthOut);

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

    // Input attributes.
    aDensityIn = tAttr.create("densityIn", "densityIn", MFnData::kFloatArray);
    tAttr.setKeyable(true);
    tAttr.setWritable(true);
    addAttribute(aDensityIn);
    attributeAffects(aDensityIn, aDensityOut);
    attributeAffects(aDensityIn, aFluid);

    aVelocityUIn = tAttr.create("velocityUIn", "velocityUIn", MFnData::kFloatArray);
    tAttr.setKeyable(true);
    tAttr.setWritable(true);
    addAttribute(aVelocityUIn);
    attributeAffects(aVelocityUIn, aVelocityUOut);
    attributeAffects(aVelocityUIn, aFluid);

    aVelocityVIn = tAttr.create("velocityVIn", "velocityVIn", MFnData::kFloatArray);
    tAttr.setKeyable(true);
    tAttr.setWritable(true);
    addAttribute(aVelocityVIn);
    attributeAffects(aVelocityVIn, aVelocityVOut);
    attributeAffects(aVelocityVIn, aFluid);

    aVelocityWIn = tAttr.create("velocityWIn", "velocityWIn", MFnData::kFloatArray);
    tAttr.setKeyable(true);
    tAttr.setWritable(true);
    addAttribute(aVelocityWIn);
    attributeAffects(aVelocityVIn, aVelocityVOut);
    attributeAffects(aVelocityVIn, aFluid);

    aShowFluidIn = nAttr.create("showFluidIn", "showFluidIn", MFnNumericData::kBoolean);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aShowFluidIn);
    attributeAffects(aShowFluidIn, aShowFluidOut);
    attributeAffects(aShowFluidIn, aFluid);

    aShowVoxelsIn = nAttr.create("showVoxelsIn", "showVoxelsIn", MFnNumericData::kBoolean);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aShowVoxelsIn);
    attributeAffects(aShowVoxelsIn, aShowVoxelsOut);

    aVoxelAlphaIn = nAttr.create("voxelAlphaIn", "voxelAlphaIn", MFnNumericData::kFloat);
    nAttr.setMin(0.0f);
    nAttr.setMax(1.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aVoxelAlphaIn);
    attributeAffects(aVoxelAlphaIn, aVoxelAlphaOut);

    aVoxelCountWidthIn = nAttr.create("voxelCountWidthIn", "voxelCountWidthIn", MFnNumericData::kInt);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aVoxelCountWidthIn);
    attributeAffects(aVoxelCountWidthIn, aVoxelCountWidthOut);
    attributeAffects(aVoxelCountWidthIn, aDensityOut);
    attributeAffects(aVoxelCountWidthIn, aVelocityUOut);
    attributeAffects(aVoxelCountWidthIn, aVelocityVOut);
    attributeAffects(aVoxelCountWidthIn, aVelocityWOut);
    attributeAffects(aVoxelCountWidthIn, aFluid);

    aVoxelCountHeightIn = nAttr.create("voxelCountHeightIn", "voxelCountHeightIn", MFnNumericData::kInt);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aVoxelCountHeightIn);
    attributeAffects(aVoxelCountHeightIn, aVoxelCountHeightOut);
    attributeAffects(aVoxelCountHeightIn, aDensityOut);
    attributeAffects(aVoxelCountHeightIn, aVelocityUOut);
    attributeAffects(aVoxelCountHeightIn, aVelocityVOut);
    attributeAffects(aVoxelCountHeightIn, aVelocityWOut);
    attributeAffects(aVoxelCountHeightIn, aFluid);

    aVoxelCountLengthIn = nAttr.create("voxelCountLengthIn", "voxelCountLengthIn", MFnNumericData::kInt);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aVoxelCountLengthIn);
    attributeAffects(aVoxelCountLengthIn, aVoxelCountLengthOut);
    attributeAffects(aVoxelCountLengthIn, aDensityOut);
    attributeAffects(aVoxelCountLengthIn, aVelocityUOut);
    attributeAffects(aVoxelCountLengthIn, aVelocityVOut);
    attributeAffects(aVoxelCountLengthIn, aVelocityWOut);
    attributeAffects(aVoxelCountLengthIn, aFluid);

    aDomainOriginXIn = nAttr.create("domainOriginXIn", "domainOriginXIn", MFnNumericData::kFloat);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainOriginXIn);
    attributeAffects(aDomainOriginXIn, aDomainOriginXOut);
    attributeAffects(aDomainOriginXIn, aSourceOriginXOut);
    attributeAffects(aDomainOriginXIn, aFluid);

    aDomainOriginYIn = nAttr.create("domainOriginYIn", "domainOriginYIn", MFnNumericData::kFloat);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainOriginYIn);
    attributeAffects(aDomainOriginYIn, aDomainOriginYOut);
    attributeAffects(aDomainOriginYIn, aSourceOriginYOut);
    attributeAffects(aDomainOriginYIn, aFluid);

    aDomainOriginZIn = nAttr.create("domainOriginZIn", "domainOriginZIn", MFnNumericData::kFloat);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainOriginZIn);
    attributeAffects(aDomainOriginZIn, aDomainOriginZOut);
    attributeAffects(aDomainOriginZIn, aSourceOriginZOut);
    attributeAffects(aDomainOriginZIn, aFluid);

    aDomainWidthIn = nAttr.create("domainWidthIn", "domainWidthIn", MFnNumericData::kFloat);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainWidthIn);
    attributeAffects(aDomainWidthIn, aDomainWidthOut);
    attributeAffects(aDomainWidthIn, aSourceWidthOut);
    attributeAffects(aDomainWidthIn, aSourceOriginXOut);
    attributeAffects(aDomainWidthIn, aFluid);

    aDomainHeightIn = nAttr.create("domainHeightIn", "domainHeightIn", MFnNumericData::kFloat);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainHeightIn);
    attributeAffects(aDomainHeightIn, aDomainHeightOut);
    attributeAffects(aDomainHeightIn, aSourceHeightOut);
    attributeAffects(aDomainHeightIn, aSourceOriginYOut);
    attributeAffects(aDomainHeightIn, aFluid);

    aDomainLengthIn = nAttr.create("domainLengthIn", "domainLengthIn", MFnNumericData::kFloat);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainLengthIn);
    attributeAffects(aDomainLengthIn, aDomainLengthOut);
    attributeAffects(aDomainLengthIn, aSourceLengthOut);
    attributeAffects(aDomainLengthIn, aSourceOriginZOut);
    attributeAffects(aDomainLengthIn, aFluid);

    aSourceOriginXIn = nAttr.create("sourceOriginXIn", "sourceOriginXIn", MFnNumericData::kFloat);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceOriginXIn);
    attributeAffects(aSourceOriginXIn, aSourceOriginXOut);
    attributeAffects(aSourceOriginXIn, aSourceHeightOut);
    attributeAffects(aSourceOriginXIn, aSourceWidthOut);
    attributeAffects(aSourceOriginXIn, aSourceLengthOut);
    attributeAffects(aSourceOriginXIn, aFluid);

    aSourceOriginYIn = nAttr.create("sourceOriginYIn", "sourceOriginYIn", MFnNumericData::kFloat);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceOriginYIn);
    attributeAffects(aSourceOriginYIn, aSourceOriginYOut);
    attributeAffects(aSourceOriginYIn, aSourceHeightOut);
    attributeAffects(aSourceOriginYIn, aSourceWidthOut);
    attributeAffects(aSourceOriginYIn, aSourceLengthOut);
    attributeAffects(aSourceOriginYIn, aFluid);

    aSourceOriginZIn = nAttr.create("sourceOriginZIn", "sourceOriginZIn", MFnNumericData::kFloat);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceOriginZIn);
    attributeAffects(aSourceOriginZIn, aSourceOriginZOut);
    attributeAffects(aSourceOriginZIn, aSourceHeightOut);
    attributeAffects(aSourceOriginZIn, aSourceWidthOut);
    attributeAffects(aSourceOriginZIn, aSourceLengthOut);
    attributeAffects(aSourceOriginZIn, aFluid);

    aSourceWidthIn = nAttr.create("sourceWidthIn", "sourceWidthIn", MFnNumericData::kFloat);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceWidthIn);
    attributeAffects(aSourceWidthIn, aSourceWidthOut);
    attributeAffects(aSourceWidthIn, aSourceOriginXOut);
    attributeAffects(aSourceWidthIn, aFluid);

    aSourceHeightIn = nAttr.create("sourceHeightIn", "sourceHeightIn", MFnNumericData::kFloat);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceHeightIn);
    attributeAffects(aSourceHeightIn, aSourceHeightOut);
    attributeAffects(aSourceHeightIn, aSourceOriginYOut);
    attributeAffects(aSourceHeightIn, aFluid);

    aSourceLengthIn = nAttr.create("sourceLengthIn", "sourceLengthIn", MFnNumericData::kFloat);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceLengthIn);
    attributeAffects(aSourceLengthIn, aSourceLengthOut);
    attributeAffects(aSourceLengthIn, aSourceOriginZOut);
    attributeAffects(aSourceLengthIn, aFluid);

    return MS::kSuccess;
}

MStatus FluidLocatorNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus status;

    if (plug != aFluid &&
        plug != aDensityOut &&
        plug != aVelocityUOut &&
        plug != aVelocityVOut &&
        plug != aVelocityWOut &&
        plug != aShowFluidOut &&
        plug != aShowVoxelsOut &&
        plug != aVoxelAlphaOut &&
        plug != aVoxelCountWidthOut &&
        plug != aVoxelCountHeightOut &&
        plug != aVoxelCountLengthOut &&
        plug != aDomainOriginXOut &&
        plug != aDomainOriginYOut &&
        plug != aDomainOriginZOut &&
        plug != aDomainHeightOut &&
        plug != aDomainWidthOut &&
        plug != aDomainLengthOut &&
        plug != aSourceOriginXOut &&
        plug != aSourceOriginYOut &&
        plug != aSourceOriginZOut &&
        plug != aSourceWidthOut &&
        plug != aSourceHeightOut &&
        plug != aSourceLengthOut)
    {
        return MS::kUnknownParameter;
    }

    MDataHandle dataHandle = data.inputValue(aDensityIn, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData densityFnData(dataHandle.data());
    MFloatArray density = densityFnData.array();

    dataHandle = data.inputValue(aVelocityUIn, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData velocityUFnData(dataHandle.data());
    MFloatArray velocityU = velocityUFnData.array();

    dataHandle = data.inputValue(aVelocityVIn, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData velocityVFnData(dataHandle.data());
    MFloatArray velocityV = velocityVFnData.array();

    dataHandle = data.inputValue(aVelocityWIn, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData velocityWFnData(dataHandle.data());
    MFloatArray velocityW = velocityWFnData.array();

    bool showFluid = data.inputValue(aShowFluidIn, &status).asBool();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    bool showVoxels = data.inputValue(aShowVoxelsIn, &status).asBool();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float voxelAlpha = data.inputValue(aVoxelAlphaIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    int voxelCountWidth = data.inputValue(aVoxelCountWidthIn, &status).asInt();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    int voxelCountHeight = data.inputValue(aVoxelCountHeightIn, &status).asInt();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    int voxelCountLength = data.inputValue(aVoxelCountLengthIn, &status).asInt();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float domainOriginX = data.inputValue(aDomainOriginXIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float domainOriginY = data.inputValue(aDomainOriginYIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float domainOriginZ = data.inputValue(aDomainOriginZIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

	float domainHeight = data.inputValue(aDomainHeightIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

	float domainWidth = data.inputValue(aDomainWidthIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

	float domainLength = data.inputValue(aDomainLengthIn, &status).asFloat();
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

    dataHandle = data.outputValue(aFluid, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnStringArrayData fluidFnData(dataHandle.data());
    MStringArray fluid = fluidFnData.array();

    // Locator transform node.
    MFnDependencyNode nodeFn(thisMObject());
    MString name = nodeFn.name();
    name.substitute("Shape", "");

    // Get output values which may have an affect on how fluids is drawn.
    int voxelCountWidthOut = data.outputValue(aVoxelCountWidthOut, &status).asInt();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    int voxelCountHeightOut = data.outputValue(aVoxelCountHeightOut, &status).asInt();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    int voxelCountLengthOut = data.outputValue(aVoxelCountLengthOut, &status).asInt();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float domainOriginOutX = data.outputValue(aDomainOriginXOut, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float domainOriginOutY = data.outputValue(aDomainOriginYOut, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float domainOriginOutZ = data.outputValue(aDomainOriginZOut, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float domainHeightOut = data.outputValue(aDomainHeightOut, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float domainWidthOut = data.outputValue(aDomainWidthOut, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float domainLengthOut = data.outputValue(aDomainLengthOut, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float sourceOriginOutX = data.outputValue(aSourceOriginXOut, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float sourceOriginOutY = data.outputValue(aSourceOriginYOut, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float sourceOriginOutZ = data.outputValue(aSourceOriginZOut, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float sourceHeightOut = data.outputValue(aSourceHeightOut, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float sourceWidthOut = data.outputValue(aSourceWidthOut, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float sourceLengthOut = data.outputValue(aSourceLengthOut, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    bool showFluidOut = data.outputValue(aShowFluidOut, &status).asBool();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    // Fluid size (not counting the boundary buffers).
    int size = voxelCountWidth * voxelCountHeight * voxelCountLength;

    // Compare the cached outputs with the inputs to see if any changes were made.  If there
    // were, clear the fluid. This is equivalent of the user adjusting the simluation, so there's 
    // a cost to pay. This may be optimized later on, if necessary.
    if (voxelCountWidth != voxelCountWidthOut || voxelCountHeight != voxelCountHeightOut || voxelCountLength != voxelCountLengthOut || 
        domainWidth != domainWidthOut || domainHeight != domainHeightOut || domainLength != domainLengthOut || 
        domainOriginX != domainOriginOutX || domainOriginY != domainOriginOutY || domainOriginZ != domainOriginOutZ || 
        sourceWidth != sourceWidthOut || sourceHeight != sourceHeightOut || sourceLength != sourceLengthOut ||
        sourceOriginX != sourceOriginOutX || sourceOriginY != sourceOriginOutY || sourceOriginZ != sourceOriginOutZ ||
        fluid.length() != size ||
        ((showFluid != showFluidOut) && !showFluid))
    {
        // Calling this causes R6025 error.  Not sure why.
        //resetFluid(fluid, size);

        // Ge the current size/length.
        int length = fluid.length();
        if (length != 0)
        {
            // If there are any elements, delete them.
            for (int i = 0; i < length; i++)
            {
                MString name = fluid[i];
                if (name != NULL || name.length() != 0 || name != "")
                {
                    MGlobal::executeCommand("delete " + fluid[i]);
                    fluid.set("", i);
                }
            }
        }
        // Set the new size;
        fluid.setLength(size);
    }

    // If showFluid flag is not set to false, simulate the fluid.
    if (showFluid)
    {
        simulateFluid(name, fluid, density, domainWidth, domainHeight, domainLength,
            voxelCountWidth, voxelCountHeight, voxelCountLength);
    }
 
    MDataHandle hOutput = data.outputValue(aFluid, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnStringArrayData fluidFnDataOut;
    MObject dataOut = fluidFnDataOut.create(fluid, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(dataOut);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aDensityOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData densityFnDataOut;
    dataOut = densityFnDataOut.create(density, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(dataOut);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aVelocityUOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData vUFnDataOut;
    dataOut = vUFnDataOut.create(velocityU, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(dataOut);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aVelocityVOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData vVFnDataOut;
    dataOut = vVFnDataOut.create(velocityV, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(dataOut);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aVelocityWOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData vWFnDataOut;
    dataOut = vWFnDataOut.create(velocityW, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(dataOut);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aShowFluidOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(showFluid);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aShowVoxelsOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(showVoxels);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aVoxelAlphaOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOutput.set(voxelAlpha);
    hOutput.setClean();
    data.setClean(plug);

    hOutput = data.outputValue(aVoxelCountWidthOut, &status);
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

	return MS::kSuccess;
}

void FluidLocatorNode::draw(M3dView& view, const MDagPath& DGpath, M3dView::DisplayStyle style, M3dView::DisplayStatus stat)
{
	MStatus status;
	float domainHeight;
	float domainWidth;
	float domainLength;
    float sourceHeight;
    float sourceWidth;
    float sourceLength;
    int voxelCountWidth;
    int voxelCountHeight;
    int voxelCountLength;
    bool showVoxels;
    float voxelAlpha;
    float domainOriginX;
    float domainOriginY;
    float domainOriginZ;
    float sourceOriginX;
    float sourceOriginY;
    float sourceOriginZ;

	MFnDependencyNode dFn(thisMObject(), &status);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to initialize dependency node.");
		return;
	}

    MPlug fluidPlug = dFn.findPlug(aFluid, &status);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to getfluid plug.");
        return;
    }
    MObject fluidObj;
    status = fluidPlug.getValue(fluidObj);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get fluid value.");
        return;
    }

    MPlug valPlug = dFn.findPlug(aDomainWidthIn, &status);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to get domain width plug.");
		return;
	}
	status = valPlug.getValue(domainWidth);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to get domain width value.");
		return;
	}

    valPlug = dFn.findPlug(aDomainHeightIn, &status);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get domain height plug.");
        return;
    }
    status = valPlug.getValue(domainHeight);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get domain height value.");
        return;
    }

	valPlug = dFn.findPlug(aDomainLengthIn, &status);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to get domain length plug.");
		return;
	}
	status = valPlug.getValue(domainLength);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to get domain length value.");
		return;
	}

    valPlug = dFn.findPlug(aVoxelCountWidthIn, &status);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get voxelCountWidth plug.");
        return;
    }
    status = valPlug.getValue(voxelCountWidth);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get voxelCountWidth value.");
        return;
    }

    valPlug = dFn.findPlug(aVoxelCountHeightIn, &status);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get voxelCountHeight plug.");
        return;
    }
    status = valPlug.getValue(voxelCountHeight);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get voxelCountHeight value.");
        return;
    }

    valPlug = dFn.findPlug(aVoxelCountLengthIn, &status);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get voxelCountLength plug.");
        return;
    }
    status = valPlug.getValue(voxelCountLength);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get voxelCountLength value.");
        return;
    }

    valPlug = dFn.findPlug(aShowVoxelsIn, &status);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get showVoxel plug.");
        return;
    }
    status = valPlug.getValue(showVoxels);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get showVoxel value.");
        return;
    }

    valPlug = dFn.findPlug(aVoxelAlphaIn, &status);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get voxelAlpha plug.");
        return;
    }
    status = valPlug.getValue(voxelAlpha);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get voxelAlpha value.");
        return;
    }

    valPlug = dFn.findPlug(aSourceWidthIn, &status);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get source width plug.");
        return;
    }
    status = valPlug.getValue(sourceWidth);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get source width value.");
        return;
    }

    valPlug = dFn.findPlug(aSourceHeightIn, &status);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get source height plug.");
        return;
    }
    status = valPlug.getValue(sourceHeight);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get source height value.");
        return;
    }

    valPlug = dFn.findPlug(aSourceLengthIn, &status);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get source length plug.");
        return;
    }
    status = valPlug.getValue(sourceLength);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get source length value.");
        return;
    }

    valPlug = dFn.findPlug(aSourceOriginXIn, &status);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get source origin x plug.");
        return;
    }
    status = valPlug.getValue(sourceOriginX);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get source origin x value.");
        return;
    }

    valPlug = dFn.findPlug(aSourceOriginYIn, &status);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get source origin y plug.");
        return;
    }
    status = valPlug.getValue(sourceOriginY);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get source origin y value.");
        return;
    }

    valPlug = dFn.findPlug(aSourceOriginZIn, &status);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get source origin z plug.");
        return;
    }
    status = valPlug.getValue(sourceOriginZ);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get source origin z value.");
        return;
    }

    valPlug = dFn.findPlug(aDomainOriginXIn, &status);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get domain origin x plug.");
        return;
    }
    status = valPlug.getValue(domainOriginX);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get domain origin x value.");
        return;
    }

    valPlug = dFn.findPlug(aDomainOriginYIn, &status);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get domain origin y plug.");
        return;
    }
    status = valPlug.getValue(domainOriginY);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get domain origin y value.");
        return;
    }

    valPlug = dFn.findPlug(aDomainOriginZIn, &status);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get domain origin z plug.");
        return;
    }
    status = valPlug.getValue(domainOriginZ);
    if (status != MS::kSuccess)
    {
        MGlobal::displayError("Unable to get domain origin z value.");
        return;
    }

	view.beginGL();
    glPushAttrib(GL_CURRENT_BIT);

    if (showVoxels)
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        MColor col = colorRGB(stat);
        if (stat == M3dView::kLead)
        {
            glColor4f(0.26f, 1.0f, 0.64f, voxelAlpha);
        }
        else
        {
            glColor4f(col.r, col.g, col.b, voxelAlpha);
        }

        float wIncrement = domainWidth / voxelCountWidth;
        float hIncrement = domainHeight / voxelCountHeight;
        float lIncrement = domainLength / voxelCountLength;

        glBegin(GL_LINES);
        for (int i = 0; i <= voxelCountWidth; i++)
        {
            for (int j = 0; j <= voxelCountHeight; j++)
            {
                glVertex3f(domainOriginX + wIncrement*i, domainOriginY, domainOriginZ + lIncrement*j);
                glVertex3f(domainOriginX + wIncrement*i, domainOriginY + domainHeight, domainOriginZ + lIncrement*j);

                glVertex3f(domainOriginX + wIncrement*i, domainOriginY + hIncrement*j, domainOriginZ);
                glVertex3f(domainOriginX + wIncrement*i, domainOriginY + hIncrement*j, domainLength);

                glVertex3f(domainOriginX, hIncrement*i, domainOriginY + lIncrement*j);
                glVertex3f(domainOriginX + domainWidth, domainOriginY + hIncrement*i, domainOriginZ + lIncrement*j);
            }
        }
        glEnd();
    }
    else
    {
        // Draw domain.
        glBegin(GL_LINE_LOOP);
        glVertex3f(domainOriginX, domainOriginY, domainOriginZ);
        glVertex3f(domainOriginX, domainOriginY + domainHeight, domainOriginZ);
        glVertex3f(domainOriginX + domainWidth, domainOriginY + domainHeight, domainOriginZ);
        glVertex3f(domainOriginX + domainWidth, domainOriginY, domainOriginZ);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glVertex3f(domainOriginX, domainOriginY, domainOriginZ + domainLength);
        glVertex3f(domainOriginX, domainOriginY + domainHeight, domainOriginZ + domainLength);
        glVertex3f(domainOriginX + domainWidth, domainOriginY + domainHeight, domainOriginZ + domainLength);
        glVertex3f(domainOriginX + domainWidth, domainOriginY, domainOriginZ + domainLength);
        glEnd();

        glBegin(GL_LINES);
        glVertex3f(domainOriginX, domainOriginY, domainOriginZ);
        glVertex3f(domainOriginX, domainOriginY, domainOriginZ + domainLength);

        glVertex3f(domainOriginX + domainWidth, domainOriginY, domainOriginZ);
        glVertex3f(domainOriginX + domainWidth, domainOriginY, domainOriginZ + domainLength);

        glVertex3f(domainOriginX, domainOriginY + domainHeight, domainOriginZ);
        glVertex3f(domainOriginX, domainOriginY + domainHeight, domainOriginZ + domainLength);

        glVertex3f(domainOriginX + domainWidth, domainOriginY + domainHeight, domainOriginZ);
        glVertex3f(domainOriginX + domainWidth, domainOriginY + domainHeight, domainOriginZ + domainLength);
        glEnd();
    }

    // Draw source.
    if (stat == M3dView::kLead)
    {
        glColor3f(0.26f, 1.0f, 0.64f);
    }
    else
    {
        glColor3f(1.0f, 0.0f, 0.0f);
    }

    glLineWidth(2.0f);

    glBegin(GL_LINE_LOOP);
    glVertex3f(domainOriginX + sourceOriginX, domainOriginY + sourceOriginY, domainOriginZ + sourceOriginZ);
    glVertex3f(domainOriginX + sourceOriginX, domainOriginY + sourceOriginY + sourceHeight, domainOriginZ + sourceOriginZ);
    glVertex3f(domainOriginX + sourceOriginX + sourceWidth, domainOriginY + sourceOriginY + sourceHeight, domainOriginZ + sourceOriginZ);
    glVertex3f(domainOriginX + sourceOriginX + sourceWidth, domainOriginY + sourceOriginY, domainOriginZ + sourceOriginZ);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex3f(domainOriginX + sourceOriginX, domainOriginY + sourceOriginY, domainOriginZ + sourceOriginZ + sourceLength);
    glVertex3f(domainOriginX + sourceOriginX, domainOriginY + sourceOriginY + sourceHeight, domainOriginZ + sourceOriginZ + sourceLength);
    glVertex3f(domainOriginX + sourceOriginX + sourceWidth, domainOriginY + sourceOriginY + sourceHeight, domainOriginZ + sourceOriginZ + sourceLength);
    glVertex3f(domainOriginX + sourceOriginX + sourceWidth, domainOriginY + sourceOriginY, domainOriginZ + sourceOriginZ + sourceLength);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(domainOriginX + sourceOriginX, domainOriginY + sourceOriginY, domainOriginZ + sourceOriginZ);
    glVertex3f(domainOriginX + sourceOriginX, domainOriginY + sourceOriginY, domainOriginZ + sourceOriginZ + sourceLength);

    glVertex3f(domainOriginX + sourceOriginX + sourceWidth, domainOriginY + sourceOriginY, domainOriginZ + sourceOriginZ);
    glVertex3f(domainOriginX + sourceOriginX + sourceWidth, domainOriginY + sourceOriginY, domainOriginZ + sourceOriginZ + sourceLength);

    glVertex3f(domainOriginX + sourceOriginX, domainOriginY + sourceOriginY + sourceHeight, domainOriginZ + sourceOriginZ);
    glVertex3f(domainOriginX + sourceOriginX, domainOriginY + sourceOriginY + sourceHeight, domainOriginZ + sourceOriginZ + sourceLength);

    glVertex3f(domainOriginX + sourceOriginX + sourceWidth, domainOriginY + sourceOriginY + sourceHeight, domainOriginZ + sourceOriginZ);
    glVertex3f(domainOriginX + sourceOriginX + sourceWidth, domainOriginY + sourceOriginY + sourceHeight, domainOriginZ + sourceOriginZ + sourceLength);
    glEnd();

    glPopAttrib();
	view.endGL();
}

// Simulated fluid by drawing spheres in the Maya viewport.
void FluidLocatorNode::simulateFluid(MString locatorName, MStringArray &fluid, MFloatArray &density,
    float domainWidth, float domainHeight, float domainLength, int voxelCountWidth, int voxelCountHeight, int voxelCountLength)
{
	MSelectionList previous_list;
	MGlobal::getActiveSelectionList(previous_list);

    // Minimum radius to render.
    float minRadius = 0.01;

    float x_offset = domainWidth / voxelCountWidth;
    float x_init = x_offset / 2;
    float y_offset = domainHeight / voxelCountHeight;
    float y_init = y_offset / 2;
    float z_offset = domainLength / voxelCountLength;
    float z_init = z_offset / 2;

    float smallest = std::fminf(std::fminf(x_offset, y_offset), z_offset);

    for (int x = 0; x < voxelCountWidth; x++) {
        MString x_name(std::to_string(x).c_str());
        MString x_pos(std::to_string(x_init + ((float)x * x_offset)).c_str());
        for (int y = 0; y < voxelCountHeight; y++) {
            MString y_name(std::to_string(y).c_str());
            MString y_pos(std::to_string(y_init + ((float)y * y_offset)).c_str());
            for (int z = 0; z < voxelCountLength; z++) {
                int i = x + (y * voxelCountWidth) + (z * voxelCountWidth * voxelCountHeight);
                // Density index must be calculated separately, since it's larger by 2 in each dimension.
                int d_i = (x + 1) + ((y + 1) * (voxelCountWidth + 2)) + ((z + 1) * (voxelCountWidth + 2) * (voxelCountHeight + 2));
                MString z_name(std::to_string(z).c_str());
                MString z_pos(std::to_string(z_init + ((float)z * z_offset)).c_str());
                MString pos = x_pos + " " + y_pos + " " + z_pos;
                // Cap radius multiplier at 1.
                float densityVal = density[d_i];
                if (densityVal > 1)
                {
                    densityVal = 1;
                }
                float radiusVal = (smallest / 2) * densityVal;
                MString radius(std::to_string(radiusVal).c_str());
                MString fluidParticleName = "fSphere_" + x_name + "_" + y_name + "_" + z_name;
                MString existingName = fluid[i];
                if (fluid[i] == fluidParticleName)
                {
                    if (radiusVal > minRadius)
                    {
                        MGlobal::executeCommand("sphere -e -r " + radius + " " + fluidParticleName);
                    }
                    else
                    {
                        MGlobal::executeCommand("delete " + fluid[i]);
                        fluid.set("", i);
                    }
                }
                else if (radiusVal > minRadius)
                {
                    fluid.set(fluidParticleName, i);
                    MGlobal::executeCommand("sphere -n " + fluidParticleName + " -r " + radius);
                    MGlobal::executeCommand("move -r " + pos);
                    MGlobal::executeCommand("select " + locatorName);
                    MGlobal::executeCommand("parent -a -s " + fluidParticleName);
                }
                MString temp = fluid[i];
            }
        }
    }
    //MGlobal::executeCommand("select " + locatorName);
	// Restore the selection list.
	MGlobal::setActiveSelectionList(previous_list);
}

// Clears fluid by deleting spheres and setting the desired size.
void FluidLocatorNode::resetFluid(MStringArray &fluid, int size)
{
    // If empty, just set the desired size.
    int length = fluid.length();
    if (length == 0)
    {
        fluid.setLength(size);
        return;
    }

    // If there are any elements, delete them.
    for (int i = 0; i < length; i++)
    {
        MString name = fluid[i];
        if (name != NULL || name.length() != 0 || name != "")
        {
            MGlobal::executeCommand("delete " + fluid[i]);
            fluid.set("", i);
        }
    }
    // Set the new size;
    fluid.setLength(size);
}
