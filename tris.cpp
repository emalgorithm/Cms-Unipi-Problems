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

char m[10][10];
int nO, nX;

int tris(){
    bool trisX = false, trisO = false;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            if(i == 0)
                if(m[i][j] != '.' && m[i][j] == m[i+1][j] && m[i+1][j] == m[i+2][j])
                    m[i][j] == 'X' ? trisX = true : trisO = true;
            if(j == 0)
                if(m[i][j] != '.' && m[i][j] == m[i][j+1] && m[i][j+1] == m[i][j+2])
                    m[i][j] == 'X' ? trisX = true : trisO = true;
            if(i == 0 && j == 0 && m[i][j] != '.' && m[i][j] == m[i+1][j+1] && m[i+1][j+1] == m[i+2][j+2])
                m[i][j] == 'X' ? trisX = true : trisO = true;
            if(i == 0 && j == 2 && m[i][j] != '.' && m[i][j] == m[i+1][j-1] && m[i+1][j-1] == m[i+2][j-2])
                m[i][j] == 'X' ? trisX = true : trisO = true;
        }
    if(!trisX && !trisO)
        return -1;
    if(trisX)
        return 1;
    if(trisO)
        return 0;
}

bool ric(int n1, int n2){
    int trisRes = tris();
    if(trisRes != -1)
        return trisRes;
    if(n1+n2 >= 9)
        return false;
    if(n2 >= n1){
        bool cond = false;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(m[i][j] == '.'){
                    m[i][j] = 'X';
                    if(ric(n1+1, n2))
                        cond = true;
                    m[i][j] = '.';
                }
        return cond;
    }
    else{
        bool cond = true;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(m[i][j] == '.'){
                    m[i][j] = 'O';
                    if(!ric(n1, n2+1))
                        cond = false;
                    m[i][j] = '.';
                }
        return cond;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            cin>>m[i][j];
            if(m[i][j] == 'O') nO++;
            if(m[i][j] == 'X') nX++;
        }
    cout<<(ric(nX, nO) ? 1 : 0);
    return 0;
}
