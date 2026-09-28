#include <iostream>
using namespace std;

struct SNode {
    int info;
    SNode* next;
};

SNode* SL = NULL;
SNode* SR = NULL;

SNode* createS(int n) {
    SNode* temp = (SNode*)malloc(sizeof(SNode));
    temp->info = n;
    temp->next = NULL;
    return temp;
}

void insertSFront(int n) {
    SNode* temp1 = createS(n);

    if (SL == NULL) {
        SL = SR = temp1;
        SR->next = SL;
    }
    else {
        temp1->next = SL;
        SL = temp1;
        SR->next = SL;
    }
}

void insertSEnd(int n) {
    SNode* temp1 = createS(n);

    if (SL == NULL) {
        SL = SR = temp1;
        SR->next = SL;
    }
    else {
        SR->next = temp1;
        SR = temp1;
        SR->next = SL;
    }
}

void insertSAfter(int n, int value) {
    if (SL == NULL) {
        cout << "Singly List is Empty" << endl;
        return;
    }

    SNode* trav = SL;

    do {
        if (trav->info == value)
            break;

        trav = trav->next;
    } while (trav != SL);

    if (trav->info != value) {
        cout << "Student not found" << endl;
        return;
    }

    SNode* temp1 = createS(n);

    temp1->next = trav->next;
    trav->next = temp1;

    if (trav == SR)
        SR = temp1;
}

void deleteS(int n) {
    if (SL == NULL) {
        cout << "Singly List is Empty" << endl;
        return;
    }

    SNode* trav = SL;
    SNode* temp;

    if (SL->info == n) {
        if (SL == SR) {
            free(SL);
            SL = SR = NULL;
        }
        else {
            temp = SL;
            SL = SL->next;
            SR->next = SL;
            free(temp);
        }
        return;
    }

    while (trav->next != SL && trav->next->info != n)
        trav = trav->next;

    if (trav->next == SL) {
        cout << "Student not found" << endl;
        return;
    }

    temp = trav->next;
    trav->next = temp->next;

    if (temp == SR)
        SR = trav;

    free(temp);
}

void displayS() {
    cout << "Singly Circular: ";

    if (SL == NULL) {
        cout << "Empty" << endl;
        return;
    }

    SNode* temp = SL;

    do {
        cout << temp->info << " ";
        temp = temp->next;
    } while (temp != SL);

    cout << endl;
}

struct DNode {
    int info;
    DNode* next;
    DNode* prev;
};

DNode* DL = NULL;
DNode* DR = NULL;

DNode* createD(int n) {
    DNode* temp = (DNode*)malloc(sizeof(DNode));
    temp->info = n;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void insertDFront(int n) {
    DNode* temp1 = createD(n);

    if (DL == NULL) {
        DL = DR = temp1;
        DL->next = DL;
        DL->prev = DL;
    }
    else {
        temp1->next = DL;
        temp1->prev = DR;

        DL->prev = temp1;
        DR->next = temp1;

        DL = temp1;
    }
}

void insertDEnd(int n) {
    DNode* temp1 = createD(n);

    if (DL == NULL) {
        DL = DR = temp1;
        DL->next = DL;
        DL->prev = DL;
    }
    else {
        temp1->next = DL;
        temp1->prev = DR;

        DR->next = temp1;
        DL->prev = temp1;

        DR = temp1;
    }
}

void insertDAfter(int n, int value) {
    if (DL == NULL) {
        cout << "Doubly List is Empty" << endl;
        return;
    }

    DNode* trav = DL;

    do {
        if (trav->info == value)
            break;

        trav = trav->next;
    } while (trav != DL);

    if (trav->info != value) {
        cout << "Student not found" << endl;
        return;
    }

    DNode* temp1 = createD(n);

    temp1->next = trav->next;
    temp1->prev = trav;

    trav->next->prev = temp1;
    trav->next = temp1;

    if (trav == DR)
        DR = temp1;
}

void deleteD(int n) {
    if (DL == NULL) {
        cout << "Doubly List is Empty" << endl;
        return;
    }

    DNode* trav = DL;

    do {
        if (trav->info == n)
            break;

        trav = trav->next;
    } while (trav != DL);

    if (trav->info != n) {
        cout << "Student not found" << endl;
        return;
    }

    if (DL == DR) {
        free(trav);
        DL = DR = NULL;
    }
    else {
        trav->prev->next = trav->next;
        trav->next->prev = trav->prev;

        if (trav == DL)
            DL = trav->next;

        if (trav == DR)
            DR = trav->prev;

        free(trav);
    }
}

void displayD() {
    cout << "Doubly Circular: ";

    if (DL == NULL) {
        cout << "Empty" << endl;
        return;
    }

    DNode* temp = DL;

    do {
        cout << temp->info << " ";
        temp = temp->next;
    } while (temp != DL);

    cout << endl;
}

int main() {
    int n, value;

    cout << "Enter 5 students:" << endl;

    for (int i = 0; i < 5; i++) {
        cin >> n;
        insertSEnd(n);
        insertDEnd(n);
    }

    cout << endl;

    cout << "Initial Lists" << endl;
    displayS();
    displayD();

    cout << endl;

    cout << "Enter student to insert at front: ";
    cin >> n;

    insertSFront(n);
    insertDFront(n);

    displayS();
    displayD();

    cout << endl;

    cout << "Enter student to insert at end: ";
    cin >> n;

    insertSEnd(n);
    insertDEnd(n);

    displayS();
    displayD();

    cout << endl;

    cout << "Enter student to insert: ";
    cin >> n;

    cout << "Enter student after which to insert: ";
    cin >> value;

    insertSAfter(n, value);
    insertDAfter(n, value);

    displayS();
    displayD();

    cout << endl;

    cout << "Enter student to delete: ";
    cin >> n;

    deleteS(n);
    deleteD(n);

    displayS();
    displayD();

    return 0;
}