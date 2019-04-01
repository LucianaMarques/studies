#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

/* Base tree node definition */
class Node {
public:
    Node * left = NULL;
    Node * right = NULL;
    Node * father = NULL;
    int data;
    Node(int d){
        this->data = d;
    }
};

Node * create_BST(vector<int> v);

int main(){

    return 0;
}

Node * create_BST(vector<int> v){
    if (v.size() == 0) return NULL;
    Node * current = new Node (v[0]);
    for (int i = 1; i < v.size(); i++){
        Node * n = new Node(v[i]);
        if (i == 1){
            n->left = current;
            current->father = n;
            n = current;
        }
        else if (current->left != NULL && current->right == NULL){
            current->right = n;
            n->father = current;
        }
        else if (current->left != NULL && current->right != NULL){
            if (left_height(current) == right_height(current))
            {
                if (current->right->right == NULL) {
                    current = current->right;
                    current->right = n;
                    n->father = current;
                }
            }
            else
            {
                current = current->right;
            }
            
        }    
        else if (current->right == NULL && current->left == NULL && current->father!=NULL){
            if (current->father->left == NULL){
                if (get_left_subtree_height(current->father) > 1){
                    current->right = n;
                    n->father = current;
                    current =     
                }
                
            }
            else{
                while(current->father!=NULL){
                    current = current->father;
                }
                n->left = current;
                current->father = n;
                current = n;
            }
        }
    }
    return current;
}