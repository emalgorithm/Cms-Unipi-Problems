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

int N,s[55]; 
ifstream in; ofstream out;

void ric(int curr, int c, int p){
       if(c==N){
            for(int i=0;i<p;i++)
                out<<s[i]<<" ";
            out<<endl;
        }
        for(int i=1;i<=curr;i++)
            if(i+c<=N){
                s[p]=i;
                ric(i,c+i,p+1);
            }
}

int main(){
    
    in.open("input.txt"); out.open("output.txt");
    
    in>>N;
    
    for(int i=0;i<N;i++){
        s[0]=i+1;
        ric(i+1,i+1,1);
    }

    in.close(); out.close();
    return 0;
}



