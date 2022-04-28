/*******************************************************************
*
*  DESCRIPTION: Atomic Model Lock
*
*  AUTHOR: Rami Madhoun
*
*  EMAIL: mailto://rtmadhou@sce.carleton.ca
*
*  DATE: 15/10/2004
*
*******************************************************************/

#ifndef _LOCK_H
#define _LOCK_H


#include "atomic.h"     // class Atomic

class Lock : public Atomic
{
public:
	Lock( const string &name = "Lock" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	
	typedef enum phases {CLOSED_HIGH, CLOSED_LOW,OPEN_LOW};
	
	const Port &controlIn;
	const Port &In;
	Port &Out;
	Port &controlOut;	
	
	phases phase;
	Time transitionTime;
	Time wFlowTime;
	int shipID ;

};	// class Lock

// ** inline ** // 
inline
string Lock::className() const
{
	return "Lock" ;
}

#endif   //_LOCK_H
