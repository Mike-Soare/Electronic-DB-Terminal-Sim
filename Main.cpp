/***********************************************************************
 *  Title: Main.cpp                                                    *
 *  Author: Mike B. Soare                                              *
 *  Date: 10/30/2020                                                   *
 *  Purpose: Electronic database system simulator using hash tables.   *
 *           Simulates a search and enter system for electronics.      *
 ***********************************************************************/
#include "Electronics.h"
#include "HashTable.h"
#include "HashEntry.h"

void enterFromFile(HashTable<Electronics*> *);
void enterManually(HashTable<Electronics*> *);
void searchElectronic(HashTable<Electronics*> *);
void deleteElectronic(HashTable<Electronics*> *);

int main()
{
    int userChoice;
    HashTable<Electronics*> *table = new HashTable<Electronics*>(10); //DMA of hash table

    cout << "########################################################################################" << endl << setw(69) << "WELCOME TO THE ELECTRONICS MANAGEMENT SYSTEM" << endl << "########################################################################################" << endl;

    do
    {
        cout << "--------------------------------------------" << endl << setw(30) << "Management Menu" << endl << "--------------------------------------------" << endl;
        cout << "\t1. Add Electronics From a File" << endl << "\t2. Add an Electronic Manually" << endl << "\t3. Search for an Electronic" << endl << "\t4. Delete an Electronic" << endl << "\t5. Print Hash Table" << endl << "\t6. Exit Program" << endl << "Enter your choice: ";
        cin >> userChoice;

        while(userChoice > 6 || userChoice < 1) //Validate user input
        {
            cout << "--------------------------------------------" << endl << "Invalid Choice!" << endl << "Enter your choice: ";
            cin >> userChoice;
        }

        switch(userChoice)
        {
            case 1:
                enterFromFile(table);
                break;
            
            case 2:
                enterManually(table);
                break;
            
            case 3:
                searchElectronic(table);
                break;
            
            case 4:
                deleteElectronic(table);
                break;
            
            case 5:
                table->printHashTable();
                break;
        }

    }while(userChoice != 6);
    
    cout << "--------------------------------------------" << endl << setw(25) << "Goodbye." << endl << "--------------------------------------------";

    delete table; //Deallocates DMA of hash table

    return 0;
}

/************************************************************************
 *  Function Name: enterFromFile()                                      *
 *  Parameters: HashTable pointer                                       *
 *  Returns: none                                                       *
 *  Purpose: Extracts data from file | Inputs data into hash table      *
 ************************************************************************/
void enterFromFile(HashTable<Electronics*> *table) 
{
    int productCount = 0, productID;
    string temp, name, description, date;
    double cost;
    Electronics *Electronic;
    ifstream inFile;

    inFile.open("dataFile.txt"); //Opens file

    if(inFile.is_open())
    {
        inFile >> productID;

        while(!inFile.eof()) //Extracts data until end of file is reached
        {
            inFile.ignore();
            
            getline(inFile, temp);
            name = temp;

            getline(inFile, temp);
            description = temp;

            inFile >> cost;
            inFile.ignore();

            getline(inFile, temp);
            date = temp;

            Electronic = new Electronics(productID, name, description, cost, date); //Creates new object

            table->putValue(productID, Electronic); //Puts new object into hash table

            cout << "--------------------------------------------" << endl;
            cout << "Product Name: " << Electronic->getName() << endl << "Unique ID: " << Electronic->getIDNum() << endl;
            inFile >> productID;

            productCount++;
        }

        cout << "--------------------------------------------" << endl << productCount << " Electronic products have been added from" << endl << "dataFile.txt" << endl;
    }
    else
    {
        cout << "Error Opening File!" << endl;
    }

    inFile.close(); //Closes file
}

/************************************************************************
 *  Function Name: enterManually()                                      *
 *  Parameters: HashTable pointer                                       *
 *  Returns: none                                                       *
 *  Purpose: Prompts user to enter a product manually                   *
 ************************************************************************/
void enterManually(HashTable<Electronics*> *table)
{
    int key;
    string name, description;
    double cost;
    string date;
    Electronics *product;

    cout << "--------------------------------------------" << endl;
    cout << "Unique ID: ";
    cin >> key;

    while(!cin) //Validate user input to be integer
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "--------------------------------------------" << endl << "Non-Integer Input!" << endl << "Please enter an integer: ";
        cin >> key;
    }

    cin.ignore();

    cout << "--------------------------------------------" << endl;
    cout << "Product Name: ";
    getline(cin, name);

    cout << "--------------------------------------------" << endl;
    cout << "Product Description: ";
    getline(cin, description);

    cout << "--------------------------------------------" << endl;
    cout << "Product Cost: $";
    cin >> cost;

    cin.ignore();

    cout << "--------------------------------------------" << endl;
    cout << "Product Manufacture Date: ";
    getline(cin, date);

    product = new Electronics(key, name, description, cost, date); //Creates new object

    table->putValue(key, product); //Puts new object into hash table
}

/************************************************************************
 *  Function Name: searchElectronic()                                   *
 *  Parameters: HashTable pointer                                       *
 *  Returns: none                                                       *
 *  Purpose: Prompts user to search a product | Displays product        *
 *                                              information             *
 ************************************************************************/
void searchElectronic(HashTable<Electronics*> *table)
{
    int productID;
    Electronics *product;

    cout << "--------------------------------------------" << endl << "Enter the Unique ID for the Electronic you" << endl << "are searching for: ";
    cin >> productID;
    cout << "--------------------------------------------" << endl;

    product = table->getValue(productID);

    if(product != NULL)
    {
        product->printElectronic(); //Displays data to user
    }
    else
    {
        cout << "There\'s not an Electronic with the Product ID \'" << productID << "\'." << endl;
    }
}

/************************************************************************
 *  Function Name: deleteElectronic()                                   *
 *  Parameters: HashTable pointer                                       *
 *  Returns: none                                                       *
 *  Purpose: Prompts user to delete a product                           *
 ************************************************************************/
void deleteElectronic(HashTable<Electronics*> *table)
{
    int productID;

    cout << "--------------------------------------------" << endl << "These are the current Electronics in storage:" << endl << "--------------------------------------------" << endl;

    table->printHashTable();

    cout << "--------------------------------------------" << endl << "Enter the Unique Product ID of the Electronic" << endl << "you would like to remove: ";
    cin >> productID;

    table->removeValue(productID); //Removes object from hash table
}