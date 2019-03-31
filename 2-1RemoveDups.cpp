#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

/* Base class for a Linked List node */
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

void remove_dups(Node * head);
Node * create_list(void);
void print_list(Node * head);

int main(){
    Node * head = create_list();
    remove_dups(head);
    print_list(head);
    return 0;
}

void print_list(Node * head){
    Node * current = head;
    while(current!= NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node * create_list(void){
    Node * head = new Node(1);
    head->appendTotail(4);
    head->appendTotail(4);
    head->appendTotail(4);
    head->appendTotail(5);
    return head;
}

/* given the head of the list, remove nodes with duplicate data */
void remove_dups(Node * head){
    set<int> dups;
    Node * past = NULL;
    Node * current = head;
    while(current->next != NULL){
        if (dups.find(current->data) != dups.end()){
            past->next = current->next;
            current = past->next;
        }
        else{
            dups.insert(current->data);
            past = current;
            current = current->next;
        }
    }
}