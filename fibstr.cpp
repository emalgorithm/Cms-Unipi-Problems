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
 
#define MAX_N 1000005
 
#define N_CHAR 130
 
using namespace std;
 
typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;
 
int N,sol=1,indI,indF;
string fib="a",S;
vi f;
 
int main() {
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
   
    in>>N>>S;
 
    f.push_back(1); f.push_back(2);
    for(int i=2;i<30;i++)
        f.push_back(f[i-1]+f[i-2]);
       
 
    for(int i=0;i<N-1;i++){
        char t=S[i],t2=S[i+1];
        if(t==t2)
            continue;
       
        int shift = 2,fibNum = 0, cond = true;
       
        while(cond){
            for(int j = i ; j < i + f[fibNum]; j++)
                if(S[j] != S[j + shift]){
                    cond = false;
                    break;
                }
            if(cond)
                shift += f[fibNum++];                  
        }
        
        if(shift > sol){
                sol = shift;
                indI = i;
                indF = i+shift-1;
        }        
       
    }
   
    out<<indI+1<<" "<<indF+1;
    in.close(); out.close();
    return 0;
}
//25 abcdbeababcdeebeedeedcacb
