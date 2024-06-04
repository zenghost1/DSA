#include <bits/stdc++.h>
using namespace std;


class fenwick
{
private:
    int N = 100005;
    vector<int> T;
    
public:

    fenwick(){
        T.resize(N, 0);
    }
    void update(int id, int val)
    {
        while (id < N)
        {
            T[id] += val;
            id += (id & -id);
        }
    }

    // query from 1 to id
    int query(int id)
    {
        int ans = 0;
        while (id > 0)
        {
            ans += T[id];
            id -= (id & -id);
        }
        return ans;
    }

    // to get range sum [l,r] find range [1,r] - [1,l-1] and this will give you the range from l->r;
    int rangesum(int l, int r)
    {
        return query(r) - query(l - 1);
    }

    // lower-bound in prefix sums array *Binary lifting* in array
    int find_lb(int k){
        int curr = 0, ans = 0, prevSum = 0;
        for(int i= log2(N); i>=0; i--){
            if(T[curr + 1<<i] + prevSum < k){
                curr += 1<<i;
                prevSum += T[i];
            }
        }
        return (curr+1);
    }

    void print(){
        for(int i=1; i<17; i++){
            cout<< T[i] << " ";
        }
    }

};

int main(int argc, char const *argv[])
{
    int arr[17] = {0,1,0,2,1,1,3,0,4,2,5,2,2,3,1,0,2};
    
    fenwick F = fenwick();

    for(int i=1; i<17; i++){
        F.update(i,arr[i]);
    }

    F.print();

    return 0;
}
