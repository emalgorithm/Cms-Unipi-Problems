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

int N,M,r[105],w[2005],p[2005],s;
queue<int> q;

int main(){
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
    
    in>>N>>M;//scanf("%d %d",&N ,&M);
    for(int i=0;i<N;i++) in>>r[i];//scanf("%d",&r[i]);
    for(int i=0;i<M;i++) in>>w[i];//scanf("%d",&w[i]);
    
    bitset<105> mask;
    int count=0;
    
    for(int i=0;i<2*M;i++){
        int t;
        in>>t;//scanf("%d",&t);
        if(t>0){
            if(count==N)
                q.push(t);
            else{
                for(int j=0;j<N;j++)
                    if(!mask.test(j)){
                        mask.set(j);
                        p[t-1]=j;
                        break;
                    }
                count++;
            }
        }
        if(t<0){
            t*=(-1);
            mask.set(p[t-1],0);
            s+=(w[t-1]*r[p[t-1]]);
            count--;
            if(!q.empty()){
                int m=q.front();
                q.pop();
                p[m-1]=p[t-1];
                mask.set(p[m-1]);
                count++;
            }
        }
    }
                    
    out<<s;//printf("%d",s);
    
    in.close(); out.close();
  
    return 0;
}
//3 4 2 3 5 200 100 300 800 3 2 -3 1 4 -4 -2 -1


