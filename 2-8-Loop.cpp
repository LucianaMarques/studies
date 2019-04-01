#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <set>
using namespace std;

class Node {
public:
    Node * next = NULL;
    int data;
    Node(int d){
        this->data = d;
    }
    void appendTotail(int d){
        Node * end = new Node(d);
        Node * n = this;
        while (n->next != NULL){
            n = n->next;
        }
        n->next = end;
    }
};

Node* create_list(void);
void print_list(Node * head);
Node* is_loop(Node* head);

int main(){
    Node * head = create_list();
    if (is_loop(head) == NULL) cout << "There is no loop" << endl;
    else cout << "There is a loop" << endl;
    return 0;
}

Node* is_loop(Node* head){
    Node * current = head;
    set<Node*> s;
    while (current!=NULL){
        if (s.find(current)!=s.end()) return current;
        else s.insert(current);
        current = current->next;
    }
    s.clear();
    return NULL;
}

Node * create_list(void){
    Node * head = new Node(6);
    head->appendTotail(8);
    head->appendTotail(8);
    head->next->next->next = head;
    return head;
}

void print_list(Node * head){
    Node * current = head;
    while(current!= NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}