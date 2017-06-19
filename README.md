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

Videos demonstrating results of this plugin may be found at:
https://www.youtube.com/watch?v=Yrc4ADP0xRs
https://www.youtube.com/watch?v=h7o_w0TVFBY
https://www.youtube.com/watch?v=rcVG6ZtEgWk
