#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

bool is_unique(string s);

int main(){
    string e = "ASP";
    cout << is_unique(e) << endl;
    return 0;
}

bool is_unique(const string s){
    set<char> chars;
    for (int i = 0; i < s.size(); i++){
        if (chars.find(s[i]) == chars.end()){
            chars.insert(s[i]);
        }
        else{
            return false;
        }
    }
    return true;
}