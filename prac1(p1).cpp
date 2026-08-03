#include<iostream>
using namespace std;

int main() 
{
    int n, h;
    cout<<"Enter number of items: ";
    cin>>n;

    string items[n];
    cout<<"Enter items: ";

    for(int i = 0; i < n; i++)
    {
        cin>>items[i];
    }
    cout<<"Enter number of hours: ";
    cin>>h;

    int k=h%n;

    cout<<"Final display order: ";

    for (int i=0;i<n;i++) 
    {
        cout<<items[(i+k)%n]<<" ";
    }
    cout<<endl;
    return 0;
}
