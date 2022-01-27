#include <iostream>

using namespace std;

int main()
{
    int n,S=1;
    cout<<"Nhap n :";cin>>n;
    for(int i=1;i<=n;i++)
    {
        S*=i;
    }
    cout<<"n! = "<<S;
}
