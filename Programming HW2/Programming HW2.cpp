
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
void insertperson(PersonNode** head_ref, PersonNode* node);
void print(BookNode* head);
void printperson(PersonNode* head);
void search(BookNode* head, int code, string title);
void showallbooks();
void personsearch(PersonNode* head, int ID, string name);
void printcomputer(BookNode* head);
int main()
{
    //Book linked list start
    ChildrenBook temp; 
    ComputerBook computer;
    Novel noveltemp;
    Teacher techertemp;
    Student studenttemp;
    processdata(temp,computer,noveltemp);

    processperson(techertemp, studenttemp);
 
    int choice = 0;
    while (!(choice == 6))
    {
        cout << "--------------------------" << endl << "         Menu" << endl << "--------------------------" << endl;
        cout << "  1. Search a book" << endl;
        cout << "  2. Rent a book" << endl;
        cout << "  3. Return a book" << endl;
        cout << "  4. Show my information" << endl;
        cout << "  5. Show all books" << endl;
        cout << "  6. Exit" << endl;
        cin >> choice;
        if (choice == 1)
        {
            int code;
            string searchtitle;
            cout << "Enter Code: ";
            cin >> code;
            cout << endl << "Enter Title: ";
            cin >> searchtitle;
            if ((code > 1000) && (code < 2000))
            {
                search(library[0], code, searchtitle);
            }
            else if ((code > 2000) && (code < 3000))
            {
                search(library[1], code, searchtitle);
            }
            else if ((code > 3000) && (code < 4000))
            {
                search(library[2], code, searchtitle);
            }
            else
            {
                cout << "Please Enter a valid code" << endl;
            }
        }
        else if (choice == 2)
        {
            int tempid;
            int tempcode;
            cout << "Enter your ID: ";
            cin >> tempid;
            cout << "Enter the book code to return : ";
            cin >> tempcode;
            if ((tempid < 100) && (tempid > 0))
            {
                personsearch(person[0], tempid, tempname);
            }
            else if ((tempid > 100) && (tempid < 300))
            {
                personsearch(person[1], tempid, tempname);
            }
        }
        else if (choice == 3)
        {

        }
        else if (choice == 4)
        {
            int tempid;
            string tempname;
            cout << "Enter your ID:";
            cin >> tempid;
            cout << endl << "Enter your name:";
            cin >> tempname;
            if ((tempid < 100) && (tempid > 0))
            {
                personsearch(person[0], tempid, tempname);
            }
            else if((tempid > 100) && (tempid < 300))
            {
                personsearch(person[1], tempid, tempname);
            }
        }
        else if (choice == 5)
        {
            showallbooks();
        }
        else
        {

        }
    }
    
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
    Book computerbook, novel, children;
    infile.open("person.txt");
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
                insertperson(&person[0], node);
                teachtemp.setcode1(code1);
                if ((code1 > 1000) && (code1 < 2000)) 
                {
                     children.removebook(library[0],code1);
                }
                else if ((code1 > 2000) && (code1 < 3000))
                {
                    computerbook.removebook(library[1], code1);
                }
                else if ((code1 > 3000) && (code1 < 4000))
                {
                    novel.removebook(library[2], code1);
                }
            }
            else if (numberrented == 2)
            {
                infile >> code1 >> code2;
                teachtemp.setname(name);
                teachtemp.setid(id);
                teachtemp.setcount(numberrented);
                PersonNode* node = new PersonNode;
                node->person = teachtemp;
                insertperson(&person[0], node);
                teachtemp.setcode1(code1);
                teachtemp.setcode2(code2);
                if ((code1 > 1000) && (code1 < 2000))
                {
                    children.removebook(library[0], code1);
                }
                else if ((code1 > 2000) && (code1 < 3000))
                {
                    computerbook.removebook(library[1], code1);
                }
                else if ((code1 > 3000) && (code1 < 4000))
                {
                    novel.removebook(library[2], code1);
                }
                //code 2
                if ((code2 > 1000) && (code2 < 2000))
                {
                    children.removebook(library[0], code2);
                }
                else if ((code2 > 2000) && (code2 < 3000))
                {
                    computerbook.removebook(library[1], code2);
                }
                else if ((code2 > 3000) && (code2 < 4000))
                {
                    novel.removebook(library[2], code2);
                }
            }
        }
        else if ((id > 100) && (id < 300))
        {
            infile >> name >> numberrented;
            if (numberrented == 1)
            {
                infile >> code1;
                studenttemp.setname(name);
                studenttemp.setid(id);
                studenttemp.setcount(numberrented);
                PersonNode* node = new PersonNode;
                node->person = studenttemp;
                studenttemp.setcode1(code1);
                insertperson(&person[1], node);
                if ((code1 > 1000) && (code1 < 2000))
                {
                    children.removebook(library[0], code1);
                }
                else if ((code1 > 2000) && (code1 < 3000))
                {
                    computerbook.removebook(library[1], code1);
                }
                else if ((code1 > 3000) && (code1 < 4000))
                {
                    novel.removebook(library[2], code1);
                }
            }
            else if (numberrented == 2)
            {
                infile >> code1 >> code2;
                studenttemp.setname(name);
                studenttemp.setid(id);
                studenttemp.setcount(numberrented);
                studenttemp.setcode1(code1);
                studenttemp.setcode2(code2);
                PersonNode* node = new PersonNode;
                node->person = studenttemp;
                insertperson(&person[1], node);
                if ((code1 > 1000) && (code1 < 2000))
                {
                    children.removebook(library[0], code1);
                }
                else if ((code1 > 2000) && (code1 < 3000))
                {
                    computerbook.removebook(library[1], code1);
                }
                else if ((code1 > 3000) && (code1 < 4000))
                {
                    novel.removebook(library[2], code1);
                }
                //code 2
                if ((code2 > 1000) && (code2 < 2000))
                {
                    children.removebook(library[0], code2);
                }
                else if ((code2 > 2000) && (code2 < 3000))
                {
                    computerbook.removebook(library[1], code2);
                }
                else if ((code2 > 3000) && (code2 < 4000))
                {
                    novel.removebook(library[2], code2);
                }
            
            }
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
void insertperson(PersonNode** head_ref, PersonNode* node)
{
    PersonNode* current;
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->person.getid() >= node->person.getid())
    {
        node->link = *head_ref;
        *head_ref = node;
    }
    else
    {
        /* Locate the node before the
 point of insertion */
        current = *head_ref;
        while (current->link != NULL && current->link->person.getid() < node->person.getid())
        {
            current = current->link;
        }
        node->link = current->link;
        current->link = node;
    }
}

void showallbooks()
{
    cout << "==================================" << endl << "   Childrens Books   " << endl << "==================================" << endl;
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
    cout << "==================================" << endl << "   Computer Books   " << endl << "==================================" << endl;
    cout << " Code ";
    cout << setw(10);
    cout << " Title ";
    cout << setw(5);
    cout << " Publisher ";
    cout << " Available ";
    cout << " Rented ";
    cout << endl;
    cout << "---------------------------------" << endl;
    printcomputer(library[1]);
    cout << "==================================" << endl << "   Novel Books   " << endl << "==================================" << endl;
    cout << " Code ";
    cout << setw(10);
    cout << " Title ";
    cout << setw(5);
    cout << " Year ";
    cout << " Available ";
    cout << " Rented ";
    cout << endl;
    cout << "---------------------------------" << endl;
    print(library[2]);
}
void print(BookNode* head)
{
    //getting subclass methods
    for (BookNode* ptr = head; ptr != NULL; ptr = ptr->link)
        cout << ptr->book.getcode() << "     " << ptr->book.gettitle() << "     " << ptr->book.getavailable() << " " << ptr->book.getrented() << endl;
    cout << endl;
}
void printcomputer(BookNode* head)
{
    //getting subclass methods
    for (BookNode* ptr = head; ptr != NULL; ptr = ptr->link)
        cout << ptr->book.getcode() << "     " << ptr->book.gettitle() << "     " << ptr->book.getpublisher() << "    " << ptr->book.getavailable() << " " << ptr->book.getrented() << endl;
    cout << endl;
}
void printperson(PersonNode* head)
{
    for (PersonNode* ptr = head; ptr != NULL; ptr = ptr->link)
        cout << ptr->person.getid() << "     " << ptr->person.getname() ;
    cout << endl;
}
void search(BookNode* head, int code,string title)
{
    BookNode* current = head; // Initialize current
    while (current != NULL) {
        if ((current->book.getcode() == code) && (current->book.gettitle() == title))
        {
            cout << current->book.gettitle() << "exists" << endl;
            cout << "catagory:";
            if ((current->book.getcode() > 1000) && (current->book.getcode() > 2000))
            {
                cout << "Childrens Book" << endl;
                cout << "available: " << current->book.getavailable() << "Rented:" << current->book.getrented();
            }
            else if ((current->book.getcode() > 2000) && (current->book.getcode() > 3000))
            {
                cout << "Computer Book" << endl;
                cout << "available: " << current->book.getavailable() << "Rented:" << current->book.getrented();
            }
            else if ((current->book.getcode() >32000) && (current->book.getcode() > 4000))
            {
                cout << "Novel" << endl;
                cout << "available: " << current->book.getavailable() << "Rented:" << current->book.getrented();
            }
        }
        else
        {
            cout << "Book not found please try again";
            break;
        }
        current = current->link;
    }

}

void personsearch(PersonNode* head,int ID,string name)
{
    PersonNode* current = head; // Initialize current
    while (current != NULL)
    {
        if ((current->person.getname() == name) && (current->person.getid() == ID))
        {
            cout << "you have rented " << current->person.getcount() << " books";
        }
        current = current->link;
    }
}
void personadd(PersonNode* head, int ID, int code, BookNode* library)
{
   
    PersonNode* current = head; // Initialize current
    cout << "You have rented " << current->person.getcount() << " Book.";
    while (current != NULL)
    {
        if (current->person.getid() == ID)
        {
            if(current->person.getcode1())
        }
        current = current->link;
    }
}