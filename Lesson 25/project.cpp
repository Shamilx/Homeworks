#include <iostream>
#include <vector>
#include <conio.h>
#include <string.h>
#include <algorithm>

using namespace std;

class Car
{
    string brand;      // Mercedes
    string model;      // GL550
    int year;        // 2020
    double engineSize; // 5.5
    double price;

public:
    Car(string brand, string model, int year, double engineSize, double price)
    {
        this->brand = brand;
        this->model = model;
        this->year = year;
        this->engineSize = engineSize;
        this->price = price;
    }

    string getBrand()
    {
        return this->brand;
    }

    string getModel()
    {
        return this->model;
    }

    short getYear()
    {
        return this->year;
    }

    double getEngineSize()
    {
        return this->engineSize;
    }

    double getPrice()
    {
        return this->price;
    }
};

class Storage
{
    static vector<Car *> Cars;
    Storage() = delete;

public:
    static void pushToStorage(string brand, string model, int year, double engineSize, double price)
    {
        Cars.push_back(new Car(brand, model, year, engineSize, price));
    }

    static void displayAllCars()
    {
        for (auto i : Cars)
        {
            cout << i->getBrand() << "\t" << i->getModel() << "\t" << i->getYear() << "\t" << i->getPrice() << "\n";
        }
        _getch();
    }

    static vector<Car *> &getCars()
    {
        return Cars;
    }

    static vector<Car *> getCopyOfCars()
    {
        return Cars;
    }
};

vector<Car *> Storage::Cars = {};

namespace Functions
{
    void Menu();
    
    void createCar()
    {
        string brand;
        string model;
        int year;
        double engineSize;
        double price;

        cout << "\nCar brand : ";
        cin >> brand;
        cout << "\nCar model : ";
        cin >> model;
        cout << "\nCar year  : ";
        cin >> year;
        cout << "\nCar engine size : ";
        cin >> engineSize;
        cout << "\nCar price : ";
        cin >> price;

        Storage::pushToStorage(brand, model, year, engineSize, price);
    }

    template <typename T>
    void sortCars(T ptr)
    {
        cout << "\n1)For Brands\n";
        cout << "\n2)For Years\n";
        cout << "\n3)For Prices\n";

        auto stringCmpr = [](const void *first, const void *second) -> int {
            auto myFirst = (Car *)(first);
            auto mySecond = (Car *)(second);

            return strcmp(myFirst->getBrand().c_str(), mySecond->getBrand().c_str());
        };

        auto yearCompare = [](Car *first,Car *second) -> int {
            return first->getYear() < second->getYear();
            // if(first->getYear() > second->getYear())
            //      return 1; 
            // else if(first->getYear() < second->getYear()) 
            //      return -1; 
            // else return 0;
        };

        auto priceCompare = [](Car *first,Car *second) -> int {
            return first->getPrice() < second->getPrice();
        };

        vector<Car*> Cars = Storage::getCopyOfCars();
        
        switch (ptr())
        {
        case -1:
            throw exception();
        case 1:
            sort(Cars.begin(), Cars.end(), stringCmpr);
            break;
        case 2:
            sort(Cars.begin(),Cars.end(),yearCompare);
            break;
        case 3:
            sort(Cars.begin(),Cars.end(),priceCompare);
            break;
        default:
            Functions::Menu(); return;
        }

        for (auto i : Cars)
        {
            cout << i->getBrand() << "\t" << i->getModel() << "\t" << i->getYear() << "\t" << i->getPrice() << "\n";
        }
        _getch();
    }

    void deleteCar()
    {
        string name;
        cout << "Input the model of car which will be deleted : ";
        cin >> name;
        for_each(Storage::getCars().begin(), Storage::getCars().end(), [name](Car *car) {
            if (car->getModel() == name)
            {
                Storage::getCars().erase(find(Storage::getCars().begin(), Storage::getCars().end(), car));
                return;
            }
        });
    }

    void Menu()
    {
        auto selection = []() -> int {
            string select;
            cin >> select;

            // Check for char
            for (int i = 0; i < select.length(); i++)
            {
                if (!(select[i] > 47 && select[i] < 58))
                {
                    return -1;
                }
            }

            return atoi(select.c_str());
        };

        system("cls");
        cout << "\n1)Create a Car\n";
        cout << "\n2)Delete a Car\n";
        cout << "\n3)Display all Cars\n";
        cout << "\n4)Sorting\n";

        switch (selection())
        {
        case -1:
            throw exception();
        case 1:
            createCar();
            Menu();
            return;
        case 2:
            deleteCar();
            Menu();
            return;
        case 3:
            Storage::displayAllCars();
            Menu();
            return;
        case 4:
            sortCars(selection);
            Menu();
            return;
        default:
            Menu();
            return;
        }
    }
}

int main()
{
    Functions::Menu();
}