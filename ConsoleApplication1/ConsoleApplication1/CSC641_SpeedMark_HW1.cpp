 //File: CSC641_SpeedMark_HW1.cpp
 //Author: Richard Chhay
 //Institution: San Francisco State University
 //Date: February 13, 2018
 //Course: CSC 641 COMPUTER PERFORMANCE EVALUATION
 //Summary: This program seeks to provide an assessment of a computer's processing speed by using floating point and integer operations.
	//		When the program is ran it will perform two tests, matrix inversions and bubble sort. The program will record and calculate 
	//		the average speed that it takes for the tasks to be completed. 
//Sources:
//			Bubble Sort Algorithm
//			Author: Jozo Dujmovic
//			Title: Performance Measurements
//			Retrieved from iLearn
//
//			Integral Algorithm
//			Author: Technology of Computing
//			Web Site Name: HelloACM
//			URL: https://helloacm.com/c-function-to-compute-numerical-integral-using-function-pointers/
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

#ifdef _WIN32
#define WINPAUSE system("pause")
#endif

using namespace std;
const int x = 100, y = 100;
const float PI = 3.1415f;

// ====== Time functions ======
double sec()
{
	return double(clock()) / double(CLOCKS_PER_SEC);
}
double millisec()
{
	return clock()*1000. / CLOCKS_PER_SEC;
}

// ====== Bubble Sort Assessment ======
void MakeArray(int c[]) // Populate the array with decrementing values
{
	int i,j = 0;
	for (i = 100000; i < 100000; i--) {
		j++;
		c[i] = j;
	}
}

void swap(int* a, int* b)
{
	int temp = *a; *a = *b; *b = temp;
}

void BubbleSort(int c[], int n)
{	
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (c[j] > c[j + 1])
				swap(&c[j], &c[j + 1]);
}

//	====== Integral Assessment ======
void integral(float(*f)(float x), float a, float b, int n) {
	float step = (b - a) / n;  // width of each small rectangle
	float area = 0.0f;  // signed area
	for (int i = 0; i < n; i++) {
		area += f(a + (i + 0.5f) * step) * step; // sum up each small rectangle
	}
}

// ====== BEGIN MAIN ======
int main()
{
		int NINT = 0, NFLOAT = 0;
		double START, VINT, VFLOAT, AverageSpeed;

		// ====== Integral ======
		cout << "Begin Integral Assessment";
		START = sec(); // start timer for matrix inversion
		while (sec() < START + 10) { cout.precision(7); integral(cos, 0, PI / 2, 100000); NFLOAT++; }
		VFLOAT = NFLOAT*60 / (sec() - START); // (number of ops * 60) / (final time - start time)
		cout << "\nNumber of Operations: " << NFLOAT << "\nElapsed Time for Integration: " << (sec() - START);

		// ======= Bubble Sort =======
		// Initializing array to be sorted
		int c[10000];
		int n = sizeof(c)/sizeof(c[0]);
		cout.setf(ios::fixed, ios::floatfield);
		cout.setf(ios::showpoint);

		cout << "\n\nBegin Bubble Sort";
		START = sec();	// start timer for bubble sort
		while (sec() < START + 10) { MakeArray(c); BubbleSort(c, n); NINT++; }

		
		VINT = NINT*60 / (sec() - START); // (number of ops * 60) / (final time - start time)
		cout << "\nNumber of Operations = " << setw(6) << NINT <<"\nTime Elaspsed Bubble Sort =" << setprecision(2) << setw(6) << (sec() - START);

		//Calculating Average Speed
		AverageSpeed = (2 * VFLOAT*VINT) / (VFLOAT + VINT);

		cout << "\n\n\n====== FINAL RESULTS ======";
		printf("\nVFLOAT: %f\nVINT: %f\nAverageSpeed: %f\n", VFLOAT, VINT, AverageSpeed);

		char key;
		cout << "Close the window to exit.";
		cin >> key;

		return 0;
}

