

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
#include <math.h>
#include <random>

using namespace std;






int main(){
    int n;
    string m;
   while(cin>>n>>m){
       map<string, int> tally;
       string max_string = "";
       int max_val = 0;
       for(int i = 0; i < m.size(); i++){
           string temp = "";
           for(int j = i; j < i + n; j++){
               temp += m[j];
           }
           tally[temp]++;
           if(tally[temp] > max_val){
               max_val = tally[temp];
               max_string = temp;
           }
       }
       cout<<max_string<<endl;
    }
    return 0;
}


