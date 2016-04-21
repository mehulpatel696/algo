

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
    string m;

    while(cin>>m){
        if(m == ".") break;
        map<string, int> vals;
        int max_val = 1;

            for(int j = 1; j < m.size(); j++){
               string last = "";
                 for(int l = 0; l < m.size() - j + 1; l += j){
                    string temp = "";
                    for(int k = 0 + l; k < j + l; k++) temp += m[k];
                    //cout<<last<<" "<<temp<<endl;
                    vals[temp]++;
                    if(last == "")  last = temp;
                    else {
                        if(last != temp) break;
                        last = temp;
                        if(vals[temp] > max_val) max_val = vals[temp];
                    }

                }

            }

        cout<<max_val<<endl;

    }

    return 0;
}


