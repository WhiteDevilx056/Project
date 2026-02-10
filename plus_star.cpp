#include<iostream>
using namespace std;
int main(){


    int n;
    cout<<"enter value of n: ";
    cin>>n;
int mid = n/2+1;


    // for (int i = 1; i <=n; i++)
    // {
    //     for (int j = 1; j <=n; j++)
    //     {
    //         if (i==n/2+1 || j==n/2+1) //// good but not right for even number of n
    //         {
    //             cout<<"*";
    //         }
    //         else{
    //             cout<<" ";
    //         }
            
    //     }
    //     cout<<endl;
    // }
    
    if (n%2==0)
    {
        cout<<"Plus sign bas odd num se nhi banta";
        return 0;
    }
    
        for (int i = 1; i <=n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i==mid || j==mid)
                {
                    cout<<"*";  
                }
                else{
                    cout<<" ";
                }
                
            }
            cout<<"\n";
            
        }
        

    return 0;
}