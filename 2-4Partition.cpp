#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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
Node * partition_list(Node * head, int pivot);

int main(){
    Node * head = create_list();
    Node * n = partition_list(head,5);
    print_list(n);
    return 0;
}

Node * partition_list(Node * head, int pivot){
    Node * current = head;
    Node * first = NULL;
    Node * first2 = first;
    Node * second = NULL;
    Node * second2 = head;
    while(current!=NULL){
        if (current->data < pivot){
            if (first==NULL)
            {
                first = new Node (current->data);
                first2 = first;
            }
            else 
            {
                first->next = new Node(current->data);
                first = first->next;
            }
        }
        else
        {
            if (second==NULL) 
            {
                second = new Node(current->data);
                second2 = second;
            }
            else
            {
                second->next = new Node(current->data);
                second = second->next;
            }
        }
        current = current->next;
    }
    if (first2 != NULL) 
    {
        first->next = second2;
        return first2;
    }
    else return second2;
}

Node * create_list(void){
    Node * head = new Node(5);
    head->appendTotail(8);
    head->appendTotail(6);
    head->appendTotail(3);
    head->appendTotail(1);
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