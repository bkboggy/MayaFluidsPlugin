#ifndef FLUID_SOLVER_NODE_H
#define FLUID_SOLVER_NODE_H

#include <maya/MFloatArray.h>
#include <maya/MFnFloatArrayData.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnTypedAttribute.h>
#include <maya/MFnUnitAttribute.h>
#include <maya/MTime.h>
#include <maya/MPxNode.h>

// Performs calculations on fluid domain in terms of
// velocity and density fields.
class FluidSolverNode : public MPxNode
{
public:
    // Default constructor.
    FluidSolverNode();
    // Destructor.
    virtual ~FluidSolverNode();
    // Maya API node creator.
    static void* creator();

    // Initializes node attributes.
    static MStatus initialize();
    // Performs node computation.
    virtual MStatus compute(const MPlug& plug, MDataBlock& data);
    
    // Fluid solver methods.
    void add_source(int N, float* x, float* s, float dt);
    void set_bnd(int N, int b, float* x);
    void lin_solve(int N, int b, float* x, float* x0, float a, float c);
    void diffuse(int N, int b, float* x, float* x0, float diff, float dt);
    void advect(int N, int b, float* d, float* d0, float* u, float* v, float* w, float dt);
    void project(int N, float* u, float* v, float* w, float* p, float* div);
    void dens_step(int N, float* x, float* x0, float* u, float* v, float* w, float diff, float dt);
    void vel_step(int N, float* u, float* v, float* u0, float* v0, float* w0, float visc, float dt);

    // Maya node ID.
    static MTypeId id;

    // Outputs.
    static MObject aX;
    static MObject aU;
    static MObject aV;
    static MObject aW;

    // Inputs.
    static MObject aTime;  
    static MObject aN;
    static MObject aDt;
    static MObject aDiff;
    static MObject aVisc;
    static MObject aForce;
    static MObject aSource;
    static MObject aX0;
    static MObject aU0;
    static MObject aV0;
    static MObject aW0;
};

#endif
