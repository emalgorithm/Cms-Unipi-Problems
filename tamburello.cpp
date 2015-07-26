#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>

#define MAX_N 100005

using namespace std;

int readInt(){
    int n = 0;
    int ch = getchar_unlocked();
    int sign = 1;
    while(ch < '0' || ch > '9'){
        if(ch == '-') 
            sign = -1; 
        ch = getchar_unlocked();
    }

    while(ch >= '0' && ch <= '9'){
            n = (n << 3) + (n << 1) + ch - '0';
            ch = getchar_unlocked();
    }
    n *= sign;
    return n;
}   

int N, array[MAX_N], temp ,mini = MAX_N;

int main(){
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

   N = readInt();
   
   for(int i = 0; i < N; i++) 
       array[i] = readInt();
   
   for(int i = 1; i <= N / 2; i++) {
   	         if(N % i==0) {
   	         	for(int j = 0; j < (N - i); j++) {
   	         	    if(array[j] == array[j + i])
						temp += 1;
					}
   	         	if(temp == N - i) {
   	         		mini = i;
   	         		break;
   	         		}
				}
   	           temp = 0;
   }
   if(mini == MAX_N)
       cout<<"2"<<endl;
   else {
   	   for(int i=0; i < mini; i++)
   	       cout<<array[i]<<" ";     
   }
   
   return 0;
}
