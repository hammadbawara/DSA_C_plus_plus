/*
NAME    : HAMMAD ZAFAR
ROLL NO : 2022CS639(A)
*/
#include <iostream>
#include <stack>
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



int main() {

    BinarySearchTree binarySearchTree;

    binarySearchTree.insertRecursion(10);
    binarySearchTree.insertRecursion(20);
    binarySearchTree.insertRecursion(5);
    binarySearchTree.insertRecursion(23);
    binarySearchTree.insertRecursion(9);
    binarySearchTree.insertRecursion(6);
    binarySearchTree.insertRecursion(3);
    binarySearchTree.insertRecursion(1);

    int num;
    cout << "Enter the number: ";
    cin >> num;

    int num1 = num-1;
    int num2 = 1;

    bool isFound = false;
    for (int i=0; i<(num/2); i++) {
        bool firstFound = binarySearchTree.search(num1);

        if (firstFound) {
            bool secFound = binarySearchTree.search(num2);
            if (secFound) {
                if (num2 != num1) {
                    isFound = true;
                    cout << "Pair of (" << num1 << "," << num2 << ") make " << num << endl;
                    break;
                }
            }
        }
        num1--;
        num2++;
    }
    if (!isFound) {
        cout << "No pair in the tree found those sum make "<< num << endl;
    }
    

    return 0;
}