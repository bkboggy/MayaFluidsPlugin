#include "fluidSolverNode.h"

// Maya node ID.
MTypeId FluidSolverNode::id(0x00000101);

// Outputs.
MObject FluidSolverNode::aDensity;
MObject FluidSolverNode::aVelocityU;
MObject FluidSolverNode::aVelocityV;
MObject FluidSolverNode::aVelocityW;

// Inputs.
MObject FluidSolverNode::aTime;
MObject FluidSolverNode::aVoxelCountWidth;
MObject FluidSolverNode::aTimestep;
MObject FluidSolverNode::aDiffusionRate;
MObject FluidSolverNode::aViscosity;
MObject FluidSolverNode::aForceMultipler;
MObject FluidSolverNode::aSourceMultiplier;
MObject FluidSolverNode::aInitDensity;
MObject FluidSolverNode::aInitVelocityU;
MObject FluidSolverNode::aInitVelocityV;
MObject FluidSolverNode::aInitVelocityW;

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

    aTime = uAttr.create("time", "time", MFnUnitAttribute::kTime);
    uAttr.setKeyable(true);
    addAttribute(aTime);
    attributeAffects(aTime, aDensity);
    attributeAffects(aTime, aVelocityU);
    attributeAffects(aTime, aVelocityV);
    attributeAffects(aTime, aVelocityW);

    aVoxelCountWidth = nAttr.create("voxelCountWidth", "voxelCountWidth", MFnNumericData::kInt, 10);
    nAttr.setKeyable(true);
    addAttribute(aVoxelCountWidth);
    attributeAffects(aVoxelCountWidth, aDensity);
    attributeAffects(aVoxelCountWidth, aVelocityU);
    attributeAffects(aVoxelCountWidth, aVelocityV);
    attributeAffects(aVoxelCountWidth, aVelocityW);

    aVoxelCountHeight = nAttr.create("voxelCountHeight", "voxelCountHeight", MFnNumericData::kInt, 10);
    nAttr.setKeyable(true);
    addAttribute(aVoxelCountHeight);
    attributeAffects(aVoxelCountHeight, aDensity);
    attributeAffects(aVoxelCountHeight, aVelocityU);
    attributeAffects(aVoxelCountHeight, aVelocityV);
    attributeAffects(aVoxelCountHeight, aVelocityW);

    aVoxelCountLength = nAttr.create("voxelCountLength", "voxelCountLength", MFnNumericData::kInt, 10);
    nAttr.setKeyable(true);
    addAttribute(aVoxelCountLength);
    attributeAffects(aVoxelCountLength, aDensity);
    attributeAffects(aVoxelCountLength, aVelocityU);
    attributeAffects(aVoxelCountLength, aVelocityV);
    attributeAffects(aVoxelCountLength, aVelocityW);

    aTimestep = nAttr.create("timestep", "timestep", MFnNumericData::kFloat, 0.001f);
    nAttr.setKeyable(true);
    addAttribute(aTimestep);
    attributeAffects(aTimestep, aDensity);
    attributeAffects(aTimestep, aVelocityU);
    attributeAffects(aTimestep, aVelocityV);
    attributeAffects(aTimestep, aVelocityW);

    aDiffusionRate = nAttr.create("diffusionRate", "diffusionRate", MFnNumericData::kFloat, 0.0f);
    nAttr.setKeyable(true);
    addAttribute(aDiffusionRate);
    attributeAffects(aDiffusionRate, aDensity);
    attributeAffects(aDiffusionRate, aVelocityU);
    attributeAffects(aDiffusionRate, aVelocityV);
    attributeAffects(aDiffusionRate, aVelocityW);

    aViscosity = nAttr.create("viscosity", "viscosity", MFnNumericData::kFloat, 0.0f);
    nAttr.setKeyable(true);
    addAttribute(aViscosity);
    attributeAffects(aViscosity, aDensity);
    attributeAffects(aViscosity, aVelocityU);
    attributeAffects(aViscosity, aVelocityV);
    attributeAffects(aViscosity, aVelocityW);

    aForceMultipler = nAttr.create("forceMultiplier", "forceMultiplier", MFnNumericData::kFloat, 5.0f);
    nAttr.setKeyable(true);
    addAttribute(aForceMultipler);
    attributeAffects(aForceMultipler, aDensity);
    attributeAffects(aForceMultipler, aVelocityU);
    attributeAffects(aForceMultipler, aVelocityV);
    attributeAffects(aForceMultipler, aVelocityW);

    aSourceMultiplier = nAttr.create("sourceMultiplier", "sourceMultiplier", MFnNumericData::kFloat, 200.0f);
    nAttr.setKeyable(true);
    addAttribute(aSourceMultiplier);
    attributeAffects(aSourceMultiplier, aDensity);
    attributeAffects(aSourceMultiplier, aVelocityU);
    attributeAffects(aSourceMultiplier, aVelocityV);
    attributeAffects(aSourceMultiplier, aVelocityW);

    MFloatArray defaultMArr(100, 0.0f);
    MFnFloatArrayData fnDefaultMArr;
    MFnData defaultArrData = fnDefaultMArr.create(defaultMArr, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MObject defaultArr = defaultArrData.object();

    aInitDensity = tAttr.create("prevDensity", "prevDensity", MFnData::kFloatArray, defaultArr);
    tAttr.setKeyable(true);
    addAttribute(aInitDensity);
    attributeAffects(aInitDensity, aDensity);

    aInitVelocityU = tAttr.create("prevVelocityU", "preVelocityU", MFnData::kFloatArray, defaultArr);
    tAttr.setKeyable(true);
    addAttribute(aInitVelocityU);
    attributeAffects(aInitVelocityU, aVelocityU);
    attributeAffects(aInitVelocityU, aDensity);

    aInitVelocityV = tAttr.create("prevVelocityV", "prevVelocityV", MFnData::kFloatArray, defaultArr);
    tAttr.setKeyable(true);
    addAttribute(aInitVelocityV);
    attributeAffects(aInitVelocityV, aVelocityV);
    attributeAffects(aInitVelocityV, aDensity);

    aInitVelocityW = tAttr.create("prevVelocityW", "preVelocityW", MFnData::kFloatArray, defaultArr);
    tAttr.setKeyable(true);
    addAttribute(aInitVelocityW);
    attributeAffects(aInitVelocityW, aVelocityW);
    attributeAffects(aInitVelocityW, aDensity);

    return MS::kSuccess;
}

// Perform node computations.
MStatus FluidSolverNode::compute(const MPlug& plug, MDataBlock& data)
{
    // Status to be returned.
    MStatus status;

    // Check if node is working on an appropriate plug.
    if (plug != aDensity && plug != aVelocityU && plug != aVelocityV && plug != aVelocityW)
    {
        return MS::kUnknownParameter;
    }

    // Initialize fluid calculation variables with default values.
    int voxelCountWidth = data.inputValue(aVoxelCountWidth, &status).asInt();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    int voxelCountHeight = data.inputValue(aVoxelCountHeight, &status).asInt();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    int voxelCountLength = data.inputValue(aVoxelCountLength, &status).asInt();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float timestep = data.inputValue(aTimestep, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float diffusionRate = data.inputValue(aDiffusionRate, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float viscocity = data.inputValue(aViscosity, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float forceMultiplier = data.inputValue(aForceMultipler, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float sourceMultiplier = data.inputValue(aSourceMultiplier, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    // TODO: Get input velocity and density values and decide when to use them
    //       as init or when to use previous out values.
    //       Replace C++ arrays with Maya arrays within Stam's algorithm.

    MDataHandle arrDataHandle = data.outputValue(aVelocityU, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData initVelocityUFnData(arrDataHandle.data());
    MFloatArray initVelocityUArr = initVelocityUFnData.array();
    unsigned int initVelocityUlength = initVelocityUArr.length();
    float* initVelocityU = new float[initVelocityUlength];
    initVelocityUArr.get(initVelocityU);
    float* velocityU = new float[initVelocityUlength];
    Utilities::initializeFloatArray(velocityU, initVelocityUlength, 0.0f);
    
    arrDataHandle = data.outputValue(aVelocityV, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData initVelocityVFnData(arrDataHandle.data());
    MFloatArray initVelocityVArr = initVelocityVFnData.array();
    unsigned int initVelocityVlength = initVelocityVArr.length();
    float* initVelocityV = new float[initVelocityVlength];
    initVelocityVArr.get(initVelocityV);
    float* velocityV = new float[initVelocityVlength];
    Utilities::initializeFloatArray(velocityV, initVelocityVlength, 0.0f);

    arrDataHandle = data.outputValue(aVelocityW, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData initVelocityWFnData(arrDataHandle.data());
    MFloatArray initVelocityWArr = initVelocityWFnData.array();
    unsigned int initVelocityWlength = initVelocityWArr.length();
    float* initVelocityW = new float[initVelocityWlength];
    initVelocityWArr.get(initVelocityW);
    float* velocityW = new float[initVelocityWlength];
    Utilities::initializeFloatArray(velocityW, initVelocityWlength, 0.0f);

    arrDataHandle = data.outputValue(aDensity, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData initDensityFnData(arrDataHandle.data());
    MFloatArray initDensityArr = initDensityFnData.array();
    unsigned int initDensitylength = initDensityArr.length();
    float* initDensity = new float[initDensitylength];
    initDensityArr.get(initDensity);
    float* density = new float[initDensitylength];
    Utilities::initializeFloatArray(density, initDensitylength, 0.0f);

    // TODO: Check this step to see if the logic is appropriate with new code.
    // Compute new density and velocity fields.
    if (voxelCountWidth > 0 && voxelCountHeight > 0 && voxelCountLength > 00 && initDensitylength > 0 && 
        initVelocityUlength > 0 && initVelocityVlength > 0 && initVelocityWlength > 0)
    {
        vel_step(voxelCountWidth, voxelCountHeight, voxelCountLength, 
            velocityU, velocityV, initVelocityU, initVelocityV, initVelocityW, viscocity, timestep);
        dens_step(voxelCountWidth, voxelCountHeight, voxelCountLength, density, initDensity, 
            velocityU, velocityV, velocityW, diffusionRate, timestep);
    }

    // Get output values.
    MFloatArray velocityUOut(velocityU, initVelocityUlength);
    MFloatArray velocityVOut(velocityV, initVelocityVlength);
    MFloatArray velocityWOut(velocityW , initVelocityWlength);
    MFloatArray densityOut(density, initDensitylength);

    // Pass new density and velocity fields as outputs.
    MDataHandle hOut = data.outputValue(aVelocityU, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData fnDataOut;
    MObject dataOut = fnDataOut.create(velocityUOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOut.set(dataOut);
    hOut.setClean();
    data.setClean(plug);

    hOut = data.outputValue(aVelocityV, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    dataOut = fnDataOut.create(velocityVOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOut.set(dataOut);
    hOut.setClean();
    data.setClean(plug);

    hOut = data.outputValue(aVelocityW, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    dataOut = fnDataOut.create(velocityWOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOut.set(dataOut);
    hOut.setClean();
    data.setClean(plug);

    hOut = data.outputValue(aDensity, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    dataOut = fnDataOut.create(densityOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOut.set(dataOut);
    hOut.setClean();
    data.setClean(plug);

    // Clean up.
    delete[] initDensity;
    delete[] density;
    delete[] initVelocityU;
    delete[] velocityU;
    delete[] initVelocityV;
    delete[] velocityV;
    delete[] initVelocityW;
    delete[] velocityW;

    return MS::kSuccess;
}

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
    lin_solve(N, b, x, x0, a, 1 + 4*  a);
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
    float* u, float* v, float* u0, float* v0, float* w0, float visc, float dt)
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
