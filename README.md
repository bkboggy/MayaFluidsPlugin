# MayaFluidsPlugin

As a tip, use the following python script to load the plugin from any location:

```
import maya.cmds as cmds

pluginName = "MayaFluidsPlugin.mll"
pluginPath = "Your path goes here" + pluginName
loaded = cmds.pluginInfo(pluginName, query=True, loaded=True)
if loaded:
  cmds.unloadPlugin(pluginName)
cmds.loadPlugin(pluginPath)
```
