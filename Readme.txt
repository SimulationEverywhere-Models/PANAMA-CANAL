This folder contains the files necessary to execute and test the Panama Canal model.
The model consists of four atomic models and two coupled ones:

* Queue (atomic)
* Lock (atomic)
* Canal Control Unit (atomic)
* Gate (atomic)
* Gatun_Locks (coupled)
* Panama_Canal (coupled)

Here is a brief description of each of the files associated with the model:

- queue.cpp, queue.h     	   -> queue model definition and implementation
- queue.ev                         -> queue events input file
- queue.ma                         -> queue coupled model definition used to test the queue model separately
- queue.bat                        -> queue batch file used to execute the model
- queue.log                        -> queue simulation log file

- controller.cpp, controller.h     -> controller model definition and implementation
- controller.ev                    -> controller events input file
- controller.ma                    -> controller coupled model definition used to test the controller model separately
- controller.bat                   -> controller batch file used to execute the model
- controller.log                   -> controller simulation log file

- lock.cpp, lock.h                 -> lock model definition and implementation
- lock.ev                          -> lock events input file
- lock.ma                          -> lock coupled model definition used to test the lock model separately
- lock.bat                         -> lock batch file used to execute the model
- lock.log                         -> lock simulation log file

- gate.cpp, gate.h                 -> gate model definition and implementation
- gate.ev                          -> gate events input file
- gate.ma                          -> gate coupled model definition used to test the gate model separately
- gate.bat                         -> gate batch file used to execute the model
- gate.log                         -> gate simulation log file

- gatun_locks.ev                   -> gatun_locks events input file
- gatun_locks.ma                   -> gatun_locks coupled model definition used to test the gatun_locks model separately
- gatun_locks.bat                  -> gatun_locks batch file used to execute the model
- gatun_locks.log                  -> gatun_locks simulation log file

- panama_canal.ev                  -> panama_canal events input file
- panama_canal.ma                  -> panama_canal coupled model definition used to test the panama_canal model 
- panama_canal.bat                 -> panama_canal batch file used to execute the model
- panama_canal.log                 -> panama_canal simulation log file


- register.cpp		               -> used to register the atomic models with the CD++ simulator
