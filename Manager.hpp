#ifndef MANAGER_HPP
#define MANAGER_HPP
#include <iostream>
using namespace std;

class Manager : public Vehicle
{
    string name;
 public:
    Manager (string name = "NA")
    : name(name) {}
     friend ostream& operator<< (ostream& os, Manager& m )
    {   os << m.name;
        return os;
    }
    friend istream& operator>> (istream& is,Manager& m)
    {   cout << "Input manager name :  ";
        is >> m.name;
        return is;
    }
};

#endif
