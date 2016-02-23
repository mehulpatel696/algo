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
#include <climits>

using namespace std;
#define printv(a) for(int i = 0; i < a.size(); i++) cout<<a[i]<<endl;

void bitRep(vector<string> &arr){
    for(int i = 0; i < (1<<15);i++){
        bitset<15> bit(i);
        arr.push_back(bit.to_string());
    }
}

bool hasDups(vector<string> arr){
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size() - 1; i++) if(arr[i] == arr[i+1]) return true;
    return false;
}

int min_leds(vector<string> &givens, vector<string> reps){
    int min_leds = INT_MIN;
    for(int i = 0; i < reps.size(); i++){
        unordered_set<int> temp;
        bitset<15> tt(reps[i]);
        int temp_set = tt.count();
        for(int j = 0; j < givens.size();j++){
           int result = stoi(givens[j]) & (~stoi(reps[i]));
           temp.insert(result);
        }
        if(temp.size() != givens.size()) return min_leds;
        min_leds = (min_leds < temp_set) ? temp_set : min_leds;

    }
    return min_leds;
}

int main(){

    int testcases;
    vector<string> reps;
    bitRep(reps);
    cin>>testcases;
    int n,p;
    while(testcases--){
        cin>>p>>n;
        vector<string> nums;
        for(int i = 0; i < n; i++){
            string temp;
            for(int j = 0; j < p;j++){
                char t;
                cin>>t;
                temp += t;
            }
            nums.push_back(temp);
        }
        cout<< p - min_leds(nums, reps)<<endl;
    }
    return 0;
}
