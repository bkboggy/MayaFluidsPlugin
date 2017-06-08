#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <maya/MFloatArray.h>
#include <maya/MGlobal.h>
#include <maya/MString.h>
#include <maya/MStringArray.h>

// A general utilities class.
class Utilities
{
public:
    // Initializes elements in a float array to the specified value.
    static void initializeFloatArray(float* arr, int size, float val);

    static void simulateFluid(MString locatorName, MStringArray &fluid, MFloatArray &density,
        float domainWidth, float domainHeight, float domainLength, int voxelCountWidth, int voxelCountHeight , int voxelCountLength);
};

#endif
