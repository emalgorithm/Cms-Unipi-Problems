
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <stdio.h>

#define INF 999999999;

using namespace std;

int grid[55][55], cost[55][55], N, M;
int memo[55][55][55][55];

int cut(int left, int right, int up, int down){
    if(left == right -1 && up == down - 1)
        return 0;
    if(memo[left][right][up][down] != 0) return memo[left][right][up][down];
    int sol = INF;
    
    int c = 0;
    for(int j=up;j<down;j++)
        c += cost[j][right-1] - (left > 0 ? cost[j][left-1] : 0) ;
    
    for(int i=left+1;i<right;i++)
        sol = min(sol, cut(left,i,up,down) + cut(i,right,up,down) + c );
    for(int i=up+1;i<down;i++)
        sol = min(sol, cut(left,right,up,i) + cut(left,right,i,down) + c);
    return memo[left][right][up][down] = sol;
}

int main() {
    
    #ifdef EVAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    scanf("%d %d",&N,&M);
    
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            scanf("%d",&grid[i][j]);
    
    for(int i=0;i<N;i++){
        int c = 0;
        for(int j=0;j<M;j++){
            c += grid[i][j];
            cost[i][j] = c;
        }
    }
    
    cout<<cut(0,M,0,N);

    return 0;
}

