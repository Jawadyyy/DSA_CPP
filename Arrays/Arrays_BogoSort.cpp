#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isSorted(int array[], int s)
{
    for (int i = 0; i < s - 1; i++)
    {
        if (array[i] > array[i + 1])
            return false;
    }
    return true;
}

void shuffle(int array[], int s)
{
    for (int i = 0; i < s; i++)
    {
        int randomIndex = rand() % s;
        int temp = array[i];
        array[i] = array[randomIndex];
        array[randomIndex] = temp;
    }
}

void bogosort(int array[], int s)
{
    while (!isSorted(array, s))
    {
        shuffle(array, s);
    }

    cout << "Sorted array: ";
    for (int i = 0; i < s; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand(time(0));

    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;

    int ray[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter elements of array: " << endl;
        cin >> ray[i];
    }

    bogosort(ray, size);
    return 0;
}
