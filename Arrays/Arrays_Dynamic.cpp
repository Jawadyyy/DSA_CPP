#include <iostream>

using namespace std;

void displayArray(int ray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << ray[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    displayArray(arr, size);

    delete[] arr;

    return 0;
}
