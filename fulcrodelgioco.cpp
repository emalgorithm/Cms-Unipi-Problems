#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int N,s[15],v[15],m,ind;
vector<int> g[15];

void DFS(int a, int b){
	v[a]=1;
	for(int j=0;j<g[a].size();j++)
		if(v[g[a][j]]==0 && g[a][j]!=b)
			DFS(g[a][j],b);
}
		

int main(){
	ifstream in; ofstream out;
	in.open("input.txt"); out.open("output.txt");
	
	in>>N;
	for(int i=0;i<N;i++){
		int t,t2;
		in>>t>>t2;
		g[t-1].push_back(t2-1);
	}
	
	for(int i=1;i<11;i++){
		DFS(0,i);
		for(int j=0;j<11;j++)
			if(v[j]==0)
				s[i]++;
		for(int j=0;j<11;j++)
			v[j]=0;
	}
	
	for(int i=1;i<11;i++)
		if(s[i]>m){
			m=s[i];
			ind=i;
		}
	
	out<<ind+1;
	
    in.close(); out.close();
    return 0;
}// 21 1 2 1 5 1 3 3 5 5 4 4 2 2 4 4 6 5 6 6 3 2 7 7 6 6 10 8 6 8 10 7 10 10 8 10 9 10 11 9 1 11 9

