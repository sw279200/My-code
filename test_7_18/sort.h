#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
void PrintArray(int* a, int n);

void Swap(int* a, int* b);

void InsertSort(int* a, int n);

void ShellSort(int* a, int n);

void BubbleSort(int* a, int n);

void SelectSort(int* a, int n);

void AdjustDown(int* a, int n, int parent);

void HeapSort(int* a, int n);

void QuickSort(int* a, int left, int right);

int GetMidIndex(int* a, int left, int right);


void QuickSortNonR(int* a, int start, int end);

void MergeSortNonR(int* a, int n);

void CountSort(int* a, int n);
