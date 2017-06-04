#ifndef INITIALIZE_DOMAIN_NODE_H
#define INITIALIZE_DOMAIN_NODE_H

#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnTypedAttribute.h>
#include <math.h>

class InitializeDomainNode : public MPxNode
{
public:
                    InitializeDomainNode();
    virtual         ~InitializeDomainNode();
    static void*    creator();

    static MStatus  initialize();
    virtual MStatus compute(const MPlug& plug, MDataBlock& data);
    
    static MTypeId  id;

    static MObject  aOrigin;
    static MObject  aWidth;
    static MObject  aHeight;
    static MObject  aN;
    static MObject  adt;
    static MObject  ax;

    static MObject  aLocator;
};

#endif
