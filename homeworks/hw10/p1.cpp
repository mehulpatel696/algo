

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



long long vals[10000] = {-1};
char winner[10000] = { 'n' };


void fill(){

    long long i = 1;
    bool nine = true;
    int counter = 0;
    while(i < 4294967295){
        vals[counter] = i;
        if(nine){
            winner[counter++] = 'o';
            i *= 9;
            nine = false;
        } else {
            winner[counter++] = 's';
            i *= 2;
            nine = true;
        }
    }
}

int main(){

    int n;
    string s = "Stan wins.";
    string o = "Ollie wins.";
    fill();
    while(cin>>n){
       int i = 1;
        while(vals[i] < n) i++;
        char w = winner[i];
        if(w == 's') cout<<s<<endl;
        else cout<<o<<endl;
   }



}
