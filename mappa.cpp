#include <cstdlib>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <fstream>

using namespace std;

typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;



int N,d[10005];
char lab[105][105];
vi g[10005];

int main(){
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
    
    in>>N;
    for(int i=0;i<N*N;i++)
        d[i]=-1;
    for(int i=0;i<N;i++)
         for(int j=0;j<N;j++)
             in>>lab[i][j];
    
    for(int i=0;i<N;i++)
         for(int j=0;j<N;j++)
              if(lab[i][j]=='*')
                   for(int k=i-1;k<=i+1;k++)
                        for(int m=j-1;m<=j+1;m++)
                             if((k>=0 && m>=0) && (k!=i || m!=j) && lab[k][m]=='*' )
                                    g[i*N+j].push_back(k*N+m);
                                           
    
    queue<int> q;
    q.push(0);
    d[0]=1;
    while(!q.empty()){
        int nodo=q.front();
        q.pop();
        for(int i=0;i<g[nodo].size();i++)
            if(d[g[nodo][i]]==-1){
                d[g[nodo][i]]=d[nodo]+1;
                q.push(g[nodo][i]);
            }
    }
    
    /*for(int i=0;i<N*N;i++){
        cout<<i<<": ";
        for(int j=0;j<g[i].size();j++)
            cout<<g[i][j]<<" ";
        cout<<endl;
    }*/
    
    out<<d[N*N-1];
                                             
    in.close(); out.close();
    return 0;
}
