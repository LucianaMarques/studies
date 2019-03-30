#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

string str_compression(string input);

int main(){
    cout << str_compression("aaabbcdeee") << endl;
    return 0;
}

string str_compression(string input){
    if (input.size() == 0) return input;
    int count = 1;
    char current = input[0];
    string result = "";
    for (int i = 1; i < input.size(); i++){
        if (input[i] == current) count ++;
        else {
            result.push_back(current);
            result.push_back(count + '0');
            current = input[i];
            count = 1;
        }
    }
    result.push_back(current);
    result.push_back(count + '0');
    if (result.size() > input.size()) return input;
    return result;
}