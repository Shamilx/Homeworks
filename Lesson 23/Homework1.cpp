#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Group;

class Student
{
    Group* group;
    string name{};   
    int age{}; 
public:
    Student(string name,int age,Group& obj)
    {
        this->name = name;
        this->age = age;
        this->group = &obj;
    }

    string getName() { return name; } 
};

class Teacher
{
    Group* group;
    string name{};   
    int age{}; 
public:
    Teacher(string name,int age,Group& obj)
    {
        this->name = name;
        this->age = age;
        this->group = &obj;
    }

    string getName() { return name; } 
};

struct Group
{
    vector<Teacher*> Teachers;
    vector<Student*> students;
public:
    void addTeacher(string name, int age) { Teachers.push_back(new Teacher(name, age,*this)); }

    void deleteTeacher(string name)
    {
        if(Teachers.empty()) { cout << "What are you doing?\n"; return; }
        for(int i = 0;i < Teachers.size();i++)
        {
            if(Teachers[i]->getName() == name)
            {
                delete Teachers[i];
                break;
            }
        }

        if(Teachers.empty())
        {
            if(!students.empty())
            {
                for(int i = 0;i < students.size();i++)
                {
                    delete students[i];
                }
            }
        }
    }

    void addStudent(string name, int age) { students.push_back(new Student(name, age,*this)); }

    void deleteStudent(string name)
    {
        if(students.empty()) { cout << "What are you doing?\n"; return; }
        for(int i = 0;i < students.size();i++)
        {
            if(students[i]->getName() == name)
            {
                delete students[i];
                break;
            }
        }
    }
        

};

int main()
{
   // group - > Group group1 - > methodlar (addTeacher,addStudent,deleteStudent(string),deleteTeacher(string))

    
}
