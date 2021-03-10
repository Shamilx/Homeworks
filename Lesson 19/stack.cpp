#include <iostream>

using namespace std;

class Stack
{
    int arr[30];
    int size{};
public:

    void push(int val)
    {
        try
        {
            if(size == 30) throw("You have been reached to limit");

            arr[size] = val;
            size++;
        }
        catch(const char* e)
        {
            std::cerr << e << '\n';
        }
    }
    

    void pop()
    {
        try
        {
            if(size == 0) throw("Size number");

            arr[size] = 0;
            size--;
        }
        catch(const char* e)
        {
            std::cerr << e << endl;
        }
    }
    void print()
    {
        for(int i = 0;i < size;i++) cout << arr[i] << endl;
    }
};



int main()
{
    Stack obj;
    obj.push(5);
    obj.push(4);
    obj.push(3);
    obj.push(2);
    obj.pop();
    obj.print();
}