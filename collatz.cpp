#include <iostream>
#include <fstream>
using namespace std;

int n,c;

int main(){
	ifstream in; ofstream out;
	in.open("input.txt"); out.open("output.txt");
	
	in>>n;
	c++;
	while(n!=1){
		c++;
		if(n%2==0)
			n/=2;
		else
			n=n*3+1;
	}
	out<<c;
    
    in.close(); out.close();
    return 0;
}
