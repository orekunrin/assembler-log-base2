// COMP375HW2-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program calculates the log base 2 of a number by shifting its bits to the right
// Written by John Orekunrin

#include <iostream>
using namespace std;

int main(int argn, char* argv[])
{
	int number, log;
	cout << "Enter a number >";
	cin >> number;
	_asm {
		// Calculate the log2 of number and store the result in log
		mov eax, number
		mov ebx, 0	// ebx will equal log
		wloop:	cmp eax, 1
				je	done
				shr eax, 1
				inc ebx
				jmp wloop
				done : mov log, ebx
	}
	cout << "The logarithm is " << log << endl;
	return 0;
}