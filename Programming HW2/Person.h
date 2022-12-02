using namespace std;
// Person class
class Person
{
    // complete the class
public:
    //Default constructor for person class
    Person();
    // Person constructor
    Person(int id, string name, int count);
    // Return id of the person
    int getid();
    // Sets the id of the person
    void setid(int id);
    // returns the name of the person
    string getname();
    void setname(string name);
    //gets the number of books that the user has
    int getcount();
    //sets the number of books the user has
    void setcount(int count);
    //returns the code of the first book
    virtual int getcode1() { return 0; };
    //returns code of 2nd book
    virtual int getcode2() { return 0; };
    //returns code of the third book
    virtual int getcode3() { return 0; };
    //Sets the first code 
    virtual void setcode1(int code) { cout << "super"; };
    //Sets the second code
    virtual void setcode2(int code) { cout << "super"; };
    //copy constructor
    Person(const Person& p1)
    {

    }
    //destructor
private:
    // set id of person
    int id;
    //name of person
    string name;
    // the number of books
    int count;
};
// Subclass of person can rent two books
class Student : public Person
{
    // complete the class
public:
    //Default constructor for student
    Student() : Person(0000, "Empty", 0)
    {
        code[0] = 0;
        code[1] = 0;
    }
    //Student constructor for only one code
    Student(int id, string name, int count, int code1) : Person(id, name, count)
    {
        code[0] = code1;
        code[1] = 0;
    }//Student constructor for two code
    Student(int id, string name, int count, int code1,int code2) : Person(id,name,count)
    {
        code[0] = code1;
        code[1] = code2;
    }
    void setcode1(int code);
    void setcode2(int code);
    void setcode3(int code);
    int getcode1();
    int getcode2();
private:
    int code[2];
};

class Teacher : public Person
{
    // complete the class
public:
    Teacher() : Person(0000, "Empty", 0)
    {
        code[0] = 0;
        code[1] = 0;
        code[2] = 0;
    }
    Teacher(int id, string name, int count, int code1) : Person(id, name, count)
    {
        code[0] = code1;
        code[1] = 0;
    }
    Teacher(int id, string name, int count, int code1, int code2) : Person(id, name, count)
    {
        code[0] = code1;
        code[1] = code2;
        code[2] = 0;
    }
    Teacher(int id, string name, int count, int code1, int code2, int code3) : Person(id, name, count)
    {
        code[0] = code1;
        code[1] = code2;
        code[2] = code3;
    }
    void setcode1(int code);
    void setcode2(int code);
    void setcode3(int code);
    int getcode1();
    int getcode2();
    int getcode3();
private:
    int code[3];
};
//person linked list
struct PersonNode
{
    Person *person;
    PersonNode* link;
};
PersonNode* person[2];

Person::Person()
{
    id = 0000;
    name = "Empty";
    count = 0;
}
Person::Person(int id, string name, int count)
{
    this->id = id;
    this->name = name;
    this->count = count;
}

int Person::getid()
{
    return id;
}
void Person::setid(int id)
{
    this->id = id;
}
string Person::getname()
{
    return name;
}
void Person::setname(string name)
{
    this->name = name;
}
int Person::getcount()
{
    return count;
}
void Person::setcount(int count)
{
    this->count = count;
}

void Student::setcode1(int code)
{
    this->code[0] = code;
}
void Student::setcode2(int code)
{
    this->code[1] = code;
}
int Student::getcode1()
{
    return code[0];
}
int Student::getcode2()
{
    return code[1];
}

void Teacher::setcode1(int code)
{
    this->code[0] = code;
}
void Teacher::setcode2(int code)
{
    this->code[1] = code;
}
void Teacher::setcode3(int code)
{
    this->code[2] = code;
}
int Teacher::getcode1()
{
    return code[0];
}
int Teacher::getcode2()
{
    return code[1];
}
int Teacher::getcode3()
{
    return code[2];
}