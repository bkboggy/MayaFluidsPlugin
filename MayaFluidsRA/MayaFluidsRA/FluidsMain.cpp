#include "FrameReaderNode.h"
#include "RootCreate.h"
#include "RootNode.h"
#include <maya/MFnPlugin.h>

MStatus initializePlugin(MObject obj)
{
	MStatus status;

	MFnPlugin fnPlugin(obj, "Raymond Aceves", "1.0.0", "Any");

	status = fnPlugin.registerNode("fReader",
		FrameReaderNode::id,
		FrameReaderNode::creator,
		FrameReaderNode::initialize);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.registerNode("fd_Root",
		RootNode::id,
		RootNode::creator,
		RootNode::initialize,
		MPxNode::kLocatorNode);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.registerCommand("createFluidRoot",
		RootCreate::creator,
		RootCreate::newSyntax);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	return MS::kSuccess;
}

MStatus uninitializePlugin(MObject obj)
{
	MStatus status;

	MFnPlugin fnPlugin(obj);

	status = fnPlugin.deregisterNode(FrameReaderNode::id);

	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = fnPlugin.deregisterCommand("createFluidRoot");

	CHECK_MSTATUS_AND_RETURN_IT(status);

	return MS::kSuccess;
}