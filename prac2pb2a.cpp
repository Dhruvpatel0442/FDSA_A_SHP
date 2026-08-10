#include <iostream>
using namespace std;

int binarySearchIterative(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {10,20,30,40,50,60,70};
    int size = 7;
    int target = 60;

    int result = binarySearchIterative(arr, size, target);

    if(result != -1)
        cout<<"Element found at index "<<result;
    else
        cout<<"Element not found";

    return 0;
}