#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

/* Base tree node definition */
class Node {
public:
    Node * left = NULL;
    Node * right = NULL;
    int data;
    Node(int d){
        this->data = d;
    }
};

bool validate_BST(Node * father);

int main(){
    Node * father = new Node(2);
    father->left = new Node(1);
    father->right = new Node(3);
    cout << validate_BST(father) << endl;
    return 0;
}

bool validate_BST(Node * father){
    if (father == NULL) return true;
    if (father->left == NULL && father->right == NULL) return true;
    if (father->left != NULL)
        if (father->left->data > father->data) return false;
    if (father->right != NULL)
        if (father->right->data < father->data) return false;
    return validate_BST(father->left)&&validate_BST(father->right);
}
