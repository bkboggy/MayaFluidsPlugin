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

    static void createSpheres(MString locatorName, float length, float width, float height, int N, int M, int O);

    static void simulateFluid(MString locatorName, MStringArray sphereNames, MFloatArray density, float length, float width, float height, int N, int M, int O);
};

#endif
