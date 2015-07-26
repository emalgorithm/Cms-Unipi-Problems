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
#define MAX_N 2000005
 
int N,M,a[MAX_N],counter;

int main() {
    
    #ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    scanf("%d %d",&M,&N);
    for(int i=0;i<N;i++)
        scanf("%d",&a[i]);
    
    int r = -1, l = -1, sum = 0;
    while(l < N && r < N){
        while(sum < M || r <= l){
            r++;
            if(r == N)
                break;
            sum += a[r];
            if(sum == M && l != r){
                //cout<<l<<" "<<r<<endl;
                counter ++;
                int t = r;
                while(++t < N &&  a[t] == 0){
                    //cout<<l<<" "<<t<<endl;
                    counter ++;
                }
            }
            
        }
        while(sum >= M && l < r){
            l++;
            if(l == N)
                break;
            sum -= a[l];
            if(sum == M && l != r){
                //cout<<l<<" "<<r<<endl;
                counter ++;
                int t = r;
                while(++t < N &&  a[t] == 0){
                    //cout<<l<<" "<<t<<endl;
                    counter ++;
                }
            }
        }
    }
    
    printf("%d",counter);//cout<<counter;
    return 0;
}

//9 20 2 3 0 4 0 3 1 0 1 0 1 0 0 0 5 0 4 0 0 2