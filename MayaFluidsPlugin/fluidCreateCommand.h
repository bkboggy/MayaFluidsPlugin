#ifndef FLUIDCREATECOMMAND_H
#define FLUIDCREATECOMMAND_H

#include "fluidTimeNode.h"
#include "fluidLocatorNode.h"
#include "fluidDomainNode.h"
#include "fluidSolverNode.h"
#include <maya/MPxCommand.h>
#include <maya/MSyntax.h>
#include <maya/MSelectionList.h>
#include <maya/MGlobal.h>
#include <maya/MFnDependencyNode.h>
#include <maya/MDagModifier.h>
#include <maya/MArgDatabase.h>
#include <maya/MDagPath.h>

class FluidCreateCommand : public MPxCommand
{
public:
	FluidCreateCommand();
	virtual MStatus doIt(const MArgList& argList);
	virtual MStatus redoIt();
	virtual MStatus undoIt();
	virtual bool isUndoable() const;
	static void* creator();
	static MSyntax newSyntax();
private:
	//used to store names of nodes created
	MString fLocatorTransformName;
	MString fLocatorName;
	MString fTimeName;
	MString fDomainName;
	MString fSolverName;
};
#endif