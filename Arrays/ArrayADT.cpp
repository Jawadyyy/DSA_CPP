#include <iostream>

using namespace std;

class arrayADT {
private:
    int *arrayp;
    int capacity;
    int size = 0;

public:
    arrayADT(int capacity) {
        this->capacity = capacity;
        size = 0;
        arrayp = new int[capacity];
    }

    ~arrayADT() {
        delete[] arrayp;
    }

    void insert(int num, int index) {
        if (size >= capacity) {
            cout << "Array is full" << endl;
            return;
        }

        if (index < 0 || index > size) {
            cout << "Invalid operation" << endl;
            return;
        }

        for (int i = size; i > index; i--) {
            arrayp[i] = arrayp[i - 1];
        }

        arrayp[index] = num;
        size++;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            cout << "Out of Bounds" << endl;
            return;
        }

        for (int i = index; i < size - 1; i++) {
            arrayp[i] = arrayp[i + 1];
        }

        size--;
    }

    void update(int num, int index) {
        if (index < 0 || index >= size) {
            cout << "Out of Bounds" << endl;
            return;
        }
        arrayp[index] = num;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arrayp[i] << " ";
        }
        cout << endl;
    }

    void bubblesort() {
        for (int j = 0; j < size; j++) {
            for (int z = 0; z < size - j; z++) {
                if (arrayp[z] > arrayp[z + 1]) {
                    int swap = arrayp[z];
                    arrayp[z] = arrayp[z + 1];
                    arrayp[z + 1] = swap;
                }
            }
        }

        cout << "Sorted array: " << endl;
        display();
    }

    void linearsearch(int num) const {
        int pos = -1;

        for (int i = 0; i < size; i++) {
            if (arrayp[i] == num) {
                pos = i;
                break;
            }
        }
        if (pos != -1)
            cout << "Number found at index: " << pos << endl;
        else
            cout << "Number not found" << endl;
    }
};

int main() {
    
    int totalsize;
    cout << "Enter the Size of the Dynamic Array: " << endl;
    cin >> totalsize;

    arrayADT adt(totalsize);

    int choice, num, index;

    do {
        cout << "Call An Operation for the Array" << endl;
        cout << "1) Insert " << endl;
        cout << "2) Remove " << endl;
        cout << "3) Update " << endl;
        cout << "4) Display " << endl;
        cout << "5) Bubble Sort " << endl;
        cout << "6) Linear Search" << endl;
        cout << "7) Close" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter the number to insert: " << endl;
                cin >> num;
                cout << "Enter the index at which to insert: " << endl;
                cin >> index;
                adt.insert(num, index);
            break;
            }

            case 2: {
                cout << "Enter the index of the element to remove: " << endl;
                cin >> index;
                adt.remove(index);
                break;
            }

            case 3: {
                cout << "Enter the number to update: " << endl;
                cin >> num;
                cout << "Enter the index at which to update: " << endl;
                cin >> index;
                adt.update(num, index);
                break;
            }

            case 4: {
                cout << "Array contents: " << endl;
                adt.display();
                break;
            }

            case 5: {
                adt.bubblesort();
                break;
            }

            case 6: {
                cout << "Enter the number to search: " << endl;
                cin >> num;
                adt.linearsearch(num);
                break;
            }

            case 7: {
                cout << "Exiting......." << endl;
                break;
            }

            default: {
                cout << "Try Again!!!" << endl;
                break;
            }
        }

    } while (choice != 7);

    return 0;
}