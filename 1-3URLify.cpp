#include <iostream>
#include <string>
using namespace std;

void urli(string& s, int len);

int main(){
    string input = "Mr. John Smith    ";
    int len = 14;
    urli(input, len);
    cout << input << endl;
    return 0;
}

void urli(string& s, int len){
    int p1 = s.size() - 1; 
    int p2 = len - 1; 
    for (int i = p1; p2 >= 0; i--){
        if (s[p2] != ' '){
            s[i] = s[p2];
        }
        else
        {
            s[i] = '0';
            s[i-1] = '2';
            s[i-2] = '%';
            i = i - 2;
        }
        p2 --;        
    }
}