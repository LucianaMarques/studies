#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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
int get_list_size(Node * head);
bool is_palindrome(Node * head);

int main(){
    Node * head = create_list();
    cout << is_palindrome(head) << endl;
    return 0;
}

bool is_palindrome(Node * head){
    int size = get_list_size(head);
    cout << "size is: " << size << endl;
    stack<int> p;
    Node * current = head;
    for (int i = 0; i < size/2; i++){
        cout << current->data << endl;
        p.push(current->data);
        current = current->next;
    }
    if (size%2!=0) current = current->next;
    while(current!=NULL){
        if (p.top() != current->data) return false;
        current = current->next;
        p.pop();
    }
    return true;
}

int get_list_size(Node * head){
    int count = 0; 
    Node * current = head;
    while(current!=NULL){
        current = current->next;
        count++;
    }
    return count;
}

Node * create_list(void){
    Node * head = new Node(6);
    head->appendTotail(8);
    head->appendTotail(8);
    head->appendTotail(6);
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