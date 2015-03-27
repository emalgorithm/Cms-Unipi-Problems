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

int mat[104][104],ris[104][104],n,t,m;

int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
    
    in>>n;

    for(int i=0;i<n;i++)
        for(int j=0;j<i+1;j++)
            in>>mat[i][j];

    ris[0][0]=mat[0][0];
    t=1;
    for(int i=1;i<n;i++){
        ris[i][0]=ris[i-1][0]+mat[i][0];
        ris[i][t]=ris[i-1][t-1]+mat[i][t];
        t++;
    }

    for(int i=2;i<n;i++)
        for(int j=1;j<i;j++)
            ris[i][j]=max(ris[i-1][j-1],ris[i-1][j])+mat[i][j];
            
    for(int i=0;i<n;i++)
        m=max(m,ris[n-1][i]);
    
    out<<m;

    
    
    in.close(); out.close(); 
    return 0;
}
//5 7 3 8 8 1 0 2 7 4 4 4 5 2 6 5












