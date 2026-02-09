#include "pch.h"
#include "../Task1/Task1.h"

// Тесты для is_sorted 
TEST(IsSorted, Ascending) {
	int arr[] = { 1, 2, 3, 4, 5 };
	EXPECT_TRUE(is_sorted(arr, 5));
}

TEST(IsSorted, Descending) {
	int arr[] = { 5, 4, 3, 2, 1 };
	EXPECT_FALSE(is_sorted(arr, 5));
}

TEST(IsSorted, Unsorted) {
	int arr[] = { 1, 3, 2, 5, 4 };
	EXPECT_FALSE(is_sorted(arr, 5));
}

TEST(IsSorted, SingleElement) {
	int arr[] = { 42 };
	EXPECT_TRUE(is_sorted(arr, 1));
}

TEST(IsSorted, Empty) {
	int arr[] = { 0 };
	EXPECT_TRUE(is_sorted(arr, 0));
}

// Тесты для seek_run (линейный поиск)
TEST(SeekRun, Found) {
	int arr[] = { 1, 3, 5, 7, 9 };
	EXPECT_EQ(seek_run(arr, 5, 5), 2);
}

TEST(SeekRun, NotFound) {
	int arr[] = { 1, 3, 5, 7, 9 };
	EXPECT_EQ(seek_run(arr, 5, 4), -1);
}

TEST(SeekRun, FirstElement) {
	int arr[] = { 1, 3, 5, 7, 9 };
	EXPECT_EQ(seek_run(arr, 5, 1), 0);
}

TEST(SeekRun, LastElement) {
	int arr[] = { 1, 3, 5, 7, 9 };
	EXPECT_EQ(seek_run(arr, 5, 9), 4);
}

// Тесты для binary_seek (бинарный поиск)
TEST(BinarySeek, Found) {
	int arr[] = { 1, 3, 5, 7, 9 };
	EXPECT_EQ(binary_seek(arr, 5, 5), 2);
}

TEST(BinarySeek, NotFound) {
	int arr[] = { 1, 3, 5, 7, 9 };
	EXPECT_EQ(binary_seek(arr, 5, 4), -1);
}

TEST(BinarySeek, FirstElement) {
	int arr[] = { 1, 3, 5, 7, 9 };
	EXPECT_EQ(binary_seek(arr, 5, 1), 0);
}

TEST(BinarySeek, LastElement) {
	int arr[] = { 1, 3, 5, 7, 9 };
	EXPECT_EQ(binary_seek(arr, 5, 9), 4);
}

TEST(BinarySeek, SingleElement) {
	int arr[] = { 5 };
	EXPECT_EQ(binary_seek(arr, 1, 5), 0);
}

// Тесты для interpol_seek (интерполяционный поиск)
TEST(InterpolSeek, Found) {
	int arr[] = { 1, 3, 5, 7, 9 };
	EXPECT_EQ(interpol_seek(arr, 5, 5), 2);
}

TEST(InterpolSeek, NotFound) {
	int arr[] = { 1, 3, 5, 7, 9 };
	EXPECT_EQ(interpol_seek(arr, 5, 4), -1);
}

TEST(InterpolSeek, FirstElement) {
	int arr[] = { 1, 3, 5, 7, 9 };
	EXPECT_EQ(interpol_seek(arr, 5, 1), 0);
}

TEST(InterpolSeek, LastElement) {
	int arr[] = { 1, 3, 5, 7, 9 };
	EXPECT_EQ(interpol_seek(arr, 5, 9), 4);
}

TEST(InterpolSeek, SingleElement) {
	int arr[] = { 5 };
	EXPECT_EQ(interpol_seek(arr, 1, 5), 0);
}
