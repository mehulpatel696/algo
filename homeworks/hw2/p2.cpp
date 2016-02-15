
#include<iostream>
#include<cstdlib>
#include<vector>
#include<sstream>
#include<algorithm>
#include<unordered_set>
#include <algorithm>
#include <cstddef>
using namespace std;



//Put all the cars in an unordered set
// OYBG 3 1
// BGVO 0 3
// First base case
// if( dup > (n1_a + n1_b) || dup > (ne_a + ne_b) return flase;
// get same position
// if( same_position 0



int main()
{


    int testcases;
    cin>>testcases;
    while(testcases--){

        int t = 2;
        unordered_set<char> vals1, vals2;
        vector<char> v1,v2;
        char a;
        int l = 4;
        int n1_a, n1_b;
        while(l--)  {
            cin>>a;
            vals1.insert(a);
            v1.push_back(a);
        }

                cin>>n1_a>>n1_b;

        char b;
        int n2_a,n2_b;
        int dups = 0;
        l = 4;

        while(l--)  {
            scanf("%c", &b);
            if(vals1.find(b) != vals1.end()) dups++;
            vals2.insert(b);
            v2.push_back(b);
        }

        cin>>n2_a>>n2_b;
        int same_position = 0;
        for(int i = 0; i < v1.size();i++) if(v1[i] == v2[i]) same_position++;
        if(dups > (n1_a + n1_b) || dups > (n2_a + n2_b)) cout<<"CHEAT"<<endl;
        else if(0) cout<<"POSSIBLE"<<endl;




    }
    return 0;
}
