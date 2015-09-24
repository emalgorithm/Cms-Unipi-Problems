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

#define MAX_N 20000005

#define N_CHAR 130

using namespace std;

typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;

int n,m,c;
string W,S;
int car[N_CHAR];
int temp[N_CHAR];

int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
    
    in>>n>>m>>S>>W;
    
    for(int i=0;i<n;i++)
        car[(int)(S[i])]++;
    
  
    
    for(int i=0;i<m-n+1;i++){
        bool cond=true;
        for(int j=i;j<i+n;j++){
            if(car[int(W[j])])
                temp[(int)(W[j])]++;
            else{
                cond=false;
                break;
            }
        }
        if(cond)
            for(int j=0;j<N_CHAR;j++)
                if(car[j]!=temp[j]){
                    cond=false;
                    break;
                }
        for(int j=0;j<N_CHAR;j++)
            temp[j]=0;
        if(cond)
            c++;
    }
    out<<c;
     
    in.close(); out.close(); 
    return 0;
}


//4 11 cAda AbrAcadAbRa










