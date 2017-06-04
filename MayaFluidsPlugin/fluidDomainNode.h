#ifndef FLUID_DOMAIN_NODE_H
#define FLUID_DOMAIN_NODE_H

#include <maya/MFloatArray.h>
#include <maya/MFnFloatArrayData.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnTypedAttribute.h>
#include <maya/MFnUnitAttribute.h>
#include <maya/MPxNode.h>

// Defines fluid domain in terms of velocity and
// density fields.
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

    // Outputs.
    static MObject aN;
    static MObject aDt;
    static MObject aDiff;
    static MObject aVisc;
    static MObject aForce;
    static MObject aSource;
    static MObject aX;
    static MObject aU;
    static MObject aV;
    static MObject aW;
};

#endif
