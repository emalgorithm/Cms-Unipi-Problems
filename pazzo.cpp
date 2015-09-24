#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int N,M,s;

int main() {
	ifstream in; ofstream out;
	in.open("input.txt"); out.open("output.txt");
	in>>N>>M;
	
	for(int i=0;i<M;i++){
		int t,t2;
		in>>t>>t2;
		if(t==s)
		  s=t2;
		else if(s==t2)
		  s=t;
	}
	
    out<<s;
    
    in.close(); out.close();
    return 0;
}

