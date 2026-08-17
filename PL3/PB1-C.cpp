#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of marks: ";
    cin >> n;

    int marks[n];

    cout << "Enter marks: ";
    for (int i = 0; i < n; i++)
        cin >> marks[i];

    for (int i = 1; i < n; i++)
    {
        int key = marks[i];
        int j = i - 1;

        while (j >= 0 && marks[j] > key)
        {
            marks[j + 1] = marks[j];
            j--;
        }

        marks[j + 1] = key;
    }

    cout << "Sorted marks: ";
    for (int i = 0; i < n; i++)
        cout << marks[i] << " ";

    return 0;
}
