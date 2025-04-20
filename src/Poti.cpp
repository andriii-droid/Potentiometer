//Datei: Poti.cpp
//Implementationsdatei für die Klasse Poti
//Autor: Andri Andermatt, 28.03.2025
#include <Arduino.h>
#include <Poti.h>

Poti::Poti( int initPotPin, int initRange, bool initConstrain, int initPotiMinValue, int initPotiMaxValue)
    :potPin {initPotPin}, 
    range{initRange}, 
    constrain{initConstrain},
    PotiMinValue{initPotiMinValue}, 
    PotiMaxValue{initPotiMaxValue}
{
}

void Poti::updatePotiValue()
{
    int valueTemp = map(analogRead(potPin), PotiMinValue, PotiMaxValue, 0, range);
    if (constrain)
    {
        potiValue = constrain(valueTemp, 0, range);
    } else
    {
        potiValue = valueTemp;
    }
}

bool Poti::potiOverValue(int value, int precision) const
{
    bool flag = false;
    if ((value > precision) && (value < (range - precision)))
    {
        if (potiValue >= value)
        {
            flag = true;
        } else if (potiValue <= (value - precision))
        {
            flag = false;
        }
    } else
    {
        flag = false;
    }

    return flag;
}

bool Poti::potiUnderValue(int value, int precision) const
{
    bool flag = false;
    if ((value > precision) && (value < (range - precision)))
    {
        if (potiValue <= value)
        {
            flag = true;
        } else if (potiValue >= (value + precision))
        {
            flag = false;
        }
    } else
    {
        flag = false;
    }

    return flag; 
}
