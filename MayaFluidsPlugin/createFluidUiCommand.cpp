#include "createFluidUiCommand.h"

// Default constructor.
CreateFluidUiCommand::CreateFluidUiCommand()
{
}

// Executes the command.
MStatus CreateFluidUiCommand::doIt(const MArgList& argList)
{
    MStatus status;

    MString pluginPath = MGlobal::executeCommandStringResult("pluginInfo -query -path MayaFluidsPlugin;");
    pluginPath.substitute("MayaFluidsPlugin.mll", "MayaFluidsPluginUI.mel");

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
void* CreateFluidUiCommand::creator()
{
    return new CreateFluidUiCommand;
}
