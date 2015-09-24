#include <vector>
#include <algorithm>
#include <math.h>

#define MAX_N 100005

using namespace std;

int prime[MAX_N];

int monete(int N, int v[]) {
    
    for(int i = 2; i<= MAX_N/2; i++) {
        if(prime[i] == 0) {
            for(int j = 2; i * j < MAX_N; j++) {
                prime[i * j] = 1;
            }
        }
    }
    
    int sol = 0;
    for(int i = 2; i <= N / 2; i++) {
        if(prime[i] == 0) {
            if((N - i + 1) / i >= sol) {
                vector< int > verticalJumps;
                for(int j = i - 1; j < N; j += i) {
                    verticalJumps.push_back(v[j]);
                }
                sort(verticalJumps.begin(), verticalJumps.end());
                
                int solTemp = 0;
                int currValue = -1;
                for(int j = 0; j < verticalJumps.size(); j++) {
                    int vJ = verticalJumps[j];
                    if(vJ != currValue) {
                        currValue = vJ;
                        solTemp = 1;
                    }
                    else {
                        solTemp++;
                    }
                    sol = max(sol, solTemp);
                }
            }
        }
    }
    return sol;
}


