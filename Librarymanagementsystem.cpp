#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class Book
{
private:
    string title;
    string author;
    int year;
    int copies;

public:
    void add_book(string t, string a, int y, int c)
    {
        title = t;
        author = a;
        year = y;
        copies = c;
    }

    void display_book()
    {
        cout << setw(20) << left << title << setw(20) << left << author << setw(10) << year << setw(5) << copies << endl;
    }

    string get_title()
    {
        return title;
    }

    string get_author()
    {
        return author;
    }

    int get_year()
    {
        return year;
    }

    int get_copies()
    {
        return copies;
    }

    void update_copies(int c)
    {
        copies += c;
    }
};

int main()
{
    Book books[100];
    int count = 0;
    int option;
    string title, author;
    int year, copies;
    bool found;

    do
    {
        cout << endl;
        cout << "Library Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Update Book Copies" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << endl;
            cout << "Add Book" << endl;
            cout << "Enter Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            cout << "Enter Year: ";
            cin >> year;
            cout << "Enter Copies: ";
            cin >> copies;
            books[count].add_book(title, author, year, copies);
            count++;
            break;

        case 2:
            cout << endl;
            cout << "Display All Books" << endl;
            cout << setw(20) << left << "Title" << setw(20) << left << "Author" << setw(10) << "Year" << setw(5) << "Copies" << endl;
            for (int i = 0; i < count; i++)
            {
                books[i].display_book();
            }
            break;

        case 3:
            cout << endl;
            cout << "Search Book" << endl;
            cout << "Enter Title: ";
            cin.ignore();
            getline(cin, title);
            found = false;
            for (int i = 0; i < count; i++)
            {
                if (books[i].get_title() == title)
                {
                    found = true;
                    cout << setw(20) << left << "Title" << setw(20) << left << "Author" << setw(10) << "Year" << setw(5) << "Copies" << endl;
                    books[i].display_book();
                    break;
                }
            }
            if (!found)
            {
                cout << "Book not found!" << endl;
            }
            break;

        case 4:
            for (int i = 0; i < count; i++)
            {
                if (books[i].get_title() == title)
                {
                    found = true;
                    cout << "Enter Number of Copies to Add/Subtract: ";
                    cin >> copies;
                    books[i].update_copies(copies);
                    cout << "Copies Updated!" << endl;
                    break;
                }
            }
            if (!found)
            {
                cout << "Book not found!" << endl;
            }
            break;
        case 5:
            cout << endl;
            cout << "Exiting Program" << endl;
            break;

        default:
            cout << endl;
            cout << "Invalid Option! Please Try Again." << endl;
            break;
        }

    } while (option != 5);

    return 0;
