[top]
components : gate@Gate
out : Out
out : controlOut
in : In
in : controlIn
Link : In In@gate
Link : controlIn controlIn@gate
Link : Out@Gate Out
Link : controlOut@Gate controlOut

[gate]
transition_time : 01:00:00:00
w_flow_time	:	00:10:00:00