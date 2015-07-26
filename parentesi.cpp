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

#define INF 1000000005
#define MAX_N 4000005
#define MOD int(1e9)+7
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int n;
string v;
bool cond = true;


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>v; 
    for(string::iterator it=v.begin();it!=v.end()-1;it++){
        if(it < v.begin())
            continue;
        char c = *it, c1 = *(it+1);
        if(c == '(' && c1 == ')'){
            v.erase(it,it+2);     
            it -=2;
        }
        else if(c == '[' && c1 == ']'){
            v.erase(it,it+2);
            it -= 2;
        }
        else if(c == '{' && c1 == '}'){
            v.erase(it,it+2);
            it -= 2;
        }
        else if(c == '<' && c1 == '>'){
            v.erase(it,it+2);
            it -= 2;
        }
    }
    if(v.length()==0)
        cout<<"corretta";
    else
        cout<<"malformata";
    return 0;
}
