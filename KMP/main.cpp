#include <iostream>
#include"KMP.h"
using namespace std;

int main()
{
    string P="abcdaabcab";
    string P2="abe";
    string T="abcddabcababcdaabcababcdaabcaba";
    int pos;
    KMPExtMatching(T,P2,pos);
    cout<<pos<<endl;
}
