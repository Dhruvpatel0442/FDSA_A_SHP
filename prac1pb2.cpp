#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of books: ";
    cin >> n;

    int books[n];


    for(int i = 0; i < n; i++) {
        cout << "Enter book ID: ";
        cin >> books[i];
    }

    cout << "Books borrowed more than once are: ";

    for(int i = 0; i < n; i++) {
        int count = 0;
        bool printed = false;

        for(int k = 0; k < i; k++) {
            if(books[k] == books[i]) {
                printed = true;
                break;
            }
        }

        if(printed)
            continue;

        for(int j = 0; j < n; j++) {
            if(books[i] == books[j]) {
                count++;
            }
        }
        if(count > 1) {
            cout << books[i] << " ";
        }
    }

    return 0;
}