#ifndef FLUID_DOMAIN_NODE_H
#define FLUID_DOMAIN_NODE_H

#include <maya/MFloatArray.h>
#include <maya/MFnFloatArrayData.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnTypedAttribute.h>
#include <maya/MFnUnitAttribute.h>
#include <maya/MPxNode.h>

// Defines fluid domain in terms of velocity and density fields.
class FluidDomainNode : public MPxNode
{
public:
    // Default constructor.
    FluidDomainNode();
    // Destructor.
    virtual ~FluidDomainNode();
    // Maya API node creator.
    static void* creator();

    // Initializes node attributes.
    static MStatus initialize();
    // Performs node computation.
    virtual MStatus compute(const MPlug& plug, MDataBlock& data);

    // Maya node ID.
    static MTypeId id;

    // Attributes.
    static MObject aVoxelCount;      // Number of voxels.
    static MObject aShowVoxels;        // Indicates whether voxels are shown.
    static MObject aTimestep;          // Timestep.
    static MObject aDiffusion;         // Diffusion rate.
    static MObject aViscosity;         // Viscosity.
    static MObject aForceMultiplier;   // Force multipler.
    static MObject aSourceMultiplier;  // Source multipler.
    static MObject aDensity;           // Density field.
    static MObject aVelocityU;         // U-component of velocity field.
    static MObject aVelocityV;         // V-component of velocity field.
    static MObject aVelocityW;         // W-component of velocity field.
    static MObject aWidth;             // Domain width.
    static MObject aHeight;            // Domain height.
    static MObject aLength;            // Domain length.
    static MObject aMinTime;           // Minimum time.
    static MObject aMaxTime;           // Maximum time.
    static MObject aTimeScale;         // Time scale.
    static MObject aVoxelAlpha;        // Voxel alpha channel.
};

#endif
