[top]
components : controller@Controller
out : controlLocks
out : controlQueue
in : controlIn
Link : controlIn controlIn@controller
Link : controlLocks@controller controlLocks
Link : controlQueue@controller controlQueue

[controller]
processing_time : 00:05:00:000