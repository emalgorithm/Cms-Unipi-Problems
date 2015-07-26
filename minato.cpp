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

using namespace std;

typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;

int r,c,s,nP[10005];
bool v[10005];
char mat[105][105];
vi g[10005],ts;

void dfs(int nodo){
	v[nodo]=true;   
    for(int i=0;i<g[nodo].size();i++)
    	if(!v[g[nodo][i]])
        	dfs(g[nodo][i]);
    ts.push_back(nodo);
}
    
                      
int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
    
    in>>r>>c;
    
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            in>>mat[i][j];
    
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            if(i<r-1 && mat[i][j]=='*' && mat[i+1][j]=='*')
                g[i*c+j].push_back((i+1)*c+j);
            if(j<c-1 && mat[i][j]=='*' && mat[i][j+1]=='*')
                g[i*c+j].push_back(i*c+j+1);
            //if(j<c-1 && i<r-1 && mat[i][j]=='*' && mat[i+1][j+1]=='*')
              //  g[i*c+j].push_back((i+1)*c+j+1);
        }
    
    dfs(0);
    
    reverse(ts.begin(),ts.end());
  
    nP[ts[0]]=1;
    
    for(int i=0;i<ts.size();i++)
    	for(int j=0;j<g[ts[i]].size();j++)
    		nP[g[ts[i]][j]]+=nP[ts[i]];
    
    out<<nP[r*c-1]; 
        
    in.close(); out.close(); 
    return 0;
}

