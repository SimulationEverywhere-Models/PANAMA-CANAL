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

/** include files **/
#include "gate.h"      // class Subnet
#include "message.h"    // class ExternalMessage, InternalMessage
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator
#include <stdlib.h>
 
/** public functions **/

/*******************************************************************
* Function Name: Gate
* Description: 
********************************************************************/
Gate::Gate( const string & name )
: Atomic( name )
, In( addInputPort( "In" ) )
, controlIn( addInputPort( "controlIn" ) )
, Out( addOutputPort( "Out" ) )
, controlOut( addOutputPort( "controlOut" ) )
, transitionTime(1,0,0,0)
, wFlowTime(0,10,0,0)
{
	
	string time( MainSimulator::Instance().getParameter( description(), "transition_time" ) ) ;

	if( time != "" )
	transitionTime = time ;
	
	string time2 ( MainSimulator::Instance().getParameter( description(), "w_flow_time" ) ) ;

	if( time2 != "" )
	wFlowTime = time2 ;
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/

Model & Gate::initFunction()
{
	shipID = 0;
	phase = CLOSED;
	this->passivate();
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model & Gate::externalFunction( const ExternalMessage & msg )
{

	if (msg.port() == controlIn && msg.value() == 1 && phase == CLOSED) 
	{
	holdIn(active,wFlowTime);
	}	    
	
	if (msg.port() == In && msg.value() != 0 &&  phase==OPEN  && shipID == 0 )
	{
		shipID = msg.value();
		holdIn(active,transitionTime);

	}
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model & Gate::internalFunction( const InternalMessage & msg )
{
	
	if (phase == CLOSED && shipID == 0 )
	{	
		phase = OPEN;
		holdIn(active,Time::Inf);
	}
	
	else if (phase == OPEN && shipID != 0 )
	{	
		phase = CLOSED;		
		shipID = 0;
		this->passivate();
	}
	
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model & Gate::outputFunction( const InternalMessage & msg )
{		
	if (phase == OPEN && shipID != 0 )
	{
		sendOutput(msg.time(), Out,shipID);
		sendOutput(msg.time(), controlOut, 1);
	}                                            
	return *this ;
}

