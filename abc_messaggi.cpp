#include <math.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <utility>
#include <functional>
#include <queue>
#include <map>
#include <set>

#define MAX_N 1000005
#define INF 1000000005
#define MOD 1000000007

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int n, m;
map< string, vector< string > > sent, rec;

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        string a, b;
        cin>>a>>b;
        sent[a].push_back(b);
        rec[b].push_back(a);
    }

    for(int i=0;i<m;i++){
        string a, b;
        cin>>a>>b;
        if(b == "INVIATI"){
            cout<<sent[a].size()<<" ";
            for(int i=0;i<sent[a].size();i++)
                cout<<sent[a][i]<<" ";
            cout<<endl;
        }
        if(b == "RICEVUTI"){
            cout<<rec[a].size()<<" ";
            for(int i=0;i<rec[a].size();i++)
                cout<<rec[a][i]<<" ";
            cout<<endl;
        }
    }


    return 0;
}

