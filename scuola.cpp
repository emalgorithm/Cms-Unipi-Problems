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
#include <math.h>
#include <string.h>
#include <stdlib.h> 

using namespace std;

typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;
typedef vector<vi> vvi; 
typedef pair< int, string > is;

#define pb push_back 
#define MAX_N 200005
 
int N,P;

int main() {
    
    #ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    scanf("%d %d",&N,&P);
    if(P == 1){
        int counter = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                cout<<j+1<<" "<<(j+counter)%N+1<<" ";
            cout<<endl;
            counter = (counter+1)%N;
        }             
    }
    else{
        deque<int> in, out;
        for(int i=0;i<N/2;i++){
            in.push_back(i+1);
            out.push_back(N-i);
        }
        for(int i=0;i<N-1;i++){
            deque<int>::iterator it,it2;
            for(it=in.begin(),it2=out.begin();it!=in.end(),it2!=out.end();it++,it2++)
                printf("%d %d ",*it,*it2);//cout<<*it<<" "<<*it2<<" ";
            printf("\n");
            
            int t = out.front(); 
            out.pop_front();
            int fix = in.front();
            in.pop_front();
            int last = in.back();
            in.pop_back();
            in.push_front(t);
            in.push_front(fix);
            out.push_back(last);
        }
    }
    
    return 0;
}

//5 8 5 4 1 1 2 1 1 3 1 3 2 1 1 5 0 1 4 1 3 4 0 2 5 1