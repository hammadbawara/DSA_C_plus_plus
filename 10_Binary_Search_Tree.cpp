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
};



int main() {

    BinarySearchTree binarySearchTree;

    binarySearchTree.insertRecursion(10);
    binarySearchTree.insertRecursion(20);
    binarySearchTree.insertRecursion(5);
    binarySearchTree.insertRecursion(23);
    binarySearchTree.insertRecursion(9);
    binarySearchTree.insertRecursion(6);
    binarySearchTree.insertRecursion(3);

    cout << "Preorder" << endl;
    binarySearchTree.printOrder();
    cout << "Postorder" << endl;
    binarySearchTree.printPostOrder();
    cout << "Inorder" << endl;
    binarySearchTree.printInorder();

    return 0;
}