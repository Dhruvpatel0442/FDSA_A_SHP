#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() 
{
    int m;
    cout<<"Enter number of borrow records: ";
    cin>>m;

    vector<int> log(m);
    cout<<"Enter book IDs: ";
    for(int i=0;i<m;i++)
    {
        cin>>log[i];
    }

    unordered_map<int, int> freq;
    for(int id : log) 
    {
        freq[id]++;
    }

    cout<<"Books borrowed more than once: ";
    for(auto &entry : freq)
    {
        if(entry.second > 1) 
        {
            cout<<entry.first<<" ";
        }
    }
    cout<<endl;
    return 0;
}
