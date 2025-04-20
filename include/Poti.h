//Datei: Poti.h
//Headerdatei für die Klasse poti
//Autor: Andri Andermatt, 28.03.2025
#include <Arduino.h>

#ifndef POTI_H_
#define POTI_H_
    class Poti
    {
        public:
            explicit Poti(int initPotPin, int initRange, bool initConstrain = true, int initPotiMinValue = 0, int initPotiMaxValue = 8191); //Ctor
            //PotPin: Pin of the Potentiometer
            //Range: Range of the Potentiometervalue
            //PotiMinValue: Value that corresponds to 0 in Output
            //PotiMaxValue: Value that corresponds to range in Output

            void updatePotiValue();
            //Updates Value of potiValue

            int getPotiValue() const {return potiValue;}
            //Gets the Value of the Potentiometer

            bool potiOverValue(int value, int precision = 10) const;
            //True if poti is over Value
            //Value: Must be in range
            //Precision: Steps Poti needs to change to change output back, must be smaller than value

            bool potiUnderValue(int value, int precision = 10) const;
            //True if poti is under Value
            //Value: Must be in range
            //Precision: Steps Poti needs to change to change output back, must be smaller than value

        private:
            int potPin;
            int range;  //Range of Potivalue
            int potiValue = 0; //PotiValue with the new Range
            bool constrain; //If True constrains output to the range, if false overflow may occur
            int PotiMinValue;
            int PotiMaxValue;
    };


#endif //POTI_H_