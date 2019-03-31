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
void ret_kth_last(int k, Node * head);

int main(){
    Node * head = create_list();
    ret_kth_last(3,head);
    return 0;
}

Node * create_list(void){
    Node * head = new Node(1);
    head->appendTotail(4);
    head->appendTotail(6);
    head->appendTotail(7);
    head->appendTotail(5);
    return head;
}

void ret_kth_last(int k, Node * head){
    //First, advance k nodes from head
    Node * current = head;
    for (int i = 0; i < k; i++){
        current = current->next;
        if (current == NULL){
            cout << "The list is smaller than k" << endl;
            return;
        }
    }
    Node * last = current;
    Node * beg = head;
    while (last != NULL){
        last = last->next;
        beg = beg->next;
    }
    print_list(beg);
}

void print_list(Node * head){
    Node * current = head;
    while(current!= NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
