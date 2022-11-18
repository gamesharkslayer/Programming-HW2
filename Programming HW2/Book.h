using namespace std;

class Book
{
    // complete the class
public:

    Book();
    Book(int code, string title, int available, int rented);
    void setcode(int code);
    int getcode();
    void settitle(string title);
    string gettitle();
    void setavailable(int available);
    int getavailable();
    void setrented(int rented);
    int getrented();
  //  void addbook(int code);
    //void removebook(BookNode* head, int code);
 
private:
    int code;
    string title;
    int available;
    int rented;
};

class ChildrenBook : public Book
{
    // complete the class
public:
    ChildrenBook() : Book(0, "Empty", 0, 0)
    {
        age = 0;
    }
    ChildrenBook(int code, string title, int available, int rented, int age) : Book(code, title, available, rented)
    {
        this->age = age;
    }
    void setage(int age);
    int getage();
private:
    int age;
};

class ComputerBook : public Book
{
    // complete the class
public:
    ComputerBook() :Book(0, "Empty", 0, 0)
    {
        publisher = "Blank";
    }
    ComputerBook(int code, string title, int available, int rented, string publisher) : Book(code, title, available, rented)
    {
        this->publisher = publisher;
    }
    void setpublisher(string publisher);
    string getpublisher();
private:
    string publisher;
};

class Novel : public Book
{ // complete the class
public:
    Novel() : Book(0, "Empty", 0, 0)
    {
        this->publish_date = 000000;
    }
    Novel(int code, string title, int available, int rented, int publish_date) : Book(code, title, available, rented)
    {
        this->publish_date = publish_date;
    }
    void setdate(int date);
    int getdate();
private:
    int publish_date;
};


struct BookNode
{
    Book book;
    BookNode* link;
};
BookNode* library[3];

Book::Book()
{
    this->code = 0000000;
    this->title = "title";
    this->available = 0;
    this->rented = 0;
}
Book::Book(int code, string title, int available, int rented)
{
    this->code = code;
    this->title = title;
    this->available = available;
    this->rented = rented;
}
void Book::setcode(int code)
{
    this->code = code;
}
int Book::getcode()
{
    return code;
}
void Book::settitle(string title)
{
    this->title = title;
}
string Book::gettitle()
{
    return title;
}
void Book::setavailable(int available)
{
    this->available = available;
}
int Book::getavailable()
{
    return available;
}
void Book::setrented(int rented)
{
    this->rented = rented;
}
int Book::getrented()
{
    return rented;
}
//error
/*
void Book::removebook(BookNode* head, int code)
{

    BookNode* current = head; // Initialize current
    int newava = current->book.getavailable();
    int newrent = current->book.getrented();
    while (current != NULL) {
        if (current->book.getcode() == code)
        {
            newava--;
            newrent++;
            current->book.setavailable(newava);
            current->book.setrented(newrent);
        }

        current = current->link;
    }

}
*/
void ChildrenBook::setage(int age)
{
    this->age = age;
}
int ChildrenBook::getage()
{
    return age;
}
void ComputerBook::setpublisher(string publisher)
{
    this->publisher = publisher;
}
string ComputerBook::getpublisher()
{
    return publisher;
}
void Novel::setdate(int date)
{
    this->publish_date = date;
}
int Novel::getdate()
{
    return publish_date;
}