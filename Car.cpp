#include"Car.h"
#include<sstream>
#include<exception>
#include<stdexcept>

unsigned int MyCar::Car::ID = 0;
const std::string MyCar::CarCheck::possibleColors[] = {

        "Red",
        "Blue",
        "Green",
        "Yellow",
        "Black",
        "White",
        "Grey"

};


// Checkers

bool MyCar::CarCheck::checkColor(const std::string& color){

    for(int i = 0; i < COLOR_AMOUNT; ++i){
        if(color == possibleColors[i]){
            return true;
        }
    }
    return false;

}

bool MyCar::CarCheck::checkPlate(const std::string& plate){

    for(int i = 0; i < (int) plate.length(); ++i){
        if(i < LETTER_AMOUNT){
            if(!isupper(plate[i])){
                return false;
            }
        }
        else{
            if(!isdigit(plate[i])){
                return false;
            }
        }
        if(i > PLATE_LENGTH){
            return false;
        }
    }
    return true;
}

bool MyCar::CarCheck::checkEnginePower(const unsigned int& enginePower){

    if(enginePower <= MAX_ENGINE_POWER){
        return true;
    }
    else{
        return false;
    }

}

bool MyCar::CarCheck::checkWeight(const unsigned int& weight){

    if(weight <= MAX_WEIGHT){
        return true;
    }
    else{
        return false;
    }
}

bool MyCar::CarCheck::checkManufactureYear(const unsigned int& manufactureYear){

    if(manufactureYear >= FIRST_CAR_DATE && manufactureYear <= CURRENT_YEAR){
        return true;
    }
    else{
        return false;
    }
}



MyCar::Car::Car(const std::string& manufacturer, const std::string& model, const unsigned int& manufactureYear, const std::string& color,
                const std::string& plate, const std::string& vin, const unsigned int& enginePower, const unsigned int& weight)
{

    setColor(color);
    setVin(vin);
    setPlate(plate);
    setEnginePower(enginePower);
    setWeight(weight);
    setManufacturer(manufacturer);
    setModel(model);
    setManufactureYear(manufactureYear);
    ++ID;
    objectID = ID;
}

MyCar::Car::~Car(){
    // empty
}


std::string MyCar::Car::toString(){

    std::stringstream ss;
    ss << "ID: "<< objectID << " " << manufacturer << " " << model << " " << manufactureYear << " " << color << " " << plate << " "
     << vin << " " << enginePower << " KW "<< weight << " KG";
    return ss.str();
}

// Getters

std::string MyCar::Car::getColor(){
    return color;
}

std::string MyCar::Car::getVin(){
    return vin;
}

std::string MyCar::Car::getPlate(){
    return plate;
}

unsigned int MyCar::Car::getEnginePower(){
    return enginePower;
}

std::string MyCar::Car::getModel(){
    return model;
}

unsigned int MyCar::Car::getWeight(){
    return weight;
}

std::string MyCar::Car::getManufacturer(){
    return manufacturer;
}

unsigned int MyCar::Car::getManufactureYear(){
    return manufactureYear;
}

unsigned int MyCar::Car::getID(){
    return objectID;
}

// Setters

void MyCar::Car::setColor(const std::string& color){
    if(check.checkColor(color)){
        this->color = color;
    }
    else{
        throw std::invalid_argument("Not available color");
    }
}

void MyCar::Car::setVin(const std::string& vin){
    this->vin = vin;
}

void MyCar::Car::setPlate(const std::string& plate){
    if(check.checkPlate(plate)){
        this->plate = plate;
    }
    else{
        throw std::invalid_argument("Not a valid plate (plate has to have only 3 capital letters followed by 3 numbers)");
    }
}

void MyCar::Car::setEnginePower(const unsigned int& enginePower){
    if(check.checkEnginePower(enginePower)){
        this->enginePower = enginePower;
    }
    else{
        throw std::invalid_argument("Engine power out of range");
    }

}
void MyCar::Car::setWeight(const unsigned int& weight){
    if(check.checkWeight(weight)){
        this->weight = weight;
    }
    else{
        throw std::invalid_argument("Weight out of range");
    }

}

void MyCar::Car::setManufacturer(const std::string& manufacturer){
    this->manufacturer = manufacturer;
}

void MyCar::Car::setModel(const std::string& model){
    this->model = model;
}

void MyCar::Car::setManufactureYear(const unsigned int& manufactureYear){
    if(check.checkManufactureYear(manufactureYear)){
        this->manufactureYear = manufactureYear;
    }
    else{
        throw std::invalid_argument("Manufacture year out of range");
    }
}
