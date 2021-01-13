/***********************************************************************
 *  Title: HashEntry.h                                                 *
 *  Author: Mike B. Soare                                              *
 *  Date: 10/30/2020                                                   *
 *  Purpose: Header file that works with HashTable.h to implement the  *
 *                  hash table                                         *
 ***********************************************************************/
#ifndef HASHENTRY_H
#define HASHENTRY_H

#include <iostream>
#include <iomanip>
#include "Electronics.h"
using namespace std;

template<typename Obj>
class HashEntry
{
    private:
        int key;
        Obj value; //Template type of Obj
        HashEntry *next;        

    public:
       /************************************************************************
		*  Function Name: HashEntry() [Constructor]							   *
		*  Parameters: int key | Obj value									   *
		*  Returns: None													   *
		*  Purpose: Initializes variables                                      *
		************************************************************************/
        HashEntry(int, Obj);

        ~HashEntry();
    
        /*
            Accessor Functions [Getter]
        */
        int getKey() const;
        
        Obj getValue() const;

        HashEntry *getNext() const
        {
            return next;
        };

        /*
            Mutator Functinos [Setter]
        */
        void setNext(HashEntry *);
        
        void setValue(Obj);
};

template<typename Obj>
HashEntry<Obj>::HashEntry(int k, Obj val)
{
    key = k;
    value = val;
    next = NULL;
}

template<typename Obj>
HashEntry<Obj>::~HashEntry()
{

}

template<typename Obj>
int HashEntry<Obj>::getKey() const
{
    return key;
}

template<typename Obj>
Obj HashEntry<Obj>::getValue() const
{
    return value;
}

template<typename Obj>
void HashEntry<Obj>::setNext(HashEntry *nextChain)
{
    next = nextChain;
}

template<typename Obj>
void HashEntry<Obj>::setValue(Obj val)
{
    value = val;
}

#endif