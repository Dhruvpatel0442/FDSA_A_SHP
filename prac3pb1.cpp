#include <iostream>
using namespace std;


void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

       
        if(swapped == false)
            break;
    }
}


void selectionSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    int arr1[n], arr2[n], arr3[n];

    cout << "Enter marks: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr1[i];

        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }

    bubbleSort(arr1, n);
    selectionSort(arr2, n);
    insertionSort(arr3, n);

    cout << "\nBubble Sort: ";
    printArray(arr1, n);

    cout << "Selection Sort: ";
    printArray(arr2, n);

    cout << "Insertion Sort: ";
    printArray(arr3, n);

    return 0;
}