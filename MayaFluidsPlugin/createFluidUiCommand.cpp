#include "createFluidUiCommand.h"

// Default constructor.
CreateFluidUiCommand::CreateFluidUiCommand()
{
}

// Executes the command.
MStatus CreateFluidUiCommand::doIt(const MArgList& argList)
{
    MStatus status;


    return MS::kSuccess;
}

// Maya command creator method.
void* CreateFluidUiCommand::creator()
{
    return new CreateFluidUiCommand();
}
