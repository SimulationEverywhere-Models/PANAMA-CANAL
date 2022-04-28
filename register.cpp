/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Rujun Hu
*
*  STUDENT#: 258902
*
*  EMAIL: rujun_hu@yahoo.ca
*
*  DATE: 16/10/2001
*
*******************************************************************/

#include "modeladm.h" 
#include "mainsimu.h"
#include "queue.h"        // class Qeueu
#include "controller.h"   // class Controller
#include "gate.h"         // class Gate
#include "lock.h"        // class Lock

void MainSimulator::registerNewAtomics()
{
 	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Queue>(), "Queue" ) ;   
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Controller>(), "Controller" ) ;   
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Gate>(), "Gate" ) ;   
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Lock>(), "Lock" ) ;   
}