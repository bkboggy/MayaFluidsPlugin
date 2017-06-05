#include "createFluidMenuCommand.h"

// Default constructor.
CreateFluidMenuCommand::CreateFluidMenuCommand()
{
}

// Executes the command.
MStatus CreateFluidMenuCommand::doIt(const MArgList& argList)
{
    MStatus status;

    MString pluginPath = MGlobal::executeCommandStringResult("pluginInfo -query -path MayaFluidsPlugin;");
    pluginPath.substitute("MayaFluidsPlugin.mll", "MayaFluidsPluginMenu.mel");

    std::string fileContent;
    std::ifstream file(pluginPath.asChar());
    if (file.is_open())
    {
        std::stringstream strStream;
        strStream << file.rdbuf();
        std::string cmdTextStr = strStream.str();
        const char* cmdTextCStr = cmdTextStr.c_str();
        MGlobal::executeCommand(cmdTextCStr);
        strStream.str("");
    }
    file.close();

    return MS::kSuccess;
}

// Maya command creator method.
void* CreateFluidMenuCommand::creator()
{
    return new CreateFluidMenuCommand;
}
