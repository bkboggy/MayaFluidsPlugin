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
