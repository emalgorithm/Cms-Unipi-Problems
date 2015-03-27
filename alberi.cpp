#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

int preIndex;

struct node* constructTree(int pre[], int post[], int l, int h, int size){
   
    if (preIndex >= size || l > h)
        return NULL;
 
    node* root = new node(); root->data=pre[preIndex++];

    if (l == h)
        return root;
 
    int i;
    for (i = l; i <= h; ++i)
        if (pre[preIndex] == post[i])
            break;

    if (i <= h){
        root->left = constructTree(pre, post, l, i, size);
        root->right = constructTree(pre, post, i + 1, h, size);
    }
 
    return root;
}
 
int index=0;
void fillInorder (node* node,int *SIMM){
    if (node == NULL)
        return;
    fillInorder(node->left,SIMM);
    SIMM[index++]=node->data;
    fillInorder(node->right,SIMM);
}

void visita(int N, int *PRE, int *POST, int *SIMM ){
    int preIndex=0;
    node *root=constructTree(PRE,POST,0,N-1,N);
    fillInorder(root,SIMM);
   // for(int i=0;i<N;i++)
     //   std::cout<<SIMM[i]<<" ";
}
 
/*int main (){
    int pre[] = {5,3,2,1,6,7,4};
    int post[] = {2,6,7,1,3,4,5};
    int simm[10];
    int size = 7; int preIndex=0;
 
    visita(size,pre,post,simm);
    cin>>simm[3];
 
    return 0;
}*/



