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
#include <bitset>
#include <string.h>
 
#define MAX_N 500000
 
#define N_CHAR 130
 
using namespace std;
 
typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;
typedef pair< ii, ii> iiii;
 


int N,curr=1, printable[MAX_N], v[MAX_N],color[MAX_N];
vii g[MAX_N];
vector<char> sol;
string longer;

void dfs(int n){
    v[n] = 1;
    
    while(printable[n]-- > 0)
        sol.push_back('P');
    
    for(int i=0;i<g[n].size();i++)
        if(!v[g[n][i].first] && !color[g[n][i].first]){
            sol.push_back(char('a'+g[n][i].second));
            dfs(g[n][i].first);
        }
    
    for(int i=0;i<g[n].size();i++)
        if(!v[g[n][i].first] && color[g[n][i].first]){
            sol.push_back(char('a'+g[n][i].second));
            dfs(g[n][i].first);
        }
    sol.push_back('-');        
}

void colorLonger(int n, int ind){
    if(ind == longer.size())
        return;
    for(int i=0;i<g[n].size();i++)
        if(char(g[n][i].second+'a') == longer[ind]){
            color[g[n][i].first] = 1;
            colorLonger(g[n][i].first,ind+1);
            break;
        }
}

int main() {
    
    #ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        char word[40];
        scanf("%s",word);
        string sWord(word);
        if(sWord.length() > longer.length())
            longer=sWord;
        int node = 0;
        
        for(int j=0;j<sWord.length();j++){
            int cond = false;
            for(int k=0;k<g[node].size();k++)
                if(g[node][k].second == sWord[j]-'a'){
                    cond = true;
                    node = g[node][k].first;
                    break;
                }
            if(!cond){
                g[node].push_back(make_pair(curr++,sWord[j]-'a'));
                node = curr-1;
            }
            if(j == sWord.length()-1)
                printable[node]++;
        }
    }
    
    /*for(int i=0;i<13;i++){
        for(int j=0;j<g[i].size();j++)
            cout<<g[i][j].first<<" "<<char(g[i][j].second+'a')<<"      ";
        cout<<endl;
    }*/
    colorLonger(0,0);
    
    //for(int i=0;i<15;i++)
      //  cout<<color[i]<<" ";
    //for(int i=0;i<15;i++)
        //cout<<printable[i];
    
    dfs(0);
    int l = sol.size() - 1;
    while(l >= 0 && sol[l]=='-')
        l--;
    printf("%d\n",l+1);
    for(int i=0;i<=l;i++)
        printf("%c\n",sol[i]);
    return 0;
}

//3 the poem print

//7 6 4 2 5 2 6 2 4 3 4 4 4 5 4 6 









