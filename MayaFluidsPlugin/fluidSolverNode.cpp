#include "fluidSolverNode.h"

// Maya node ID.
MTypeId FluidSolverNode::id(0x00000101);

// Outputs.
MObject FluidSolverNode::aDensityOut;
MObject FluidSolverNode::aVelocityUOut;
MObject FluidSolverNode::aVelocityVOut;
MObject FluidSolverNode::aVelocityWOut;
MObject FluidSolverNode::aVoxelCountWidthOut;
MObject FluidSolverNode::aVoxelCountHeightOut;
MObject FluidSolverNode::aVoxelCountLengthOut;

// Inputs.
MObject FluidSolverNode::aTimeIn;
MObject FluidSolverNode::aVoxelCountWidthIn;
MObject FluidSolverNode::aVoxelCountHeightIn;
MObject FluidSolverNode::aVoxelCountLengthIn;
MObject FluidSolverNode::aTimestepIn;
MObject FluidSolverNode::aDiffusionRateIn;
MObject FluidSolverNode::aViscosityIn;
MObject FluidSolverNode::aForceMultiplerIn;
MObject FluidSolverNode::aSourceMultiplierIn;
MObject FluidSolverNode::aDensityIn;
MObject FluidSolverNode::aVelocityUIn;
MObject FluidSolverNode::aVelocityVIn;
MObject FluidSolverNode::aVelocityWIn;
MObject FluidSolverNode::aActiveSourceIn;
MObject FluidSolverNode::aActiveSourceRateIn;
MObject FluidSolverNode::aSourceDensityIn;

// Default constructor.
FluidSolverNode::FluidSolverNode() {}

// Destructor.
FluidSolverNode::~FluidSolverNode() {}

// Maya API node creator.
void* FluidSolverNode::creator()
{
    return new FluidSolverNode();
}

// Initializes node attributes.
MStatus FluidSolverNode::initialize()
{
    // Status to be returned.
    MStatus status;

    // Attribute functions.
    MFnNumericAttribute nAttr;
    MFnTypedAttribute tAttr;
    MFnUnitAttribute uAttr;

    // Attributes.
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

    aTimeIn = uAttr.create("timeIn", "timeIn", MFnUnitAttribute::kTime);
    uAttr.setKeyable(true);
    addAttribute(aTimeIn);
    attributeAffects(aTimeIn, aDensityOut);
    attributeAffects(aTimeIn, aVelocityUOut);
    attributeAffects(aTimeIn, aVelocityVOut);
    attributeAffects(aTimeIn, aVelocityWOut);

    aVoxelCountWidthIn = nAttr.create("voxelCountWidthIn", "voxelCountWidthIn", MFnNumericData::kInt, 10);
    nAttr.setKeyable(true);
    addAttribute(aVoxelCountWidthIn);
    attributeAffects(aVoxelCountWidthIn, aVoxelCountWidthOut);
    attributeAffects(aVoxelCountWidthIn, aDensityOut);
    attributeAffects(aVoxelCountWidthIn, aVelocityUOut);
    attributeAffects(aVoxelCountWidthIn, aVelocityVOut);
    attributeAffects(aVoxelCountWidthIn, aVelocityWOut);

    aVoxelCountHeightIn = nAttr.create("voxelCountHeightIn", "voxelCountHeightIn", MFnNumericData::kInt, 10);
    nAttr.setKeyable(true);
    addAttribute(aVoxelCountHeightIn);
    attributeAffects(aVoxelCountHeightIn, aVoxelCountHeightOut);
    attributeAffects(aVoxelCountHeightIn, aDensityOut);
    attributeAffects(aVoxelCountHeightIn, aVelocityUOut);
    attributeAffects(aVoxelCountHeightIn, aVelocityVOut);
    attributeAffects(aVoxelCountHeightIn, aVelocityWOut);

    aVoxelCountLengthIn = nAttr.create("voxelCountLengthIn", "voxelCountLengthIn", MFnNumericData::kInt, 10);
    nAttr.setKeyable(true);
    addAttribute(aVoxelCountLengthIn);
    attributeAffects(aVoxelCountLengthIn, aVoxelCountLengthOut);
    attributeAffects(aVoxelCountLengthIn, aDensityOut);
    attributeAffects(aVoxelCountLengthIn, aVelocityUOut);
    attributeAffects(aVoxelCountLengthIn, aVelocityVOut);
    attributeAffects(aVoxelCountLengthIn, aVelocityWOut);

    aTimestepIn = nAttr.create("timestepIn", "timestepIn", MFnNumericData::kFloat, 0.001f);
    nAttr.setKeyable(true);
    addAttribute(aTimestepIn);
    attributeAffects(aTimestepIn, aDensityOut);
    attributeAffects(aTimestepIn, aVelocityUOut);
    attributeAffects(aTimestepIn, aVelocityVOut);
    attributeAffects(aTimestepIn, aVelocityWOut);

    aDiffusionRateIn = nAttr.create("diffusionRateIn", "diffusionRateIn", MFnNumericData::kFloat, 0.0f);
    nAttr.setKeyable(true);
    addAttribute(aDiffusionRateIn);
    attributeAffects(aDiffusionRateIn, aDensityOut);
    attributeAffects(aDiffusionRateIn, aVelocityUOut);
    attributeAffects(aDiffusionRateIn, aVelocityVOut);
    attributeAffects(aDiffusionRateIn, aVelocityWOut);

    aViscosityIn = nAttr.create("viscosityIn", "viscosityIn", MFnNumericData::kFloat, 0.0f);
    nAttr.setKeyable(true);
    addAttribute(aViscosityIn);
    attributeAffects(aViscosityIn, aDensityOut);
    attributeAffects(aViscosityIn, aVelocityUOut);
    attributeAffects(aViscosityIn, aVelocityVOut);
    attributeAffects(aViscosityIn, aVelocityWOut);

    aForceMultiplerIn = nAttr.create("forceMultiplierIn", "forceMultiplierIn", MFnNumericData::kFloat, 5.0f);
    nAttr.setKeyable(true);
    addAttribute(aForceMultiplerIn);
    attributeAffects(aForceMultiplerIn, aDensityOut);
    attributeAffects(aForceMultiplerIn, aVelocityUOut);
    attributeAffects(aForceMultiplerIn, aVelocityVOut);
    attributeAffects(aForceMultiplerIn, aVelocityWOut);

    aSourceMultiplierIn = nAttr.create("sourceMultiplierIn", "sourceMultiplierIn", MFnNumericData::kFloat, 200.0f);
    nAttr.setKeyable(true);
    addAttribute(aSourceMultiplierIn);
    attributeAffects(aSourceMultiplierIn, aDensityOut);
    attributeAffects(aSourceMultiplierIn, aVelocityUOut);
    attributeAffects(aSourceMultiplierIn, aVelocityVOut);
    attributeAffects(aSourceMultiplierIn, aVelocityWOut);

    aDensityIn = tAttr.create("densityIn", "densityIn", MFnData::kFloatArray);
    tAttr.setKeyable(true);
    addAttribute(aDensityIn);
    attributeAffects(aDensityIn, aDensityOut);

    aVelocityUIn = tAttr.create("velocityUIn", "velocityUIn", MFnData::kFloatArray);
    tAttr.setKeyable(true);
    addAttribute(aVelocityUIn);
    attributeAffects(aVelocityUIn, aVelocityUOut);
    attributeAffects(aVelocityUIn, aDensityOut);

    aVelocityVIn = tAttr.create("velocityVIn", "velocityVIn", MFnData::kFloatArray);
    tAttr.setKeyable(true);
    addAttribute(aVelocityVIn);
    attributeAffects(aVelocityVIn, aVelocityVOut);
    attributeAffects(aVelocityVIn, aDensityOut);

    aVelocityWIn = tAttr.create("velocityWIn", "velocityWIn", MFnData::kFloatArray);
    tAttr.setKeyable(true);
    addAttribute(aVelocityWIn);
    attributeAffects(aVelocityWIn, aVelocityWOut);
    attributeAffects(aVelocityWIn, aDensityOut);

    aActiveSourceIn = nAttr.create("activeSourceIn", "activeSourceIn", MFnNumericData::kBoolean, false);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aActiveSourceIn);
    attributeAffects(aActiveSourceIn, aDensityOut);
    attributeAffects(aActiveSourceIn, aVelocityUOut);
    attributeAffects(aActiveSourceIn, aVelocityVOut);
    attributeAffects(aActiveSourceIn, aVelocityWOut);

    aActiveSourceRateIn = nAttr.create("activeSourceRateIn", "activeSourceRateIn", MFnNumericData::kInt, 1);
    nAttr.setKeyable(true);
    nAttr.setWritable(true);
    addAttribute(aActiveSourceRateIn);
    attributeAffects(aActiveSourceIn, aDensityOut);
    attributeAffects(aActiveSourceIn, aVelocityUOut);
    attributeAffects(aActiveSourceIn, aVelocityVOut);
    attributeAffects(aActiveSourceIn, aVelocityWOut);

    aSourceDensityIn = tAttr.create("sourceDensityIn", "sourceDensityIn", MFnData::kFloatArray);
    tAttr.setKeyable(true);
    tAttr.setWritable(true);
    addAttribute(aSourceDensityIn);
    attributeAffects(aSourceDensityIn, aDensityOut);
    attributeAffects(aSourceDensityIn, aVelocityUOut);
    attributeAffects(aSourceDensityIn, aVelocityVOut);
    attributeAffects(aSourceDensityIn, aVelocityWOut);

    return MS::kSuccess;
}

// Perform node computations.
MStatus FluidSolverNode::compute(const MPlug& plug, MDataBlock& data)
{
    // Status to be returned.
    MStatus status;

    // Check if node is working on an appropriate plug.
    if (plug != aDensityOut && 
        plug != aVelocityUOut && 
        plug != aVelocityVOut &&
        plug != aVelocityWOut &&
        plug != aVoxelCountWidthOut &&
        plug != aVoxelCountHeightOut &&
        plug != aVoxelCountLengthOut)
    {
        return MS::kUnknownParameter;
    }

    double timeIn = data.inputValue(aTimeIn, &status).asDouble();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    int voxelCountWidthIn = data.inputValue(aVoxelCountWidthIn, &status).asInt();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    int voxelCountHeightIn = data.inputValue(aVoxelCountHeightIn, &status).asInt();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    int voxelCountLengthIn = data.inputValue(aVoxelCountLengthIn, &status).asInt();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    int voxelCountWidthOut = data.inputValue(aVoxelCountWidthOut, &status).asInt();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    int voxelCountHeightOut = data.inputValue(aVoxelCountHeightOut, &status).asInt();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    int voxelCountLengthOut = data.inputValue(aVoxelCountLengthOut, &status).asInt();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float timestep = data.inputValue(aTimestepIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float diffusionRate = data.inputValue(aDiffusionRateIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float viscocity = data.inputValue(aViscosityIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float forceMultiplier = data.inputValue(aForceMultiplerIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float sourceMultiplier = data.inputValue(aSourceMultiplierIn, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    // Get input density and velocity.
    MDataHandle dataHandle = data.inputValue(aDensityIn, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData densityInFnData(dataHandle.data());
    MFloatArray densityInArr = densityInFnData.array();

    dataHandle = data.inputValue(aVelocityUIn, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData velocityUInFnData(dataHandle.data());
    MFloatArray velocityUInArr = velocityUInFnData.array();

    dataHandle = data.inputValue(aVelocityVIn, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData velocityVInFnData(dataHandle.data());
    MFloatArray velocityVInArr = velocityVInFnData.array();

    dataHandle = data.inputValue(aVelocityWIn, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData velocityWInFnData(dataHandle.data());
    MFloatArray velocityWInArr = velocityWInFnData.array();

    dataHandle = data.outputValue(aDensityOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData densityFnCachedData(dataHandle.data());
    MFloatArray densityCachedArr = densityFnCachedData.array();
    float* densityCached = new float[densityCachedArr.length()];
    densityCachedArr.get(densityCached);

    dataHandle = data.outputValue(aVelocityUOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData velocityUFnCachedData(dataHandle.data());
    MFloatArray velocityUCachedArr = velocityUFnCachedData.array();

    dataHandle = data.outputValue(aVelocityVOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData velocityVFnCachedData(dataHandle.data());
    MFloatArray velocityVCachedArr = velocityVFnCachedData.array();

    dataHandle = data.outputValue(aVelocityWOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData velocityWFnCachedData(dataHandle.data());
    MFloatArray velocityWCachedArr = velocityWFnCachedData.array();

    // Add two in each dimension of size for solver boundaries.
    int size = (voxelCountWidthIn + 2) * (voxelCountHeightIn + 2) * (voxelCountLengthIn + 2);

    // Initial calculations (either previously cached or initial ones from the domain node).
    float* velocityU0 = new float[size];
    float* velocityV0 = new float[size];
    float* velocityW0 = new float[size];
    float* density0 = new float[size];     

    // Get minimum and current times.
    double mTime = MAnimControl::minTime().value();
    double cTime = MAnimControl::currentTime().value();

    // If this is an initial frame or voxel counts changed, use input information to setup ararys.
    if (mTime == cTime || voxelCountWidthOut != voxelCountWidthIn ||
        voxelCountHeightOut != voxelCountHeightIn || voxelCountLengthOut != voxelCountLengthIn)
    {
        // Copy information from input arrays.
        velocityUInArr.get(velocityU0);
        velocityVInArr.get(velocityV0);
        velocityWInArr.get(velocityW0);
        densityInArr.get(density0);

    }
    // Otherwise, use cached data.
    else
    {
        // Copy information from cached arrays.
        velocityUCachedArr.get(velocityU0);
        velocityVCachedArr.get(velocityV0);
        velocityWCachedArr.get(velocityW0);
        densityCachedArr.get(density0);
    }

    // New calculations (what is going to be used for the new output).
    float* velocityU = new float[size];
    float* velocityV = new float[size];
    float* velocityW = new float[size];
    float* density = new float[size];

    // Initialize new arrays with 0's.
    Utilities::initializeFloatArray(velocityU, size, 0.0f);
    Utilities::initializeFloatArray(velocityV, size, 0.0f);
    Utilities::initializeFloatArray(velocityW, size, 0.0f);
    Utilities::initializeFloatArray(density, size, 0.0f);

    if (mTime != cTime)
    {
        // Calculate new velocity.
        vel_step(voxelCountWidthIn, voxelCountHeightIn, voxelCountLengthIn, velocityU, velocityV, velocityW,
            velocityU0, velocityV0, velocityW0, viscocity, timestep);

        // Calculate new density.
        dens_step(voxelCountWidthIn, voxelCountHeightIn, voxelCountLengthIn, density, density0,
            velocityU, velocityV, velocityW, diffusionRate, timestep);
    }

    // Get output values.
    MFloatArray velocityUOut(velocityU, size);
    MFloatArray velocityVOut(velocityV, size);
    MFloatArray velocityWOut(velocityW, size);
    MFloatArray densityOut(density, size);

    // Pass new density and velocity fields as outputs.
    MDataHandle hOut = data.outputValue(aVelocityUOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData fnDataOut;
    MObject dataOut = (mTime != cTime) ? fnDataOut.create(velocityUOut, &status) : fnDataOut.create(velocityUInArr, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOut.set(dataOut);
    hOut.setClean();
    data.setClean(plug);

    hOut = data.outputValue(aVelocityVOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    dataOut = (mTime != cTime) ? fnDataOut.create(velocityVOut, &status) : fnDataOut.create(velocityVInArr, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOut.set(dataOut);
    hOut.setClean();
    data.setClean(plug);

    hOut = data.outputValue(aVelocityWOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    dataOut = (mTime != cTime) ? fnDataOut.create(velocityWOut, &status) : fnDataOut.create(velocityWInArr, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOut.set(dataOut);
    hOut.setClean();
    data.setClean(plug);

    hOut = data.outputValue(aDensityOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    dataOut = (mTime != cTime) ? fnDataOut.create(densityOut, &status) : fnDataOut.create(densityInArr, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOut.set(dataOut);
    hOut.setClean();
    data.setClean(plug);

    hOut = data.outputValue(aVoxelCountWidthOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOut.set(voxelCountWidthIn);
    hOut.setClean();
    data.setClean(plug);

    hOut = data.outputValue(aVoxelCountHeightOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOut.set(voxelCountHeightIn);
    hOut.setClean();
    data.setClean(plug);

    hOut = data.outputValue(aVoxelCountLengthOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOut.set(voxelCountLengthIn);
    hOut.setClean();
    data.setClean(plug);

    // Clean up.
    delete[] density0;
    delete[] density;
    delete[] velocityU0;
    delete[] velocityU;
    delete[] velocityV0;
    delete[] velocityV;
    delete[] velocityW0;
    delete[] velocityW;

    return MS::kSuccess;
}

// TODO: Get rid of macros.
#define IX(i,j,k) ((i)+(M+2)*(j) + (M+2)*(N+2)*(k))
#define SWAP(x0,x) {float * tmp=x0;x0=x;x=tmp;}
#define MAX(a,b)            (((a) > (b)) ? (a) : (b))
#define LINEARSOLVERTIMES 10

void FluidSolverNode::add_source(int M, int N, int O, float * x, float * s, float dt)
{
    int i, size = (M + 2)*(N + 2)*(O + 2);
    for (i = 0; i < size; i++)
    {
        x[i] += dt*s[i];
    }
}

void FluidSolverNode::set_bnd(int M, int N, int O, int b, float * x)
{
    // bounds are cells at faces of the cube
    int i, j;

    for (i = 1; i <= M; i++) {
        for (j = 1; j <= N; j++) {
            x[IX(i, j, 0)] = b == 3 ? -x[IX(i, j, 1)] : x[IX(i, j, 1)];
            x[IX(i, j, O + 1)] = b == 3 ? -x[IX(i, j, O)] : x[IX(i, j, O)];
        }
    }

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= O; j++) {
            x[IX(0, i, j)] = b == 1 ? -x[IX(1, i, j)] : x[IX(1, i, j)];
            x[IX(M + 1, i, j)] = b == 1 ? -x[IX(M, i, j)] : x[IX(M, i, j)];
        }
    }

    for (i = 1; i <= M; i++) {
        for (j = 1; j <= O; j++) {
            x[IX(i, 0, j)] = b == 2 ? -x[IX(i, 1, j)] : x[IX(i, 1, j)];
            x[IX(i, N + 1, j)] = b == 2 ? -x[IX(i, N, j)] : x[IX(i, N, j)];
        }
    }

    x[IX(0, 0, 0)] = 1.0 / 3.0*(x[IX(1, 0, 0)] + x[IX(0, 1, 0)] + x[IX(0, 0, 1)]);
    x[IX(0, N + 1, 0)] = 1.0 / 3.0*(x[IX(1, N + 1, 0)] + x[IX(0, N, 0)] + x[IX(0, N + 1, 1)]);

    x[IX(M + 1, 0, 0)] = 1.0 / 3.0*(x[IX(M, 0, 0)] + x[IX(M + 1, 1, 0)] + x[IX(M + 1, 0, 1)]);
    x[IX(M + 1, N + 1, 0)] = 1.0 / 3.0*(x[IX(M, N + 1, 0)] + x[IX(M + 1, N, 0)] + x[IX(M + 1, N + 1, 1)]);

    x[IX(0, 0, O + 1)] = 1.0 / 3.0*(x[IX(1, 0, O + 1)] + x[IX(0, 1, O + 1)] + x[IX(0, 0, O)]);
    x[IX(0, N + 1, O + 1)] = 1.0 / 3.0*(x[IX(1, N + 1, O + 1)] + x[IX(0, N, O + 1)] + x[IX(0, N + 1, O)]);

    x[IX(M + 1, 0, O + 1)] = 1.0 / 3.0*(x[IX(M, 0, O + 1)] + x[IX(M + 1, 1, O + 1)] + x[IX(M + 1, 0, O)]);
    x[IX(M + 1, N + 1, O + 1)] = 1.0 / 3.0*(x[IX(M, N + 1, O + 1)] + x[IX(M + 1, N, O + 1)] + x[IX(M + 1, N + 1, O)]);
}

void FluidSolverNode::lin_solve(int M, int N, int O, int b, float * x, float * x0, float a, float c)
{
    int i, j, k, l;

    // iterate the solver
    for (l = 0; l < LINEARSOLVERTIMES; l++) {
        // update for each cell
        for (i = 1; i <= M; i++) {
            for (j = 1; j <= N; j++) {
                for (k = 1; k <= O; k++) {
                    x[IX(i, j, k)] = (x0[IX(i, j, k)] + a*(x[IX(i - 1, j, k)] + x[IX(i + 1, j, k)] + x[IX(i, j - 1, k)] + x[IX(i, j + 1, k)] + x[IX(i, j, k - 1)] + x[IX(i, j, k + 1)])) / c;
                }
            }
        }
        set_bnd(M, N, O, b, x);
    }
}

void FluidSolverNode::diffuse(int M, int N, int O, int b, float * x, float * x0, float diff, float dt)
{
    int max = MAX(MAX(M, N), MAX(N, O));
    float a = dt*diff*max*max*max;
    lin_solve(M, N, O, b, x, x0, a, 1 + 6 * a);
}

void FluidSolverNode::advect(int M, int N, int O, int b, float * d, float * d0, float * u, float * v, float * w, float dt)
{
    int i, j, k, i0, j0, k0, i1, j1, k1;
    float x, y, z, s0, t0, s1, t1, u1, u0, dtx, dty, dtz;

    dtx = dty = dtz = dt*MAX(MAX(M, N), MAX(N, O));

    for (i = 1; i <= M; i++) {
        for (j = 1; j <= N; j++) {
            for (k = 1; k <= O; k++) {
                x = i - dtx*u[IX(i, j, k)]; y = j - dty*v[IX(i, j, k)]; z = k - dtz*w[IX(i, j, k)];
                if (x<0.5f) x = 0.5f; if (x>M + 0.5f) x = M + 0.5f; i0 = (int)x; i1 = i0 + 1;
                if (y<0.5f) y = 0.5f; if (y>N + 0.5f) y = N + 0.5f; j0 = (int)y; j1 = j0 + 1;
                if (z<0.5f) z = 0.5f; if (z>O + 0.5f) z = O + 0.5f; k0 = (int)z; k1 = k0 + 1;

                s1 = x - i0; s0 = 1 - s1; t1 = y - j0; t0 = 1 - t1; u1 = z - k0; u0 = 1 - u1;
                d[IX(i, j, k)] = s0*(t0*u0*d0[IX(i0, j0, k0)] + t1*u0*d0[IX(i0, j1, k0)] + t0*u1*d0[IX(i0, j0, k1)] + t1*u1*d0[IX(i0, j1, k1)]) +
                    s1*(t0*u0*d0[IX(i1, j0, k0)] + t1*u0*d0[IX(i1, j1, k0)] + t0*u1*d0[IX(i1, j0, k1)] + t1*u1*d0[IX(i1, j1, k1)]);
            }
        }
    }

    set_bnd(M, N, O, b, d);
}

void FluidSolverNode::project(int M, int N, int O, float * u, float * v, float * w, float * p, float * div)
{
    int i, j, k;

    for (i = 1; i <= M; i++) {
        for (j = 1; j <= N; j++) {
            for (k = 1; k <= O; k++) {
                div[IX(i, j, k)] = -1.0 / 3.0*((u[IX(i + 1, j, k)] - u[IX(i - 1, j, k)]) / M + (v[IX(i, j + 1, k)] - v[IX(i, j - 1, k)]) / M + (w[IX(i, j, k + 1)] - w[IX(i, j, k - 1)]) / M);
                p[IX(i, j, k)] = 0;
            }
        }
    }

    set_bnd(M, N, O, 0, div); set_bnd(M, N, O, 0, p);

    lin_solve(M, N, O, 0, p, div, 1, 6);

    for (i = 1; i <= M; i++) {
        for (j = 1; j <= N; j++) {
            for (k = 1; k <= O; k++) {
                u[IX(i, j, k)] -= 0.5f*M*(p[IX(i + 1, j, k)] - p[IX(i - 1, j, k)]);
                v[IX(i, j, k)] -= 0.5f*M*(p[IX(i, j + 1, k)] - p[IX(i, j - 1, k)]);
                w[IX(i, j, k)] -= 0.5f*M*(p[IX(i, j, k + 1)] - p[IX(i, j, k - 1)]);
            }
        }
    }

    set_bnd(M, N, O, 1, u); set_bnd(M, N, O, 2, v); set_bnd(M, N, O, 3, w);
}

void FluidSolverNode::dens_step(int M, int N, int O, float * x, float * x0, float * u, float * v, float * w, float diff, float dt)
{
    add_source(M, N, O, x, x0, dt);
    SWAP(x0, x); 
    diffuse(M, N, O, 0, x, x0, diff, dt);
    SWAP(x0, x); 
    advect(M, N, O, 0, x, x0, u, v, w, dt);
}

void FluidSolverNode::vel_step(int M, int N, int O, float * u, float * v, float * w, float * u0, float * v0, float * w0, float visc, float dt)
{
    add_source(M, N, O, u, u0, dt); 
    add_source(M, N, O, v, v0, dt); 
    add_source(M, N, O, w, w0, dt);
    SWAP(u0, u); 
    diffuse(M, N, O, 1, u, u0, visc, dt);
    SWAP(v0, v); 
    diffuse(M, N, O, 2, v, v0, visc, dt);
    SWAP(w0, w); 
    diffuse(M, N, O, 3, w, w0, visc, dt);
    project(M, N, O, u, v, w, u0, v0);
    SWAP(u0, u); 
    SWAP(v0, v); 
    SWAP(w0, w);
    advect(M, N, O, 1, u, u0, u0, v0, w0, dt); 
    advect(M, N, O, 2, v, v0, u0, v0, w0, dt); 
    advect(M, N, O, 3, w, w0, u0, v0, w0, dt);
    project(M, N, O, u, v, w, u0, v0);
}


/*   OLD CODE
// Fluid solver macros.
#define IX(i,j) ((i)+(N+2)*(j))
#define SWAP(x0,x) {float*  tmp=x0;x0=x;x=tmp;}
#define FOR_EACH_CELL for ( i=1 ; i<=N ; i++ ) { for ( j=1 ; j<=N ; j++ ) {
#define END_FOR }}

// Adds source density.
void FluidSolverNode::add_source(int N, float* x, float* s, float dt)
{
    int i, size = (N + 2)*(N + 2);
    for (i = 0; i < size; i++)
    {
        x[i] += dt*s[i];
    }
}

// Sets boundaries.
void FluidSolverNode::set_bnd(int N, int b, float* x)
{
    for (int i = 1; i <= N; i++)
    {
        x[IX(0, i)] = b == 1 ? -x[IX(1, i)] : x[IX(1, i)];
        x[IX(N + 1, i)] = b == 1 ? -x[IX(N, i)] : x[IX(N, i)];
        x[IX(i, 0)] = b == 2 ? -x[IX(i, 1)] : x[IX(i, 1)];
        x[IX(i, N + 1)] = b == 2 ? -x[IX(i, N)] : x[IX(i, N)];
    }
    x[IX(0, 0)] = 0.5f*(x[IX(1, 0)] + x[IX(0, 1)]);
    x[IX(0, N + 1)] = 0.5f*(x[IX(1, N + 1)] + x[IX(0, N)]);
    x[IX(N + 1, 0)] = 0.5f*(x[IX(N, 0)] + x[IX(N + 1, 1)]);
    x[IX(N + 1, N + 1)] = 0.5f*(x[IX(N, N + 1)] + x[IX(N + 1, N)]);
}

// Linear fluid solver.
void FluidSolverNode::lin_solve(int N, int b, float* x, float* x0, float a, float c)
{
    int i, j;

    for (int k = 0; k<20; k++)
    {
        FOR_EACH_CELL
            x[IX(i, j)] = (x0[IX(i, j)] + a*(x[IX(i - 1, j)] + x[IX(i + 1, j)] + x[IX(i, j - 1)] + x[IX(i, j + 1)])) / c;
        END_FOR
            set_bnd(N, b, x);
    }
}

// Diffuses density.
void FluidSolverNode::diffuse(int N, int b, float* x, float* x0, float diff, float dt)
{
    float a = dt*diff*N*N;
    lin_solve(N, b, x, x0, a, 1 + 4 * a);
}

// Advects density and velocity.
void FluidSolverNode::advect(int N, int b, float* d, float* d0, float* u, float* v, float* w, float dt)
{
    int i, j, i0, j0, i1, j1;
    float x, y, s0, t0, s1, t1, dt0;

    dt0 = dt*N;
    FOR_EACH_CELL
        x = i - dt0*u[IX(i, j)];
    y = j - dt0*v[IX(i, j)];
    if (x<0.5f) x = 0.5f;
    if (x>N + 0.5f) x = N + 0.5f;
    i0 = (int)x; i1 = i0 + 1;
    if (y<0.5f) y = 0.5f;
    if (y>N + 0.5f) y = N + 0.5f;
    j0 = (int)y; j1 = j0 + 1;
    s1 = x - i0; s0 = 1 - s1;
    t1 = y - j0; t0 = 1 - t1;
    d[IX(i, j)] = s0*(t0*d0[IX(i0, j0)] + t1*d0[IX(i0, j1)]) + s1*(t0*d0[IX(i1, j0)] + t1*d0[IX(i1, j1)]);
    END_FOR
        set_bnd(N, b, d);
}

// Normalizes velocity.
void FluidSolverNode::project(int N, float* u, float* v, float* w, float* p, float* div)
{
    int i, j;

    FOR_EACH_CELL
        div[IX(i, j)] = -0.5f*(u[IX(i + 1, j)] - u[IX(i - 1, j)] + v[IX(i, j + 1)] - v[IX(i, j - 1)]) / N;
    p[IX(i, j)] = 0;
    END_FOR
        set_bnd(N, 0, div); set_bnd(N, 0, p);

    lin_solve(N, 0, p, div, 1, 4);

    FOR_EACH_CELL
        u[IX(i, j)] -= 0.5f*N*(p[IX(i + 1, j)] - p[IX(i - 1, j)]);
    v[IX(i, j)] -= 0.5f*N*(p[IX(i, j + 1)] - p[IX(i, j - 1)]);
    END_FOR
        set_bnd(N, 1, u); set_bnd(N, 2, v);
}

// Calculates new density.
void FluidSolverNode::dens_step(int voxelCountWidth, int voxelCountHeight, int voxelCountLength,
    float* x, float* x0, float* u, float* v, float* w, float diff, float dt)
{
    //add_source(N, x, x0, dt);
    //SWAP(x0, x); 
    diffuse(voxelCountWidth, 0, x, x0, diff, dt);
    SWAP(x0, x);
    advect(voxelCountWidth, 0, x, x0, u, v, w, dt);
}

// Calculates new velocity.
void FluidSolverNode::vel_step(int voxelCountWidth, int voxelCountHeight, int voxelCountLength,
    float* u, float* v, float* w, float* u0, float* v0, float* w0, float visc, float dt)
{
    //add_source(N, u, u0, dt); 
    //add_source(N, v, v0, dt);
    SWAP(u0, u);
    diffuse(voxelCountWidth, 1, u, u0, visc, dt);
    SWAP(v0, v);
    diffuse(voxelCountWidth, 2, v, v0, visc, dt);
    project(voxelCountWidth, u, v, u0, v0, w0);
    SWAP(u0, u);
    SWAP(v0, v);
    advect(voxelCountWidth, 1, u, u0, u0, v0, w0, dt);
    advect(voxelCountWidth, 2, v, v0, u0, v0, w0, dt);
    project(voxelCountWidth, u, v, u0, v0, w0);
}
*/
