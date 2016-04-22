

#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <stack>
#include <queue>
#include <stdio.h>
#include <limits.h>
#include <string.h>

//120 + (120*24) + (120*6*2) + (120*2*3) + 2500 + 120

using namespace std;



bool lenRepeated(int l, string a){
    if(a.size()%l != 0) return false;
    string s = "";
    for(int i = 0; i < l; i++) s += a[i];


    for(int i = 0;  i < a.length(); i+=s.length()){
        string temp = a.substr(i, s.length());
        //cout<<temp<<" ";
        if(s != temp) return false;
    }
    return true;


}


int main(){

    int testcases;
    cin>>testcases;
    while(testcases--){
        string s;
        cin>>s;
        int minv = INT_MAX;
        for(int i = 1; i <= s.length(); i++) if(lenRepeated(i, s)) minv = min(minv, i);
        cout<<minv<<endl;
        if(testcases != 0)cout<<endl;
    }



}
