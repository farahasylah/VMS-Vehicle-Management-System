#ifndef VEHICLE_HPP
#define VEHICLE_HPP
#include "Vehicle.hpp"
using namespace std;


class Vehicle {
protected:
    string type;
    string brand;
    string colour;
    double price;
    bool sold;
    string manager;
public:
    Vehicle(string type = " ",string model = " ",string colour = "No colour",
            double price = 0,bool sold = false,string manager = "[NA]")
    : type(type),brand(model),colour(colour),price(price),sold(sold),manager(manager)
    {   type = type;
        brand = model;
        colour = colour;
        price = price;
        sold = sold;
        manager = manager;
    }
    string getType() {return type;}
    string getBrand() {return brand;}
	string getColour() {return colour;}
	double getPrice() {return price;}
	bool getStatus() {return sold;}
	string getmanager() {return manager;}

    friend ostream& operator<< (ostream& os, Vehicle& v )
    {   os << "\t"<< v.getType();
        os << "\t\t"<< v.getBrand()<< "\t";
        os << "\t"<< v.getColour()<< "\t";
        os << "\t"<< v.getPrice() << "k\t";
        os << "\t"<< v.getStatus() ;
         os << "\t"<< v.getmanager() << "\t";

        return os;
    }
    friend istream& operator>> (istream& is,Vehicle& v)
    {   cout << " Input model and colour of vehicle:  ";
        is >> v.brand  >> v.colour ;
        cout << "\n Input price of vehicle:  ";
        is >> v.price;
        return is;
    }
};

class Manager{
    string name;
 public:
    Manager (string name = "NA")
    : name(name) {}
    string getManager() {return name;}
     friend ostream& operator<< (ostream& os, Manager& m )
    {   os << m.getManager();
        return os;
    }
    friend istream& operator>> (istream& is,Manager& m)
    {   cout << "Input manager name :  ";
        is >> m.name;
        return is;
    }
};

class Van : public Vehicle,public Manager {
public:
    Van(string type = "[NA]",string model = "[NA]",string colour = "[NA]",double price = 0,bool sold = false ,string manager = "[NA]")
    : Vehicle (type,model,colour,price,sold), Manager(manager) {}
    friend ostream& operator<< (ostream& os, Van& a )
    {   os << a.getType() <<"\t\t "<< a.getBrand() <<"\t\t "<< a.getColour() <<"\t "<< a.getManager();
        return os;
    }
    friend istream& operator>> (istream& is,Van& a)
    {   cout << "Input model of vehicle:  ";
        is >> a.type >> a.brand >> a.colour >> a.manager;
        return is;
    }
};

class Bus : public Vehicle,public Manager {
public:
    Bus(string type = "[NA]",string model = "[NA]",string colour = "[NA]",double price = 0,bool sold = false ,string manager = "[NA]")
    : Vehicle (type,model,colour,price,sold), Manager(manager) {}
    friend ostream& operator<< (ostream& os, Bus& b )
    {   os << b.getType() <<"\t\t "<< b.getBrand() <<"\t\t "<< b.getColour() <<"\t "<< b.getManager();
        return os;
    }
    friend istream& operator>> (istream& is,Bus& b)
    {   cout << "Input model of vehicle:  ";
        is >> b.type >> b.brand >> b.colour >> b.manager;
        return is;
    }
};

class Car : public Vehicle,public Manager {
public:
     Car(string type = "[NA]",string model = "[NA]",string colour = "[NA]",double price = 0,bool sold = false ,string manager = "[NA]")
    : Vehicle (type,model,colour,price,sold), Manager(manager) {}
    friend ostream& operator<< (ostream& os, Car& c )
    {   os << c.getType() <<"\t\t "<< c.getBrand() <<"\t\t "<< c.getColour() <<"\t "<< c.getManager();
        return os;
    }
    friend istream& operator>> (istream& is,Car& c)
    {   cout << "Input model of vehicle:  ";
        is >> c.type >> c.brand >> c.colour >> c.manager;
        return is;
    }
};


#endif

