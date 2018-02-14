 //File: CSC641_SpeedMark_HW1.cpp
 //Author: Richard Chhay
 //Institution: San Francisco State University
 //Date: February 13, 2018
 //Course: CSC 641 COMPUTER PERFORMANCE EVALUATION
 //Summary: This program seeks to provide an assessment of a computer's processing speed by using floating point and integer operations.
	//		When the program is ran it will perform two tests, matrix inversions and bubble sort. The program will record and calculate 
	//		the average speed that it takes for the tasks to be completed. 
//Sources: 
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

void BubbleSort(int c[], int na)
{
	int i, done = 0; // Sort termination flag
	while ((!done) && (na > 1))
	{
		done = 1;
		for (i = 0; i < na - 1; i++)
			if (c[i] > c[i + 1])
			{
				swap(c[i], c[i + 1]); done = 0;
			}
		na--;
	}
}

int testBS(int a[], int na) // Test of correct sorting
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
	int a[100000];

	START = sec(); // start timer for matrix inversion
	while (sec() < START + 3) { MINX(); NFLOAT++; }
	VFLOAT = 60 * NFLOAT / (sec() - START); // (number of ops * 60) / (final time - start time)
	printf("Elapsed Time for Matrix Inversion: %f", (sec() - START));

	// Bubble Sort
	// Initializing array to be sorted
	cout << "\nBegin Bubble Sort";
	int c[100000], na, i, delta = 5000;
	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);

	// Populating array with data
	for (na = delta; na <= 10 * delta; na += (delta / 2))
	{
		MakeRandArray(c, na);
	}

	START = sec();	// start timer for bubble sort
	while (sec() < START + 3) { BubbleSort(c, na); NINT++; }
	if (testBS(a, na)) {
		cout << "\nNumber of Operations = " << setw(6) << na
			<< " Time Elaspsed Bubble Sort =" << setprecision(2) << setw(6) << sec() - START
			<< " sec |";
	}else{
		cout << "Bubble Sort Error!";
	}
	VINT = 60 * NINT / (sec() - START); // (number of ops * 60) / (final time - start time)

	//Calculating Average Speed
	AverageSpeed = 2 * VFLOAT*VINT / (VFLOAT + VINT);
	VFLOAT = 1.0;

	printf("VFLOAT: %f\nVINT: %f\nAverageSpeed: %f\n", VFLOAT, VINT, AverageSpeed);

	for (;;) {}

	return 0;
}

