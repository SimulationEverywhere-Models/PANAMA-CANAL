[top]
components : controller@Controller
components : queue@Queue
components : Gatun_Locks

out	: Out
in	: In

Link : In In@queue
Link : Out@Gatun_Locks Out
Link : Out@queue In@Gatun_Locks
Link : controlQueue@controller controlIn@queue
Link : controlLocks@controller controlIn@Gatun_Locks
Link : controlOut@Gatun_Locks controlIn@controller


[controller]
processing_time : 00:05:00:000

[queue]
preparation_time : 00:30:00:000

[Gatun_Locks]
components : gate@Gate
components : lock3@lock
components : lock2@Lock
components : lock1@Lock

out : Out
out	: controlOut
in	: In
in	: controlIn

Link : In In@lock1
Link : controlIn controlIn@lock1
Link : Out@gate Out
Link : controlOut@gate controlOut 
Link : Out@lock1 In@lock2
Link : controlOut@lock1 controlIn@lock2
Link : Out@lock2 In@lock3
Link : controlOut@lock2 controlIn@lock3
Link : Out@lock3 In@gate
Link : controlOut@lock3 controlIn@gate

[gate]
transition_time : 01:00:00:00
w_flow_time	:	00:10:00:00

[lock3]
transition_time : 01:00:00:00
w_flow_time	:	00:10:00:00

[lock2]
transition_time : 01:00:00:00
w_flow_time	:	00:10:00:00

[lock1]
transition_time : 01:00:00:00
w_flow_time	:	00:10:00:00