#include "fluidSolverNode.h"

// Fluid solver macros.
#define IX(i,j) ((i)+(N+2)*(j))
#define SWAP(x0,x) {float * tmp=x0;x0=x;x=tmp;}
#define FOR_EACH_CELL for ( i=1 ; i<=N ; i++ ) { for ( j=1 ; j<=N ; j++ ) {
#define END_FOR }}

// Maya node ID.
MTypeId FluidSolverNode::id;

// Outputs.
MObject FluidSolverNode::aX;
MObject FluidSolverNode::aU;
MObject FluidSolverNode::aV;
MObject FluidSolverNode::aW;

// Inputs.
MObject FluidSolverNode::aN;
MObject FluidSolverNode::aDt;
MObject FluidSolverNode::aDiff;
MObject FluidSolverNode::aVisc;
MObject FluidSolverNode::aForce;
MObject FluidSolverNode::aSource;
MObject FluidSolverNode::aX0;
MObject FluidSolverNode::aU0;
MObject FluidSolverNode::aV0;
MObject FluidSolverNode::aW0;

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
    MStatus status;
    MFnNumericAttribute nAttr;
    MFnTypedAttribute tAttr;

    // Outputs.
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

    // Inputs.
    aN = nAttr.create("N", "N", MFnNumericData::kInt, 20);
    nAttr.setKeyable(true);
    addAttribute(aN);
    attributeAffects(aN, aX);
    attributeAffects(aN, aU);
    attributeAffects(aN, aV);
    attributeAffects(aN, aW);

    aDt = nAttr.create("dt", "dt", MFnNumericData::kFloat, 0.0005f);
    nAttr.setKeyable(true);
    addAttribute(aDt);
    attributeAffects(aDt, aX);
    attributeAffects(aDt, aU);
    attributeAffects(aDt, aV);
    attributeAffects(aDt, aW);

    aDiff = nAttr.create("diff", "diff", MFnNumericData::kFloat, 0.0f);
    nAttr.setKeyable(true);
    addAttribute(aDiff);
    attributeAffects(aDiff, aX);
    attributeAffects(aDiff, aU);
    attributeAffects(aDiff, aV);
    attributeAffects(aDiff, aW);

    aVisc = nAttr.create("visc", "visc", MFnNumericData::kFloat, 0.0f);
    nAttr.setKeyable(true);
    addAttribute(aVisc);
    attributeAffects(aVisc, aX);
    attributeAffects(aVisc, aU);
    attributeAffects(aVisc, aV);
    attributeAffects(aVisc, aW);

    aForce = nAttr.create("force", "force", MFnNumericData::kFloat, 5.0f);
    nAttr.setKeyable(true);
    addAttribute(aForce);
    attributeAffects(aForce, aX);
    attributeAffects(aForce, aU);
    attributeAffects(aForce, aV);
    attributeAffects(aForce, aW);

    aSource = nAttr.create("source", "source", MFnNumericData::kFloat, 200.0f);
    nAttr.setKeyable(true);
    addAttribute(aSource);
    attributeAffects(aSource, aX);
    attributeAffects(aSource, aU);
    attributeAffects(aSource, aV);
    attributeAffects(aSource, aW);

    aX0 = tAttr.create("x0", "x0", MFnData::kFloatArray);
    tAttr.setKeyable(true);
    addAttribute(aX0);
    attributeAffects(aX0, aX);

    aU0 = tAttr.create("u0", "u0", MFnData::kFloatArray);
    tAttr.setKeyable(true);
    addAttribute(aU0);
    attributeAffects(aU0, aU);
    attributeAffects(aU0, aX);

    aV0 = tAttr.create("v0", "v0", MFnData::kFloatArray);
    tAttr.setKeyable(true);
    addAttribute(aV0);
    attributeAffects(aV0, aV);
    attributeAffects(aV0, aX);

    aW0 = tAttr.create("w0", "w0", MFnData::kFloatArray);
    tAttr.setKeyable(true);
    addAttribute(aW0);
    attributeAffects(aW0, aW);
    attributeAffects(aW0, aX);

    return MS::kSuccess;
}

// Performs node computation.
MStatus FluidSolverNode::compute(const MPlug& plug, MDataBlock& data)
{
    // Status to be returned.
    MStatus status;

    // Check if node is working on an appropriate plug.
    if (plug != aX && plug != aU && plug != aV && plug != aW)
    {
        return MS::kUnknownParameter;
    }

    // Initialize fluid calculation variables with default values.
    int N = data.inputValue(aN, &status).asInt();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float dt = data.inputValue(aDt, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float diff = data.inputValue(aDiff, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float visc = data.inputValue(aVisc, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float force = data.inputValue(aForce, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    float source = data.inputValue(aSource, &status).asFloat();
    CHECK_MSTATUS_AND_RETURN_IT(status);

    MDataHandle arrDataHandle = data.inputValue(aU0, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData u0FnData(arrDataHandle.data());
    MFloatArray u0Arr = u0FnData.array();
    unsigned int u0length = u0Arr.length();
    float *u0 = new float[u0length];
    float *u = new float[u0length];
    u0Arr.get(u0);
    u0Arr.get(u);

    arrDataHandle = data.inputValue(aV0, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData v0FnData(arrDataHandle.data());
    MFloatArray v0Arr = v0FnData.array();
    unsigned int v0length = v0Arr.length();
    float *v0 = new float[v0length];
    float *v = new float[v0length];
    v0Arr.get(v0);
    v0Arr.get(v);

    arrDataHandle = data.inputValue(aW0, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData w0FnData(arrDataHandle.data());
    MFloatArray w0Arr = w0FnData.array();
    unsigned int w0length = w0Arr.length();
    float *w0 = new float[w0length];
    float *w = new float[w0length];
    w0Arr.get(w0);
    w0Arr.get(w);

    arrDataHandle = data.inputValue(aX0, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData x0FnData(arrDataHandle.data());
    MFloatArray x0Arr = x0FnData.array();
    unsigned int x0length = x0Arr.length();
    float *x0 = new float[x0length];
    float *x = new float[x0length];
    x0Arr.get(x0);
    x0Arr.get(x);

    // Compute new density and velocity fields.
    vel_step(N, u, v, u0, v0, w0, visc, dt);
    dens_step(N, x, x0, u, v, w, diff, dt);

    // Get output values.
    MFloatArray uOut(u, u0length);
    MFloatArray vOut(v, v0length);
    MFloatArray wOut(w, w0length);
    MFloatArray xOut(x, x0length);

    // Pass new density and velocity fields as outputs.
    MDataHandle hOut = data.outputValue(aU, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MFnFloatArrayData fnDataOut;
    MObject dataOut = fnDataOut.create(uOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOut.set(dataOut);
    hOut.setClean();
    data.setClean(plug);

    hOut = data.outputValue(aV, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    dataOut = fnDataOut.create(vOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOut.set(dataOut);
    hOut.setClean();
    data.setClean(plug);

    hOut = data.outputValue(aW, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    dataOut = fnDataOut.create(wOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOut.set(dataOut);
    hOut.setClean();
    data.setClean(plug);

    hOut = data.outputValue(aX, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    dataOut = fnDataOut.create(xOut, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    hOut.set(dataOut);
    hOut.setClean();
    data.setClean(plug);

    return MS::kSuccess;
}

void FluidSolverNode::add_source(int N, float *x, float *s, float dt)
{
    int i, size = (N + 2)*(N + 2);
    for (i = 0; i < size; i++)
    {
        x[i] += dt*s[i];
    }
}

void FluidSolverNode::set_bnd(int N, int b, float *x)
{
    int i;

    for (i = 1; i <= N; i++) 
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

void FluidSolverNode::lin_solve(int N, int b, float *x, float *x0, float a, float c)
{
    int i, j, k;

    for (k = 0; k<20; k++) 
    {
        FOR_EACH_CELL
            x[IX(i, j)] = (x0[IX(i, j)] + a*(x[IX(i - 1, j)] + x[IX(i + 1, j)] + x[IX(i, j - 1)] + x[IX(i, j + 1)])) / c;
        END_FOR
            set_bnd(N, b, x);
    }
}

void FluidSolverNode::diffuse(int N, int b, float *x, float *x0, float diff, float dt)
{
    float a = dt*diff*N*N;
    lin_solve(N, b, x, x0, a, 1 + 4 * a);
}

void FluidSolverNode::advect(int N, int b, float *d, float *d0, float *u, float *v, float *w, float dt)
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

void FluidSolverNode::project(int N, float *u, float *v, float *w, float *p, float *div)
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

void FluidSolverNode::dens_step(int N, float *x, float *x0, float *u, float *v, float *w, float diff, float dt)
{
    add_source(N, x, x0, dt);
    SWAP(x0, x); 
    diffuse(N, 0, x, x0, diff, dt);
    SWAP(x0, x); 
    advect(N, 0, x, x0, u, v, w, dt);
}

void FluidSolverNode::vel_step(int N, float *u, float *v, float *u0, float *v0, float *w0, float visc, float dt)
{
    add_source(N, u, u0, dt); 
    add_source(N, v, v0, dt);
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
