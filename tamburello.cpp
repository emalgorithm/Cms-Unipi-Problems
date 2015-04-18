#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <fstream>


using namespace std;

int main()
{  int N,array[100000]={0},k,temp=0,mini=100000,i;
ifstream in;
in.open("input.txt");
ofstream out;
out.open("output.txt");
   in>>N;
   for(i=1;i<=N;i++) 
   	         in>>array[i];
   for(i=1;i<=N/2;i++) {
   	         if(N%i==0) {
   	         	for(int j=1;j<=(N-i);j++) {
   	         	    if(array[j]==array[j+i])
						temp+=1;
					}
   	         	if(temp==N-i) {
   	         		mini=i;
   	         		break;
   	         		}
				}
   	           temp=0;
   }
   if(mini==100000)
   out<<"2"<<endl;
   else {
   	for(i=1;i<=mini;i++)
   	out<<array[i]<<" ";     
}
in.close();
out.close(); }
