#include <iostream>
#include "Car.h"

using namespace MyCar;
using namespace std;

int main()
{
    try{
        Car car1;
        Car car2("Subaru","Impreza",2013,"Grey","ABC123","JPKSKD12612",110,1950);
        Car car3;
        Car car4("Audi","100",1998,"Red","AGH354","VWksadjasf222151",128,2500);

        cout << "Car 2 color " << car2.getColor() << endl;
        cout << "Car 2 engine power " << car2.getEnginePower() << " KW" << endl;
        cout << "Car 2 manufacturer " << car2.getManufacturer() << endl;
        cout << "Car 2 manufacture year " << car2.getManufactureYear() << endl;
        cout << "Car 4 model " << car4.getModel() << endl;
        cout << "Car 4 plate " << car4.getPlate() << endl;
        cout << "Car 4 vin " << car4.getVin() << endl;
        cout << "Car 4 weight " << car4.getWeight() << " KG" << endl;

        cout << car1.toString() << endl;
        cout << car2.toString() << endl;
        cout << car4.toString() << endl;
        car3.setManufacturer("Porsche");
        car3.setColor("Black");
        car3.setVin("jbsajbc2211s");
        car3.setManufactureYear(2020);
        car3.setEnginePower(350);
        car3.setModel("Panamera");
        car3.setWeight(2000);
        cout << car3.toString() << endl;
        car3.setPlate("bb222s22"); // throws exception



    }
    catch(invalid_argument& except){
        cerr << "Invalid argument: "<< except.what() << endl;
    }
    catch(...){
        cerr << "Exception detected" << endl;
    }
    return 0;
}
