#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    int N,max=-1;
    in>>N;
    for(int i=0;i<N;i++){
        int temp,temp2,sum;
        in>>temp>>temp2;
        sum=temp+temp2;
        if(sum>max && sum%2==0)
            max=sum;
    }
    out<<max;
    
    system("PAUSE");
    in.close();
    out.close();
    return EXIT_SUCCESS;
}
