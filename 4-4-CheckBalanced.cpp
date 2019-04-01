#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
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

bool check_balanced(Node * father);
Node * create_BST();
int height(Node * father, int h);

int main(){
    Node * father = create_BST();
    // cout << height(father,0) << endl;
    cout << check_balanced(father) << endl;
    return 0;
}

bool check_balanced(Node * father){
    cout << height(father->left,0) << height(father->right,0) << endl;
    if (abs(height(father->left, 0) - height(father->right, 0)) <= 1){
        return true;
    }
    return false;
}

Node * create_BST(){
    Node * father = new Node(2);
    father->left = new Node(1);
    father->right = new Node(3);
    father->right->right = new Node(4);
    return father;
}

int height(Node * father, int h){
    if (father == NULL) return 0;
    else if (father->left == NULL && father->right == NULL) return h + 1;
    else{
        return max(height(father->left, h+1), height(father->right,h+1));
    }
}