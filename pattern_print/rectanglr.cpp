#include<iostream>
using namespace std;

int main(){

int n;


cout<<"Enter your number for rec: ";
cin>>n;
int clm=n+1;

for (int i = 1; i <=n; i++)
{
    for (int j = 1; j <= clm; j++)
    {
        cout<<"* ";
    }
    
    cout<<"\n";
}

return 0;

}