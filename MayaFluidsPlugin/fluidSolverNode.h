#ifndef FLUID_SOLVER_NODE_H
#define FLUID_SOLVER_NODE_H

#include <maya/MFloatArray.h>
#include <maya/MFnFloatArrayData.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnTypedAttribute.h>
#include <maya/MFnUnitAttribute.h>
#include <maya/MTime.h>
#include <maya/MPxNode.h>
#include "utilities.h"

// Performs calculations on fluid domain in terms of velocity and density fields.
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
    
    // Adds source density.
    void add_source(int N, float* x, float* s, float dt);
    // Sets boundaries.
    void set_bnd(int N, int b, float* x);
    // Linear fluid solver.
    void lin_solve(int N, int b, float* x, float* x0, float a, float c);
    // Diffuses density.
    void diffuse(int N, int b, float* x, float* x0, float diff, float dt);
    // Advects density and velocity.
    void advect(int N, int b, float* d, float* d0, float* u, float* v, float* w, float dt);
    // Normalizes velocity.
    void project(int N, float* u, float* v, float* w, float* p, float* div);
    // Calculates new density.
    void dens_step(int voxelCountWidth, int voxelCountHeight, int voxelCountLength,
        float* x, float* x0, float* u, float* v, float* w, float diff, float dt);
    // Calculates new velocity.
    void vel_step(int voxelCountWidth, int voxelCountHeight, int voxelCountLength,
        float* u, float* v, float* u0, float* v0, float* w0, float visc, float dt);

    // Maya node ID.
    static MTypeId id;

    // Outputs.
    static MObject aDensity;            // New density field.
    static MObject aVelocityU;          // New u-component of velocity field.
    static MObject aVelocityV;          // New v-component of velocity field.
    static MObject aVelocityW;          // New w-component of velocity field.

    // Inputs.
    static MObject aTime;               // Simulation time (sec, frame, etc.).
    static MObject aVoxelCountWidth;    // Number of voxels.
    static MObject aVoxelCountHeight;
    static MObject aVoxelCountLength;
    static MObject aTimestep;           // Timestep.
    static MObject aDiffusionRate;      // Diffusion rate.
    static MObject aViscosity;          // Viscosity.
    static MObject aForceMultipler;     // Force multipler.
    static MObject aSourceMultiplier;   // Source multipler.
    static MObject aInitDensity;        // Previous density field.
    static MObject aInitVelocityU;      // Previous u-component of velocity field.
    static MObject aInitVelocityV;      // Previous v-component of velocity field.
    static MObject aInitVelocityW;      // Previous w-component of velocity field.
};

#endif
