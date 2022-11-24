using namespace std;
// Person class
class Person
{
    // complete the class
public:
    Person();
    Person(int id, string name, int count);
    int getid();
    void setid(int id);
    string getname();
    void setname(string name);
    int getcount();
    void setcount(int count);
private:
    int id;
    string name;
    int count;
};

class Student : public Person
{
    // complete the class
public:
    Student() : Person(0000, "Empty", 0)
    {
        code[0] = 0;
        code[1] = 0;
    }
    Student(int id, string name, int count, int code1) : Person(id, name, count)
    {
        code[0] = code1;
        code[1] = 0;
    }
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