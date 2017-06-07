#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <maya/MGlobal.h>
#include <maya/MString.h>

// A general utilities class.
class Utilities
{
public:
    // Initializes elements in a float array to the specified value.
    static void initializeFloatArray(float* arr, int size, float val);

	static void createSpheres(MString locatorName, float length, float width, float height, int N, int M, int O);
};

#endif
