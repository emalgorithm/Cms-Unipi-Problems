#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <queue>
#include <fstream>
#include <cstdlib>

#define INF 999999999

using namespace std;

typedef pair<int, int> ii ;
typedef vector< ii >   vii ;
typedef vector<int> vi ;

int sol;

class SegmentTree {         
private: vi st, A, lazy;            
  int n;
  int left (int p) { return p << 1; }     // Left child
  int right(int p) { return (p << 1) + 1; } // Right child


  void query(int p, int L, int R, int i, int j) {                  
    if (L > R || i >  R || j <  L) return; // Out of range
    
    if(lazy[p]!=0){    // Check if this node has to be updated
        st[p] = (R - L + 1) - st[p];   // Update
        if(L != R){
            lazy[left(p)] = 1 - lazy[left(p)];  // Sign children as to be updated
            lazy[right(p)] = 1 - lazy[right(p)];
        }
        lazy[p] = 0;
    }
     
    if (L >= i && R <= j){ sol+=st[p]; return ;}  // Totally within range [i, j]         
     
    query(left(p) , L              , (L+R) / 2, i, j);
    query(right(p), (L+R) / 2 + 1, R          , i, j);
    }          
  
  int update_tree(int p, int L, int R, int i, int j) {
        
    if(lazy[p]!=0){     // Check if this no has to be updated
        st[p] = (R - L + 1) - st[p];
        if(L != R){
            lazy[left(p)] = 1 - lazy[left(p)];
            lazy[right(p)] = 1 - lazy[right(p)];
        }
        lazy[p] = 0;
    }
    
	if(L > R || L > j || R < i) // Current segment is not within range [i, j]
		return INF;
    
    if(L >= i && R <= j){        //Current segment is totally within range [i, j]
        int d = ((R - L + 1) - st[p]) - st[p] ; //Calculate difference 
        st[p] = (R - L + 1) - st[p];   // Change value
        if(L != R){    // Stop here and sign children as to be updated
            lazy[left(p)] = 1 - lazy[left(p)];
            lazy[right(p)] = 1 - lazy[right(p)];
        }
        return d;  // Return difference to parent to update its value 
    }
 
	int s = update_tree(left(p), L, (L+R)/2, i, j); // Updating left child
	int s2 = update_tree(right(p), 1+(L+R)/2, R, i, j); // Updating right child
	int d2 = ( (s!=INF ? s : 0) + (s2!=INF ? s2 : 0) ); // Calculating difference from the ones given by the children
	st[p] += d2; // Updating root 
	return d2;  // Return difference
}

public:
  SegmentTree(const vi &_A) {
    A = _A; n = (int)A.size();              
    st.assign(4 * n, 0); 
    lazy.assign(4 * n, 0);                                             
  }

  void query(int i, int j) { return query(1, 0, n - 1, i, j); }   

  int update_tree(int i, int j) {
    return update_tree(1, 0, n - 1, i, j); }
};

int N,Q;

int main() {
    FILE * in; FILE * out;
    in = fopen("input.txt","r"); out = fopen("output.txt","w");
    
    fscanf(in, "%d %d" , &N, &Q);
    
    int arr[N];
    
    vi A(arr,arr+N);
    SegmentTree st(A);
    
    for(int i=0;i<Q;i++){
        int t,q,q2;
        fscanf(in, "%d %d %d " , &t, &q, &q2);
        if(t){
            sol=0;
            st.query(q,q2);
            fprintf(out, "%d\n", sol);           
        }
        else
            st.update_tree(q,q2);
    }
    
    fclose(in); fclose(out);
    return 0;
}
//25 abcdbeababcdeebeedeedcacb





