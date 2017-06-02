#ifndef TESTCOMMAND_H
#define TESTCOMMAND_H

#include <maya/MPxCommand.h>
#include <maya/MGlobal.h>
#include <maya/MObject.h>

class TestCommand : public MPxCommand
{
public:
	TestCommand();
	virtual MStatus doIt(const MArgList& argList);
	static void* creator();
};

#endif
