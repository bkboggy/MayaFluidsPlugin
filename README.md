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
<a href="http://www.youtube.com/watch?feature=player_embedded&v=Yrc4ADP0xRs
" target="_blank"><img src="http://img.youtube.com/vi/Yrc4ADP0xRs/0.jpg" 
alt="Result #1" width="240" height="180" border="10" /></a>


<a href="http://www.youtube.com/watch?feature=player_embedded&v=h7o_w0TVFBY
" target="_blank"><img src="http://img.youtube.com/vi/h7o_w0TVFBY/0.jpg" 
alt="Result #2" width="240" height="180" border="10" /></a>


<a href="http://www.youtube.com/watch?feature=player_embedded&v=rcVG6ZtEgWk
" target="_blank"><img src="http://img.youtube.com/vi/rcVG6ZtEgWk/0.jpg" 
alt="Result #3" width="240" height="180" border="10" /></a>
