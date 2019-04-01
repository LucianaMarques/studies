#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <exception>
using namespace std;

class Stack{
public:
    Stack(){}
    vector<int> v;
    int minor;
    void pop(){
        this->v.erase(this->v.begin() + this->v.size()-1);
    }
    void push(int d){
        if (this->v.size() == 0) minor = d;
        else if (d < minor) this->minor = d;
        this->v.push_back(d);
    }
    int min(){
        if (v.size() != 0) return minor;
        else return -1; //learn how to throw exceptions
    }
};

int main(){
    return 0;
}