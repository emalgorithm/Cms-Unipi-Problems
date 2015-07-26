#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

char s16[] = "VFFHHHHHHHQQQQGG";
char s32[] = "VFFFFHHHHHHHHHHHHHHQQQQQQQOOOOGG";
char s64[] = "VFFFFFFFHHHHHHHHHHHHHHHHHHHHHHHHHHHHQQQQQQQQQQQQQQOOOOOOOOSSSSGG";

int main() {
	ifstream in; ofstream out;
	in.open("input.txt"); out.open("output.txt");
	int M, me, i, ind=0;
	in>>M>>me;
	for(i=1; i<M; i++){
		int t;
		in>>t;
		if(t>me) ind++;
	}
	if(M==16) out<<s16[ind];
	if(M==32) out<<s32[ind];
	if(M==64) out<<s64[ind];
		
    in.close(); out.close();
    return 0;
}

