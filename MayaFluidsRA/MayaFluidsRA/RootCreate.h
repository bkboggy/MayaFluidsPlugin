#ifndef ROOTCREATE_H
#define ROOTCREATE_H

#include "FrameReaderNode.h"
#include "RootNode.h"
#include <maya/MPxCommand.h>
#include <maya/MSyntax.h>
#include <maya/MSelectionList.h>
#include <maya/MGlobal.h>
#include <maya/MFnDependencyNode.h>
#include <maya/MDagModifier.h>
#include <maya/MArgDatabase.h>

class RootCreate : public MPxCommand
{
public:
	RootCreate();
	virtual MStatus doIt(const MArgList& argList);
	virtual MStatus redoIt();
	virtual MStatus undoIt();
	virtual bool isUndoable() const;
	static void* creator();
	static MSyntax newSyntax();
private:
	MString rootName;
	MString fReaderName;
};
#endif