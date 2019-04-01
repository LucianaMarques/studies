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
Node * sum_lists(Node * head1, Node * head2);

int main(){
    Node * head1 = create_list();
    print_list(head1);
    Node * head2 = create_list();
    Node * result = sum_lists(head1,head2);
    print_list(result);
    return 0;
}

Node * sum_lists(Node * head1, Node * head2){
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    int sum = head1->data + head2->data;
    int carry = 0;
    if (sum > 9){
        carry = sum/10;
        sum = sum%10;
    }
    Node * result = new Node(sum);
    head1 = head1->next;
    head2 = head2->next;
    Node * current = result;
    while(head1 != 0 || head2 != 0){
        if (head1 == NULL) sum = head2->data + carry;
        else if (head2 == NULL) sum = head1->data + carry;
        else sum = head1->data + head2->data + carry;
        if (sum > 9){
            carry = sum/10;
            sum = sum%10;
        }
        else carry = 0;
        current->next = new Node(sum);
        current = current->next;
        Node * free_head1 = head1;
        Node * free_head2 = head2;
        head1 = head1->next;
        head2 = head2->next;
        free(free_head1);
        free(free_head2);
    }
    if (carry!=0) current->next = new Node(carry);
    return result;
}

Node * create_list(void){
    Node * head = new Node(5);
    head->appendTotail(8);
    head->appendTotail(6);
    head->appendTotail(3);
    head->appendTotail(8);
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