/*
Example from Maya 2017 devkit
will be modified to work with our project
*/


#ifndef MULTISPHERENODE_H
#define MULTISPHERENODE_H

#include <string.h>
#include <maya/MIOStream.h>
#include <math.h>
#include <maya/MPxNode.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MFnTypedAttribute.h>
#include <maya/MFnNurbsCurve.h>
#include <maya/MFnNurbsCurveData.h>
#include <maya/MString.h>
#include <maya/MTypeId.h>
#include <maya/MPlug.h>
#include <maya/MPointArray.h>
#include <maya/MDataBlock.h>
#include <maya/MDataHandle.h>
#include <maya/MArrayDataHandle.h>
#include <maya/MArrayDataBuilder.h>
class multiSphereNode : public MPxNode
{
public:
	multiSphereNode() {};
	virtual             ~multiSphereNode();
	virtual MStatus     compute(const MPlug& plug, MDataBlock& data);
	static  void*       creator();
	static  MStatus     initialize();
public:
	static  MObject     inputCurve;
	static  MObject     outputCurves;
	static  MObject     numCurves;
	static  MObject     curveOffset;
	static  MTypeId     id;
};

#endif
