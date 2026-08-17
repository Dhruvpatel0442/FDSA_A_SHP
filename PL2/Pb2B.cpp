#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int left, int right, int target)
{
    if (left > right)
        return -1;

    int mid = (left + right) / 2;

    if (arr[mid] == target)
        return mid;

    if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, right, target);

    return binarySearchRecursive(arr, left, mid - 1, target);
}

int main()
{
    int arr[] = {10,20,30,40,50,60,70};
    int size = 7;
    int target = 60;

    int result = binarySearchRecursive(arr, 0, size - 1, target);

    if(result != -1)
        cout<<"Element found at index "<<result;
    else
        cout<<"Element not found";

    return 0;
}