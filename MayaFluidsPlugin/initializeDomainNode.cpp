#include "initializeDomainNode.h"

MTypeId InitializeDomainNode::id(0x00000030);

MObject InitializeDomainNode::aOrigin;
MObject InitializeDomainNode::aWidth;
MObject InitializeDomainNode::aHeight;
MObject InitializeDomainNode::aN;
MObject InitializeDomainNode::adt;
MObject InitializeDomainNode::ax;

MObject InitializeDomainNode::aLocator;

InitializeDomainNode::InitializeDomainNode() {}

InitializeDomainNode::~InitializeDomainNode() {}

void* InitializeDomainNode::creator()
{
    return new InitializeDomainNode();
}

MStatus InitializeDomainNode::initialize()
{
    MStatus status;
    MFnNumericAttribute nAttr;
    MFnTypedAttribute tAttr;

    aOrigin = tAttr.create("origin", "origin", MFnData::kPointArray);
    tAttr.setWritable(false);
    tAttr.setStorable(false);
    addAttribute(aOrigin);

    aWidth = nAttr.create("width", "width", MFnNumericData::kDouble);
    nAttr.setWritable(false);
    nAttr.setStorable(false);
    addAttribute(aWidth);

    aHeight = nAttr.create("height", "height", MFnNumericData::kDouble);
    nAttr.setWritable(false);
    nAttr.setStorable(false);
    addAttribute(aHeight);

    aN = nAttr.create("N", "N", MFnNumericData::kInt);
    tAttr.setKeyable(true);
    addAttribute(aN);

    adt = nAttr.create("dt", "dt", MFnNumericData::kDouble);
    tAttr.setKeyable(true);
    addAttribute(adt);

    ax = tAttr.create("x", "x", MFnData::kDoubleArray);
    tAttr.setWritable(false);
    tAttr.setStorable(false);
    addAttribute(ax);

    aLocator = tAttr.create("locator", "locator", MFnData::kNObject);
    tAttr.setKeyable(true);
    addAttribute(aLocator);
    attributeAffects(aLocator, aOrigin);
    attributeAffects(aLocator, aWidth);
    attributeAffects(aLocator, aHeight);
    attributeAffects(aLocator, ax);

    return MStatus::kSuccess;
}

MStatus InitializeDomainNode::compute(const MPlug& plug, MDataBlock& data)
{
    MStatus status;

    if (plug != aOrigin && plug != aWidth && plug != aHeight && 
        plug != aN && plug != adt && plug != ax)
    {
        return MS::kUnknownParameter;
    }

    

    return MS::kSuccess;
}
