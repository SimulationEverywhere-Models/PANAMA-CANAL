/*******************************************************************
*
*  DESCRIPTION: Atomic Model Queue
*
*  AUTHOR: Rami Madhoun 
*
*  EMAIL: mailto://rtmadhou@connect.carleton.ca
*
*  DATE: 12/10/2004
*
*******************************************************************/

/** include files **/
#include "queue.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )


/** public functions **/

/*******************************************************************
* Function Name: Queue
* Description: 
********************************************************************/
Queue::Queue( const string & name )
: Atomic( name )
, In( addInputPort( "In" ) )
, controlIn( addInputPort( "controlIn" ) )
, Out( addOutputPort( "Out" ) )
, preparationTime( 0, 30, 0, 0 )


{	
	string time( MainSimulator::Instance().getParameter( description(), "preparation_time" ) ) ;

	if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description: Initialize the model
********************************************************************/
Model & Queue::initFunction()
{

	shipList.erase(shipList.begin(),shipList.end());
	this-> passivate();
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model & Queue::externalFunction( const ExternalMessage & msg )
{
	if (msg.port() == In && msg.value() != 0)
	{
		if (shipList.empty() && this->state() == active)
			holdIn(active, preparationTime);
		
			shipList.push_back(msg.value());	
	}
	
	if (msg.port() == controlIn && msg.value() ==1 && this->state() == passive) 
	{
		if ( shipList.empty() )
			holdIn(active, Time::Inf);
		else
			holdIn(active,preparationTime);
	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model & Queue::internalFunction( const InternalMessage & )
{	
	if ( this->state() == active) 
	{
		shipList.pop_front();
		this->passivate();
	}

	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model & Queue::outputFunction( const InternalMessage &msg )
{	
	if (!shipList.empty())
	{
		sendOutput(msg.time(), Out, shipList.front());
	}
	 
	return *this ;
}
