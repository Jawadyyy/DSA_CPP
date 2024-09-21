#include <iostream>

using namespace std;

void linearsearch(int array[], int s)
{
    int numli, pos = -1;
    cout << "Enter a number to search using linear search: " << endl;
    cin >> numli;

    for (int i = 0; i < s; i++)
    {
        if (array[i] == numli)
        {
            pos = i;
            break;
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

    linearsearch(ray, size);
    return 0;
}
