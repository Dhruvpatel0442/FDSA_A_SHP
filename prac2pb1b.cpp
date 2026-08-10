#include <iostream>
using namespace std;

int recursiveLinearSearch(int arr[], int n, int index, int target)
{
    if(index == n)
        return -1;

    if(arr[index] == target)
        return index;

    return recursiveLinearSearch(arr, n, index + 1, target);
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

    int result = recursiveLinearSearch(arr, n, 0, target);

    if(result != -1)
        cout << "License plate found at position: " << result + 1 << endl;
    else
        cout << "License plate not found." << endl;

    return 0;
}