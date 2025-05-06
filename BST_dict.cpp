// best and avg for all=o(logn)
// worst for all=o(n)
// for diplsy all case o(n)
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string keyword, meaning;
    Node* left;
    Node* right;

    Node(string k, string m) {
        keyword = k;
        meaning = m;
        left = right = nullptr;
    }
};

class Dictionary {
    Node* root;	//Usually used to represent the root of the tree.

    Node* insert(Node* node, string k, string m) {  //Node* node Just a pointer to any other node (temporary/helper).
        if (node == nullptr)
         return new Node(k, m);
        if (k < node->keyword)
            node->left = insert(node->left, k, m);
        else if (k > node->keyword)
            node->right = insert(node->right, k, m);
        else
            cout << "Keyword already exists.\n";
        return node;
    }

    Node* search(Node* node, string k, int& cmp) {
        //int& cmp means that cmp is passed as a reference to the search function.
        //Modify cmp directly: Since it's passed by reference, any changes made to
        // cmp inside the function will be reflected outside the function as well. 
        //This is important because you want to keep track of how many comparisons 
        //were made during the search, and this count should be updated outside the function too.
            while (node) {
                cmp++;  
                if (k == node->keyword)  // Check if the current node's keyword matches 'k'
                    return node;

                if (k < node->keyword) {
                    node = node->left;  // Move to the left child if 'k' is smaller
                } else {
                    node = node->right;  // Move to the right child if 'k' is larger
                }
            }
            return nullptr;  // Return nullptr if the keyword isn't found
        }
        

    //inorder(...) is required because:
//It's used in displayAscending() to show the dictionary in ascending order 

    void inorder(Node* node) {
        if (node== nullptr)
         return;
         //Inorder
        inorder(node->left);//Visit left subtree (smaller values)
        cout << node->keyword << ": " << node->meaning << endl;//Visit current node
        inorder(node->right);//Visit right subtree (larger values)
    }

    Node* findMin(Node* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, string k) {
        if (node== nullptr)
         return nullptr;
         //if grater or smaller than key move left and right
        if (k < node->keyword)
            node->left = deleteNode(node->left, k);
        else if (k > node->keyword)
            node->right = deleteNode(node->right, k);
        else {

            //Now, you've found the node that needs to be deleted. There are 3 possible cases:

            if (!node->left && !node->right)
                return nullptr;
                //Node has only right child
            else if (!node->left)
                return node->right;
                //Node has only left child
            else if (!node->right)
                return node->left;

            Node* temp = findMin(node->right);
            node->keyword = temp->keyword;
            node->meaning = temp->meaning;
            node->right = deleteNode(node->right, temp->keyword);
        }
        return node;
    }

    Node* update(Node* node, string k, string newMeaning) {
        int cmp = 0;
        Node* found = search(node, k, cmp);
        if (found) {
            found->meaning = newMeaning;
            cout << "Meaning updated.\n";
        } else {
            cout << "Keyword not found.\n";
        }
        return node;
    }

public:
    Dictionary() {
        root = nullptr;
    }

    void add(string k, string m) {
        root = insert(root, k, m);
    }

    void remove(string k) {
        root = deleteNode(root, k);
    }

    void updateMeaning(string k, string m) {
        root = update(root, k, m);
    }

    void searchKeyword(string k) {
        int cmp = 0;
        Node* res = search(root, k, cmp);
        if (res) {
            cout << "Meaning: " << res->meaning << endl;
        } else {
            cout << "Keyword not found.\n";
        }
        cout << "Comparisons made: " << cmp << endl;
    }

    void displayAscending() {
        inorder(root);
    }
};

int main() {
    Dictionary dict;
    int choice;
    string keyword, meaning;

    do {
        cout << "\n--- Dictionary Menu ---\n";
        cout << "1. Add keyword\n2. Search keyword\n3. Delete keyword\n4. Update meaning\n";
        cout << "5. Display Ascending\n6. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter keyword: ";
                cin >> keyword;
                cin.ignore();
                cout << "Enter meaning: ";
                getline(cin, meaning);
                dict.add(keyword, meaning);
                break;
            case 2:
                cout << "Enter keyword to search: ";
                cin >> keyword;
                dict.searchKeyword(keyword);
                break;
            case 3:
                cout << "Enter keyword to delete: ";
                cin >> keyword;
                dict.remove(keyword);
                break;
            case 4:
                cout << "Enter keyword to update: ";
                cin >> keyword;
                cin.ignore();
                cout << "Enter new meaning: ";
                getline(cin, meaning);
                dict.updateMeaning(keyword, meaning);
                break;
            case 5:
                dict.displayAscending();
                break;
        }

    } while (choice != 6);

    return 0;
}
