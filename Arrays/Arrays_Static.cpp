#include <iostream>

using namespace std;

void display(int ray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << ray[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[5] = {29, 32, 44, 88, 78};
    int size = 5;

    display(arr, size);

    return 0;
}
