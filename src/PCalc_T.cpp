#include "PCalc_T.h"

#include <iostream>///
#include <bits/stdc++.h>///


PCalc_T::PCalc_T(unsigned int count, unsigned int arraySize) :PCalc(arraySize) {}
PCalc_T :: ~PCalc_T(){}

void PCalc_T::markNonPrimes()
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
}
