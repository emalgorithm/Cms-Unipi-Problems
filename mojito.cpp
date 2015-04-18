#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
typedef pair<int,int> ii;

int x,y,N,xM,yM,c,v[105];
ii b[105],p[105];

int fN(int x,int y){
	int ind=0,t=(abs(b[0].first-x)+abs(b[0].second-y));
	for(int i=0;i<N;i++){
		if((abs(b[i].first-x)+abs(b[i].second-y)<t)){
			t=(abs(b[i].first-x)+abs(b[i].second-y));
			ind=i;
		}
		if((abs(b[i].first-x)+abs(b[i].second-y)==t)){
			if(b[i].first<b[ind].first)
				ind=i;
			if(b[i].first==b[ind].first)
				if(b[i].second<b[ind].second)
					ind=i;
		}
	}
	return ind;
}			

int main(){
	ifstream in; ofstream out;
	in.open("input.txt"); out.open("output.txt");
	in>>x>>y>>xM>>yM>>N;
	
	for(int i=0;i<N;i++)
		in>>b[i].first>>b[i].second>>p[i].first>>p[i].second;
	
	int ind=0;
	
	while(v[ind]<2){
		ind=fN(xM,yM);
		xM=p[ind].first; yM=p[ind].second;
		v[ind]++;
	}
	
	for(int i=0;i<N;i++)
		if(v[i]!=0)
			c++;
	out<<c;
	
    in.close(); out.close();
    return 0;
}
