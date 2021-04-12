#include <iostream>
#include"DLinkList.h"


using namespace std;

int main()
{
    DlnkList<int> a;
    a.insert(0,0);
    a.insert(1,1);
    a.insert(2,2);
    a.delete_(0);
    a.print();

}
