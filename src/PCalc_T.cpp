#include "PCalc_T.h"

#include <iostream>///
#include <thread>///

//#include <time.h>
//#include <stdio.h>
#include <chrono>


PCalc_T::PCalc_T(unsigned int arraySize, unsigned int count) :PCalc(arraySize) 
{
	threadSize = count;
}
PCalc_T :: ~PCalc_T(){}

unsigned int n = 0;
//unsigned int t1 = 0;
unsigned int t2 = 0;
//unsigned int p = 2;
//std::thread first(thread1);
//std::thread second(thread2);

//struct timespec;
//struct timespec sleeptime = 1000000;
//timespec sleeptime;
//sleeptime.tv_sec = 0;
//sleeptime.tv_nsec = 100000000;

void PCalc_T::markNonPrimes()
{
	n = this->array_size();
	//t2 = n / 2;
	std::thread threadList[threadSize];
	int threadCheck[threadSize];

	//std::cout << "\nt2: " << t2 << "\n";
	for (unsigned int m = 0; m < threadSize; m++)
	{
		threadCheck[m] = 0;
	}

		//performs Sieve of Eratosthenes algorithm and marks all non primes false
		for (unsigned int p = 2; p * p <= n; p++)
		{
			//std::cout << "getting to thread1 for loop\n";
			if (this->at(p) == true)
			{
				//std::cout << "getting to thread1 for loop\n";
				for (unsigned int q = 0; q < threadSize; q++)
				{
					std::cout << "new thread q: " << threadCheck[q] << "\n";
					//if (p > ) {
					//	for (unsigned int b = 0; b < n; b++) {

					//	}
					//}
					if (threadCheck[q] == 0) {
						//if (threadList[q].joinable()) {
						//	threadList[q].join();
						//}
						//std::thread first([p, this, q, &threadCheck]() {
						std::thread first([&]{
							std::cout << "starting point:" << p << "\n";
							for (int i = p * p; i <= n; i += p)
							{
								std::cout << "i: " << i << "\n";
								this->at(i) = false;
							}
							std::cout << "\nOut of for loop\n";
							threadCheck[q] = 0;//setting to zero to get new job
							});

						//break;
					}
					//std::this_thread::sleep_for(std::chrono::milliseconds(200));
					//nanosleep(&sleeptime, NULL);
				}
			}
		}
		for (unsigned int r = 0; r < threadSize; r++) 
		{
			if (threadList[r].joinable()) 
			{
				threadList[r].join();
			}
		}
}

//void PCalc_T::thread1()
//{ 
//	t2 = n / 2;
//	//performs Sieve of Eratosthenes algorithm and marks all non primes false
//	for (p; p * p <= t2; p++)
//	{
//		if (this->at(p) == true)
//		{
//			for (int i = p * p; i <= n; i += p)
//			{
//				this->at(i) = false;
//			}
//		}
//	}
//}
//
//void PCalc_T::thread2()
//{
//	for (p; p * p <= n; p++)
//	{
//		if (this->at(p) == true)
//		{
//			for (int i = p * p; i <= n; i += p)
//			{
//				this->at(i) = false;
//			}
//		}
//	}
//}