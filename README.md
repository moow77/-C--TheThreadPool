#The Thread Pool in C++
This is the issue for the thread pool in C++.

#Why use it
Thread pool is a good mechanism because it provides programmers with a way to manage multi-thread programming and system performance. When a thread pool is created, programmers can setup the maximum thread number for the thread pool. Therefore, programmers can easily to assign tasks they want into the pool without worrying about the shortage of system resource due to the excess of threads.
However, C++ 98 does not provide any API for this convenient mechanism. It also does not like Java, which has various kinds of thread pool API, such as Thread, Runnable, schedule, scheduleAtFixedRate, scheduleWithFixedDelay, and so on. When I involved in some project in C++, this problem trouble me very often.

#How to use it
Please refer to the example code in the example folder. Once it is executed, the follwoing message will be observable.

[ThreadPool] Creating new thread. Total thread number now is 1

[ThreadPool] Creating new thread. Total thread number now is 2

[ThreadPool] Try to signal the sleeping thread.

[Task] task 2 is running in thread 2

[Task] task 1 is running in thread 1

[Task] task 3 is running in thread 2

#The next step
I am planning to add a new feature to control the minimum amount of thread in the pool. When there is no more tasks need to be executed, the thread pool will terminate redundant threads and wait for new tasks with minimum thread number.
