#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
    int number;
    while(cin >> number){
        vector<int> numbers;
        vector<int> difference;
        for(int i = 0; i < number; i++){
            int temp;
            cin>>temp;
            numbers.push_back(temp);
        }
        for(int i = 0; i < number - 1; i++) difference.push_back(abs(numbers[i] - numbers[i+1]));
        sort(difference.begin(), difference.end());
        bool isJolly = true;
        for(int i = 0; i < difference.size(); i++){
            if(difference[i] != i+1){
                isJolly = false;
                break;
            }
        }
        if(isJolly) cout<<"Jolly";
        else cout<<"Not jolly";
        cout<<endl;
    }
    return 0;
}






