#ifndef GENERATE_FLUID_COMMAND_H
#define GENERATE_FLUID_COMMAND_H

#include "fluidTimeNode.h"
#include "fluidLocatorNode.h"
#include "fluidDomainNode.h"
#include "fluidSolverNode.h"
#include "utilities.h"
#include <maya/MPxCommand.h>
#include <maya/MSyntax.h>
#include <maya/MSelectionList.h>
#include <maya/MGlobal.h>
#include <maya/MFnDependencyNode.h>
#include <maya/MDagModifier.h>
#include <maya/MArgDatabase.h>
#include <maya/MDagPath.h>

// Generates fluid.
class GenerateFluidCommand : public MPxCommand
{
public:
    // Default constructor.
	GenerateFluidCommand();
    // Executes the command.
	virtual MStatus doIt(const MArgList& argList);
    // Attempts to restore previous execution of the command.
	virtual MStatus redoIt();
    // Attempts to undo actions completed by the command.
	virtual MStatus undoIt();
    // Flags indicating whether the command is undoable.
	virtual bool isUndoable() const;
    // Maya command creator method.
	static void* creator();
    // Command syntax.
	static MSyntax newSyntax();
private:
	// Used to store names of nodes created.
	MString fLocatorTransformName;
	MString fLocatorName;
	MString fTimeName;
	MString fDomainName;
	MString fSolverName;
};

#endif
