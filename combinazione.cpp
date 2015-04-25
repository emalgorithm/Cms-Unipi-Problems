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
#define MAX_N 5001000
#define MOD 1000000007

//FILE * in; FILE * out;
ifstream in; ofstream out;

int N, med[MAX_N];
ii sol[MAX_N];

int main() {
    //in = fopen("input.txt","r"); out = fopen("output.txt","w");
    in.open("input.txt"); out.open("output.txt");
    
    //fscanf(in, "%d %d %d %d" , &N, &M, &A, &B);
    in>>N;
    for(int i=0;i<N;i++) in>>med[i];
    for(int i=0;i<N-1;i++){
        sol[i].first =(i == 0 ? (2 * med[i] - med[i+1]) : max(sol[i-1].second,2 * med[i] - med[i+1]));
        sol[i].second = med[i];
    }
    //for(int i=0;i<N;i++)
      //  cout<<sol[i].first<<" "<<sol[i].second<<endl;
    for(int i=N-2;i>0;i--){
        sol[i-1].first = max(sol[i-1].first, med[i-1] * 2 - sol[i].second);
        sol[i-1].second = min(sol[i-1].second, med[i-1] * 2- sol[i].first);
    }
    //cout<<endl<<endl;
    //for(int i=0;i<N;i++)
    //    cout<<sol[i].first<<" "<<sol[i].second<<endl;
    int s = sol[0].second - sol[0].first;
    s++;
    s = max(s, 0);
    out<<s;
    in.close(); out.close();
    //fclose(in); fclose(out);
    return 0;
}

//-1 15 19 34 -3 45 -3 -1 21 18 -2 91 72 -4 81 29 -1 47 -2 84 65 -4 12 58 -2 

//5 10 10 10 10 10 0 1 1 2 2 3 3 4
