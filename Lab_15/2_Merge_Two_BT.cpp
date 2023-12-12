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
            insert(root, value);
        }
        
    }

    void insert(Node *node, int value) {
        if (node == NULL) {
            node = new Node(value);
            return;
        }

        if (value < node->value) {
            if (node->left == NULL) {
                node->left = new Node(value);
            }else {
                insert(node->left, value);
            }
        } else {
            if (node->right == NULL) {
                node->right = new Node(value);
            }else {
                insert(node->right, value);
            }
        }
    }

    int getMin() {
        Node *min = root;
        while (min->left != NULL) {
            min = min->left;
        }
        return min->value;
    }

    int getMax() {
         Node *max = root;
        while (max->right != NULL) {
            max = max->right;
        }
        return max->value;
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

    bool search(int value) {
        return search(root, value);
    }

    bool search(Node *node, int value) {
        bool isFound = false;
        if (node == NULL) {
            isFound = false;
        }
        else if (node->value == value) {
            isFound = true;
        }else {
            if (node->value > value) {
                isFound = search(node->left, value);
            }else {
                isFound = search(node->right, value);
            }
        }
        return isFound;

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

void merge(Node* root, BinarySearchTree *bsh) {
    if (root == NULL) {
        return;
    } else {
        bsh->insertRecursion(root->value);
        merge(root->left, bsh);
        merge(root->right, bsh);
    }
}



void mergeTree(Node *root1, Node *root2) {
    Node *temp = root1;
    BinarySearchTree bsh;
    merge(root1, &bsh);
    merge(root2, &bsh);

    bsh.printOrder();
}

int main() {

    BinarySearchTree BST1;
    BST1.insertRecursion(20);
    BST1.insertRecursion(10);
    BST1.insertRecursion(30);
    BST1.insertRecursion(25);
    BST1.insertRecursion(100);

    BinarySearchTree BST2;
    BST2.insertRecursion(50);
    BST2.insertRecursion(5);
    BST2.insertRecursion(70);

    mergeTree(BST1.root, BST2.root);

    return 0;
}