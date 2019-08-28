/*
 * QuickSort.h
 *
 *  Created on: Jul 22, 2019
 *      Author: alex
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include "InsertionSort.h"
#include "ArrayOperations.h"

const static int THRESHOLD = 9;

template <typename E>
int partition(E array[], int lowerBound, int upperBound, E& pivot) {
	do {
		while (array[++lowerBound] < pivot);
		while (lowerBound < upperBound && pivot < array[--upperBound]);
		swap(array, lowerBound, upperBound);
	} while (lowerBound < upperBound);
	return lowerBound;
}

template <typename E>
int findPivot(E array[], int lowerBound, int upperBound) {
	return (upperBound + lowerBound)/2;
}

// Choose median value of front, middle, end to be pivot
template <typename E>
int findPivot2(E array[], int lowerBound, int upperBound) {
	int mid = (lowerBound + upperBound)/2;
	E lowVal = array[lowerBound];
	E midVal = array[mid];
	E highVal = array[upperBound];
	if (lowVal > midVal) {
		if (midVal > highVal) {
			return mid;
		} else if (lowVal > highVal) {
			return upperBound;
		} else {
			return lowerBound;
		}
	} else {
		if (lowVal > highVal) {
			return lowerBound;
		} else if (midVal > highVal) {
			return upperBound;
		} else {
			return mid;
		}
	}
}

template <typename E>
void QuickSort(E array[], int lowerBound, int upperBound) {
	if (upperBound <= lowerBound) return;

	// Find pivot
	int pivotIndex = findPivot<E>(array, lowerBound, upperBound);
	// Move pivot to end to calculate partitioning of array
	swap(array, pivotIndex, upperBound);

	// Partition array
	int rightStart = partition<E>(array, lowerBound - 1, upperBound, array[upperBound]);
	// Replace pivot at correct location
	swap(array, rightStart, upperBound);
	// Sort subarrays, excluding pivot location
	QuickSort<E>(array, lowerBound, rightStart - 1);
	QuickSort<E>(array, rightStart + 1, upperBound);
}

template <typename E>
void QuickSort2(E array[], int lowerBound, int upperBound) {
	if (upperBound <= lowerBound) return;

	// Find pivot
	int pivotIndex = findPivot2<E>(array, lowerBound, upperBound);
	// Move pivot to end to calculate partitioning of array
	swap(array, pivotIndex, upperBound);

	// Partition array
	int rightStart = partition<E>(array, lowerBound - 1, upperBound, array[upperBound]);
	// Replace pivot at correct location
	swap(array, rightStart, upperBound);
	// Sort subarrays, excluding pivot location
	QuickSort2<E>(array, lowerBound, rightStart - 1);
	QuickSort2<E>(array, rightStart + 1, upperBound);
}

template <typename E>
void QuickSort3(E array[], int lowerBound, int upperBound) {
	if (upperBound - lowerBound + 1 <= THRESHOLD) {
		InsertionSort<E>(&array[lowerBound], upperBound - lowerBound + 1);
		return;
	}

	// Find pivot
	int pivotIndex = findPivot2<E>(array, lowerBound, upperBound);
	// Move pivot to end to calculate partitioning of array
	swap(array, pivotIndex, upperBound);

	// Partition array
	int rightStart = partition<E>(array, lowerBound - 1, upperBound, array[upperBound]);
	// Replace pivot at correct location
	swap(array, rightStart, upperBound);
	// Sort subarrays, excluding pivot location
	QuickSort3<E>(array, lowerBound, rightStart - 1);
	QuickSort3<E>(array, rightStart + 1, upperBound);
}

template <typename E>
void QuickSort4Help(E array[], int lowerBound, int upperBound) {
	if (upperBound - lowerBound + 1 <= THRESHOLD) {
		return;
	}

	// Find pivot
	int pivotIndex = findPivot2<E>(array, lowerBound, upperBound);
	// Move pivot to end to calculate partitioning of array
	swap(array, pivotIndex, upperBound);

	// Partition array
	int rightStart = partition<E>(array, lowerBound - 1, upperBound, array[upperBound]);
	// Replace pivot at correct location
	swap(array, rightStart, upperBound);
	// Sort subarrays, excluding pivot location
	QuickSort4Help<E>(array, lowerBound, rightStart - 1);
	QuickSort4Help<E>(array, rightStart + 1, upperBound);
}

template <typename E>
void QuickSort4(E array[], int lowerBound, int upperBound) {
	QuickSort4Help(array, lowerBound, upperBound);
	InsertionSort(array, upperBound - lowerBound + 1);
}

#endif /* QUICKSORT_H_ */
