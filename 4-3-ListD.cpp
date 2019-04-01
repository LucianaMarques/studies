#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class ListNode{
public:
    ListNode * next = NULL;
    int data;
    ListNode(int d){
        this->data = d;
    }
    void addNext(ListNode * n){
        ListNode * current = this;
        while(current->next!=NULL){
            current = current->next;
        }
        current->next = n;
    }
};

class TreeNode{
public:
    TreeNode * left = NULL;
    TreeNode * right = NULL;
    int data;
    TreeNode(int d){
        this->data = d;
    }
};

void print_list(ListNode * head);
vector<ListNode *> create_node(TreeNode * father);

int main(){

    return 0;
}

vector<ListNode *> create_node(TreeNode * father){
    vector<ListNode *> lists;
    queue<TreeNode *> q;
    q.push(father);
    queue<TreeNode *> d;
    while(!q.empty()){
        (!q.empty){
            d.push(q.front());
            q.pop();
        }
        ListNode * l = new ListNode(d.front()->data);
        lists.push_back(l);
        q.push(d.front()->left);
        q.push(d.front()->right);
        d.pop();
        while(!d.empty()){
            q.push(d.front()->left);
            q.push(d.front()->right);
            l->next = new ListNode(d.front()->data);
            l = l->next;
            d.pop();
        }
    }
    return lists;
}

void print_list(ListNode * head){
    ListNode * current = head;
    while(current!= NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}