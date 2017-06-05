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
MObject FluidSolverNode::aVoxelCount;
MObject FluidSolverNode::aTimestep;
MObject FluidSolverNode::aDiffusion;
MObject FluidSolverNode::aViscosity;
MObject FluidSolverNode::aForceMultipler;
MObject FluidSolverNode::aSourceMultiplier;
MObject FluidSolverNode::aPrevDensity;
MObject FluidSolverNode::aPrevVelocityU;
MObject FluidSolverNode::aPrevVelocityV;
MObject FluidSolverNode::aPrevVelocityW;

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

    aVoxelCount = nAttr.create("voxelCount", "voxelCount", MFnNumericData::kInt, 10);
    nAttr.setKeyable(true);
    addAttribute(aVoxelCount);
    attributeAffects(aVoxelCount, aDensity);
    attributeAffects(aVoxelCount, aVelocityU);
    attributeAffects(aVoxelCount, aVelocityV);
    attributeAffects(aVoxelCount, aVelocityW);

    aTimestep = nAttr.create("timestep", "timestep", MFnNumericData::kFloat, 0.001f);
    nAttr.setKeyable(true);
    addAttribute(aTimestep);
    attributeAffects(aTimestep, aDensity);
    attributeAffects(aTimestep, aVelocityU);
    attributeAffects(aTimestep, aVelocityV);
    attributeAffects(aTimestep, aVelocityW);

    aDiffusion = nAttr.create("diffusion", "diffusion", MFnNumericData::kFloat, 0.0f);
    nAttr.setKeyable(true);
    addAttribute(aDiffusion);
    attributeAffects(aDiffusion, aDensity);
    attributeAffects(aDiffusion, aVelocityU);
    attributeAffects(aDiffusion, aVelocityV);
    attributeAffects(aDiffusion, aVelocityW);

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

    aPrevDensity = tAttr.create("prevDensity", "prevDensity", MFnData::kFloatArray, defaultArr);
    tAttr.setKeyable(true);
    addAttribute(aPrevDensity);
    attributeAffects(aPrevDensity, aDensity);

    aPrevVelocityU = tAttr.create("prevVelocityU", "preVelocityU", MFnData::kFloatArray, defaultArr);
    tAttr.setKeyable(true);
    addAttribute(aPrevVelocityU);
    attributeAffects(aPrevVelocityU, aVelocityU);
    attributeAffects(aPrevVelocityU, aDensity);

    aPrevVelocityV = tAttr.create("prevVelocityV", "prevVelocityV", MFnData::kFloatArray, defaultArr);
    tAttr.setKeyable(true);
    addAttribute(aPrevVelocityV);
    attributeAffects(aPrevVelocityV, aVelocityV);
    attributeAffects(aPrevVelocityV, aDensity);

    aPrevVelocityW = tAttr.create("prevVelocityW", "preVelocityW", MFnData::kFloatArray, defaultArr);
    tAttr.setKeyable(true);
    addAttribute(aPrevVelocityW);
    attributeAffects(aPrevVelocityW, aVelocityW);
    attributeAffects(aPrevVelocityW, aDensity);

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
    int N = data.inputValue(aVoxelCount, &status).asInt();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float dt = data.inputValue(aTimestep, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float diff = data.inputValue(aDiffusion, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float visc = data.inputValue(aViscosity, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float force = data.inputValue(aForceMultipler, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float source = data.inputValue(aSourceMultiplier, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    MDataHandle arrDataHandle = data.outputValue(aVelocityU, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData u0FnData(arrDataHandle.data());
    MFloatArray u0Arr = u0FnData.array();
    unsigned int u0length = u0Arr.length();
    float* u0 = new float[u0length];
    u0Arr.get(u0);
    float* u = new float[u0length];
    Utilities::initializeFloatArray(u, u0length, 0.0f);
    
    arrDataHandle = data.outputValue(aVelocityV, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData v0FnData(arrDataHandle.data());
    MFloatArray v0Arr = v0FnData.array();
    unsigned int v0length = v0Arr.length();
    float* v0 = new float[v0length];
    v0Arr.get(v0);
    float* v = new float[v0length];
    Utilities::initializeFloatArray(v, v0length, 0.0f);

    arrDataHandle = data.outputValue(aVelocityW, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData w0FnData(arrDataHandle.data());
    MFloatArray w0Arr = w0FnData.array();
    unsigned int w0length = w0Arr.length();
    float* w0 = new float[w0length];
    w0Arr.get(w0);
    float* w = new float[w0length];
    Utilities::initializeFloatArray(w, w0length, 0.0f);

    arrDataHandle = data.outputValue(aDensity, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData x0FnData(arrDataHandle.data());
    MFloatArray x0Arr = x0FnData.array();
    unsigned int x0length = x0Arr.length();
    float* x0 = new float[x0length];
    x0Arr.get(x0);
    float* x = new float[x0length];
    Utilities::initializeFloatArray(x, x0length, 0.0f);

    // Compute new density and velocity fields.
    if (N > 0 && x0length > 0 && u0length > 0 && v0length > 0 && w0length > 0)
    {
        vel_step(N, u, v, u0, v0, w0, visc, dt);
        dens_step(N, x, x0, u, v, w, diff, dt);
    }

    // Get output values.
    MFloatArray uOut(u, u0length);
    MFloatArray vOut(v, v0length);
    MFloatArray wOut(w, w0length);
    MFloatArray xOut(x, x0length);

    // Pass new density and velocity fields as outputs.
    MDataHandle hOut = data.outputValue(aVelocityU, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData fnDataOut;
    MObject dataOut = fnDataOut.create(uOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOut.set(dataOut);
    hOut.setClean();
    data.setClean(plug);

    hOut = data.outputValue(aVelocityV, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    dataOut = fnDataOut.create(vOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOut.set(dataOut);
    hOut.setClean();
    data.setClean(plug);

    hOut = data.outputValue(aVelocityW, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    dataOut = fnDataOut.create(wOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOut.set(dataOut);
    hOut.setClean();
    data.setClean(plug);

    hOut = data.outputValue(aDensity, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    dataOut = fnDataOut.create(xOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOut.set(dataOut);
    hOut.setClean();
    data.setClean(plug);

    // Clean up.
    delete[] x;
    delete[] u;
    delete[] v;
    delete[] w;

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
void FluidSolverNode::dens_step(int N, float* x, float* x0, float* u, float* v, float* w, float diff, float dt)
{
    //add_source(N, x, x0, dt);
    //SWAP(x0, x); 
    diffuse(N, 0, x, x0, diff, dt);
    SWAP(x0, x); 
    advect(N, 0, x, x0, u, v, w, dt);
}

// Calculates new velocity.
void FluidSolverNode::vel_step(int N, float* u, float* v, float* u0, float* v0, float* w0, float visc, float dt)
{
    //add_source(N, u, u0, dt); 
    //add_source(N, v, v0, dt);
    SWAP(u0, u); 
    diffuse(N, 1, u, u0, visc, dt);
    SWAP(v0, v); 
    diffuse(N, 2, v, v0, visc, dt);
    project(N, u, v, u0, v0, w0);
    SWAP(u0, u); 
    SWAP(v0, v);
    advect(N, 1, u, u0, u0, v0, w0, dt); 
    advect(N, 2, v, v0, u0, v0, w0, dt);
    project(N, u, v, u0, v0, w0);
}
