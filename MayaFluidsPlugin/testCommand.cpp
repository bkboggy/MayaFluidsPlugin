#include "testCommand.h"

TestCommand::TestCommand() {}

void* TestCommand::creator()
{
	return new TestCommand;
}

MStatus TestCommand::doIt(const MArgList& argList)
{
	MGlobal::displayInfo("Test message.");
	return MS::kSuccess;
}
