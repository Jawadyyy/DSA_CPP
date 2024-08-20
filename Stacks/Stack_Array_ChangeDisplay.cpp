#include <iostream>
#include <string>

using namespace std;

class Stack {
    private:
        int top;
        int ray[5];

    public:
        Stack() {
            top = -1;
            for(int i = 0; i<5; i++) {
                ray[i] = 0;
            }
        }

        void change(int pos, int val) {
            ray[pos] = val;
            cout << "Value chnaged at location" << pos << endl;
        }

        void dislay() {
            cout << "All values in the Stack are: " << endl;
            for(int i = 4; i>=0; i--) {
                cout << ray[i] << endl;
            }
        }

       
};

int main() {

    return 0;
}
