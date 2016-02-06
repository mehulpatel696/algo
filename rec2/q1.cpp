#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int test_cases;
    cin>>test_cases;
    while(test_cases > 0){
        int stores;
        cin>>stores;
        vector<int> store_nums(stores,0);
        int counter = 0;
        while(stores){
            int temp;
            cin>>temp;
            store_nums[counter] = temp;
            counter++;
            stores--;
        }
        sort(store_nums.begin(), store_nums.end());
        int min_distance = (store_nums[store_nums.size() - 1] - store_nums[0]) * 2;
        cout<<min_distance<<endl;
        test_cases--;
    }
    return 0;
}