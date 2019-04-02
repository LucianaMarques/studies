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

int main(){

}

/*

    A
B       C
          D
    A
B       C
  E   F   D

*/

bool BFS(Node* node, char target){
    if (node == NULL) return false;
    else if (node->data != target){
        return BFS(node->right, target) || BFS(node->left, target);
    }
    else if (node->data == target){
        return true;
    }
}