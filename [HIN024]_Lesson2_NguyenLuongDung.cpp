#include <iostream>

using namespace std;

int main()
{
    int x,y,S=1;
    cout<<"Nhap x :";cin>>x;
    cout<<"Bai 1 : ";
    for(int i=1;i<=x;i++)
    {
        S*=i;
    }
    cout<<"x! = "<<S;
    cout<<"\nBai2: ";
    tryagain:
     cout<<"\nNhap y :";
     cin>>y;
     if(y<=0) {cout<<"So ban vua nhap khong phai so duong"<<endl;goto tryagain;}
      else cout<<"\nSo duong ban vua nhap la "<<y;

}
