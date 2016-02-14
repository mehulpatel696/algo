
#include<iostream>
#include<cstdlib>
#include<vector>
#include<sstream>
#include<algorithm>
#include<unordered_set>
using namespace std;


#define rem(l,rm) for(vector<string>::iterator it = l.begin(); it != l.end(); it++) (*it).erase((*it).begin() + rm);
#define insert(set, vec) for(int i = 0; i < vec.size(); i++) set.insert(vec[i]);


int min_leds_needed(int rm, vector<string> l, int d){
    rem(l,rm);
    int m_d  = 0;
    unordered_set<string> ss;
    insert(ss,l);
    bool val = (ss.size() == l.size()) ? false : true;
    if(val) return d;
    else for(int i = 0; i < l[0].size(); i++) m_d = max(m_d,min_leds_needed(i, l,  d + 1));
    return m_d;
    return 0;
}


int main()
{
    int testcases;
    cin>>testcases;
    while(testcases--){
        int p,n,t;
        cin>>p>>n;
        t = p;
        vector<string> leds;
        while(n--){
            string led = "";
            while(p--){
                char l;
                cin>>l;
                led += l;
            }
            p = t;
            leds.push_back(led);
        }
        int m = 0;
        for(int i = 0; i < p; i++) m = max(m, min_leds_needed(i, leds, 0));
        cout<<p - m<<endl;
    }
    return 0;
}
