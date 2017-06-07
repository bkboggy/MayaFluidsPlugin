#include "utilities.h"

// Initializes elements in a float array to the specified value.
void Utilities::initializeFloatArray(float* arr, int size, float val)
{
    if (arr == nullptr)
    {
        return;
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = val;
    }
}

void Utilities::createSpheres(MString locatorName, float length, float width, float height, int N, int M, int O)
{
	float x_offset = width / (float)N;
	float x_init = x_offset / 2.0f;
	float y_offset = height / (float)M;
	float y_init = x_offset / 2.0f;
	float z_offset = length / (float)O;
	float z_init = x_offset / 2.0f;
	float smallest = x_offset;
	if (y_offset < x_offset && y_offset < z_offset)
		smallest = y_offset;
	else if (z_offset < x_offset && z_offset < y_offset)
		smallest = z_offset;
	MString rr(std::to_string(smallest/10.0f).c_str());
	for (int i = 0; i < N; i++) {
		MString ii(std::to_string(i).c_str());
		MString xx(std::to_string(x_init + ((float)i * x_offset)).c_str());
		for (int j = 0; j < M; j++) {
			MString jj(std::to_string(j).c_str());
			MString yy(std::to_string(y_init + ((float)j * y_offset)).c_str());
			for (int k = 0; k < O; k++) {
				MString kk(std::to_string(k).c_str());
				MString zz(std::to_string(z_init + ((float)k * z_offset)).c_str());
				MGlobal::executeCommand("sphere -n fSphere_" + ii + "_" + jj + "_" + kk + " -r " + rr);
				MGlobal::executeCommand("move -r " + xx + " " + yy + " " + zz);
				MGlobal::executeCommand("select " + locatorName);
				MGlobal::executeCommand("parent -a -s fSphere_" + ii + "_" + jj + "_" + kk);
				MGlobal::executeCommand("setAttr \"fSphere_" + ii + "_" + jj + "_" + kk +"Shape.template\" 1");
			}
		}
	}
	MGlobal::executeCommand("select " + locatorName);
}
