#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;

int A,D;
float t,pA[5],pD[5];

		

int main(){
	ifstream in; ofstream out;
	in.open("input.txt"); out.open("output.txt");
	
	in>>t>>A>>D;
	
	for(int i=0;i<A;i++){
		float temp,pI,pF;
		in>>temp>>pI>>temp>>pF;
		pA[i]=(pF-pI)*t/10+pI;
	}
	
	for(int i=0;i<D;i++){
		float temp,pI,pF;
		in>>temp>>pI>>temp>>pF;
		pD[i]=(pF-pI)*t/10+pI;
	}
	
	sort(pA,pA+A);
	sort(pD,pD+D);
	
	if(pA[0]<pD[0])
		out<<"F";
	else
		out<<"R";
	
    in.close(); out.close();
    return 0;
}// 7 2 2 21 27 27 18 51 24 45 15 24 12 21 21 42 12 42 21
