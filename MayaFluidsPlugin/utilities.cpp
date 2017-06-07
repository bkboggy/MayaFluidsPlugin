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
    {
        smallest = y_offset;
    }
    else if (z_offset < x_offset && z_offset < y_offset)
    {
        smallest = z_offset;
    }

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

void Utilities::simulateFluid(MString locatorName, MStringArray &sphereNames, MFloatArray &density, float width, float height, float length, int N, int M, int O)
{
    float x_offset = width / N;
    float x_init = x_offset / 2;
    float y_offset = height / M;
    float y_init = x_offset / 2;
    float z_offset = length / O;
    float z_init = x_offset / 2;
   
    float smallest = std::fminf(std::fminf(x_offset, y_offset), z_offset);

    for (int x = 0; x < N; x++) {
        MString x_name(std::to_string(x).c_str());
        MString x_pos(std::to_string(x_init + ((float)x * x_offset)).c_str());
        for (int y = 0; y < M; y++) {
            MString y_name(std::to_string(y).c_str());
            MString y_pos(std::to_string(y_init + ((float)y * y_offset)).c_str());
            for (int z = 0; z < O; z++) {
                int i = x + N * (y + O * z);
                MString z_name(std::to_string(z).c_str());
                MString z_pos(std::to_string(z_init + ((float)z * z_offset)).c_str());
                MString pos = x_pos + " " + y_pos + " " + z_pos;
                MString radius(std::to_string((smallest / 2) * density[i]).c_str());
                MString sphereName = "fSphere_" + x_name + "_" + y_name + "_" + z_name;
                if (sphereNames[i] != sphereName)
                {
                    sphereNames.set(sphereName, i);                
                    MGlobal::executeCommand("sphere -n " + sphereName + " -r " + radius);
                    MGlobal::executeCommand("move -r " + pos);
                    MGlobal::executeCommand("select " + locatorName);
                    MGlobal::executeCommand("parent -a -s " + sphereName);
                }
                else
                {
                    MGlobal::executeCommand("sphere -e -r " + radius + " " + sphereName);
                }
            }
        }
    }
    MGlobal::executeCommand("select " + locatorName);
}
