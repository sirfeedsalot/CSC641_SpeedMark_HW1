 //File: CSC641_SpeedMark_HW1.cpp
 //Author: Richard Chhay
 //Institution: San Francisco State University
 //Date: February 13, 2018
 //Course: CSC 641 COMPUTER PERFORMANCE EVALUATION
 //Summary: This program seeks to provide an assessment of a computer's processing speed by using floating point and integer operations.
	//		When the program is ran it will perform two tests, matrix inversions and bubble sort. The program will record and calculate 
	//		the average speed that it takes for the tasks to be completed. 

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

void MINX() {}


// Time functions
double sec()
{
	return double(clock()) / double(CLOCKS_PER_SEC);
}
double millisec()
{
	return clock()*1000. / CLOCKS_PER_SEC;
}

// Bubble Sort Assessment
void MakeRandArray(int a[], int n) // Populate the array
{
	int i;
	for (i = 0; i<n; i++) a[i] = rand();
}

void swap(int& a, int& b)
{
	int temp = a; a = b; b = temp;
}

void BubbleSort(int a[], int na)
{
	int i, done = 0; // Sort termination flag
	while ((!done) && (na > 1))
	{
		done = 1;
		for (i = 0; i < na - 1; i++)
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]); done = 0;
			}
		na--;
	}
}

int test(int a[], int na) // Test of correct sorting
{
	;
	for (int i = 0; i < na - 1; i++) if (a[i]>a[i + 1]) return 0;
	return 1;
}

int main()
{
	int NINT = 0, NFLOAT = 0;
	double START, VINT, VFLOAT, AverageSpeed;
	
	// Matrix Inversion
	START = sec();
	while (sec() < START + 3) { MINX(); NFLOAT++; }
	VFLOAT = 60 * NFLOAT / (sec() - START);

	// Bubble Sort
	START = sec();

	int a[100000], na, i, delta = 5000;
	double t1, t2;
	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);

	for (na = delta; na <= 10 * delta; na += (delta / 2))
	{
		MakeRandArray(a, na);
	}
	cout << "\n\n";


	while (sec() < START + 10) { BubbleSort(a, na); NINT++; cout << "bubble sort\n"; }
	VINT = 60 * NINT / (sec() - START);

	AverageSpeed = 2 * VFLOAT*VINT / (VFLOAT + VINT);

	// Finish Program
	VFLOAT = 1.0; AverageSpeed = 1.0;
	printf("VFLOAT: %f\n VINT: %f\n AverageSpeed: %f\n", VFLOAT, VINT, AverageSpeed);

	for (;;) {}

	return 0;
}

