#ifndef RUNNABLE
#define RUNNABLE
#include "Runnable.h"
#endif

class ThreadPool {
private:
	int max_num, current_num;
	
public:
	ThreadPool();
	ThreadPool(int);
	void AddTask(Runnable*);
	void execute();
};
