#include <iostream>
#include <string.h>
using namespace std;

class Person
{
private:
	char*	_name{	};
public:
	Person(string name) : _name(&name[0]) {
        
    }
	char* getName() const { return _name; }
};

int comparator(const void* first, const void* second)
{
	auto firstPerson = static_cast<const Person*>(first);
	auto secondPerson = static_cast<const Person*>(second);
    
    return strcmp(firstPerson->getName(),secondPerson->getName());
}

int main() {
    Person obj[3] = {Person("cQ"),Person("bQ"),Person("aQ")};

    cout << "Before sort : \n";
    for(auto i : obj) {
        cout << i.getName() << endl;
    }   
    
    qsort(obj,3,sizeof(char*),comparator);

    cout << "\n\nAfter Sort : \n";
    for(auto i : obj) {
        cout << i.getName() << endl;
    }
}