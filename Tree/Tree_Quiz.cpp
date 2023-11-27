/*
NAME    : HAMMAD ZAFAR
ROLL NO : 2022CS639(A)
*/
#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int v) {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = NULL;
    }

    void insertRecursion(int value) {
        if (root == NULL) {
            root = new Node(value);
        }else {
            insertRecursion(root, value);
        }
        
    }

    void insertRecursion(Node *node, int value) {
        if (node == NULL) {
            node = new Node(value);
            return;
        }

        if (value < node->value) {
            if (node->left == NULL) {
                node->left = new Node(value);
            }else {
                insertRecursion(node->left, value);
            }
        } else {
            if (node->right == NULL) {
                node->right = new Node(value);
            }else {
                insertRecursion(node->right, value);
            }
        }
    }

    void insertLoop(int value) {
        if (root == NULL) {
            root = new Node(value);
        }
        Node *node = root;
    }

    void printInorder() {
        printInOrder(root, 0);
    }

    void printOrder() {
        printOrder(root);
    }

    void printPostOrder() {
        printPostOrder(root);
    }

    void printInOrder(Node *node, int depth) {
        if (node == NULL) {
            return;
        }
        for (int i=0; i<depth; i++) {
            cout << "  ";
        }
        cout << "|___" << node->value << endl;
        printInOrder(node->left, depth + 1);
        printInOrder(node->right, depth + 1);
    }

    void printOrder(Node *node) {
        if (node == NULL) {
            return;
        }
        
        printOrder(node->left);
        cout << "|___" << node->value << endl;
        printOrder(node->right);

    }

    void printPostOrder(Node *node) {
        if (node == NULL) {
            return;
        }
        printPostOrder(node->left);
        printPostOrder(node->right);
        cout << "|___" << node->value << endl;

    }

     void deleteNode(int value) {
        Node* nodeParent = root;
        Node* node = root;
        while (node->value != value) {
            nodeParent = node;
            if (value < node->value ) {
                node = node->left;
            }else {
                node = node->right;
            }
        }

        if (nodeParent == node) {
            root = nullptr;
        }

        // Condition 1: If left and right of node are null
        if (!node->left && !node->right) {
            if (nodeParent->left) {
                if (nodeParent->left->value == node->value) {
                    nodeParent->left = nullptr;
                } else {
                    nodeParent->right = nullptr;
                }
            }
        }

        // Condition : Only one child of is not null
        else if (!node->left && node->right) {
            
        }
     }
};

int numOfLeafs(Node *node) {
    int total = 0;
    if (node->left != nullptr) {
        total += numOfLeafs(node->left);
    }
    if (node->right != nullptr) {
        total += numOfLeafs(node->right);
    }
    if (node->left == nullptr && node->right == nullptr) {
        total += 1;
    }
    return total;
}

bool areEqualBST(Node* root1, Node* root2) {
    if (!root1 && !root2)
        return true;

    if (!root1 || !root2)
        return false;

    return (root1->value == root2->value) &&
           areEqualBST(root1->left, root2->left) &&
           areEqualBST(root1->right, root2->right);
}

int main() {

    BinarySearchTree bst;

    bst.insertRecursion(15);
    bst.insertRecursion(10);
    bst.insertRecursion(6);
    bst.insertRecursion(8);
    bst.insertRecursion(17);
    bst.insertRecursion(16);
    bst.insertRecursion(1);

    BinarySearchTree bst1;

    bst1.insertRecursion(15);

    bst.printInorder();

    cout << numOfLeafs(bst.root) << endl;

    cout << areEqualBST(bst.root, bst1.root) << endl;

    bst.printInorder();

    bst.deleteNode(8);

    bst.printInorder();

    return 0;
}