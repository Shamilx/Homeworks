#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

class Person
{
private:
	char*	_name	{	};
	int		_age	{	};

public:
	Person(string name, int age) : _name(&name[0]), _age(age) { }
	char* getName() const { return _name; }
	void to_string()
	{
		cout << this->_name << "\t" << this->_age << endl;
	}

	friend bool operator<(const Person& f, const Person& s);
};

bool operator<(const Person& f, const Person& s)
{
    short a;
    return !(( a = strcmp(f.getName(),s.getName())) == -1) ? false : bool(a);
}

int main() {
    vector<Person> p;
	p.emplace_back(Person("AAA", 22));
	p.emplace_back(Person("HHH", 17));
	p.emplace_back(Person("YYY", 26));

	sort(p.begin(), p.end());
	for (auto pers : p)
	{
		pers.to_string();
	}
}