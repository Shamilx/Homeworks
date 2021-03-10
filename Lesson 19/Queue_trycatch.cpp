#include <iostream>
#include <queue>

using namespace std;

class Queue
{
	int massive[20];
	int front{},rear{};
public:
	void push(int var)
	{
		try
		{
			if(front == 20) throw("Capacity is full");

			massive[front] = var;
			front++;
		}
		catch(const char* exp)
		{
			cout << exp << endl;
		}
	}

	void pop()
	{
		try
		{
			if(front - rear == 0) throw("You cant delete empty Queue!");

			rear++;
		}
		catch(const char* exp)
		{
			cout << exp << endl;
		}
	}

	void print()
	{
		for(int i = rear;i < front;i++)
		{
			cout << massive[i] << endl;		
		}
	}
};

int main()
{

}