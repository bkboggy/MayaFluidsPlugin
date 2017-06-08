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
MObject FluidLocatorNode::aDomainOriginOut;
MObject FluidLocatorNode::aDomainHeightOut;
MObject FluidLocatorNode::aDomainWidthOut;
MObject FluidLocatorNode::aDomainLengthOut;
MObject FluidLocatorNode::aSourceOriginOut;
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
MObject FluidLocatorNode::aDomainOriginIn;
MObject FluidLocatorNode::aDomainHeightIn;
MObject FluidLocatorNode::aDomainWidthIn;
MObject FluidLocatorNode::aDomainLengthIn;
MObject FluidLocatorNode::aSourceOriginIn;
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

    aShowFluidIn = nAttr.create("showFluidIn", "showFluidIn", MFnNumericData::kBoolean, false);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aShowFluidIn);
    attributeAffects(aShowFluidIn, aShowFluidOut);
    attributeAffects(aShowFluidIn, aFluid);

    aShowVoxelsIn = nAttr.create("showVoxelsIn", "showVoxelsIn", MFnNumericData::kBoolean, false);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aShowVoxelsIn);
    attributeAffects(aShowVoxelsIn, aShowVoxelsOut);

    aVoxelAlphaIn = nAttr.create("voxelAlphaIn", "voxelAlphaIn", MFnNumericData::kFloat, 0.3f);
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

    aDomainOriginIn = nAttr.create("domainOriginIn", "domainOriginIn", MFnNumericData::k3Float);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainOriginIn);
    attributeAffects(aDomainOriginIn, aDomainOriginOut);
    attributeAffects(aDomainOriginIn, aSourceOriginOut);
    attributeAffects(aDomainOriginIn, aFluid);

    aDomainWidthIn = nAttr.create("domainWidthIn", "domainWidthIn", MFnNumericData::kFloat, 5.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainWidthIn);
    attributeAffects(aDomainWidthIn, aDomainWidthOut);
    attributeAffects(aDomainWidthIn, aSourceWidthOut);
    attributeAffects(aDomainWidthIn, aSourceOriginOut);
    attributeAffects(aDomainWidthIn, aFluid);

    aDomainHeightIn = nAttr.create("domainHeightIn", "domainHeightIn", MFnNumericData::kFloat, 5.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainHeightIn);
    attributeAffects(aDomainHeightIn, aDomainHeightOut);
    attributeAffects(aDomainHeightIn, aSourceHeightOut);
    attributeAffects(aDomainHeightIn, aSourceOriginOut);
    attributeAffects(aDomainHeightIn, aFluid);

    aDomainLengthIn = nAttr.create("domainLengthIn", "domainLengthIn", MFnNumericData::kFloat, 5.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aDomainLengthIn);
    attributeAffects(aDomainLengthIn, aDomainLengthOut);
    attributeAffects(aDomainLengthIn, aSourceLengthOut);
    attributeAffects(aDomainLengthIn, aSourceOriginOut);
    attributeAffects(aDomainLengthIn, aFluid);

    aSourceOriginIn = nAttr.create("sourceOriginIn", "sourceOriginIn", MFnNumericData::k3Float);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceOriginIn);
    attributeAffects(aSourceOriginIn, aSourceOriginOut);
    attributeAffects(aSourceOriginIn, aSourceHeightOut);
    attributeAffects(aSourceOriginIn, aSourceWidthOut);
    attributeAffects(aSourceOriginIn, aSourceLengthOut);
    attributeAffects(aSourceOriginIn, aFluid);

    aSourceWidthIn = nAttr.create("sourceWidthIn", "sourceWidthIn", MFnNumericData::kFloat, 5.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceWidthIn);
    attributeAffects(aSourceWidthIn, aSourceWidthOut);
    attributeAffects(aSourceWidthIn, aSourceOriginOut);
    attributeAffects(aSourceWidthIn, aFluid);

    aSourceHeightIn = nAttr.create("sourceHeightIn", "sourceHeightIn", MFnNumericData::kFloat, 5.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceHeightIn);
    attributeAffects(aSourceHeightIn, aSourceHeightOut);
    attributeAffects(aSourceHeightIn, aSourceOriginOut);
    attributeAffects(aSourceHeightIn, aFluid);

    aSourceLengthIn = nAttr.create("sourceLengthIn", "sourceLengthIn", MFnNumericData::kFloat, 5.0f);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aSourceLengthIn);
    attributeAffects(aSourceLengthIn, aSourceLengthOut);
    attributeAffects(aSourceLengthIn, aSourceOriginOut);
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
        plug != aDomainOriginOut &&
        plug != aDomainHeightOut &&
        plug != aDomainWidthOut &&
        plug != aDomainLengthOut &&
        plug != aSourceOriginOut &&
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

    float3& domainOrigin = data.inputValue(aDomainOriginIn, &status).asFloat3();
    CHECK_MSTATUS_AND_RETURN_IT(status);

	float domainHeight = data.inputValue(aDomainHeightIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

	float domainWidth = data.inputValue(aDomainWidthIn, &status).asFloat();
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
    float3& domainOriginOut = data.outputValue(aDomainOriginOut, &status).asFloat3();
    CHECK_MSTATUS_AND_RETURN_IT(status);
    float domainHeightOut = data.outputValue(aDomainHeightOut, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);
    float domainWidthOut = data.outputValue(aDomainWidthOut, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);
    float domainLengthOut = data.outputValue(aDomainLengthOut, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    // Compare the cached outputs with the inputs to see if any changes were made.  If there
    // were, clear the fluid. This is equivalent of the user adjusting the simluation, so there's 
    // a cost to pay. This may be optimized later on, if necessary.
    bool reset = false;
    if (voxelCountWidth != voxelCountWidthOut || voxelCountHeight != voxelCountHeightOut ||
        voxelCountLength != voxelCountLengthOut || domainWidth != domainWidthOut ||
        domainHeight != domainHeightOut || domainLength != domainLengthOut || 
        domainOrigin[0] != domainOriginOut[0] || domainOrigin[1] != domainOriginOut[1] ||
        domainOrigin[2] != domainOriginOut[2])
    {
        int size = voxelCountWidth*voxelCountHeight*voxelCountLength;
        Utilities::resetFluid(fluid, size);
    }

    // Simulate the fluid. Reset flag is passed in order to fascillitate reset of the fluid.
    // If there is any existing fluid, it'll be deleted.
    Utilities::simulateFluid(name, fluid, density, domainWidth, domainHeight, domainLength, 
        voxelCountWidth, voxelCountHeight, voxelCountLength);
 
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

	return MS::kSuccess;
}

void FluidLocatorNode::draw(M3dView& view, const MDagPath& DGpath, M3dView::DisplayStyle style, M3dView::DisplayStatus stat)
{
	MStatus status;
	float domainHeight;
	float domainWidth;
	float domainLength;
    int voxelCountWidth;
    int voxelCountHeight;
    int voxelCountLength;
    bool showVoxels;
    float voxelAlpha;

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

	MPlug valPlug = dFn.findPlug(aDomainHeightIn, &status);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to get height plug.");
		return;
	}
	status = valPlug.getValue(domainHeight);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to get height value.");
		return;
	}

	valPlug = dFn.findPlug(aDomainWidthIn, &status);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to get width plug.");
		return;
	}
	status = valPlug.getValue(domainWidth);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to get width value.");
		return;
	}

	valPlug = dFn.findPlug(aDomainLengthIn, &status);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to get length plug.");
		return;
	}
	status = valPlug.getValue(domainLength);
	if (status != MS::kSuccess)
	{
		MGlobal::displayError("Unable to get length value.");
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
                glVertex3f(wIncrement*i, 0, lIncrement*j);
                glVertex3f(wIncrement*i, domainHeight, lIncrement*j);

                glVertex3f(wIncrement*i, hIncrement*j, 0);
                glVertex3f(wIncrement*i, hIncrement*j, domainLength);

                glVertex3f(0, hIncrement*i, lIncrement*j);
                glVertex3f(domainWidth, hIncrement*i, lIncrement*j);
            }
        }
        glEnd();
    }
    else
    {
        glBegin(GL_LINE_LOOP);
        glVertex3f(0, 0, 0);
        glVertex3f(0, domainHeight, 0);
        glVertex3f(domainWidth, domainHeight, 0);
        glVertex3f(domainWidth, 0, 0);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glVertex3f(0, 0, domainLength);
        glVertex3f(0, domainHeight, domainLength);
        glVertex3f(domainWidth, domainHeight, domainLength);
        glVertex3f(domainWidth, 0, domainLength);
        glEnd();

        glBegin(GL_LINES);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, domainLength);

        glVertex3f(domainWidth, 0, 0);
        glVertex3f(domainWidth, 0, domainLength);

        glVertex3f(0, domainHeight, 0);
        glVertex3f(0, domainHeight, domainLength);

        glVertex3f(domainWidth, domainHeight, 0);
        glVertex3f(domainWidth, domainHeight, domainLength);
        glEnd();
    }

    glPopAttrib();
	view.endGL();
}
