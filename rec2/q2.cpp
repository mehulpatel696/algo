#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

int main(){
    unordered_map<string, string> languages;
    pair<string, string> one("HELLO", "ENGLISH");
    pair<string, string> two("HOLA", "SPANISH");
    pair<string, string> three("HALLO", "GERMAN");
    pair<string, string> four("BONJOUR", "FRENCH");
    pair<string, string> five("CIAO", "ITALIAN");
    pair<string, string> six("ZDRAVSTVUJTE", "RUSSIAN");
    languages.insert(one);
    languages.insert(two);
    languages.insert(three);
    languages.insert(four);
    languages.insert(five);
    languages.insert(six);
    int num = 1;
    while(true){
        string temp;
        cin>>temp; 
        
        if(temp == "#") break;
        cout<<"Case "<<num<<": ";
        if(languages.find(temp) == languages.end()) cout<<"UNKOWN"<<endl;
        else cout<<languages[temp]<<endl;
        num++;
    }
    return 0;
}