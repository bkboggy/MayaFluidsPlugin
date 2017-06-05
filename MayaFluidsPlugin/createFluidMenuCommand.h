#ifndef CREATE_FLUID_MENU_COMMAND
#define CREATE_FLUID_MENU_COMMAND

#include <fstream>
#include <sstream>
#include <string>
#include <maya/MGlobal.h>
#include <maya/MPxCommand.h>

// Creates a menu option at the top bar of the Maya Window for 
// the fluid simulator.
class CreateFluidMenuCommand : public MPxCommand
{
public:
    // Default constructor.
    CreateFluidMenuCommand();
    // Executes the command.
    virtual MStatus doIt(const MArgList& argList);
    // Maya command creator method.
    static void* creator();
};

#endif
