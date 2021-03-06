#include <iostream>
#include <vector>
using namespace std;

class Make_Car
{
    string model;
    string brand;
    int year;
    int maxSpeed;
public:
    Make_Car(string model,string brand,int year,int maxSpeed)
    {
        this->model = model; this->brand = brand;
        this->year = year; this->maxSpeed = maxSpeed;
    }
};
class Rent_Car
{
    vector<string> People;
    Make_Car* ptr;
    int price;
    bool rentable;
public:
    void makeCar(string model,string brand,int year,int maxSpeed)
    {
        if(ptr == NULL)
        {
            ptr = new Make_Car(model, brand, year, maxSpeed);
        }
    }

    void makeRentable(int price)
    {
        if(ptr != NULL)
        {
            this->price = price;
            this->rentable = true;
        }
    }

    void addPerson(string name)
    {
        if(rentable == false) { cout << "First make your car rentable\n"; return; }
        if(People.size() < 5)People.push_back(name);
        else cout << "You have given that car to max people.\n";
    }

    void deletePerson(string name)
    {
        if (People.empty()) { cout << "Add people"; return; }

            for (int i = 0; i < People.size(); i++)
            {
                if (People[i] == name) { 
                    People.erase(People.begin() + i);
                }
            }
    }

    int getPrice()  { if(People.size() != 0) return price / People.size(); return 0; }
};

int main()
{
    Rent_Car Mercedes;
    Mercedes.makeCar("GL550","Mercedes",2020,360);
    Mercedes.makeRentable(100);
    Mercedes.addPerson("Omer");
    Mercedes.addPerson("Shamil");
    Mercedes.deletePerson("Omer");
    cout << Mercedes.getPrice();
}
