#ifndef UTILITIES_H
#define UTILITIES_H

#define NULL 0

// A general utilities class.
class Utilities
{
public:
    static void initializeFloatArray(float* arr, int size)
    {
        if (arr == NULL)
        {
            return;
        }
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0.0f;
        }
    }
};

#endif
