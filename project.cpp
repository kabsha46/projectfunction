#include <iostream>
#include <string>
using namespace std;
// This is the part of the program
bool login();
void showMenu();
void addBook(string title[], int ids[], int &count);
void displayBooks(string title[], int ids[], int count);
void deleteBook(string title[], int ids[], int &count);
void issueBook(string title[], int ids[], int count, int issuedBookIds[], int issuedMemberIds[], string memberNames[], int &issuedCount);
void viewIssuedBooks(int issuedBookIds[], int issuedMemberIds[], string memberNames[], int issuedCount);

int main()

{

    // First we need to log in

    if (!login())

    {

        // If the login fails we print an error message and exit

        cout << "Login Failed!\n";

        return 0;
    }

    // We have arrays to store the book titles, ids and other information

    string title[100];

    int ids[100];

    int count = 0;

    int issuedBookIds[100];

    int issuedMemberIds[100];

    string memberNames[100];

    int issuedCount = 0;

    int choice;

    // We keep running the system until the user chooses to exit

    do

    {

        // We show the menu to the user

        showMenu();

        cin >> choice;

        // We do things based on what the user chooses

        switch (choice)

        {

        case 1:

            // Add a book

            addBook(title, ids, count);

            break;

        case 2:

            // Display books

            displayBooks(title, ids, count);

            break;

        case 3:

            // Delete a book

            deleteBook(title, ids, count);

            break;

        case 4:

            // Issue a book

            issueBook(title, ids, count, issuedBookIds, issuedMemberIds, memberNames, issuedCount);

            break;

        case 5:

            // View issued books

            viewIssuedBooks(issuedBookIds, issuedMemberIds, memberNames, issuedCount);

            break;

        case 6:

            // Exit the system

            cout << "Exiting...\n";

            break;

        default:

            // If the user enters something we print an error message

            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}

// This is the login function

bool login()

{

    string username, password;

    cout << "Username: ";

    cin >> username;

    cout << "Password: ";

    cin >> password;

    // The username and password are hardcoded for now

    if (username == "admin" && password == "1234")

        return true;

    return false;
}

// This is the menu function

void showMenu()

{

    cout << "\n===== MENU =====\n";

    cout << "1. Add Book\n";

    cout << "2. Display Books\n";

    cout << "3. Delete Book\n";

    cout << "4. Issue Book\n";

    cout << "5. View Issued Books\n";

    cout << "6. Exit\n";

    cout << "Enter choice: ";
}

// This is the add book function

void addBook(string title[], int ids[], int &count)

{

    cout << "Enter Book ID: ";

    cin >> ids[count];

    cout << "Enter Book  title :";

    cin >> title[count];

    count++;

    cout << "Book Added Successfully!\n";
}

// This is the display books function

void displayBooks(string title[], int ids[], int count)

{

    if (count == 0)

    {

        cout << "No books available!\n";

        return;
    }

    for (int i = 0; i < count; i++)

    {

        cout << "ID: " << ids[i] << " " << title[i] << endl;
    }
}

// This is the delete book function

void deleteBook(string title[], int ids[], int &count)

{

    int deleteId;

    cout << "Enter Book ID to delete: ";

    cin >> deleteId;

    for (int i = 0; i < count; i++)

    {

        if (ids[i] == deleteId)

        {

            for (int j = i; j < count - 1; j++)

            {

                ids[j] = ids[j + 1];

                title[j] = title[j + 1];
            }

            count--;

            cout << "Book Deleted!\n";

            return;
        }
    }

    cout << "Book not found!\n";
}

// This is the issue book function

void issueBook(string title[], int ids[], int count, int issuedBookIds[], int issuedMemberIds[], string memberNames[], int &issuedCount)

{

    int bookId, memberId;

    string name;

    cout << "Enter Book ID: ";

    cin >> bookId;

    bool found = false;

    for (int i = 0; i < count; i++)

    {

        if (ids[i] == bookId)

        {

            found = true;

            break;
        }
    }

    if (!found)

    {

        cout << "Book not found!\n";

        return;
    }

    cout << "Enter Member ID: ";

    cin >> memberId;

    cout << "Enter Member Name: ";

    cin >> name;

    issuedBookIds[issuedCount] = bookId;

    issuedMemberIds[issuedCount] = memberId;

    memberNames[issuedCount] = name;

    issuedCount++;

    cout << "Book Issued Successfully!\n";
}

// This is the view issued books function

void viewIssuedBooks(int issuedBookIds[], int issuedMemberIds[], string memberNames[], int issuedCount)

{

    if (issuedCount == 0)

    {

        cout << "No issued books!\n";

        return;
    }

    for (int i = 0; i < issuedCount; i++)

    {

        cout << "Book ID: " << issuedBookIds[i]

             << " Member ID: " << issuedMemberIds[i]

             << " Name: " << memberNames[i] << endl;
    }
}
