#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
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

vector<Node*> create_lists(void);
void print_list(Node * head);
bool is_intersection(Node * head1, Node * head2);

int main(){
    vector<Node *> heads = create_lists();
    print_list(heads[0]);
    print_list(heads[1]);
    cout << is_intersection(heads[0], heads[1]) << endl;
    return 0;
}

bool is_intersection(Node * head1, Node * head2){
    while(head2 != NULL){
        Node * current = head1;
        while(current != NULL){
            if (current==head2) return true;
            current = current->next;
        }
        head2 = head2->next;
    }
    return false;
}

vector<Node *> create_lists(void){
    Node * head1 = new Node(6);
    head1->appendTotail(8);
    Node * head2 = head1->next;
    head1->appendTotail(8);
    head1->appendTotail(6);
    return {head1, head2};
}

void print_list(Node * head){
    Node * current = head;
    while(current!= NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}