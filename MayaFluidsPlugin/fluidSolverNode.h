#ifndef FLUID_SOLVER_NODE_H
#define FLUID_SOLVER_NODE_H

#include <maya/MFloatArray.h>
#include <maya/MFnFloatArrayData.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnTypedAttribute.h>
#include <maya/MFnUnitAttribute.h>
#include <maya/MAnimControl.h>
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
    void add_source(int M, int N, int O, float * x, float * s, float dt);
    // Sets boundaries.
    void set_bnd(int M, int N, int O, int b, float * x);
    // Linear fluid solver.
    void lin_solve(int M, int N, int O, int b, float * x, float * x0, float a, float c);
    // Diffuses density.
    void diffuse(int M, int N, int O, int b, float * x, float * x0, float diff, float dt);
    // Advects density and velocity.
    void advect(int M, int N, int O, int b, float * d, float * d0, float * u, float * v, float * w, float dt);
    // Normalizes velocity.
    void project(int M, int N, int O, float * u, float * v, float * w, float * p, float * div);
    // Calculates new density.
    void dens_step(int M, int N, int O, float * x, float * x0, float * u, float * v, float * w, float diff, float dt);
    // Calculates new velocity.
    void vel_step(int M, int N, int O, float * u, float * v, float * w, float * u0, float * v0, float * w0, float visc, float dt);

    // Maya node ID.
    static MTypeId id;

    // Outputs.
    static MObject aDensityOut;           // New density field.
    static MObject aVelocityUOut;         // New u-component of velocity field.
    static MObject aVelocityVOut;         // New v-component of velocity field.
    static MObject aVelocityWOut;         // New w-component of velocity field.
    static MObject aVoxelCountWidthOut;    // Number of voxels.
    static MObject aVoxelCountHeightOut;
    static MObject aVoxelCountLengthOut;

    // Inputs.
    static MObject aTimeIn;               // Simulation time (sec, frame, etc.).
    static MObject aVoxelCountWidthIn;    // Number of voxels.
    static MObject aVoxelCountHeightIn;
    static MObject aVoxelCountLengthIn;
    static MObject aVelocityUIn;          // Previous u-component of velocity field.
    static MObject aVelocityVIn;          // Previous v-component of velocity field.
    static MObject aVelocityWIn;          // Previous w-component of velocity field.
    static MObject aDensityIn;            // Previous density field.
    static MObject aDiffusionRateIn;      // Diffusion rate.
    static MObject aTimestepIn;           // Timestep.
    static MObject aForceMultiplerIn;     // Force multipler.
    static MObject aSourceMultiplierIn;   // Source multipler.
    static MObject aViscosityIn;          // Viscosity.
};

#endif
