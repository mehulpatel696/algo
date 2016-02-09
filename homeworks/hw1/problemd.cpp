#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <unordered_set>
#include <unordered_map>
using namespace std;
/*
 *1.Take the number of friends
  2.Take how much each friend owes or is owed
  3.See who is talking to whom at any given time
  4.Now that you have all of this information figure out if every one can get their money back
    HOW DO WE DO THAT

 *
 *
 * */
int main(){
    int testcases;
    cin>>testcases;
    while(testcases){
        int n, m;
        cin>>n>>m;
        vector<int> owed(n);
        vector< pair<int,int> > friends(m);
        for(int i = 0; i < n; i++) cin>>owed[i];
        for(int i = 0; i < m;i++){
            int a,b;
            cin>>a>>b;
            pair<int,int> temp(a,b);
            friends.push_back(temp);
        }
        unordered_map<int, unordered_set<int> > friends_map;
        for(int i = 0; i < friends.size(); i++){
            friends_map[friends[i].first].insert(friends[i].second);
            friends_map[friends[i].second].insert(friends[i].first);
        }

        //Print the set and check if it worked
        for(unordered_map<int, unordered_set<int> >::iterator i =  friends_map.begin(); i != friends_map.end(); i++)
        {
             cout<<i->first<<" : ";
             for(unordered_set<int>::iterator j  =  (i->second).begin(); j != (i->second).end(); j++){
                  cout<<*j<<" ";
             }

        }
        testcases--;
    }
    return 0;

}
