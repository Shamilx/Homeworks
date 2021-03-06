#include <iostream>
#include <conio.h>
#include <vector>
#include<time.h>

using namespace std;

void delay(clock_t a)
{
    clock_t start;
    start  = clock();
    while(clock()-start<a)
    {

    }
}

// 1 - teacher, 2 - student , 3 - admin
class Base;

struct Group
{
    string groupName;
    Base* teacher;
    vector<Base*> GroupStudents;
};
struct Storage
{
    vector<Base*> Teachers;
    vector<Base*> Students;
    vector<Group*> Groups;
}global;

class Base
{
protected:
    string name,surname,fathername,email,loginName,pass;
    Group* group{};
    
    int age;
    Base() { id++; }
public:
    static int id;
    
    void editInfo(string name,string surname,string fathername,string email,string loginName,string pass,int age)
    {
        this->name = name;
        this->surname = surname;
        this->fathername = fathername;
        this->id = id;
        this->email = email;
        this->loginName = loginName;
        this->pass = pass;
        this->age = age;
    }
    
    void printInfo()
    {
        cout << "Name : " << name << endl;
        cout << "Surname : " << surname << endl;
        cout << "Fathername : " << fathername << endl;
        cout << "Email : " << email << endl;
        cout << "Age : " << age << endl;
    }
    
    bool LogIn(string login,string password,bool teacher)
    {
        if(teacher)
        {
            for(int i = 0;i < global.Teachers.size();++i)
            {
                if(global.Teachers[i]->loginName == login && global.Teachers[i]->pass == password)
                {
                    global.Teachers[i]->LogInSuccses();
                    return 0;
                }
            }
            return 0;
        }
        else
        {
            for(int i = 0;i < global.Students.size();++i)
            {
                if(global.Students[i]->loginName == login && global.Students[i]->pass == password)
                {
                    global.Students[i]->LogInSuccses();
                    return 0;
                }
            }
            return 0;
        }
    }

    bool haveGroup()
    {
        if(group == NULL) return 0;
        
        return 1;
    }
    // Getters
    string getName() { return name; }
    string getSurname() { return surname; }
    // Setters
    void setGroup(Group* hey) { group = hey; }
    
    virtual void LogInSuccses() {}
};
int Base::id = 0;
 
class Teacher : public Base
{
public:
    Teacher() {}
    
    void LogInSuccses()
    {
        cout << "Welcome Teacher" << endl << endl;
        delay(500);
        
        if(haveGroup())
        {
            cout << "You are in " << group->groupName << endl;
            if(group->GroupStudents.size() > 0)
            {
                for(int i = 0;i < group->GroupStudents.size();i++)
                {
                    cout << i << ")" << group->GroupStudents[i]->getName() << group->GroupStudents[i]->getSurname() << endl;
                }
                int index;
                cout << "Input a number for additional info(-1 to exit) : ";
                cin >> index;
                if(index == -1) return;
                
                group->GroupStudents[index]->printInfo();
                delay(6000);
                return;
            }
            else
            {
                cout << "Your group has not any members..." << endl;
                
                return;
            }
        }
        
    }
    
};

class Student : public Base
{
public:
    Student() {}
    
    void LogInSuccses()
    {
        cout << "Welcome Student" << endl << endl;
        delay(500);
        
        if(haveGroup())
        {
            cout << "You are in " << group->groupName << endl;
            if(group->GroupStudents.size() > 0)
            {
                for(int i = 0;i < group->GroupStudents.size();i++)
                {
                    cout << i << ")" << group->GroupStudents[i]->getName() << group->GroupStudents[i]->getSurname() << endl;
                }
                delay(6000);
            }
            else
            {
                cout << "Your group has not any members..." << endl;
                return;
            }
        }
        else
        {
            cout << "you havent got any group :/" << endl;
        }
        
    }
    
};

class Admin
{
public:
    Admin() {}
    
    bool menu()
    {
        system("cls");
        cout << "1)Create a group." << endl;
        cout << "2)Check groups." << endl;
        cout << "3)Hire a teacher." << endl;
        cout << "4)Accept a student." << endl;
        cout << "5)Delete group." << endl;
        cout << "6)Edit group." << endl;
        cout << "7)Exit" << endl;
        
        int x = (_getch() - '0');
        if(x == 7) { return 0; }
        else if(x == 6) { editGroup(); }
        else if(x == 5) { deleteGroup();  }
        else if(x == 4) { createStudent();  }
        else if(x == 3) { createTeacher();  }
        else if(x == 2) { checkGroups(); }
        else if(x == 1) { createGroup(); }
        else { menu();  }
        
        menu();
    }
    
    void editGroup()
    {
        system("cls");
        if(!global.Groups.size())
        {   
            cout << "There is no Group" << endl;
            delay(3000);
            return;
        }
        
        for(int i = 0;i < global.Groups.size();i++)
        {
            cout << i << ")" << global.Groups[i]->groupName << endl;
        }
        
        int index;
        cout << "Input index : "; cin >> index;
        
        system("cls");
        
        cout << "You have logged in as " << global.Groups[index]->groupName << endl;
        
        cout << endl << "What you gonna do?" << endl;
        cout << "1)Add Student" << endl << "2)Delete Student(From Group)" << endl;
        int index2 = _getch() - '0';
        if(index2 < 0 || index2 > 2)
        {
            editGroup();
            return;
        }
        
        if(index2 == 1)
        {
            bool find_out = true;
            cout << "Create a student and add it to list(1) or add ready one(0) : "; cin >> find_out;
            
            if(find_out)
            {
                createStudent();
                Base* lastStudent = global.Students[global.Students.size() - 1];
                lastStudent->setGroup(global.Groups[index]);
                global.Groups[index]->GroupStudents.push_back(lastStudent);
                return;
            }
            else
            {
                system("cls");
                for(int i = 0;i < global.Students.size();i++)
                {
                    if(global.Students[i]->haveGroup() == 0) cout << i << ")" << global.Students[i]->getName()  << " " << global.Students[i]->getSurname() << endl;
                }
                
                int index_temp;
                cout << "Input Index to add : (PLEASE INSERT CORRECT INDEX)";cin >> index_temp;
                global.Students[index_temp]->setGroup(global.Groups[index]);
                global.Groups[index]->GroupStudents.push_back(global.Students[index_temp]);
            }
        }
        if(index2 == 2)
        {
            system("cls");
            for(int i = 0;i < global.Groups[index]->GroupStudents.size();i++)
            {
                cout << i << ")" << global.Groups[index]->GroupStudents[i]->getName() << endl;
            }
            int index3{};
            cout << "Input index to delete : "; cin >> index3;
            if(index3 < 0 || index3 >= global.Groups[index]->GroupStudents.size())
            {
                cout << "Input correct number!" << endl;
                delay(3000);
                return;
            }
            
            global.Groups[index]->GroupStudents.erase(global.Groups[index]->GroupStudents.begin() + index);
            
            return;
        }
    }
    
    void deleteGroup()
    {
        system("cls");
        if(global.Groups.size() == 0) 
        {
            cout << "There is no Group" << endl;
            delay(3000);
            return;
        }
        
        
        for(int i = 0;i < global.Groups.size();i++)
        {
            cout << i << ")" << global.Groups[i]->groupName << endl;
        }
        
        int index;
        cout << endl << "Input an index to delete : ";
        cin >> index;
        
        if(index >= global.Groups.size() || index < 0)
        {
            cout << "Wrong one" << endl;
            delay(3000);
            return;
        }
        
        global.Groups.erase(global.Groups.begin() + index);
    }
    
    
    void createGroup()
    {
        system("cls");
        global.Groups.push_back(new Group());
        Group* last = global.Groups[global.Groups.size() - 1];
        
        cout << "Name your group : "; cin >> last->groupName;
        system("cls");
        if(global.Teachers.size() == 0)
        {
            cout << "There is no Teacher to attach to group!You are going to create one..." << endl;
            delay(3000);
            createTeacher();
            Base* lastTeacher = global.Teachers[global.Teachers.size() - 1];
            last->teacher = lastTeacher;
            lastTeacher->setGroup(last);
        }
        else
        {
            int Index{1},HaveGroup{};
            for(int i = 0;i < global.Teachers.size();i++)
            {
                if(global.Teachers[i]->haveGroup() == true)
                    continue; 
                
                cout << Index << ")" << global.Teachers[i]->getName() << " " << global.Teachers[i]->getSurname() << endl;
                Index++;
            }
            if(Index == 1) 
            {
                cout << "There is no teacher,you need to hire one again!" << endl;
                global.Groups.pop_back();
                delay(1000); return;
            }
            
            string name;
            cout << endl << "Name of teacher you want to select : " << endl; 
            cin >> name;
            
            for(int i = 0;i < global.Teachers.size();i++)
            {
                if(global.Teachers[i]->getName() == name)
                {
                    global.Teachers[i]->setGroup(last);
                    last->teacher = global.Teachers[i];
                    break;
                }
            }
        }
        
        system("cls");
        cout << "Now you are going to add students to your group." << endl;
        delay(2000);
        if(global.Students.size() == 0)
        {
            system("cls");
            cout << "There is no student in Academy!" << "You are going to create one." << endl; delay(3000);
            createStudent();
            Base* lastStudent = global.Students[global.Students.size() - 1];
            lastStudent->setGroup(last);
            last->GroupStudents.push_back(lastStudent);
            return;
        }
        else 
        {
            int temp2{};
            for(int i = 0;i < global.Students.size();i++)
            {
                if(global.Students[i]->haveGroup() == 0) { cout << i << ")" << global.Students[i]->getName() << " " << global.Students[i]->getSurname() << endl; temp2++; }
                
            }
            if(temp2 == 0) 
            {
                cout << "There is no student to add this group.Accept them from menu" << endl;
                delay(3000);
                return;
            }
            string name2;
            cout << endl << "Name of student you want to select : " << endl; 
            cin >> name2;
                        
            for(int i = 0;i < global.Students.size();i++)
            {
                if(global.Students[i]->getName() == name2)
                {
                    global.Students[i]->setGroup(last);
                    last->GroupStudents.push_back(global.Students[i]);
                    break;
                }
            }
        }
    }
    
    void createTeacher()
    {
            system("cls");
            global.Teachers.push_back(new Teacher()); 
            string name,surname,fathername,email,username,pass; int age;
            Base* last = global.Teachers[global.Teachers.size() - 1];
            cout << "Name of teacher : "; cin >> name;
            cout << "Surname of teacher : "; cin >> surname;
            cout << "Father name of teacher : "; cin >> fathername;
            cout << "Age of teacher : "; cin >> age;
            cout << "Email of teacher : "; cin >> email;
            cout << "Login Username for teacher : "; cin >> username;
            cout << "Login Password for teacher : "; cin >> pass;
            
            last->editInfo(name,surname,fathername,email,username,pass,age);
    }
    
    void createStudent()
    {
        system("cls");
        global.Students.push_back(new Student()); 
        
        string name,surname,fathername,email,username,pass; int age;
        Base* lastStudent = global.Students[global.Students.size() - 1];
        
        cout << "Name of student : "; cin >> name;
        cout << "Surname of student : "; cin >> surname;
        cout << "Father name of student : "; cin >> fathername;
        cout << "Age of student : "; cin >> age;
        cout << "Email of student : "; cin >> email;
        cout << "Login Username for student : "; cin >> username;
        cout << "Login Password for student : "; cin >> pass;
        lastStudent->editInfo(name,surname,fathername,email,username,pass,age);
    }
    
    void checkGroups()
    {
        system("cls");
        if(global.Groups.size() == 0) 
        {
            cout << "There is no Group" << endl;
            delay(3000);
            return;
        }
        
        for(int i = 0;i < global.Groups.size();i++)
        {
            cout << i << ")" << global.Groups[i]->groupName << "\t" << global.Groups[i]->teacher->getName() << endl;
        }
        
        short index;
        cout << endl << "Index for additional info : "; cin >> index;
        
        if(index >= global.Groups.size() || index < 0)
        {
            cout << "Wrong one" << endl;
            delay(3000);
            
            return;
        }
        system("cls");
        cout << endl;
        for(int i = 0;i < global.Groups[index]->GroupStudents.size();i++)
        {
            cout << i << ")" << global.Groups[index]->GroupStudents[i]->getName() << "\t" << global.Groups[index]->GroupStudents[i]->getSurname() << endl;
        }
        
        short index2;
        cout << endl << "Input index for additional info : "; cin >> index2;
        
        if(index >= global.Groups[index]->GroupStudents.size() || index < 0)
        {
            cout << "Wrong one" << endl;
            delay(3000);
            return;
        }
        
        system("cls");
        global.Groups[index]->GroupStudents[index2]->printInfo();
        delay(6000);
        return;
    }
}admin;



class Menu
{
public:
    short draw()
    {
        system("color 2F");
        cout << "Login : " << endl;
        cout << "1)LogBook" << endl;
        cout << "2)MyStat" << endl;
        cout << "3)Admin" << endl;
        short x = _getch();
        
        return (x - '0');
    }
        
    bool TeacherStart()
    {
        system("cls");
        string login,pass;
        if(global.Teachers.empty())
        {
            for(int i = 3;i > 0;--i)
            {
                cout << "There is no Teacher in Academy!(Create one)" << endl;
                delay(1500);
                system("cls");
            }
            system("cls");
            
            return 0;
        }
        
        int count = 0;
        cout << "Welcome Teacher" << endl << endl;
        cout << "Username : "; cin >> login;
        cout << "Password : "; cin >> pass;
        
        for(int i = 0;i < global.Teachers.size();++i)
        {
            if(global.Teachers[i]->LogIn(login,pass,1))
                return 0;
        }
        
        cout << "Wrong user name or password!" << endl;
        delay(1500);
        return 0;
    }

    bool StudentStart()
    {
        system("cls");
        string login,pass;
        if(global.Students.empty())
        {
            for(int i = 3;i > 0;--i)
            {
                cout << "There is no Student in Academy!(Create one)" << endl;
                delay(1500);
                system("cls");
            }
            system("cls");
            return 0;
        }
        
        int count = 0;
        cout << "Welcome Student" << endl << endl;
        cout << "Username : "; cin >> login;
        cout << "Password : "; cin >> pass;
        
        for(int i = 0;i < global.Students.size();++i)
        {
            if(global.Students[i]->LogIn(login,pass,0))
                return 0;
        }
        
        cout << "Wrong user name or password!" << endl;
        delay(1500);
        return 0;
    }

    bool AdminStart()
    {
        system("cls");
        string login,pass;
        cout << "Username : "; cin >> login;
        cout << "Password : "; cin >> pass;
        if(login == "admin" && pass == "admin")
        {
            bool t = admin.menu();
            return t;
        }
        
        return 0;
    }
};

bool start()
{
    Menu menu;
    int x = menu.draw();
    bool c;
    
    if(x == 1)
        c = menu.TeacherStart();
    else if(x == 2)
        c = menu.StudentStart();
    else if(x == 3)
        c = menu.AdminStart();
    else
    {
        return 0;
    }
    
    return c;
}

int main()
{
    while(true)
    {
        if(!start())
        {
            system("cls");
            continue;
        }
        break;
    }
}
