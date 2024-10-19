#include <iostream>
#include <vector>
using namespace std;

class RankNode {
public:
    int data;
    RankNode* left;
    RankNode* right;
    int leftSize;  

    RankNode(int data) : data(data), left(nullptr), right(nullptr), leftSize(0) {}
};

class RankTree {
public:
    RankNode* root;

    RankTree() : root(nullptr) {}

    void track(int x) {
        root = insert(root, x);
    }

    int getRankOfNumber(int x) {
        return getRank(root, x);
    }

private:
    RankNode* insert(RankNode* node, int x) {
        if (node == nullptr) {
            return new RankNode(x);
        }

        if (x < node->data) {
            node->left = insert(node->left, x);
            node->leftSize++;
        } else {
            node->right = insert(node->right, x);
        }

        return node;
    }

    int getRank(RankNode* node, int x) {
        if (node == nullptr) {
            return -1;  
        }

        if (x == node->data) {
            return node->leftSize;
        } else if (x < node->data) {
            return getRank(node->left, x);
        } else {
            int rightRank = getRank(node->right, x);
            if (rightRank == -1) {
                return -1;  
            }
            return node->leftSize + 1 + rightRank;
        }
    }
};

int main() {
    RankTree rankTree;
    int n, query, number;
    cout << "Enter the number of elements in the stream: ";
    cin >> n;

    vector<int> stream(n);
    cout << "Enter the elements of the stream: ";
    for (int i = 0; i < n; ++i) {
        cin >> stream[i];
        rankTree.track(stream[i]);
    }

    cout << "Enter the number to find the rank of: ";
    cin >> query;

    int rank = rankTree.getRankOfNumber(query);

    if (rank != -1) {
        cout << "Rank of " << query << " is: " << rank << endl;
    } else {
        cout << query << " not found in the stream." << endl;
    }

    return 0;
}
