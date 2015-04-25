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

using namespace std;

typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;

int N,M,c[505][505],mini=999999999;
ii s[25],posS[25],diff,ind;
                      
int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
    
    in>>N>>M;
    for(int i=0;i<M;i++)
        in>>s[i].first>>s[i].second;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            in>>c[i][j];
    
    for(int i=1;i<M;i++){
        posS[i].first=s[i].first-s[0].first;
        posS[i].second=s[i].second-s[0].second;
    }
    
    diff.first=-s[0].first; diff.second=-s[0].second;
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            int cost=0;
            bool b=true;
            for(int k=0;k<M;k++){
                if(i+posS[k].first<N && i+posS[k].first>=0 && j+posS[k].second<N && j+posS[k].second>=0)
                    cost+=c[i+posS[k].first][j+posS[k].second];
                else{
                    b=false;
                    break;
                }
            }
            if(b && cost<mini){
                mini=cost;
                ind.first=i;
                ind.second=j;
            }
        }
    out<<ind.first+diff.first<<" "<<diff.second+ind.second<<" "<<mini;

    in.close(); out.close(); 
    return 0;
}



//5 3 0 0 1 1 0 1 4 7 8 6 4 6 7 3 10 2 3 8 1 10 4 7 1 7 3 7 2 9 8 10 3

//














