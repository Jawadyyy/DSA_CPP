#include <iostream>

using namespace std;

void insertionsort(int array[], int s)
{
    for (int i = 1; i < s; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
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

    insertionsort(ray, size);
    return 0;
}