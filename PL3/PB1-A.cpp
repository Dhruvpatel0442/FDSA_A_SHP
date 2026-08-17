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
        for (int j = 0; j < n - i - 1; j++)
        {
            if (marks[j] > marks[j + 1])
            {
                int temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
        }
    }

    cout << "Sorted marks: ";
    for (int i = 0; i < n; i++)
        cout << marks[i] << " ";

    return 0;
}
