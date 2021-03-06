#include <iostream>
#include "Car.h"

using namespace MyCar;
using namespace std;

int main()
{
    try{
        Car car1("Porsche","Panamera",2020,"Black","CCC222","jbsajbc2211s",350,2000);
        Car car2("Subaru","Impreza",2013,"Grey","ABC123","JPKSKD12612",110,1950);

        Car car4("Audi","100",1998,"Red","AGH354","VWksadjasf222151",128,2500);

        cout << "Car 2 color " << car2.getColor() << endl;
        cout << "Car 2 engine power " << car2.getEnginePower() << " KW" << endl;
        cout << "Car 2 manufacturer " << car2.getManufacturer() << endl;
        cout << "Car 2 manufacture year " << car2.getManufactureYear() << endl;
        cout << "Car 4 model " << car4.getModel() << endl;
        cout << "Car 4 plate " << car4.getPlate() << endl;
        cout << "Car 4 vin " << car4.getVin() << endl;
        cout << "Car 4 weight " << car4.getWeight() << " KG" << endl;
        cout << "Car 4 ID " << car4.getID() << endl;

        cout << car1.toString() << endl;
        cout << car2.toString() << endl;
        cout << car4.toString() << endl;
        car1.setManufacturer("Ferrari");
        car1.setColor("Red");
        car1.setVin("bifhdksom256482");
        car1.setManufactureYear(2018);
        car1.setEnginePower(460);
        car1.setModel("458");
        car1.setWeight(1800);
        cout << car1.toString() << endl; // ID has not changed, because car1 object did not change
        car1.setPlate("bb222s22"); // throws exception



    }
    catch(invalid_argument& err){
        cerr << "Invalid argument: "<< err.what() << endl;
    }
    catch(...){
        cerr << "Unknown exception detected" << endl;
    }
    return 0;
}
