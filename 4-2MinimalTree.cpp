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
    Node * father = NULL;
    int data;
    Node(int d){
        this->data = d;
    }
};

Node * create_BST(vector<int> v);
int tree_height(Node * n, int h);
void print_BFS(Node * father);

int main(){
    Node * n = create_BST({1,2,3,4,5,6,7});
    print_BFS(n);
    return 0;
}

void print_BFS(Node * father){
    queue<Node*> q;
    q.push(father);
    queue<Node*> print;
    while(!q.empty()){
        cout << q.front()->data << " ";
        if (q.front()->left != NULL) q.push(q.front()->left);
        if (q.front()->right != NULL) q.push(q.front()->right);
        q.pop();
    }
    cout << endl;
}

Node * create_BST(vector<int> v){
    if (v.size() == 0) return NULL;
    Node * current = new Node (v[0]);
    for (int i = 1; i < v.size(); i++){
        Node * n = new Node(v[i]);
        cout << "new element" << n->data << endl;
        cout << "current element" << current->data << endl;
        if (i == 1){
            n->left = current;
            current->father = n;
            current = n;
        }
        else if (current->left != NULL && current->right == NULL){
            current->right = n;
            n->father = current;
        }
        else if (current->left != NULL && current->right != NULL){
            if (tree_height(current->left,0) == tree_height(current->right,0))
            {
                if (current->right!=NULL){
                    current->father = n;
                    n->left = current;
                    current = n; 
                }
                else{
                    current = current->right;
                    Node * grandpa = current->father;
                    Node * l = current;
                    current = current->right;
                    grandpa->right = current;
                    current->left = l;
                    l->right = NULL;
                    current->right = n;
                }
            }
            else
            {
                if (current->right == NULL){
                    current->right = n;
                    n->father = current;
                    current = n;
                }
                else{
                    current->right->right = n;
                    current = current->right;
                }
            }
                        
        }    
    }
    while(current->father!=NULL) current = current->father;
    return current;
}

int tree_height(Node * n, int h){
    if (n==NULL) return h + 1;
    else return h + max(tree_height(n->right, h),tree_height(n->left,h));
}