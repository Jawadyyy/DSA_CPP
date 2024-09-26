#include <iostream>

using namespace std;

class staticArray
{
private:
    int array[10] = {23, 21, 44, 98, 67, 12, 39, 81};
    int size = 8;

public:
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void insert(int num, int index)
    {
        if (size >= 10)
        {
            cout << "Size is Full" << endl;
            return;
        }

        if (index < 0 || index > size)
        {
            cout << "Out of Bounds" << endl;
            return;
        }

        for (int i = size; i > index; i--)
        {
            array[i] = array[i - 1];
        }
        array[index] = num;
        size++;
    }

    void remove(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Out of Bounds" << endl;
            return;
        }

        for (int i = index; i < size - 1; i++)
        {
            array[i] = array[i + 1];
        }
        size--;
    }
};

class dynamicArray
{
private:
    int *arrayp;
    int capacity;
    int size = 0;

public:
    dynamicArray(int capacity)
    {
        this->capacity = capacity;
        size = 0;
        arrayp = new int[capacity];
    }

    ~dynamicArray()
    {
        delete[] arrayp;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arrayp[i] << " ";
        }
        cout << endl;
    }

    void insert(int num, int index)
    {
        if (size >= capacity)
        {
            cout << "Array is full" << endl;
            return;
        }

        if (index < 0 || index > size)
        {
            cout << "Invalid operation" << endl;
            return;
        }

        for (int i = size; i > index; i--)
        {
            arrayp[i] = arrayp[i - 1];
        }

        arrayp[index] = num;
        size++;
    }

    void remove(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Out of Bounds" << endl;
            return;
        }

        for (int i = index; i < size - 1; i++)
        {
            arrayp[i] = arrayp[i + 1];
        }

        size--;
    }
};

int main()
{
    staticArray sobj;
    dynamicArray dobj(8);
    int opt, sopt, dopt;

    while (true)
    {
        cout << "Which Array Operations would you like to call: " << endl;
        cout << "1) Static Array: " << endl;
        cout << "2) Dynamic Array: " << endl;
        cout << "3) Exit" << endl;
        cin >> opt;

        if (opt == 1)
        {
            do
            {
                cout << "Would you like to: " << endl;
                cout << "1) Insert Elements" << endl;
                cout << "2) Delete Elements" << endl;
                cout << "3) Display Elements" << endl;
                cout << "4) Go Back to Menu" << endl;
                cin >> sopt;

                switch (sopt)
                {
                case 1:
                {
                    int num, index;
                    cout << "Enter the number to insert and the index: ";
                    cin >> num >> index;
                    sobj.insert(num, index);
                    break;
                }

                case 2:
                {
                    int index;
                    cout << "Enter the index to remove: ";
                    cin >> index;
                    sobj.remove(index);
                    break;
                }

                case 3:
                {
                    sobj.display();
                    break;
                }

                case 4:
                {
                    break;
                }

                default:
                {
                    cout << "Invalid option" << endl;
                }
                }
            } while (sopt != 4);
        }
        else if (opt == 2)
        {
            do
            {
                cout << "Would you like to: " << endl;
                cout << "1) Insert Elements" << endl;
                cout << "2) Delete Elements" << endl;
                cout << "3) Display Elements" << endl;
                cout << "4) Go Back to Menu" << endl;
                cin >> dopt;

                switch (dopt)
                {
                case 1:
                {
                    int num, index;
                    cout << "Enter the number to insert and the index: ";
                    cin >> num >> index;
                    dobj.insert(num, index);
                    break;
                }

                case 2:
                {
                    int index;
                    cout << "Enter the index to remove: ";
                    cin >> index;
                    dobj.remove(index);
                    break;
                }

                case 3:
                {
                    dobj.display();
                    break;
                }

                case 4:
                {
                    break;
                }

                default:
                {
                    cout << "Invalid option" << endl;
                }
                }
            } while (dopt != 4);
        }
        else if (opt == 3)
        {
            break;
        }
        else
        {
            cout << "Invalid option" << endl;
        }
    }

    return 0;
}
