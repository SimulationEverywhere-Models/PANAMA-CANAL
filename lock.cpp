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

/** include files **/
#include "lock.h"      // class Lock
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )


/** public functions **/

/*******************************************************************
* Function Name: Lock
********************************************************************/
Lock::Lock (const string &name )
: Atomic( name )
, controlIn( addInputPort( "controlIn" ) )
, In( addInputPort( "In" ) )
, Out( addOutputPort( "Out" ) )
, controlOut( addOutputPort( "controlOut" ) )
, transitionTime( 1, 0, 0, 0 )
, wFlowTime(0, 10, 0, 0)
, shipID(0)
{	
	string time( MainSimulator::Instance().getParameter( description(), "transition_time" ) ) ;

	if( time != "" )
		transitionTime = time ;
	
	string time2( MainSimulator::Instance().getParameter( description(), "w_flow_time" ) ) ;

	if( time2 != "" )
		wFlowTime = time2 ;	
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model & Lock::initFunction()
{
	phase = CLOSED_HIGH;
	this->passivate();
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model & Lock::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == controlIn  && msg.value() == 1 && phase == CLOSED_HIGH && shipID ==0)
	{	
		holdIn(active, wFlowTime);
	}
	if( msg.port() == In  && msg.value() != 0 && phase == CLOSED_LOW && shipID ==0 )
	{	
		shipID = msg.value();
		phase = OPEN_LOW;
		holdIn(active,transitionTime);
	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model & Lock::internalFunction( const InternalMessage & )
{	
	
	if (phase == CLOSED_HIGH && shipID ==0) 
	{
		phase = CLOSED_LOW;
		holdIn(active,Time::Inf);	
	}
	else if (phase == OPEN_LOW && shipID != 0 )
	{
		phase = CLOSED_LOW;
		holdIn(active,wFlowTime);	
	}
	else if (phase == CLOSED_LOW && shipID !=0)
	{
			shipID =0;
			phase = CLOSED_HIGH;
			holdIn(active,Time::Inf);
	}
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &Lock::outputFunction( const InternalMessage &msg )
{
	if (phase == OPEN_LOW && shipID !=0)
		sendOutput(msg.time(), controlOut, 1);
					
	if (phase == CLOSED_LOW && shipID != 0 ) 
		sendOutput(msg.time(), Out, shipID);

	return *this ;
}
