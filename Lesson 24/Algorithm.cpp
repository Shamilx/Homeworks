#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    vector<string> nameAge;
    string string2{},name;
    ifstream  fin("az.txt");
    while (getline(fin, string2))
    {
        name = string2.substr(0 , 4);
        nameAge.push_back(name);
    }
    fin.close();
    sort(nameAge.begin(), nameAge.end());
    
}



	-------------------------


	vector<string> nameAge;
    string string2{},name;
    ifstream  fin("people.txt");
    while (getline(fin, string2))
    {
        name = string2.substr(5 , 7);
        nameAge.push_back(name);
    }
    fin.close();
    sort(nameAge.begin(), nameAge.end());
    ofstream fout("sorted_by_age.txt");
    for (int i = 0; i < nameAge.size(); i++) { fout << nameAge[i] << endl; }