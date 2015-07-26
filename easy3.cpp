#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>

using namespace std;

int N, evenMax = -1, evenSec = -1, oddMax = -1, oddSec = -1, sol;

int main() {
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    in >> N;
    for (int i = 0; i < N; i++){
		int t; in>>t;
		if(t % 2 == 0){
			if(t > evenMax){
				evenSec = evenMax;
				evenMax = t;
			}
			else if(t > evenSec)
				evenSec = t;
		}
		if(t % 2 == 1){
			if(t > oddMax){
				oddSec = oddMax;
				oddMax = t;
			}
			else if(t > oddSec)
				oddSec = t;
		}
	}
	
	if((evenMax == -1 || evenSec == -1) && (oddMax == -1 || oddSec == -1))
	    sol = -1;
    else
	    sol = max(evenMax + evenSec, oddMax + oddSec);
	out << sol;
    in.close();
    out.close();
    return 0;
}
//10 1 2 3 4 5 6 7 8 9 10
