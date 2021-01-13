/***********************************************************************
 *  Title: Electronics.h                                               *
 *  Author: Mike B. Soare                                              *
 *  Date: 10/30/2020                                                   *
 *  Purpose: Header file containing Electronics class                  *
 ***********************************************************************/
#ifndef ELECTRONICS_H
#define ELECTRONICS_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
using namespace std;

class Electronics
{
    private:
        int idNum;
        string name, description;
        double cost;
        string manufactureDate;

    public:
        Electronics();

       /************************************************************************
		*  Function Name: Electronics() [Constructor]                   	   *
		*  Parameters: int id | string name | string description | double cost *
        *              | string manufactureDate                   			   *
		*  Returns: None													   *
		*  Purpose: Initializes variables                                      *
		************************************************************************/
        Electronics(int, string, string, double, string);

        ~Electronics();

       /************************************************************************
		*  Function Name: printElectronic() 								   *
		*  Parameters: None													   *
		*  Returns: None													   *
		*  Purpose: Displays product information in readable format 		   *
		************************************************************************/
        void printElectronic();

        /*
            Accessor Functions [Getter]
        */
        int getIDNum() const;
        string getName() const;
        string getDescription() const;
        double getCost() const;
        string getManufactureDate() const;

        /*
            Mutator Functions [Setter]
        */
        void setIDNum(int);
        void setName(string);
        void setDescription(string);
        void setCost(double);
        void setManufactureDate(string);

        friend ostream &operator<<(ostream & outstream, Electronics elect)
        {
            outstream << "ID: " << elect.getIDNum() << ", " << "PRODUCT NAME: " << elect.getName(); //Displays information in certain format

            return outstream;
        };
};

#endif