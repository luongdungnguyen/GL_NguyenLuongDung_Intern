#include <iostream>

using namespace std;

int main()
{
    int n,S=1;
    cout<<"Nhap n :";cin>>n;
    cout<<"Bai 1 : ";
    for(int i=1;i<=n;i++)
    {
        S*=i;
    }
    cout<<"n! = "<<S;
    cout<<"\nBai2: ";
    do
    {
        cin>>n;
     cout<<"So duong ban vua nhap la "<<n;
    }while(n<=0);
}
