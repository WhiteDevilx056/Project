#include<iostream>
using namespace std;
int main(){

int n;
cout<<"Enter your number: ";
cin>>n;

int sp=n-1;
int st=1;
for (int  i = 1; i <=n; i++)
{
    for (int j = 1; j <=sp; j++)
    {
        cout<<" ";
    }
    
    for (int k = 1; k <=st; k++)
    {
        cout<<"*";
    }
    sp--;
    st++;
    cout<<"\n";
}


}