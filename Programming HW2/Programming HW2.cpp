
// Charlie kaing
// HW 2
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Book.h"
#include "person.h"
using namespace std;

void processdata(ChildrenBook temp, ComputerBook computer, Novel noveltemp);
void processperson(Teacher techertemp, Student studenttemp);
void insert(BookNode** head_ref, BookNode* node);
void print(BookNode* head);
void search();
int main()
{
    //Book linked list start
    ChildrenBook temp; 
    ComputerBook computer;
    Novel noveltemp;
    Teacher techertemp;
    Student studenttemp;
    processdata(temp,computer,noveltemp);
    print(library[1]);
    /*
    cout << "--------------------------" << endl << "         Menu" << endl << "--------------------------" << endl;
    cout << "  1. Search a book" << endl;
    cout << "  2. Rent a book" << endl;
    cout << "  3. Return a book" << endl;
    cout << "  4. Show my information" << endl;
    cout << "  5. Show all books" << endl;
    cout << "  6. Exit" << endl;
    int choice = 0;
    while (!(choice == 6))
    {
        cin >> choice;
        if (choice == 5)
        {
            
            cout << "==================================" << endl << "   Childrens Book   " << endl << "==================================" << endl;
            cout << " Code ";
            cout << setw(10);
            cout << " Title ";
            cout << setw(5);
            cout << " Age ";
            cout << " Available ";
            cout << " Rented ";
            cout << endl;
            cout << "---------------------------------" << endl;
            print(library[0]);
            
        }
    }
    */
}

void processdata(ChildrenBook temp, ComputerBook computer, Novel noveltemp)
{
    ifstream infile;
    infile.open("book.txt");
    if (infile.fail()) { // checks for file opening
        cout << "Input file opening filed." << endl;
        exit(1);
    }
    int tempcode, temprented, tempavailable;
    int tempyear, tempage, tempdate;
    string temptitle,temppublish;
    while (!infile.eof())
    {
        infile >> tempcode;
        if ((tempcode > 1000) && (tempcode < 2000))
        {
            infile >> temptitle >> tempage >> tempavailable >> temprented;
            temp.setcode(tempcode);
            temp.settitle(temptitle);
            temp.setage(tempage);
            temp.setavailable(tempavailable);
            temp.setrented(temprented);
            BookNode* node = new BookNode;
            node->book = temp;
        
            insert(&library[0], node);
        } 
        else if ((tempcode > 2000) && (tempcode < 3000))
        {
            
            infile >> temptitle >> temppublish >> tempavailable >> temprented;
            computer.setcode(tempcode);
            computer.settitle(temptitle);
            computer.setpublisher(temppublish);
            computer.setavailable(tempavailable);
            computer.setrented(temprented);
            BookNode* node = new BookNode;
            node->book = computer;
            insert(&library[1], node);
        }
        else if ((tempcode > 3000) && (tempcode < 4000))
        {
            
            infile >> temptitle >> tempdate >> tempavailable >> temprented;
            noveltemp.setcode(tempcode);
            noveltemp.settitle(temptitle);
            noveltemp.setdate(tempdate);
            noveltemp.setavailable(tempavailable);
            noveltemp.setrented(temprented);
            BookNode* node = new BookNode;
            node->book = noveltemp;
            insert(&library[2], node);

        }
    }
}
void processperson(Teacher teachtemp, Student studenttemp)
{
    ifstream infile;
    infile.open("book.txt");
    if (infile.fail()) { // checks for file opening
        cout << "Input file opening filed." << endl;
        exit(1);
    }
    string name;
    int id, numberrented, code1, code2;
    while (!infile.eof())
    {
        infile >> id;
        if (id < 100)
        {
            infile >> name >> numberrented;
            if (numberrented == 1)
            {
                infile >> code1;
                teachtemp.setname(name);
                teachtemp.setid(id);
                teachtemp.setcount(numberrented);
                PersonNode* node = new PersonNode;
                node->person = teachtemp;
                insert();
            }
            if (numberrented == 2)
            {
                infile >> code1 >> code2;
            }
        }
        else if ((id > 100) && (id < 300))
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
void print(BookNode* head)
{
    for (BookNode* ptr = head; ptr != NULL; ptr = ptr->link)
        cout << ptr->book.getcode() << "     " << ptr->book.gettitle() << "     " << ptr->book.getavailable() << " " << ptr->book.getrented() << endl;
    cout << endl;
}