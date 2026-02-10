#include<iostream>
using namespace std;

int main()
{
int n;
cout<<"Enter n: ";
cin>>n;
int sp=n-1;
int st=1;

for (int i = 1; i <=n; i++)
{
    for (int j = 1; j <= sp; j++)
    {
        cout<<" ";
    }

    for (int  k = 1; k <= st; k++)
    {
        cout<<"*";
    }
    
    sp--;
    st+=2;

    cout<<endl;
}


cout<<"------------------"<<endl;

for (int  i = 1; i <= n; i++)
{
    for (int  j = 1; j <= n-i; j++)
    {
        cout<<" ";
    }
    
    for (int k = 1; k <=2*i-1; k++)
    {
        cout<<"*";
    }
    cout<<endl;
    
}





}