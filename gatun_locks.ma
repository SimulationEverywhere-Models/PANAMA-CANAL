[top]
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