
// Charlie kaing
// HW 2
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Book.h"
#include "person.h"
using namespace std;

/*
* Processes the books from book.txt and inputs them into the linked list
*/
void processdata(ChildrenBook* temp, ComputerBook* computer, Novel* noveltemp, BookNode* node);
/*
* Process the list of students from student.txt and enters them into an array
*/
void processperson(Teacher* teachtemp, Student* studenttemp);
/*
* Inserts a Book node into the library linked list
*/
void insert(BookNode** head_ref, BookNode* node);
/*
* Inserts a person node into the person linked list
*/
void insertperson(PersonNode** head_ref, PersonNode* node);
/*
* Prints out the books for the linked list
*/
void print(BookNode* head);
/*
* Prints out the Computer books for the linked list
*/
void printcomputer(BookNode* head);
/*
* Prints out the Person for debugging
*/
void printperson(PersonNode* head);
/*
* Searches for a book using the id as well as title
*/
void search(BookNode* head, int code, string title);
/*
* Displays all books for debugging
*/
void showallbooks();
/*
* Searches for a person using id and name
*/
void personsearch(PersonNode* head, int ID, string name);
/*
* Prints out the list of children books
*/
void printchild(BookNode* head);
/*
* Prints out the list of novels
*/
void printnovel(BookNode* head);
/*
* Searches for the given book code in the list
*/
void searchbook(BookNode* head, int code);
/*
* rents a book from the library
*/
void personadd(PersonNode* head, int ID, int code, BookNode* library);
/*
* Returns a book from the person to the library list
*/
void personreturn(PersonNode* head, int ID, int code, BookNode* library);
int main()
{
    //Book linked list start
    ChildrenBook* temp = new ChildrenBook; 
    ComputerBook* computer = new ComputerBook;
    Novel* noveltemp = new Novel;
    Teacher* techertemp = new Teacher;
    Student* studenttemp = new Student;
    BookNode* node = new BookNode();
    processdata(temp,computer,noveltemp,node);
 
    processperson(techertemp, studenttemp);
    //printperson(person[1]);
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
            cout << "Enter the book code to add : ";
            cin >> tempcode;
            if ((tempid < 100) && (tempid > 0))
            {
                if ((tempcode > 1000) && (tempcode < 2000))
                {
                    personadd(person[0], tempid, tempcode, library[0]);
                }
                else if ((tempcode > 2000) && (tempcode < 3000))
                {
                    personadd(person[0], tempid, tempcode, library[1]);
                }
                else if ((tempcode > 3000) && (tempcode < 4000))
                {
                    personadd(person[0], tempid, tempcode, library[2]);
                }
            }
            else if ((tempid > 100) && (tempid < 300))
            {
                if ((tempcode > 1000) && (tempcode < 2000))
                {
                    personadd(person[1], tempid, tempcode, library[0]);
                }
                else if ((tempcode > 2000) && (tempcode < 3000))
                {
                    personadd(person[1], tempid, tempcode, library[1]);
                }
                else if ((tempcode > 3000) && (tempcode < 4000))
                {
                    personadd(person[1], tempid, tempcode, library[2]);
                }
            }
        }
        else if (choice == 3)
        {
            int tempid;
            int tempcode;
            cout << "Enter your ID: ";
            cin >> tempid;
            cout << "Enter the book code to return : ";
            cin >> tempcode;
            if ((tempid < 100) && (tempid > 0))
            {
                if ((tempcode > 1000) && (tempcode < 2000))
                {
                    personreturn(person[0], tempid, tempcode, library[0]);
                }
                else if ((tempcode > 2000) && (tempcode < 3000))
                {
                    personreturn(person[0], tempid, tempcode, library[1]);
                }
                else if ((tempcode > 3000) && (tempcode < 4000))
                {
                    personreturn(person[0], tempid, tempcode, library[2]);
                }
            }
            else if ((tempid > 100) && (tempid < 300))
            {
                if ((tempcode > 1000) && (tempcode < 2000))
                {
                    personreturn(person[1], tempid, tempcode, library[0]);
                }
                else if ((tempcode > 2000) && (tempcode < 3000))
                {
                    personreturn(person[1], tempid, tempcode, library[1]);
                }
                else if ((tempcode > 3000) && (tempcode < 4000))
                {
                    personreturn(person[1], tempid, tempcode, library[2]);
                }
            }
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
            cout << "Please enter a valid choice" << endl;
        }
    }
    
}
// Add Exception
void processdata(ChildrenBook* temp, ComputerBook* computer, Novel* noveltemp, BookNode* node)
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
            temp = new ChildrenBook;
            infile >> temptitle >> tempage >> tempavailable >> temprented;
            temp->setcode(tempcode);
            temp->settitle(temptitle);
            temp->setage(tempage);
            temp->setavailable(tempavailable);
            temp->setrented(temprented);
            node = new BookNode;
            node->book = temp;
        
            insert(&library[0], node);
        } 
        else if ((tempcode > 2000) && (tempcode < 3000))
        {
            computer = new ComputerBook;
            infile >> temptitle >> temppublish >> tempavailable >> temprented;
            computer->setcode(tempcode);
            computer->settitle(temptitle);
            computer->setpublisher(temppublish);
            computer->setavailable(tempavailable);
            computer->setrented(temprented);
            node = new BookNode;
            node->book = computer;
            insert(&library[1], node);
        }
        else if ((tempcode > 3000) && (tempcode < 4000))
        {
            noveltemp = new Novel;
            infile >> temptitle >> tempdate >> tempavailable >> temprented;
            noveltemp->setcode(tempcode);
            noveltemp->settitle(temptitle);
            noveltemp->setdate(tempdate);
            noveltemp->setavailable(tempavailable);
            noveltemp->setrented(temprented);
            node = new BookNode;
            node->book = noveltemp;
            insert(&library[2], node);

        }
    }
}
void processperson(Teacher* teachtemp, Student* studenttemp)
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
            teachtemp = new Teacher;
            infile >> name >> numberrented;
            if (numberrented == 1)
            {
                infile >> code1;
                teachtemp->setname(name);
                teachtemp->setid(id);
                teachtemp->setcount(numberrented);
                PersonNode* node = new PersonNode;
                node->person = teachtemp;
                insertperson(&person[0], node);
                teachtemp->setcode1(code1);
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
                teachtemp->setname(name);
                teachtemp->setid(id);
                teachtemp->setcount(numberrented);
                PersonNode* node = new PersonNode;
                node->person = teachtemp;
                insertperson(&person[0], node);
                teachtemp->setcode1(code1);
                teachtemp->setcode2(code2);
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
            studenttemp = new Student;
            infile >> name >> numberrented;
            if (numberrented == 1)
            {
                infile >> code1;
                studenttemp->setname(name);
                studenttemp->setid(id);
                studenttemp->setcount(numberrented);
                PersonNode* node = new PersonNode;
                node->person = studenttemp;
                studenttemp->setcode1(code1);
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
                studenttemp->setname(name);
                studenttemp->setid(id);
                studenttemp->setcount(numberrented);
                studenttemp->setcode1(code1);
                studenttemp->setcode2(code2);
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
    if (*head_ref == NULL|| (*head_ref)->book->getcode() >= node->book->getcode())
    {
        node->link = *head_ref;
        *head_ref = node;
    }
    else 
    {
        /* Locate the node before the
 point of insertion */
        current = *head_ref;
        while (current->link != NULL && current->link->book->getcode() < node->book->getcode())
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
    if (*head_ref == NULL || (*head_ref)->person->getid() >= node->person->getid())
    {
        node->link = *head_ref;
        *head_ref = node;
    }
    else
    {
        /* Locate the node before the
 point of insertion */
        current = *head_ref;
        while (current->link != NULL && current->link->person->getid() < node->person->getid())
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
    printchild(library[0]);
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
    printnovel(library[2]);
}
void print(BookNode* head)
{
    //getting subclass methods
    for (BookNode* ptr = head; ptr != NULL; ptr = ptr->link)
        cout << ptr->book->getcode() << "     " << ptr->book->gettitle() << "     " << ptr->book->getavailable() << " " << ptr->book->getrented() << endl;
    cout << endl;
}
void printcomputer(BookNode* head)
{
    //getting subclass methods
    /*
      ComputerBook* p = new ComputerBook;
    p = &head->book;
    */
    for (BookNode* ptr = head; ptr != NULL; ptr = ptr->link)
    {
       
        cout << ptr->book->getcode() << "     " << ptr->book->gettitle() << "     " << ptr->book->getpublisher() << "    " << ptr->book->getavailable() << " " << ptr->book->getrented() << endl;
    }
        cout << endl;
     
    
}
void printchild(BookNode* head)
{
    for (BookNode* ptr = head; ptr != NULL; ptr = ptr->link)
    {

        cout << ptr->book->getcode() << "     " << ptr->book->gettitle() << "     " << ptr->book->getage() << "    " << ptr->book->getavailable() << " " << ptr->book->getrented() << endl;
    }
    cout << endl;
}
void printnovel(BookNode* head)
{
    for (BookNode* ptr = head; ptr != NULL; ptr = ptr->link)
    {

        cout << ptr->book->getcode() << "     " << ptr->book->gettitle() << "     " << ptr->book->getdate() << "    " << ptr->book->getavailable() << " " << ptr->book->getrented() << endl;
    }
    cout << endl;
}
void printperson(PersonNode* head)
{
    for (PersonNode* ptr = head; ptr != NULL; ptr = ptr->link)
        cout << ptr->person->getid() << "     " << ptr->person->getname() << "  " << ptr->person->getcount() << "   " << ptr->person->getcode1() << "  " << ptr->person->getcode2() << endl;
    cout << endl;
}
void search(BookNode* head, int code,string title)
{
    BookNode* current = head; // Initialize current
    while (current != NULL) {
        if ((current->book->getcode() == code) && (current->book->gettitle() == title))
        {
            cout << current->book->gettitle() << "exists" << endl;
            cout << "catagory:";
            if ((current->book->getcode() > 1000) && (current->book->getcode() > 2000))
            {
                cout << "Childrens Book" << endl;
                cout << "available: " << current->book->getavailable() << "Rented:" << current->book->getrented();
            }
            else if ((current->book->getcode() > 2000) && (current->book->getcode() > 3000))
            {
                cout << "Computer Book" << endl;
                cout << "available: " << current->book->getavailable() << "Rented:" << current->book->getrented();
            }
            else if ((current->book->getcode() >32000) && (current->book->getcode() > 4000))
            {
                cout << "Novel" << endl;
                cout << "available: " << current->book->getavailable() << "Rented:" << current->book->getrented();
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
        if (current->person->getname() == name && current->person->getid() == ID)
        {
            if (current->person->getcount() == 1)
            {
                
                    cout << "you have rented " << current->person->getcount() << " books";
                    if (current->person->getcode1() >= 1000 && current->person->getcode1() <= 2000)
                    {
                        searchbook(library[0], current->person->getcode1());
                    }
                    else if (current->person->getcode1() >= 2000 && current->person->getcode1() <= 3000)
                    {
                        searchbook(library[1], current->person->getcode1());
                    }
                    else if (current->person->getcode1() >= 3000 && current->person->getcode1() <= 4000)
                    {
                        searchbook(library[2], current->person->getcode1());
                    }
               
            }
            else if (current->person->getcount() == 2)
            {
               
                    //cout << "you have rented " << current->person->getcount() << " books" <<endl;
                    if (current->person->getcode1() >= 1000 && current->person->getcode1() <= 2000)
                    {
                        //cout << "search1";
                        cout << current->person->getcode1();
                        searchbook(library[0], current->person->getcode1());
                    }
                    else if (current->person->getcode1() >= 2000 && current->person->getcode1() <= 3000)
                    {
                        //cout << "search2"<<endl;
                        searchbook(library[1], current->person->getcode1());
                    }
                    else if (current->person->getcode1() >= 3000 && current->person->getcode1() <= 4000)
                    {
                      //  cout << "search3"<<endl;
                        searchbook(library[2], current->person->getcode1());
                    }
                    //search for code two
                  //  cout << "Search for code 2";
                    if (current->person->getcode2() >= 1000 && current->person->getcode2() <= 2000)
                    {
                        searchbook(library[0], current->person->getcode2());
                    }
                    else if (current->person->getcode2() >= 2000 && current->person->getcode2() <= 3000)
                    {
                        searchbook(library[1], current->person->getcode2());
                    }
                    else if (current->person->getcode2() >= 3000 && current->person->getcode2() <= 4000)
                    {
                        searchbook(library[2], current->person->getcode2());
                    }
               
                
            }
        }
        current = current->link;
    }
}
void searchbook(BookNode* head, int code)
{
   // cout << "Searching book:" << code;
    BookNode* current = head; // Initialize current
    //cout << endl;
    while (current != NULL) {
        //cout << "current book: " << current->book->getcode() << endl;
        if (current->book->getcode() == code)
        {
           // cout << "Code found";
            if ((current->book->getcode() >= 1000) && (current->book->getcode() <= 2000))
            {
               
                cout << "* " << current->book->gettitle() << " Age:" << current->book->getage() << endl;
            }
            else if ((current->book->getcode() > 2000) && (current->book->getcode() <= 3000))
            {
               
                cout << "* " << current->book->gettitle() << " Publisher:" << current->book->getpublisher() << endl;
            }
            else if ((current->book->getcode() > 3000) && (current->book->getcode() <= 4000))
            {
              
                cout << "* " << current->book->gettitle() << " Year:" << current->book->getdate() << endl;
            }
        }
        else
        {
          //  break;
        }
        current = current->link;
    }
}
void personadd(PersonNode* head, int ID, int code, BookNode* library)
{
   
    BookNode* current = library; // Initialize current
    PersonNode* currentpers = head;
   // cout << "You have rented " << currentpers->person->getcount() << " Book.";
    cout << "getting";
    while (currentpers != NULL)
    {
        if (currentpers->person->getid() == ID)
        {
            if (currentpers->person->getcode1() == 0)
            {
                cout << "Book set";
                current->book->removebook(current, code);
                int count = currentpers->person->getcount();
                count++;
                currentpers->person->setcode1(code);
            }
            else if (currentpers->person->getcode2() == 0)
            {
                cout << "Book set";
                current->book->removebook(current, code);
               int count = currentpers->person->getcount();
               count++;
               currentpers->person->setcount(count);
                currentpers->person->setcode2(code);
            }
         
        }
        currentpers = currentpers->link;
    }
}
void personreturn(PersonNode* head, int ID, int code, BookNode* library)
{

    BookNode* current = library; // Initialize current
    PersonNode* currentpers = head;
    // cout << "You have rented " << currentpers->person->getcount() << " Book.";
    char choice;
    cout << "getting";
    while (currentpers != NULL && current != NULL)
    {
        if (currentpers->person->getid() == ID)
        {
            if (currentpers->person->getcode1() == code)
            {
                cout << "Do you want to return: " << current->book->gettitle() << " (y/n) " << endl;
                cin >> choice;
                if (choice == 'y')
                {
                    current->book->addbook(current, code);
                    int count = currentpers->person->getcount();
                    count--;
                    currentpers->person->setcode1(0);
                }
                else if (choice == 'n')
                {
                    break;
                }
                else
                {
                    cout << "Please enter a valid choice\n";
                }
            }
            else if (currentpers->person->getcode2() == code)
            {
                cout << "Do you want to return: " << current->book->gettitle() << " (y/n) " << endl;
                current->book->addbook(current, code);
                int count = currentpers->person->getcount();
                count--;
                currentpers->person->setcount(count);
                currentpers->person->setcode2(0);
            }

        }
        currentpers = currentpers->link;
        current = current->link;
    }
}