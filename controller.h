/*******************************************************************
*
*  DESCRIPTION: Atomic Model Canal Control Unit
*
*  AUTHOR: Rami Madhoun
*
*  EMAIL: mailto://rtmadhou@connect.carleton.ca
*
*  DATE: 13/10/2004
*
*******************************************************************/

#ifndef _CONTROLLER_H
#define _CONTROLLER_H


#include "atomic.h"     // class Atomic

class Controller : public Atomic
{
public:
	Controller( const string & name = "Controller" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:

	const Port &controlIn;
	const Port &controlLocks;
	const Port &controlQueue;
	Time processingTime;
	
};	// class Controller

// ** inline ** // 
inline
string Controller::className() const
{
	return "Controller" ;
}

#endif   // _CONTROLLER_H
