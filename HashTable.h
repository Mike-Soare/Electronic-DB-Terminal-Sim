/***********************************************************************
 *  Title: HashTable.h                                                 *
 *  Author: Mike B. Soare                                              *
 *  Date: 10/30/2020                                                   *
 *  Purpose: Initializes hash table | Contains multiple functions to   *
 *                                    traverse and manipulate contents *
 ***********************************************************************/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <iomanip>
#include "HashEntry.h"
using namespace std;

template<typename Obj>
class HashTable
{
    private:
        int tableSize;
        HashEntry<Obj> **array; //Pointer to array of pointers

    public:
       /************************************************************************
		*  Function Name: HashTable() [Constructor] 						   *
		*  Parameters: None													   *
		*  Returns: None													   *
		*  Purpose: DMA of hash table | Initializes hash table buckets to NULL *
		************************************************************************/
        HashTable(int);

       /************************************************************************
		*  Function Name: ~HashTable() [Destructor]     		        	   *
		*  Parameters: None     											   *
		*  Returns: None													   *
		*  Purpose: Deallocates DMA of hash table | Deletes bucket contents    *
		************************************************************************/
        ~HashTable();

       /************************************************************************
		*  Function Name: getValue()							        	   *
		*  Parameters: int key   											   *
		*  Returns: Bucket contents | NULL          						   *
		*  Purpose: Filters through hash table locating key | returns key's    *
        *                                                     content          *
		************************************************************************/
        Obj getValue(int);

       /************************************************************************
		*  Function Name: putValue()        								   *
		*  Parameters: int key | Obj value      							   *
		*  Returns: None													   *
		*  Purpose: Filters through hash table locating appropriate bucket to  *
        *           store values into                                          *
		************************************************************************/
        void putValue(int, Obj);

       /************************************************************************
		*  Function Name: removeValue()							        	   *
		*  Parameters: int key   											   *
		*  Returns: None													   *
		*  Purpose: Filters through hash table locating key | deletes key      *
		************************************************************************/
        void removeValue(int);
        
       /************************************************************************
		*  Function Name: printHashTable()   				    			   *
		*  Parameters: None													   *
		*  Returns: None													   *
		*  Purpose: Prints hash table into readable format for user            *
		************************************************************************/
        void printHashTable();
};

template<typename Obj>
HashTable<Obj>::HashTable(int size)
{
    tableSize = size; 

    array = new HashEntry<Obj>*[tableSize]; //DMA of buckets with size received

    for(int x = 0; x < size; x++) //For loop initializing buckets to NULL
    {
        array[x] = NULL;
    }
}

template<typename Obj>
HashTable<Obj>::~HashTable()
{
    for(int x = 0; x < tableSize; x++) //For loop deallocating DMA of hash table buckets
    {
        if(array[x] != NULL) //If bucket contains items
        {
            HashEntry<Obj> *previousEntry = NULL;
            HashEntry<Obj> *entry = array[x];

            while(entry != NULL) //Traverses bucket nodes
            {
                previousEntry = entry;
                entry = entry->getNext();
                delete previousEntry;
            }
        }
    }

    delete [] array; //Deallocates hash table array
}

template<typename Obj>
Obj HashTable<Obj>::getValue(int key)
{
    int index = key % tableSize; //Calculates bucket index

    if(array[index] == NULL) //If bucket contains nothing return NULL
    {
        return NULL;
    }
    else
    {
        HashEntry<Obj> *entry = array[index];

        while(entry != NULL && entry->getKey() != key) //Traverses hash table bucket nodes until it reaches NULL value
        {
            entry = entry->getNext();
        }
        if(entry == NULL) //If current index of bucket has no content
        {
            return NULL;
        }
        else //Else returns contents
        {
            return entry->getValue();
        }
    }
}

template<typename Obj>
void HashTable<Obj>::putValue(int key, Obj value)
{
    int index = key % tableSize; //Calculates bucket index

    if(array[index] == NULL) //If bucket index is NULL | Create new bucket with new content
    {
        array[index] = new HashEntry<Obj>(key, value);
    }
    else //If bucket index contains content
    {
        HashEntry<Obj> *entry = array[index];

        while(entry->getNext() != NULL) //Taverse hash table index bucket until NULL is reached
        {
            entry = entry->getNext();
        }
        if(entry->getKey() == key) //If bucket index node contains similar key | Overwrite content
        {
            entry->setValue(value);
        }
        else //Else create new node in bucket index with new content
        {
            entry->setNext(new HashEntry<Obj>(key, value));
        }
    }
}

template<typename Obj>
void HashTable<Obj>::removeValue(int key)
{
    int index = key % tableSize; //Calculates bucket index
    HashEntry<Obj> *entry = array[index];
    HashEntry<Obj> *previousEntry = NULL;

    if(array[index] != NULL) //If current hash table bucket contains content
    {
        while(entry->getNext() != NULL && entry->getKey() != key) //Traverse hash table bucket nodes
        {
            previousEntry = entry;
            entry = entry->getNext();
        }
        if(key == entry->getKey()) //If key matches node
        {
            if(previousEntry == NULL)
            {
                HashEntry<Obj> *nextEntry = entry->getNext();
                delete entry;
                array[index] = nextEntry;
            }
            else
            {
                HashEntry<Obj> *next = entry->getNext();
                delete entry;
                previousEntry->setNext(next);
            }

            cout << "--------------------------------------------" << endl << "The item has been removed." << endl;
        }
    }
    else //Else display no item located
    {
        cout << "--------------------------------------------" << endl << "There is no item with that ID." << endl;
    }
}

template<typename Obj>
void HashTable<Obj>::printHashTable()
{
    cout <<"############################################";

    for(int x = 0; x < tableSize; x++) //For loop interating through buckets and node displaying content
    {
        cout << endl << "Bucket " << x << ": ";

        if(array[x] != NULL)
        {
            HashEntry<Obj> *entry = array[x];

            while(entry->getNext() != NULL) //Traverse through bucket nodes until NULL is reached
            {
                cout << "---->" << *(entry->getValue()) << setw(8);
                entry = entry->getNext();
            }
            cout << "---->" << *(entry->getValue()) << endl;
        }
        else
        {
            cout << "NULL" << endl;
        }
    }

    cout << "############################################" << endl;
}

#endif