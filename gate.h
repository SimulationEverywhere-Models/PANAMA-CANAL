/*******************************************************************
*
*  DESCRIPTION: Atomic Model Lock Gate
*
*  AUTHOR: Rami Madhoun 
*
*  EMAIL: mailto://rtmadhou@connect.carleton.ca
*
*  DATE: 13/10/2004
*
*******************************************************************/

#ifndef _GATE_H
#define _GATE_H

#include "atomic.h"     // class Atomic


/** forward declarations **/
class Distribution ;

class Gate : public Atomic
{
public:
	Gate ( const string &name = "Gate" );					//Default constructor

	virtual string className() const ;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	typedef enum phases {CLOSED,OPEN};
	
	const Port & In;
	const Port & controlIn;
	Port & Out;
	Port & controlOut;
	
	phases phase;

	Time transitionTime;
	Time wFlowTime ;
	
	int shipID;

	
	Distribution * dist;
	
	Distribution &distribution()
		{return *dist;}

};	// class Gate

// ** inline ** // 
inline
string Gate::className() const
{
	return "Gate" ;
}

#endif   //_GATE_H
