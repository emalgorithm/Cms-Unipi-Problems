#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <utility>
#include <stdio.h>
#include <queue>
#include <fstream>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <math.h>
#include <string.h>

using namespace std;

typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;
typedef vector<vi> vvi; 

#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 

#define INF 999999999
#define MAX_N 100010
#define MOD 1000000007

//FILE * in; FILE * out;
ifstream in; ofstream out;

typedef vector<int> vi;
#define LSOne(S) (S & (-S))

class FenwickTree{
public:
    vi ft;
public:
    FenwickTree(int n){ ft.assign(n+1, 0); }
    int rsq(int a){
        int sum = 0;
        for(;a;a-=LSOne(a)) sum = (sum + ft[a]) % MOD;
        return sum;
    }
    void update(int value, int ind){
        for(;ind<ft.size();ind+=LSOne(ind)) ft[ind] = (ft[ind] + value) % MOD;
    }
};

int N, original[MAX_N];
ii sorted[MAX_N];
//vii sorted;

bool cmp(ii a, ii b){
    if(a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}

int b_s(int first, int last, int n) {
    int index;

    if (first > last)
        index = -1;

    else {
        int mid = (first + last) / 2;

        if (n == sorted[mid].first)
            index = mid;
        else

            if (n < sorted[mid].first)
            index = b_s(first, mid - 1, n);
        else
            index = b_s(mid + 1, last, n);
    }
    return index;
}

int main() {
    //in = fopen("input.txt","r"); out = fopen("output.txt","w");
    in.open("input.txt"); out.open("output.txt");
    
    //fscanf(in, "%d %d %d %d" , &N, &M, &A, &B);
    
    in>>N;
    sorted[0].first = sorted[0].second = original[0] = 0;
    FenwickTree myTree(N);
    for(int i=0;i< N;i++){

        in>>original[i+1];
        sorted[i+1].first = original[i+1];
        sorted[i+1].second = i + 1;
    }

    //sort(sorted.begin(), sorted.end(), cmp);
    sort(sorted + 1, sorted + N + 1, cmp);
    for(int i=1;i<=N;i++){
        int ind = b_s(1, N, original[i]);
        //while(sorted[ind].second != i) ind++;
        //cout<<ind<<endl;
        int pos = ind;
        if(sorted[ind].second != i){
            int k = ind;
            while(k <= N && sorted[k+1].first == sorted[k].first)
                if(sorted[++k].second == i){
                    pos = k;
                    break;
                }
            k = ind;
            while(k >=1 && sorted[k-1].first == sorted[k].first)
                if(sorted[--k].second == i){
                    pos = k;
                    break;
                }
        }
        //cout<<pos<<" ";
        int k = (myTree.rsq(pos) + 1) % MOD;
        myTree.update(k, pos); 
    }
    
    out<<myTree.rsq(N);
    
    in.close(); out.close();
    //fclose(in); fclose(out);
    return 0;
}

//5 1000 2 1 1000 1001