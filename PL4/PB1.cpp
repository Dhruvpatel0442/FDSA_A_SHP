#include <iostream>

using namespace std;

struct node
{

    int info;

    struct node *link;
};

struct node *head = NULL;

struct node *create(int n)
{

    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));

    temp->info = n;
    temp->link = NULL;

    return temp;
}

void insert_front()
{

    int n;

    cout << "Enter patient ID: ";

    cin >> n;

    struct node *temp1;
    temp1 = create(n);

    if (head == NULL)
    {

        head = temp1;
    }

    else
    {

        temp1->link = head;

        head = temp1;
    }
}

void insert_end()
{
    int n;
    cout << "Enter patient ID: ";
    cin >> n;

    struct node *temp1;

    temp1 = create(n);
    if (head == NULL)
    {

        head = temp1;
    }
    else
    {

        struct node *temp = head;

        while (temp->link != NULL)
        {

            temp = temp->link;
        }

        temp->link = temp1;
    }
}

void insert_position()
{

    int n, pos;
    cout << "Enter patient ID: ";
    cin >> n;

    cout << "Enter position: ";

    cin >> pos;

    struct node *temp1 = create(n);

    if (pos == 1)
    {

        temp1->link = head;

        head = temp1;

        return;
    }

    struct node *temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->link;
    }

    if (temp == NULL)
    {

        cout << "Position out of bounds. Inserting at the end." << endl;

        insert_end();

        return;
    }

    temp1->link = temp->link;

    temp->link = temp1;
}

void display()
{

    struct node *temp = head;

    while (temp != NULL)
    {

        cout << temp->info << " ";

        temp = temp->link;
    }
}

int main()
{
    head = (struct node *)malloc(sizeof(struct node));

    head->info = 10;

    head->link = (struct node *)malloc(sizeof(struct node));
    head->link->info = 20;

    head->link->link = (struct node *)malloc(sizeof(struct node));

    head->link->link->info = 30;

    head->link->link->link = (struct node *)malloc(sizeof(struct node));

    head->link->link->link->info = 40;

    head->link->link->link->link = (struct node *)malloc(sizeof(struct node));

    head->link->link->link->link->info = 50;

    head->link->link->link->link->link = NULL;

    int choice;

    while (true)
    {

        cout << "\n1. Critical Patient";

        cout << "\n2. Routine Patient";

        cout << "\n3. Priority Patient (Specific Position)";

        cout << "\n4. Display";
        cout << "\n5. Exit";

        cout << "\nEnter choice: ";

        cin >> choice;

        if (choice == 1)

            insert_front();

        else if (choice == 2)
            insert_end();

        else if (choice == 3)

            insert_position();

        else if (choice == 4)

            display();

        else if (choice == 5)

            break;

        else
            cout << "Invalid Choice";
    }
    return 0;
}