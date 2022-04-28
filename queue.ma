[top]
components : queue@Queue
out : Out
in : In
in : controlIn
Link : In In@queue
Link : controlIn controlIn@queue
Link : Out@queue Out

[queue]
preparation_time : 00:30:00:000