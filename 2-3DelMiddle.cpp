#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
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

Node * create_list(void);
void print_list(Node * head);
void delete_node(Node* n);

int main(){
    Node * head = create_list();
    delete_node(head->next->next->next->next);
    print_list(head);
    return 0;
}

void delete_node(Node* n){
    if (n == NULL || n->next == NULL) {
        cout << "Node not possible to delete" << endl;
        return;
    }
    n->data = n->next->data;
    Node * del = n->next;
    n->next = del->next;
    free(del);
}

Node * create_list(void){
    Node * head = new Node(1);
    head->appendTotail(4);
    head->appendTotail(6);
    head->appendTotail(7);
    head->appendTotail(5);
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