#include"Car.h"

unsigned int MyCar::Car::ID = 0;

MyCar::Car::Car(){

    this->color = DEFAULT_COLOR;
    this->vin = DEFAULT_VIN;
    this->plate = DEFAULT_PLATE;
    this->enginePower = DEFAULT_POWER;
    this->model = DEFAULT_MODEL;
    this->weight = DEFAULT_WEIGHT;
    this->manufacturer = DEFAULT_MANUFACTURER;
    this->manufactureYear = DEFAULT_MANUFACTURE_YEAR;
    ++ID;
    objectID = ID;
}

MyCar::Car::Car(const std::string manufacturer, const std::string model, const unsigned int manufactureYear, const std::string color,
                const std::string plate, const std::string vin, const unsigned int enginePower, const unsigned int weight)
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

// Setters

void MyCar::Car::setColor(const std::string color){
    if(checkColor(color)){
        this->color = color;
    }
    else{
        throw std::invalid_argument("Not available color");
    }
}

void MyCar::Car::setVin(const std::string vin){
    this->vin = vin;
}

void MyCar::Car::setPlate(const std::string plate){
    if(checkPlate(plate)){
        this->plate = plate;
    }
    else{
        throw std::invalid_argument("Not available plate");
    }
}

void MyCar::Car::setEnginePower(const unsigned int enginePower){
    if(checkEnginePower(enginePower)){
        this->enginePower = enginePower;
    }
    else{
        throw std::invalid_argument("Engine power out of range");
    }

}
void MyCar::Car::setWeight(const unsigned int weight){
    if(checkWeight(weight)){
        this->weight = weight;
    }
    else{
        throw std::invalid_argument("Weight out of range");
    }

}

void MyCar::Car::setManufacturer(const std::string manufacturer){
    this->manufacturer = manufacturer;
}

void MyCar::Car::setModel(const std::string model){
    this->model = model;
}

void MyCar::Car::setManufactureYear(const unsigned int manufactureYear){
    if(checkManufactureYear(manufactureYear)){
        this->manufactureYear = manufactureYear;
    }
    else{
        throw std::invalid_argument("Manufacture year out of range");
    }
}

// Checkers

bool MyCar::Car::checkColor(const std::string color){
    for(int i = 0; i < COLOR_AMOUNT; ++i){
        if(color == possibleColors[i]){
            return true;
        }
    }
    return false;

}

bool MyCar::Car::checkPlate(const std::string plate){
    for(int i = 0; i < plate.length(); ++i){
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
        if(i > NUMBER_LENGTH){
            return false;
        }
    }
    return true;
}

bool MyCar::Car::checkEnginePower(const unsigned int enginePower){
    if(enginePower <= MAX_ENGINE_POWER){
        return true;
    }
    else{
        return false;
    }

}

bool MyCar::Car::checkWeight(const unsigned int weight){
    if(weight <= MAX_WEIGHT){
        return true;
    }
    else{
        return false;
    }
}

bool MyCar::Car::checkManufactureYear(const unsigned int manufactureYear){
    if(manufactureYear >= FIRST_CAR_DATE && manufactureYear <= CURRENT_YEAR){
        return true;
    }
    else{
        return false;
    }
}
