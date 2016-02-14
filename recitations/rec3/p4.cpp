#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct Node{
    Node* parent;
    int rank;
    int data;
};


class DisjointSet {

public:

    unordered_map<int, Node*> elms;

    void makeSet(int data){
        Node* temp  = new Node();
        temp->data = data;
        temp->rank = 0;
        temp->parent = temp;
        pair<int, Node*> p(data, temp);
        elms.insert(p);
    }

    int findSet(int a){
        return findSet(elms[a])->data;
    }

    Node* findSet(Node* a){
        if(a == nullptr) return a;
        if( a == a->parent ) return a->parent;
        a->parent  = findSet(a->parent);
        return a->parent;
    }

    void unionS(int a, int b){
        Node* n1 = elms[a];
        Node* n2 = elms[b];
        Node* p1 = findSet(n1);
        Node* p2 = findSet(n2);
        if(p1 != nullptr && p2 != nullptr){
            if(p1->rank >= p2->rank){
                p1->rank = (p1->rank == p2->rank) ? p1->rank + 1 : p1->rank;
                p2->parent = p1;
            } else p1->parent = p2;
        }
    }

};


int main() {

    int n,m;
    int c = 1;
    while(cin>>n>>m){
        if(n == 0 && m == 0) break;
        DisjointSet temp;
        for(int i = 1; i <= n; i++) temp.makeSet(i);

        int diff_religions = n;
        for(int i = 0; i < m; i++) {
            int a,b;
            cin>>a>>b;
            temp.unionS(a,b);
        }
        unordered_map<int, vector<int> > temp2;
        for(unordered_map<int, Node*>::iterator i = temp.elms.begin(); i != temp.elms.end(); i++) temp2[i->second->parent->data].push_back(i->second->data);
        for(unordered_map<int, vector<int> >::iterator e = temp2.begin(); e != temp2.end(); e++){
            diff_religions -= (e->second.size());
        }
        diff_religions += temp2.size();
        cout<<"Case "<<c<<": "<<diff_religions<<endl;
        c++;
    }

    return 0;
}
