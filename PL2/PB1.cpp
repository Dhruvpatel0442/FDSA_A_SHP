#include <iostream>
using namespace std;

int recursiveSearch(int arr[], int n, int target, int i = 0) {
if (i == n)
return -1;
if (arr[i] == target)
    return i;
return recursiveSearch(arr, n, target, i + 1);
}

int main() {
int n, target;
cout << "Enter size: ";
cin >> n;
int arr[n];
cout << "Enter elements: ";
for (int i = 0; i < n; i++)
    cin >> arr[i];
cout << "Enter target: ";
cin >> target;
int iterative = -1;
for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
        iterative = i;
        break;
    }
}
int recursive = recursiveSearch(arr, n, target);
cout << "Iterative position: " << iterative << endl;
cout << "Recursive position: " << recursive;
return 0;
}
