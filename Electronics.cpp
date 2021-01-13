/***********************************************************************
 *  Title: Electronics.cpp                                             *
 *  Author: Mike B. Soare                                              *
 *  Date: 10/30/2020                                                   *
 *  Purpose: Implementation of Electronics.h header file               *
 ***********************************************************************/
#include "Electronics.h"

Electronics::Electronics()
{

}

Electronics::Electronics(int id, string n, string desc, double c, string date)
{
    idNum = id;
    name = n;
    description = desc;
    cost = c;
    manufactureDate = date;
}

Electronics::~Electronics()
{

}

void Electronics::printElectronic()
{
    cout << "Product ID: " << getIDNum() << endl << endl;
    cout << "Product Name: " << getName() << endl << endl;
    cout << "Product Description: " << endl << setw(30) << getDescription() << endl << endl;
    cout << "Product Cost: $" << getCost() << endl << endl;
    cout << "Prouct Manufacture Date: " << getManufactureDate() << endl;
}

/*
    Accessor Functions [Getter]
*/
int Electronics::getIDNum() const
{
    return idNum;
}

string Electronics::getName() const
{
    return name;
}

string Electronics::getDescription() const
{
    return description;
}

double Electronics::getCost() const
{
    return cost;
}

string Electronics::getManufactureDate() const
{
    return manufactureDate;
}

/*
    Mutator Functions [Setter]
*/
void Electronics::setIDNum(int id)
{
    idNum = id;
}

void Electronics::setName(string productName)
{
    name = productName;
}

void Electronics::setDescription(string descrip)
{
    description = descrip;
}

void Electronics::setCost(double price)
{
    cost = price;
}

void Electronics::setManufactureDate(string date)
{
    manufactureDate = date;
}