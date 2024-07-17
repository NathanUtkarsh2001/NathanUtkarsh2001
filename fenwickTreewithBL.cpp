#include <bits/stdc++.h>
using namespace std;
 
class BinaryIndexedTree {
private:
    // Declare vector to store the BIT
    vector<int> tree;
 
public:
    // Initialize the BIT vector
    // with zeros
    BinaryIndexedTree(int n) { tree.resize(n + 1, 0); }
 
    void update(int i, int v)
    {
        i += 1;
 
        // Update the index to the next
        // node in the BIT
        while (i < tree.size()) {
            tree[i] += v;
            i += i & (-i);
        }
    }
 
    int query(int i)
    {
        i += 1;
        int res = 0;
 
        // Update the index to the
        // previous node in the BIT
        while (i > 0) {
            res += tree[i];
            i -= i & (-i);
        }
        return res;
    }
 
    int range_query(int l, int r)
    {
        int res = 0;
        while (r >= l) {
 
            // Find the largest power of
            // 2 that is less than or
            // equal to the distance between
            // l and r
            int k = r & (-r);
 
            // Include the value of the
            // node at r in the query
            // result if the binary digit
            // at the k-th position
            // of r is 1
            res += (r & k) ? tree[r] : 0;
 
            // Move up to the
            // next ancestor
            r -= k;
        }
        return res;
    }
};
 
// Drivers code
int main()
{
    int n = 10;
    BinaryIndexedTree bit(n);
 
    // Perform some updates and queries
    bit.update(0, 1);
    bit.update(1, 2);
    bit.update(2, 3);
    bit.update(3, 4);
 
    // Function Calls
    cout << bit.query(3) << endl;
    cout << bit.range_query(1, 3) << endl;
 
    return 0;
}
