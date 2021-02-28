#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include<string>
#include<sstream>
#include<exception>
#include<stdexcept>

#define DEFAULT_COLOR "Undefined"
#define DEFAULT_VIN "Undefined"
#define DEFAULT_MANUFACTURER "Undefined"
#define DEFAULT_MODEL "Undefined"
#define DEFAULT_PLATE "Undefined"
#define DEFAULT_POWER 0
#define DEFAULT_WEIGHT 0
#define DEFAULT_MANUFACTURE_YEAR 0

#define MAX_ENGINE_POWER 5000
#define MAX_WEIGHT 100000
#define FIRST_CAR_DATE 1886
#define CURRENT_YEAR 2021

#define LETTER_AMOUNT 3
#define NUMBER_LENGTH 5

#define COLOR_AMOUNT 7

namespace MyCar{

    class Car{

        private:

            std::string manufacturer;
            std::string model;
            unsigned int manufactureYear;
            std::string color;
            std::string plate;
            std::string vin;
            unsigned int enginePower;
            unsigned int weight;

            unsigned int objectID;

            unsigned static int ID;

            const std::string possibleColors[COLOR_AMOUNT] = {
                "Red",
                "Blue",
                "Green",
                "Yellow",
                "Black",
                "White",
                "Grey"
            };

        public:
            Car();
            Car(const std::string manufacturer, const std::string model, const unsigned int manufactureYear, const std::string color,
                const std::string plate, const std::string vin, const unsigned int enginePower, const unsigned int weight);
            ~Car();

            // Getters
            std::string getColor();
            std::string getVin();
            std::string getPlate();
            unsigned int getEnginePower();
            unsigned int getWeight();
            std::string getManufacturer();
            std::string getModel();
            unsigned int getManufactureYear();

            // Setters
            void setColor(const std::string color);
            void setVin(const std::string vin);
            void setPlate(const std::string plate);
            void setEnginePower(const unsigned int enginePower);
            void setWeight(const unsigned int weight);
            void setManufacturer(const std::string manufacturer);
            void setModel(const std::string model);
            void setManufactureYear(const unsigned int manufactureYear);


            std::string toString();

        private:

            // Checkers
            bool checkColor(const std::string color);
            bool checkPlate(const std::string plate);
            bool checkEnginePower(const unsigned int enginePower);
            bool checkWeight(const unsigned int weight);
            bool checkManufactureYear(const unsigned int manufactureYear);

    };

}
#endif // CAR_H_INCLUDED
