/*
 * QuickSortComp.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: alex
 */

#include "QuickSort.h"
#include <ctime>
#include <random>
#include <iostream>
using std::cout;

int main() {
	const int SIZE = 10;

	clock_t start;

	std::random_device rd;
	std::mt19937 eng(rd());

	std::uniform_int_distribution<> posDistr(0,SIZE);

	int array[SIZE]; int array1[SIZE]; int array2[SIZE]; int array3[SIZE]; int array4[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		array[i] = posDistr(eng);
		array1[i] = array[i];
		array2[i] = array[i];
		array3[i] = array[i];
		array4[i] = array[i];
	}

	start = clock();
	QuickSort<int>(array1, 0, SIZE-1);
	double orig_sort_time = (clock() - start)/ (double) CLOCKS_PER_SEC;

	start = clock();
	QuickSort2<int>(array2, 0, SIZE-1);
	double new_sort_time = (clock() - start)/ (double) CLOCKS_PER_SEC;

	start = clock();
	QuickSort3<int>(array3, 0, SIZE-1);
	double new_sort_time3 = (clock() - start)/ (double) CLOCKS_PER_SEC;

	start = clock();
	QuickSort4<int>(array4, 0, SIZE-1);
	double new_sort_time4 = (clock() - start)/ (double) CLOCKS_PER_SEC;

	for (int i = 1; i < SIZE; ++i) {
		if (array1[i] < array1[i-1]) {
			cout << "Array1 was sorted incorrectly.\n";
		}
		if (array2[i] < array2[i-1]) {
			cout << "Array2 was sorted incorrectly.\n";
		}
		if (array3[i] < array3[i-1]) {
			cout << "Array3 was sorted incorrectly.\n";
		}
		if (array4[i] < array4[i-1]) {
			cout << "Array4 was sorted incorrectly.\n";
		}
	}

	cout << "Original method took " << orig_sort_time << " s.\n";
	cout << "Method that compares three pivots took " << new_sort_time << " s.\n";
	cout << "Method that compares three pivots and uses insertion sort for small arrays took " << new_sort_time3 << " s.\n";
	cout << "Method that compares three pivots and uses insertion sort on mostly-sorted array took " << new_sort_time4 << " s.\n";
}
