#include <iostream>
using namespace std;

class DisjointSet {
private:
    int* parent;

public:
    DisjointSet(int n) {
        parent = new int[n];
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }

    bool sameSet(int x, int y) {
        return find(x) == find(y);
    }

    ~DisjointSet() {
        delete[] parent;
    }
};

int main() {
    DisjointSet ds(5);
    
    ds.unionSets(0, 1);
    ds.unionSets(1, 2);

    cout << "Root of 0: " << ds.find(0) << endl; 
    cout << "Root of 2: " << ds.find(2) << endl;


    cout << "Are 0 and 2 in the same set? " 
         << (ds.sameSet(0, 2) ? "Yes" : "No") << endl;
    
    ds.unionSets(3, 4);

    cout << "Root of 3: " << ds.find(3) << endl;
    cout << "Root of 4: " << ds.find(4) << endl;

    cout << "Are 3 and 4 in the same set? " 
         << (ds.sameSet(3, 4) ? "Yes" : "No") << endl;
    cout << "Are 0 and 4 in the same set? " 
         << (ds.sameSet(0, 4) ? "Yes" : "No") << endl;

    return 0;
}
