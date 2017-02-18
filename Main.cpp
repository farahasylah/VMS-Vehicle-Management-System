#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include "Vehicle.hpp"
#include "LList.hpp"
using namespace std;


void Main()
{
    system("cls");
    cout << "====================================================\n"
         << "\t\tVehicle Management System\n"
         << "====================================================\n"
         << " 1 - Vehicle\n"
         << " 2 - Manager\n"
         << "\n Insert any key to exit\n\n"
         << " Select : ";
}

void Create()
{
    cout <<"\n Select :\n"
        << "\t 1 - Van\n"
        << "\t 2 - Bus\n"
        << "\t 3 - Car\n\n"
        << "\t Select : ";
}

void Vmenu()
{
    cout <<" 1 - Create a vehicle \n"
        << " 2 - Modify a vehicle information\n"
        << " 3 - Erase a vehicle\n"
        << " 4 - Empty the list\n"
        << " Select : ";
}
void Selection()
{
    cout << "--------------------------------------------\n"
         << "Choice:\n"
         << "1: Insert into table \n"
         << "2: Insert after index number selection\n"
         << " or press any key to exit \n";
}

void Managermenu()
{
    cout << "Choice:\n"
        << "1 - Create a manager \n"
        << "2 - Assign to a vehicle\n"
        << "3 - Update price of vehicle \n"
        << "4 - Update vehicle status \n"
        << " or press any key to exit \n";

}
void showVlist(){
 cout << "| Index\t|"
    << "\tType\t |"
    << "\tModel\t |"
    << "\tColour\t |"
    << "\tPrice\t |"
    << "\tSOLD  |"
    << "\tManager\t |\n";

}

void showMlist(){
 cout <<"|Index|     Name     |\n";
}

int main() {

LList<Vehicle> list;
Vehicle newV;
Vehicle* modifyV;
Vehicle* selectV;
string manager = "NA";
string model,type,colour;
int choice;
char option;
double price;
bool sold = false;
bool found;

LList<Manager> mlist;
Manager newman;
Manager* modifyMan;
Manager* selectMan;
int targetindex,vehicleindex,managerindex;
string name;


 do {
    Main();
    cin >> choice;
    switch (choice)
    {
    case 1:
        do{
        system ("cls");
        showVlist();
        cout << list << endl;
        Vmenu();
        cin >> choice;
        switch (choice)
        {
        system ("cls");
        case 1 :    system ("cls");
                    showVlist();
                    cout << list << endl;
                    Create();
                    cin >>choice;
                    switch (choice)
                    {
                    case 1 :    cout << " Create a van.\n Enter model and colour : ";
                                cin  >> model >> colour;
                                cout << " Enter price (RM) in k : ";
                                cin  >> price;
                                newV = Van ("Van",model,colour,price,sold);
                                break;
                    case 2  :   cout << " Create a bus.\n Enter model and and colour : ";
                                cin  >> model >> colour;
                                cout << " Enter price (RM) in k : ";
                                cin  >> price;
                                newV = Bus ("Bus",model,colour,price,sold);
                                break;
                    case 3 :    cout << " Create a car.\n Enter model and and colour : ";
                                cin  >> model >> colour;
                                cout << " Enter price (RM) in k : ";
                                cin  >> price;
                                newV = Car ("Car",model,colour,price,sold);
                                break;
                    }
                    Selection();
                    cin >> choice;
                     switch (choice)
                    {
                    case 1 :    list.insertEnd(newV);
                                break;
                    case 2 :    system ("cls");
                                showVlist();
                                cout << list << endl;
                                cout << "Enter index number to insert after it : ";
                                cin >> targetindex;
                                found = list.insertAfter (targetindex, newV);
                                if (!found) cout << "Target not found\n";
                                else cout << "Insert complete!\n";
                                break;
                    }
                    break;

        case 2 :    cout << "Enter the index number : ";
                    cin >> targetindex;
                    found = list.modify (targetindex, modifyV);
                    if (!found)
                        cout << "No index number found\n";
                    else
                    {
                        cout << *modifyV << " retrieved.\n";
                        cout << "Enter new value: ";
                        cin >> *modifyV;
                    }
                    break;
        case 3 :    cout << "Enter the index number : ";
                    cin >> targetindex;
                    found = list.erase (targetindex);
                    if (!found)
                        cout << "No index number found\n";
                    else
                        cout << "Record deleted! \n";
                    break;
        case 4 :    list.makeEmpty();
                    cout << "Table is now empty!\n\n";
                    break;
        }
        case 5 :    system ("cls");
                    showVlist();
                    cout << list << endl;
                    showMlist();
                    cout << mlist << endl;

                    break;

        }while (choice >= 1 && choice <=4);
        break;
    case 2 : Managermenu();
            cin >> choice;
            switch (choice)
            {
             case 1 :   cout << " Create a manager.\n Enter name : ";
                        cin  >> name;
                        newman = Manager (name);
                        mlist.insertEnd(newman);
                        break;
             case 2 :
                        showVlist();
                        cout << list << endl;
                        showMlist();
                        cout << mlist << endl;
                        cout << "Assign a vehicle ";
                        cout << "Please enter target: ";
                        cin >> vehicleindex;
                        found = list.modify (vehicleindex, modifyV);
                        if (!found)
                            cout << "No index number found\n";
                        else
                        {
                            selectV = modifyV;
                            string Vtype = selectV->getType();
                            cout << "Assign to a manager ";
                            cout << "Please enter target: ";
                            cin >> managerindex;
                            found = mlist.modify (managerindex, modifyMan);
                            if (!found){
                                cout << "No index number found\n";}
                            else{
                                selectMan = modifyMan;
                                string Mselect = selectMan->getManager();
                                newV = Vehicle (Vtype,model,colour,price,sold,Mselect);
                                found = list.insertnew(vehicleindex,newV);
                                if (!found){
                                    cout << "No index number found\n";}
                                else{
                                    cout << "Insert complete!\n"; }
                            }
                        }
                        break;
             case 3 :    cout << "Update price of vehicle. Enter price (RM) :";
                        cin >> price;
                        cout << "Please enter target.";
                        cin >> targetindex;
                        newV = Vehicle (type,model,colour,price,sold,manager);
                        found = list.insertnew(targetindex,newV );
                        if (!found)
                        cout << "No index number found\n";
                        else
                        {
                        cout << "Insert complete!\n";
                        }
                        break;
            case 4 :    cout << "Update vehicle status.";
                        cout << "Is the vehicle sold out? Yes (Y) or No (N)";
                        cin  >> option;
                        if (option =='y'||option=='Y')
                        {
                            sold = true;
                            cout << "Please enter target.";
                            cin >> targetindex;
                            newV = Vehicle (type,model,colour,price,sold,manager);
                            found = list.insertnew(targetindex,newV );
                            if (!found)
                            cout << "No index number found\n";
                            else
                            {
                            cout << "Insert complete!\n";
                            }
                        }
                        else
                        cout << "The vehicle is still available";
                        break;
            }

    }
    cout << "Back to main menu ? Yes (Y) or press any key to exit : ";
    cin >> option;

} while (option == 'y' || option == 'Y' );

}
