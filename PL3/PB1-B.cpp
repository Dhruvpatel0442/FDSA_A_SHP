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

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (marks[j] < marks[minIndex])
                minIndex = j;
        }
        int temp = marks[i];
        marks[i] = marks[minIndex];
        marks[minIndex] = temp;
    }

    cout << "Sorted marks: ";
    for (int i = 0; i < n; i++)
        cout << marks[i] << " ";
    return 0;
}
