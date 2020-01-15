//
//  prime.cpp
//  Project 5
//  Created by Gavin Renken on 10/28/19.
//  Copyright © 2019 Gavin Renken. All rights reserved.
//

#include <iostream>

int main() {

	//  Creating values for lower and upper (the bounds of numbers to factorize) and asking the user for the range 
	long long int lower;	// using long long to insure it can store values up to 10 billion 
	long long int upper;
	std::cout << "Enter a range of numbers to factorize. Enter lower bound and upper bound separated by a space: ";
	std::cin >> lower >> upper;
	for (long long int i = lower; i <= upper; i++) {		// iterates through the range of numbers 
		std::cout << i << ": ";
		long long int current = i;							// variable to keep track of current location in range				
		long long int divisor = 2;
		const long long int original = current;				// created to later distinguish between the last number in a factorization and prime numbers (see line 37)

		while (divisor <= i / 2) {
			if (current % divisor == 0) {                   // when divides evenly... 
				current = current / divisor;
				if (current != 1) {
					std::cout << divisor << " x ";          // prints out factor and x for multiplication symbol 
				}
				else if (current == 1) {                    // ensures program does not print out an x after the last number in the factorization 
					std::cout << divisor;
				}
			}
			else if (current % divisor != 0) {              // when does not divide evenly, increment the divisor to check the next number (odd this time) 
				divisor += 1;
			}
		}
		if (divisor > current / 2 && current == original) { // checks to see if a number is prime and is not just the last divisor in a factorization 
			std::cout << "prime!";
		}
		std::cout << '\n';
	}
	return 0;
}
