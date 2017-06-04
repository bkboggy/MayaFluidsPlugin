#include "RootCreate.h"


const char* helpFlag = "-h";
const char* helpFlagLong = "-help";

const char* helpText = "This will create the root node for the Fluid Simulation domain.";

RootCreate::RootCreate() 
{
}

MStatus RootCreate::doIt(const MArgList& argList)
{
	MStatus status;
	
	MArgDatabase argData(syntax(), argList, &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	if (argData.isFlagSet(helpFlag))
	{
		setResult(helpText);
		return MS::kSuccess;
	}

	return redoIt();
}

MStatus RootCreate::redoIt()
{
	MStatus status;

	//get the currently selected objects to retore at end of this function
	MSelectionList previous_list;
	status = MGlobal::getActiveSelectionList(previous_list);

	MFnDependencyNode fn;
	fn.create(FrameReaderNode::id);
	fReaderName = fn.name();
	setResult(fReaderName); //what does this do?

	status = MGlobal::selectByName("time1", MGlobal::kReplaceList);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	MSelectionList sl;
	status = MGlobal::getActiveSelectionList(sl);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	MObject oTime;
	status = sl.getDependNode(0, oTime);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	MFnDependencyNode fnTime(oTime);
	MPlug outTime = fnTime.findPlug("outTime", &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	MPlug input = fn.findPlug("inValue", &status);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	MDagModifier dagMod; 
	dagMod.connect(outTime, input);
	status = dagMod.doIt();
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = MGlobal::setActiveSelectionList(previous_list);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	return MS::kSuccess;
}

MStatus RootCreate::undoIt()
{
	MStatus status;
	MSelectionList pl;

	status = MGlobal::getActiveSelectionList(pl);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	status = MGlobal::selectByName(fReaderName, MGlobal::kReplaceList);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	MGlobal::executeCommand("delete");

	status = MGlobal::setActiveSelectionList(pl);
	CHECK_MSTATUS_AND_RETURN_IT(status);

	return MS::kSuccess;
}

bool RootCreate::isUndoable() const 
{
	return true;
}

void* RootCreate::creator()
{
	return new RootCreate();
}

MSyntax RootCreate::newSyntax()
{
	MSyntax syntax;

	syntax.addFlag(helpFlag, helpFlagLong);

	return syntax;
}