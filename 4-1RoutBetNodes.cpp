#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Base graph node definition */
class Node {
public:
    Node * next = NULL;
    vector<Node *> nexts;
    int data;
    string state = "unvisited";
    Node(int d){
        this->data = d;
    }
    void appendNext(Node * n){
        this->nexts.push_back(n);
    }
};

bool is_rout(Node * n1, Node * n2);
Node * create_lists(void);
void print_list_DFS(Node * head);

int main(){
    Node * head = create_lists();
    cout << is_rout(NULL, head) << endl;
    return 0;
}

bool is_rout(Node * n1, Node * n2){
    if (n1 == NULL || n2 == NULL) return false;
    if (n1->nexts.size() == 0 && n1!=n2) return false;
    else{
        for (int i = 0; i < n1->nexts.size(); i++){
            if (n1->nexts[i] == n2) return true;
            else if (is_rout(n1->nexts[i],n2)) return true;
        }
        return false;
    }
}

Node * create_lists(void){
    Node * n1 = new Node(1);
    Node * n2 = new Node(2);
    Node * n3 = new Node(3);
    Node * n4 = new Node(4);
    Node * n5 = new Node(5);
    n1->appendNext(n2);
    n1->appendNext(n3);
    n1->appendNext(n4);
    n2->appendNext(n4);
    n3->appendNext(n4);
    n3->appendNext(n5);
    n4->appendNext(n5);
    return n1;
}

void print_list_DFS(Node * head){
    if (head == NULL){
        return;
    }
    for (int i = 0; i < head->nexts.size(); i++){
        print_list_DFS(head->nexts[i]);
    }
    cout << head->data << endl;
}