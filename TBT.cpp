// for all o(n)
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    bool lthread;
    bool rthread;

    Node(int val) {
        data = val;
        left = right = nullptr;
        lthread = rthread = true;
    }
};

class ThreadedBinaryTree {
private:
    Node* root;

public:
    ThreadedBinaryTree() {
        root = nullptr;
    }

    // Insert using preorder threading
    void insert(int val) {
        Node* newNode = new Node(val);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* curr = root;
        while (true) {
            if (val < curr->data) {
                if (!curr->lthread) {
                    curr = curr->left;
                } else {
                    newNode->left = curr->left;
                    newNode->right = curr;
                    curr->lthread = false;
                    curr->left = newNode;
                    return;
                }
            } else {
                if (!curr->rthread) {
                    curr = curr->right;
                } else {
                    newNode->right = curr->right;
                    newNode->left = nullptr;
                    curr->rthread = false;
                    curr->right = newNode;
                    return;
                }
            }
        }
    }

    // Find the next node in preorder
    Node* preorderSuccessor(Node* node) {
        if (!node->lthread)
            return node->left;
        else if (!node->rthread)
            return node->right;
        else {
            while (node && node->rthread)
                node = node->right;
            return (node ? node->right : nullptr);
        }
    }

    // Preorder traversal without stack/recursion
    void preorderTraversal() {
        Node* curr = root;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = preorderSuccessor(curr);
        }
        cout << endl;
    }
};

int main() {
    ThreadedBinaryTree tree;
    int n, val;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        tree.insert(val);
    }

    cout << "Preorder Traversal (Threaded): ";
    tree.preorderTraversal();

    return 0;
}
