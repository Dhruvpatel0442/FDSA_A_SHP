#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int n;

    cout << "Enter the number of license plates: ";
    cin >> n;

    int arr[n];

    cout << "Enter the license plate numbers:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the license plate to search: ";
    cin >> target;

    int result = linearSearch(arr, n, target);

    if(result != -1)
        cout << "License plate found at position: " << result + 1 << endl;
    else
        cout << "License plate not found." << endl;

    return 0;
}
