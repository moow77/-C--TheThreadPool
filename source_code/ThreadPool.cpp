#include <queue>
#include <iostream>  // for cout
#include <stdlib.h>  // for exit
#include <pthread.h>

#include "ThreadPool.h"
#include "Task.h"

using namespace std;

void* thread(void*);

Runnable *ptr_task;
queue<Runnable*> q_task;

// the mutex and condition for q_task
pthread_mutex_t mutex;
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;

ThreadPool::ThreadPool() {
	max_num = 1;
	current_num = 0;
}

ThreadPool::ThreadPool(int input) {
	max_num = 1;
	current_num = 0;
	if (input > 0)
		max_num = input;
}

void ThreadPool::AddTask(Runnable* task) {
	pthread_mutex_lock(&mutex);
	q_task.push(task);
	pthread_mutex_unlock(&mutex);
	
	if (current_num < max_num) {
		++current_num;
		cout << "[ThreadPool] Creating new thread. Total thread number now is "
				<< current_num << '\n';
		execute();
	} else {
		cout << "[ThreadPool] Try to signal the sleeping thread." << '\n';
		pthread_cond_signal(&condition_var);
	}
}

void ThreadPool::execute() {
	pthread_t thread_id;
	int result = pthread_create(&thread_id, NULL, &thread, (void*)current_num);

	if (result != 0) {
		cout << "Error: CrateTimer() failed\n" << '\n';
		exit(EXIT_FAILURE);
	}
}

void* thread(void* input) {
	while (true) {
		if (!q_task.empty()) {
			ptr_task = q_task.front();
			pthread_mutex_lock(&mutex);
			q_task.pop();
			pthread_mutex_unlock(&mutex);	
			ptr_task->run();
		} else {
			// waiting for the signal
			pthread_mutex_lock(&count_mutex);
			pthread_cond_wait(&condition_var, &count_mutex);
			pthread_mutex_unlock(&count_mutex);
		}
	}
	cout << "[ThreadPool] Ending the thread pool." << '\n';
}
