#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
typedef pair<int,int> ii;

int N,g[105];

		

int main(){
	ifstream in; ofstream out;
	in.open("input.txt"); out.open("output.txt");
	
	int m=0,ind;
	in>>N;
	
	for(int i=0;i<N;i++){
		int t,t2;
		in>>t>>t2;
		g[t]+=t2;
	}
	
	for(int i=0;i<105;i++)
		if(g[i]>m){
			m=g[i];
			ind=i;
		}
	out<<ind<<" "<<m;
	
    in.close(); out.close();
    return 0;
}
