[top]
components : lock@Lock
out : Out
out : controlOut
in : In
in : controlIn
Link : controlIn controlIn@lock
Link : In In@lock
Link : Out@lock Out
Link : controlOut@lock controlOut

[lock]
transition_time : 01:00:00:00
w_flow_time	: 00:10:00:00