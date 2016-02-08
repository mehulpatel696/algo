#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <list>
using namespace std;

int main(){
    string text;
    while(cin >> text){
        list<char> new_string;
        list<char>::iterator iter = new_string.begin();
        for(int i = 0; i < text.size(); i++){
            if(text[i] == '[') iter = new_string.begin();
            else if(text[i] == ']') iter = new_string.end();
            else new_string.insert(iter,text[i]);
        }
        for(list<char>::iterator i = new_string.begin(); i != new_string.end(); i++) cout<<*i;
        cout<<endl;
    }
    return 0;
}

