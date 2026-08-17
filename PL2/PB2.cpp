#include <iostream>
using namespace std;

int recursiveSearch(int arr[], int low, int high, int target) {
if (low > high)
return -1;
int mid = (low + high) / 2;
if (arr[mid] == target)
    return mid;
if (target < arr[mid])
    return recursiveSearch(arr, low, mid - 1, target);
return recursiveSearch(arr, mid + 1, high, target);
}
int main() {
int n, target;
cout << "Enter size: ";
cin >> n;

int arr[n];

cout << "Enter sorted elements: ";
for (int i = 0; i < n; i++)
    cin >> arr[i];
cout << "Enter target: ";
cin >> target;
int low = 0, high = n - 1;
int iterative = -1;

while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] == target) {
        iterative = mid;
        break;
    }
    if (target < arr[mid])
        high = mid - 1;
    else
        low = mid + 1;
}
int recursive =recursiveSearch(arr, 0, n - 1, target);
cout << "Iterative position: " << iterative << endl;
cout << "Recursive position: " << recursive;
return 0;
}
