#include <iostream>
#include <unistd.h>

#include "Task.h"

using namespace std;

Task::Task(int _task_num) {
	task_num = _task_num;
}

void Task::setThreadNum(int _thread_num) {
	thread_num = _thread_num;
}

void Task::action() {
	cout<<"[Task] task number "<<task_num<<" is executed by thread number "<<thread_num<<'\n';
	sleep(3);
}
