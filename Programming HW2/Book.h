using namespace std;

typedef struct BookNode BookNode;

class Book
{
    // complete the class
public:
    /*
    * Default constructor for the book class
    */
    Book();
    /*
    * Book constructor with code title available and rented
    */
    Book(int code, string title, int available, int rented);
    /*
    * Changes the book code to the parameter bookcode
    */
    void setcode(int code);
    /*
    * Returns the book code from the class
    */
    int getcode();
    /*
    * Changes the title of the book
    */
    void settitle(string title);
    /*
    * Returns the title of the book
    */
    string gettitle();
    /*
    * sets the ammount of books available
    */
    void setavailable(int available);
    /*
    * returns the ammount of books available
    */
    int getavailable();
    /*
    * Sets the ammount of books that have been rented out
    */
    void setrented(int rented);
    /*
    * Returns the ammount of books that are rented
    */
    int getrented();
    /*
    * Increases the available books and descreases the rented variable
    */
    void addbook(BookNode* head, int code);
    /*
    * decreases the available books and inscreases the rented variable
    */
    void removebook(BookNode* head, int code);
    /*
    * Returns the publisher of the book
    */
    virtual string getpublisher() { return"super"; };
    /*
   * Returns the age demographic of the book
   */
    virtual int getage() { return 0; };
    /*
    * Returns the publishing date for the book
    */
    virtual int getdate() { return 0; };

    //Copy constructor
    Book(const Book& b1)
    {
        code = b1.code;
        title = b1.title;
    }

    //Destructor
  
private:
    // book code
    int code;
    // The title of the book
    string title;
    // The ammount of books availble
    int available;
    //The ammount of books that have been rented
    int rented;
};

class ChildrenBook : public Book
{
    // complete the class
public:
    /*
    * Default constructor for Childrens book class
    */
    ChildrenBook() : Book(0, "Empty", 0, 0)
    {
        age = 0;
    }
    /*
    * Constructor for childrens book class
    */
    ChildrenBook(int code, string title, int available, int rented, int age) : Book(code, title, available, rented)
    {
        this->age = age;
    }
    //sets the age demographics for the book
    void setage(int age);
    // returns the age demographic for the book
    int getage();
private:
    //age demographic
    int age;
};

class ComputerBook : public Book
{
    // complete the class
public:
    /*
    * Default constructor for computer book
    */
    ComputerBook() :Book(0, "Empty", 0, 0)
    {
        publisher = "Blank";
    }
    // Constructor for computer book
    ComputerBook(int code, string title, int available, int rented, string publisher) : Book(code, title, available, rented)
    {
        this->publisher = publisher;
    }
    //Copy constructor 
    ComputerBook(const ComputerBook& p)
    {
        this->publisher = p.publisher;
    }
    /*
    * Sets the publisher of the book
    */
    void setpublisher(string publisher);
    /*
    * returns the publsiher of the book
    */
    string getpublisher()
    {
        return publisher;
    }
private:
    //Publisher of the book
    string publisher;
};

class Novel : public Book
{ // complete the class
public:
    // Default constructor for book class
    Novel() : Book(0, "Empty", 0, 0)
    {
        this->publish_date = 000000;
    }
    //Constructor for Novel class
    Novel(int code, string title, int available, int rented, int publish_date) : Book(code, title, available, rented)
    {
        this->publish_date = publish_date;
    }
    //Sets the publishing date for the novel
    void setdate(int date);
    //returns the publishing date for the novel
    int getdate();
private:
    //Publishing date 
    int publish_date;
};
//structure for linked list
struct BookNode
{
    Book* book;
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

void Book::removebook(BookNode* head, int code)
{

    BookNode* current = head; // Initialize current
    int newava = current->book->getavailable();
    int newrent = current->book->getrented();
    while (current != NULL) {
        if (current->book->getcode() == code)
        {
            newava--;
            newrent++;
            

            current->book->setavailable(newava);
            current->book->setrented(newrent);
        }

        current = current->link;
    }

}
void Book::addbook(BookNode* head, int code)
{
    BookNode* current = head; // Initialize current
    int newava = current->book->getavailable();
    int newrent = current->book->getrented();
    while (current != NULL) {
        if (current->book->getcode() == code)
        {
            newava++;
            newrent--;


            current->book->setavailable(newava);
            current->book->setrented(newrent);
        }

        current = current->link;
    }
}
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
/*
string ComputerBook::getpublisher()
{
    return publisher;
}
*/
void Novel::setdate(int date)
{
    this->publish_date = date;
}
int Novel::getdate()
{
    return publish_date;
}