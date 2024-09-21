#include <iostream>

using namespace std;

void bubblesort(int array[], int s)
{
    int swap;
    for (int j = 0; j < s - 1; j++)
    {
        for (int z = 0; z < s - j - 1; z++)
        {
            if (array[z] > array[z + 1])
            {
                swap = array[z];
                array[z] = array[z + 1];
                array[z + 1] = swap;
            }
        }
    }

    cout << "Sorted array: ";
    for (int k = 0; k < s; k++)
    {
        cout << array[k] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;

    int ray[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter elements of array: " << endl;
        cin >> ray[i];
    }

    bubblesort(ray, size);
    return 0;
}