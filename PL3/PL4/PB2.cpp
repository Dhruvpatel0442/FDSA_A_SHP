#include <iostream>
using namespace std;

struct node {
    int info;
    node* link;
};

node* head = NULL;

void delete_front() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    node* temp = head;
    head = head->link;
    free(temp);
}

void delete_last() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    if (head->link == NULL) {
        free(head);
        head = NULL;
        return;
    }

    node* trav = head;

    while (trav->link->link != NULL) {
        trav = trav->link;
    }

    free(trav->link);
    trav->link = NULL;
}

void delete_intermediate(int x) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    if (head->info == x) {
        delete_front();
        return;
    }

    node* trav = head;

    while (trav->link != NULL && trav->link->info != x) {
        trav = trav->link;
    }

    if (trav->link == NULL) {
        cout << "Value not found" << endl;
        return;
    }

    node* temp = trav->link;
    trav->link = temp->link;
    free(temp);
}

void display() {
    node* temp = head;

    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->link;
    }

    cout << endl;
}

int main() {

    head = (node*)malloc(sizeof(node));
    head->info = 10;

    head->link = (node*)malloc(sizeof(node));
    head->link->info = 20;

    head->link->link = (node*)malloc(sizeof(node));
    head->link->link->info = 30;

    head->link->link->link = (node*)malloc(sizeof(node));
    head->link->link->link->info = 40;

    head->link->link->link->link = (node*)malloc(sizeof(node));
    head->link->link->link->link->info = 50;

    head->link->link->link->link->link = NULL;

    cout << "Initial List: ";
    display();

    int choice;

    while (true) {
        cout << "\n1. Critical Patient";
        cout << "\n2. Routine Patient";
        cout << "\n3. Priority Patient (Specific Position)";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";

        cin >> choice;

        if (choice == 1) {
            delete_front();
            display();
        }
        else if (choice == 2) {
            delete_last();
            display();
        }
        else if (choice == 3) {
            delete_intermediate(20);
            display();
        }
        else if (choice == 4) {
            break;
        }
        else {
            cout << "Invalid Choice" << endl;
        }
    }

    return 0;
}