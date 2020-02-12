#include "PCalc_SP.h"

#include <iostream>///
#include <bits/stdc++.h>///

//source:https://www.geeksforgeeks.org/c-program-for-sieve-of-eratosthenes/

PCalc_SP::PCalc_SP(unsigned int arraySize):PCalc(arraySize){}
PCalc_SP::~PCalc_SP() {}

void PCalc_SP::markNonPrimes()
{
	unsigned int n = this->array_size();
	//performs Sieve of Eratosthenes algorithm and marks all non primes false
	for (unsigned int p = 2; p * p <= n; p++)
	{
		if (this->at(p) == true)
		{ 
			for (int i = p * p; i <= n; i += p)
			{
				this->at(i) = false;
			}
		}
	}


	//for (int p = 2; p <= n; p++) {
	//	if (prime[p])
	//		std::cout << p << " ";
	//}
}


