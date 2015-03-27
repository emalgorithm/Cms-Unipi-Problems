#include <cstdlib>
#include <iostream>
#include <math.h>
#include <fstream>
#include <string>

using namespace std;
ifstream in; ofstream out;

int N,p[30];

void ric(int t){
	if(t==N){
		for(int i=0;i<N;i++){
			if(p[i]==1)
				out<<"[O]";
			if(p[i]==2){
				out<<"[OOOO]";
				i++;
			}
		}
		out<<endl;
		return;
	}
	p[t]=1;
	ric(t+1);
	if(t<N-1){
		p[t]=2;
		ric(t+2);
		p[t]=0;
	}
}

    
int main(){
    in.open("input.txt"); out.open("output.txt");
    
    in>>N;
	ric(0);
    
    in.close(); out.close();
    return 0;
}
