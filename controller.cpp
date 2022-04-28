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

/** include files **/
#include "controller.h"      // class Controller
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )


/** public functions **/

/*******************************************************************
* Function Name: Controller
* Description: 
********************************************************************/
Controller::Controller( const string & name )
: Atomic( name )
, controlIn( addInputPort( "controlIn" ) )
, controlLocks( addOutputPort( "controlLocks" ) )
, controlQueue( addOutputPort("controlQueue"))
, processingTime( 0, 5, 0, 0 )


{	
	string time( MainSimulator::Instance().getParameter( description(), "processing_time" ) ) ;

	if( time != "" )
		processingTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description: Initialize the model
********************************************************************/
Model & Controller::initFunction()
{
		
	holdIn(active, processingTime);     // triggers the output and internal transition functions
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model & Controller::externalFunction( const ExternalMessage & msg )
{
	if (msg.port() == controlIn && msg.value() == 1 &&  this->state() == passive )
	{
		holdIn(active,processingTime);
	}
	
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model & Controller::internalFunction( const InternalMessage & )
{	
	if ( this->state() == active) 
	{
		this->passivate();
	}

	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model & Controller::outputFunction( const InternalMessage &msg )
{	
	if (this->state() == active)
	{
		sendOutput(msg.time(), controlLocks, 1);
		sendOutput(msg.time(), controlQueue, 1);
	}
	 
	return *this ;
}
