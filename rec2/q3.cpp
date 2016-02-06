#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>

using namespace std;

int main(){
    
    int temp;
    vector<int> ints;
    while(cin>>temp) ints.push_back(temp);
  
    unordered_map<int, int> count;
    for(int i = 0; i < ints.size();i++){
        count[ints[i]]++;
        //remove_dups.insert(ints[i]);
    }
    
    
    
    for(int i = 0; i < ints.size();i++){
        if(count.find(ints[i]) != count.end()){
            cout<<ints[i]<<" "<<count[ints[i]]<<endl;
            count.erase(ints[i]);
        }
        
    }
    
    
    return 0;
}