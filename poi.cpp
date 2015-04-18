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

int cS[2005],tV[2005],N,T,P,solved[2005][2005],pos=1,sT[2005];
                      
int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
    
    in>>N>>T>>P;
    P--;
    for(int i=0;i<N;i++)
        for(int j=0;j<T;j++){
            in>>solved[i][j];
            tV[j]+=(1-solved[i][j]);
            sT[i]+=solved[i][j];
        }
    
    for(int i=0;i<N;i++)
        for(int j=0;j<T;j++)
            if(solved[i][j])
                cS[i]+=tV[j];
    
    for(int i=0;i<N;i++){
        if(cS[i]>cS[P])
            pos++;
        if(i!=P && cS[i]==cS[P] && sT[i]>sT[P])
            pos++;
        if(i!=P && cS[i]==cS[P] && sT[P]==sT[i] && i<P)
            pos++;
    }
    
    out<<cS[P]<<" "<<pos;
        
    in.close(); out.close(); 
    return 0;
}




















