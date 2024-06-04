#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
private:
    vector<int> rank;
    vector<int> par;
public:
    DisjointSet(){
        rank.resize(n,0);
        par.resize(n,0);
        for(int i=0; i<n; i++) par[i] = i;
    }

    int findpar(int u){
        if(par[u] == u) return u;
        par[u] = findpar(par[u]);
    }

    void unionbyrank(int u, int v){
        int pu = findpar(u);
        int pv = findpar(v);

        if(pu == pv) return;

        if(rank[pu] > rank[pv]){
            par[pv] = pu;
        }else if(rank[pv] > rank[pu]){
            par[pu] = pv;
        }else{
            par[pu] = pv;
            rank[pv]++;
        }
    }
}






int main(int argc, char const *argv[])
{
    
    return 0;
}
