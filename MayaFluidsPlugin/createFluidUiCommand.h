#ifndef CREATE_FLUID_UI_COMMAND
#define CREATE_FLUID_UI_COMMAND

#include <maya/MPxCommand.h>

// Creates UI for the fluid simulator.
class CreateFluidUiCommand : public MPxCommand
{
public:
    // Default constructor.
    CreateFluidUiCommand();
    // Executes the command.
    virtual MStatus doIt(const MArgList& argList);
    // Maya command creator method.
    static void* creator();
};

#endif
