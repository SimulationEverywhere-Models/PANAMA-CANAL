/*******************************************************************
*
*  DESCRIPTION: Atomic Model Queue
*
*  AUTHOR: Rami Madhoun
*
*  EMAIL: mailto://rtmadhou@connect.carleton.ca
*
*  DATE: 13/10/2004
*
*******************************************************************/

#ifndef _QUEUE_H
#define _QUEUE_H


#include "atomic.h"     // class Atomic


class Queue : public Atomic
{
public:
	Queue( const string & name = "Queue" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:

	typedef list<int> itemList;
	itemList	shipList;
	
	const Port & In;
	const Port & controlIn;
	Port & Out;
	Time preparationTime ;   // Time needed by the ship to move from one lock to another
	
};	// class Queue

// ** inline ** // 
inline
string Queue::className() const
{
	return "Queue" ;
}

#endif   // _Queue_H
