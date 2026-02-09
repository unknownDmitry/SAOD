#include "pch.h"
#include "../Task4/sort.h"

// ==================== Тесты bubbleSort ====================

TEST(BubbleSortTest, SortsUnsortedArray) {
	int arr[] = { 5, 2, 8, 1, 9 };
	int expected[] = { 1, 2, 5, 8, 9 };
	bubbleSort(arr, 5);
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(BubbleSortTest, SortsAlreadySortedArray) {
	int arr[] = { 1, 2, 3, 4, 5 };
	int expected[] = { 1, 2, 3, 4, 5 };
	bubbleSort(arr, 5);
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(BubbleSortTest, SortsReverseSortedArray) {
	int arr[] = { 5, 4, 3, 2, 1 };
	int expected[] = { 1, 2, 3, 4, 5 };
	bubbleSort(arr, 5);
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(BubbleSortTest, SortsSingleElement) {
	int arr[] = { 42 };
	bubbleSort(arr, 1);
	EXPECT_EQ(arr[0], 42);
}

TEST(BubbleSortTest, SortsArrayWithDuplicates) {
	int arr[] = { 3, 1, 3, 2, 1 };
	int expected[] = { 1, 1, 2, 3, 3 };
	bubbleSort(arr, 5);
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

// ==================== Тесты merge ====================

TEST(MergeTest, MergesTwoSortedArrays) {
	int arr1[] = { 1, 3, 5 };
	int arr2[] = { 2, 4, 6 };
	int result[6];
	int expected[] = { 1, 2, 3, 4, 5, 6 };
	merge(arr1, 3, arr2, 3, result);
	for (int i = 0; i < 6; i++) {
		EXPECT_EQ(result[i], expected[i]);
	}
}

TEST(MergeTest, MergesArraysOfDifferentSizes) {
	int arr1[] = { 1, 5 };
	int arr2[] = { 2, 3, 4, 6 };
	int result[6];
	int expected[] = { 1, 2, 3, 4, 5, 6 };
	merge(arr1, 2, arr2, 4, result);
	for (int i = 0; i < 6; i++) {
		EXPECT_EQ(result[i], expected[i]);
	}
}

TEST(MergeTest, MergesWithEmptyFirstArray) {
	int arr1[] = { 0, }; 
	int arr2[] = {  3 };
	int result[3];
	merge(arr1, 0, arr2, 3, result);
	for (int i = 0; i < 3; i++) {
		EXPECT_EQ(result[i], arr2[i]);
	}
}

TEST(MergeTest, MergesWithEmptySecondArray) {
	int arr1[] = { 1, 2, 3 };
	int arr2[] = { 0 };
	int result[3];
	merge(arr1, 3, arr2, 0, result);
	for (int i = 0; i < 3; i++) {
		EXPECT_EQ(result[i], arr1[i]);
	}
}

// ==================== Тесты mergeSort ====================

TEST(MergeSortTest, SortsUnsortedArray) {
	int arr[] = { 5, 2, 8, 1, 9, 3 };
	int expected[] = { 1, 2, 3, 5, 8, 9 };
	mergeSort(arr, 6);
	for (int i = 0; i < 6; i++) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(MergeSortTest, SortsAlreadySortedArray) {
	int arr[] = { 1, 2, 3, 4, 5 };
	int expected[] = { 1, 2, 3, 4, 5 };
	mergeSort(arr, 5);
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(MergeSortTest, SortsReverseSortedArray) {
	int arr[] = { 5, 4, 3, 2, 1 };
	int expected[] = { 1, 2, 3, 4, 5 };
	mergeSort(arr, 5);
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(MergeSortTest, SortsSingleElement) {
	int arr[] = { 42 };
	mergeSort(arr, 1);
	EXPECT_EQ(arr[0], 42);
}

TEST(MergeSortTest, SortsArrayWithDuplicates) {
	int arr[] = { 3, 1, 3, 2, 1 };
	int expected[] = { 1, 1, 2, 3, 3 };
	mergeSort(arr, 5);
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

// ==================== Тесты quickSort ====================

TEST(QuickSortTest, SortsUnsortedArray) {
	int arr[] = { 5, 2, 8, 1, 9, 3 };
	int expected[] = { 1, 2, 3, 5, 8, 9 };
	quickSort(arr, 0, 5);
	for (int i = 0; i < 6; i++) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(QuickSortTest, SortsAlreadySortedArray) {
	int arr[] = { 1, 2, 3, 4, 5 };
	int expected[] = { 1, 2, 3, 4, 5 };
	quickSort(arr, 0, 4);
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(QuickSortTest, SortsReverseSortedArray) {
	int arr[] = { 5, 4, 3, 2, 1 };
	int expected[] = { 1, 2, 3, 4, 5 };
	quickSort(arr, 0, 4);
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(QuickSortTest, SortsSingleElement) {
	int arr[] = { 42 };
	quickSort(arr, 0, 0);
	EXPECT_EQ(arr[0], 42);
}

TEST(QuickSortTest, SortsArrayWithDuplicates) {
	int arr[] = { 3, 1, 3, 2, 1 };
	int expected[] = { 1, 1, 2, 3, 3 };
	quickSort(arr, 0, 4);
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

//Отсортированный массив, но порядок нарушают первые два элемента.
// Последние два порядок нарушают

// ==================== Тесты shellSort ====================

TEST(ShellSortTest, SortsUnsortedArray) {
	int arr[] = { 5, 2, 8, 1, 9, 3 };
	int expected[] = { 1, 2, 3, 5, 8, 9 };
	shellSort(arr, 6);
	for (int i = 0; i < 6; i++) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(ShellSortTest, SortsAlreadySortedArray) {
	int arr[] = { 1, 2, 3, 4, 5 };
	int expected[] = { 1, 2, 3, 4, 5 };
	shellSort(arr, 5);
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(ShellSortTest, SortsReverseSortedArray) {
	int arr[] = { 5, 4, 3, 2, 1 };
	int expected[] = { 1, 2, 3, 4, 5 };
	shellSort(arr, 5);
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}

TEST(ShellSortTest, SortsSingleElement) {
	int arr[] = { 42 };
	shellSort(arr, 1);
	EXPECT_EQ(arr[0], 42);
}

TEST(ShellSortTest, SortsArrayWithDuplicates) {
	int arr[] = { 3, 1, 3, 2, 1 };
	int expected[] = { 1, 1, 2, 3, 3 };
	shellSort(arr, 5);
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(arr[i], expected[i]);
	}
}
