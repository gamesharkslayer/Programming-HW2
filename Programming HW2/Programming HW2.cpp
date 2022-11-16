
// Charlie kaing
// HW 2
//

#include <iostream>
#include <fstream>
#include<iomanip>
#include "Book.h"
#include "person.h"
using namespace std;

void processdata();
void insert(BookNode** head_ref, BookNode* node);
int main()
{
    //Book linked list start
    Book* head = NULL;
    ChildrenBook* head = NULL;
    Novel* head = NULL;
    cout << "--------------------------" << endl << "     menu       " << endl << "--------------------------" << endl;
    cout << "1. Search a book" << endl;
    cout << "2. Rent a book" << endl;
    cout << "3. Return a book" << endl;
    cout << "4. Show my information" << endl;
    cout << "5. Show all books" << endl;
    cout << "6. Exit" << endl;
    int choice = 0;
    while (!(choice == 6))
    {
        cin >> choice;
    }
}

void processdata()
{
    ifstream infile;
    infile.open("book.txt");
    
    int tempcode, temprented, tempavailable;
    int tempyear, tempage, temppublish;
    string temptitle;
    while (!infile.eof())
    {
        infile >> tempcode;
        if ((tempcode > 1000) && (tempcode < 2000))
        {
            ChildrenBook temp;
            infile >> temptitle >> tempage >> tempavailable >> temprented;
            temp.settitle(temptitle);
            temp.setage(tempage);
            temp.setavailable(tempavailable);
            temp.setrented(temprented);
            insert(&library[0], temp);
        }
        else if ((tempcode > 2000) && (tempcode < 3000))
        {

        }
        else if ((tempcode > 3000) && (tempcode < 4000))
        {

        }
    }
}
void insert(BookNode** head_ref, BookNode* node)
{
    BookNode* current;
    /* Special case for the head end */
    if (*head_ref == NULL|| (*head_ref)->book.getcode() >= node->book.getcode())
    {
        node->link = *head_ref;
        *head_ref = node;
    }
    else 
    {
        /* Locate the node before the
 point of insertion */
        current = *head_ref;
        while (current->link != NULL && current->link->book.getcode() < node->book.getcode())
        {
            current = current->link;
        }
        node->link = current->link;
        current->link = node;
    }
}