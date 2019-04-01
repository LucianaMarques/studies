#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

/* Base tree node definition */
class Node {
public:
    Node * left = NULL;
    Node * right = NULL;
    Node * parent = NULL;
    int data;
    Node(int d){
        this->data = d;
    }
};

Node * find_successor(Node * father);

int main(){
    Node * father = new Node(2);
    father->left = new Node(1);
    father->left->parent = father;
    father->right = new Node(3);
    father->right->parent = father;
    //father->parent = new Node(4);
    Node * succ = find_successor(father->right);
    if (succ != NULL) cout << succ->data << endl;
    else cout << "there is no such node" << endl;
    return 0;
}

Node * find_successor(Node * father){
    if (father->parent != NULL){ //if the node is not the root
        if (father->data < father->parent->data){ //left child
            if (father->right == NULL) return father->right;
            else return father->parent;
        }
        else{ //right child
            if (father->right != NULL) return father->right;
            else {
                return father->parent->parent;
            }
        }
    }
    else {
        return father->right;
    }
}