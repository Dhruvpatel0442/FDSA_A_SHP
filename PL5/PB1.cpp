#include <iostream>
using namespace std;

struct node {
    int info;
    node* next;
    node* prev;
};

node* L = NULL;
node* R = NULL;

node* create(int n) {
    node* temp;
    temp = (node*)malloc(sizeof(node));

    temp->info = n;
    temp->next = NULL;
    temp->prev = NULL;

    return temp;
}

void insert_front() {
    int n;
    cout << "Enter song to insert at front: ";
    cin >> n;

    node* temp1 = create(n);

    if (L == NULL) {
        L = temp1;
        R = temp1;
    }
    else {
        temp1->next = L;
        L->prev = temp1;
        L = temp1;
    }
}

void insert_end() {
    int n;
    cout << "Enter song to insert at end: ";
    cin >> n;

    node* temp1 = create(n);

    if (R == NULL) {
        L = temp1;
        R = temp1;
    }
    else {
        R->next = temp1;
        temp1->prev = R;
        R = temp1;
    }
}

void insert_intermediate() {
    int n, value;

    cout << "Enter song to insert: ";
    cin >> n;

    cout << "Enter song after which you want to insert: ";
    cin >> value;

    if (L == NULL) {
        cout << "List is Empty" << endl;
        return;
    }

    node* trav = L;

    while (trav != NULL && trav->info != value) {
        trav = trav->next;
    }

    if (trav == NULL) {
        cout << "Song not found" << endl;
        return;
    }

    node* temp1 = create(n);

    if (trav == R) {
        trav->next = temp1;
        temp1->prev = trav;
        R = temp1;
    }
    else {
        temp1->next = trav->next;
        temp1->prev = trav;

        trav->next->prev = temp1;
        trav->next = temp1;
    }
}

void delete_front() {
    if (L == NULL) {
        cout << "List is Empty" << endl;
        return;
    }

    node* temp = L;

    if (L == R) {
        L = NULL;
        R = NULL;
    }
    else {
        L = L->next;
        L->prev = NULL;
    }

    free(temp);
}

void display() {
    node* temp = L;

    cout << "Playlist: ";

    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }

    cout << endl;
}

void count() {
    int count = 0;
    node* trav = L;

    while (trav != NULL) {
        count++;
        trav = trav->next;
    }

    cout << "Total Songs: " << count << endl;
}

int main() {
    L = create(101);

    L->next = create(102);
    L->next->prev = L;

    L->next->next = create(103);
    L->next->next->prev = L->next;

    L->next->next->next = create(104);
    L->next->next->next->prev = L->next->next;

    L->next->next->next->next = create(105);
    L->next->next->next->next->prev = L->next->next->next;

    R = L->next->next->next->next;

    cout << "Initial 5 Songs: ";
    display();

    insert_front();
    display();

    insert_end();
    display();

    insert_intermediate();
    display();

    delete_front();
    display();

    count();

    return 0;
}