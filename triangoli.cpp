#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <utility>
#include <stdio.h>
#include <queue>
#include <fstream>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <math.h>
#include <string.h>
#include <stdlib.h> 

using namespace std;


#include <algorithm>
#include <vector>
using namespace std;
 
typedef long long int coord_t;         // coordinate type
typedef long long int coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2
 
struct Point {
	coord_t x, y;
	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

coord2_t cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
 
vector<Point> P;

void convex_hull()
{
	int n = P.size(), k = 0;
        vector<Point> H(2*n);
	// Sort points lexicographically
	sort(P.begin(), P.end());
 
	// Build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
 
	// Build upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
 
	H.resize(k);
        printf("%d ",k-1);
}

int n;

int main() {
    
    #ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    scanf("%d",&n);//cin>>n;
   
    for(int i=0;i<n;i++){
        Point t; scanf("%lld %lld",&t.x,&t.y);//cin>>t.x>>t.y;
        P.push_back(t);
    }
    
    convex_hull();    
    
    return 0;
}

//7 -1 2 -1 5 -2 3 -3 1 1 -1 -2 -1 -3 -4