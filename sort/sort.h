#ifndef _Sort_H
#define _Sort_H
void exchange(int A[], int i, int j);
void bubbleSort(int A[], int n);
void selectSort(int A[], int n);
void insertSort(int A[], int n);
void binaryInsertSort(int A[], int n);
void shellSort(int A[], int n);
int  partition(int A[], int left, int right);
void quickSort(int A[], int left, int right);
void merge(int A[], int left, int middle, int right);
void mergeSort(int A[], int left, int right);
void heapSort(int A[], int n);
void buildMaxHeap(int A[], int n);
void heapify(int A[], int i);
#endif

