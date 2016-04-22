

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

unordered_map<char, int> conversion_c_i;
unordered_map<int, char> conversion_i_c;



void fillConversion(){
    char arr[28] = {'_','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','.'};
    for(int i = 0; i < 28; i++){
        conversion_c_i[arr[i]] = i;
        conversion_i_c[i] = arr[i];
    }


}
int main(){
    fillConversion();
    int k;
    while(cin>>k){

        if(k == 0) return 0;
        string text;
        cin>>text;

        char plaintext[text.length()];
        char ciphertext[text.length()];
        int plaincode[text.length()];
        int ciphercode[text.length()];

        for(int i = 0; i < text.length(); i++) ciphertext[i] = text[i];
        for(int i = 0; i < text.length(); i++) ciphercode[i] = conversion_c_i[text[i]];

        int n = text.length();

        for(int i=0;i<n;i++){
            int pos=(i*k)%n;
            int val=(ciphercode[i]+i)%28;
            plaincode[pos]= val;
        }

        for(int i = 0; i < text.length(); i++) plaintext[i] = conversion_i_c[plaincode[i]];

        for(int i = 0; i < text.length(); i++) cout<<plaintext[i];
        cout<<endl;








    }



}
