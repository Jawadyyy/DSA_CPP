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
}

void binarysearch(int array[], int s)
{
    bubblesort(array, s);

    int num;
    cout << "Sorted array: ";
    for (int i = 0; i < s; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\nEnter the number to search: ";
    cin >> num;

    int low = 0, high = s - 1, mid, pos = -1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array[mid] == num)
        {
            pos = mid;
            break;
        }
        else if (array[mid] < num)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (pos != -1)
        cout << "Number found at index: " << pos << endl;
    else
        cout << "Number not found" << endl;
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

    binarysearch(ray, size);
    return 0;
}
