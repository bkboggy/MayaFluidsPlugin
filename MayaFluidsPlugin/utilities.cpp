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

void Utilities::simulateFluid(MString locatorName, MStringArray &fluid, MFloatArray &density,
    float domainWidth, float domainHeight, float domainLength, int voxelCountWidth, int voxelCountHeight, int voxelCountLength)
{
    float x_offset = domainWidth / voxelCountWidth;
    float x_init = x_offset / 2;
    float y_offset = domainHeight / voxelCountHeight;
    float y_init = y_offset / 2;
    float z_offset = domainLength / voxelCountLength;
    float z_init = z_offset / 2;
   
    float smallest = std::fminf(std::fminf(x_offset, y_offset), z_offset);

    for (int x = 0; x < voxelCountWidth; x++) {
        MString x_name(std::to_string(x).c_str());
        MString x_pos(std::to_string(x_init + ((float)x * x_offset)).c_str());
        for (int y = 0; y < voxelCountHeight; y++) {
            MString y_name(std::to_string(y).c_str());
            MString y_pos(std::to_string(y_init + ((float)y * y_offset)).c_str());
            for (int z = 0; z < voxelCountLength; z++) {
                int i = x + (y * voxelCountWidth) + (z * voxelCountWidth * voxelCountHeight);
                MString z_name(std::to_string(z).c_str());
                MString z_pos(std::to_string(z_init + ((float)z * z_offset)).c_str());
                MString pos = x_pos + " " + y_pos + " " + z_pos;
                MString radius(std::to_string((smallest / 2) * density[i]).c_str());
                MString fluidParticle = "fSphere_" + x_name + "_" + y_name + "_" + z_name;
                if (fluid[i] != fluidParticle)
                {
                    fluid.set(fluidParticle, i);
                    MGlobal::executeCommand("sphere -n " + fluidParticle + " -r " + radius);
                    MGlobal::executeCommand("move -r " + pos);
                    MGlobal::executeCommand("select " + locatorName);
                    MGlobal::executeCommand("parent -a -s " + fluidParticle);
                }
                else
                {
                    MGlobal::executeCommand("sphere -e -r " + radius + " " + fluidParticle);
                }
            }
        }
    }
    MGlobal::executeCommand("select " + locatorName);
}
