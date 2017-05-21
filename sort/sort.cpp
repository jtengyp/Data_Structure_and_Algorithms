#include<limits.h>
#include"sort.h"

void exchange(int A[], int i, int j){
  int temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

/**********************************
 * Time complexity -------- O(n^2)
 * Space complexity ------- O(1)
 * Stable
**********************************/
void bubbleSort(int A[], int n){
  for(int i = 0; i < n-1; i++){
    for(int j = 0; j < n-1-i; j++){
      if(A[j] > A[j+1])
        exchange(A, j, j+1);
    }
  }
}

/**********************************
 * Time complexity -------- O(n^2)
 * Space complexity ------- O(1)
 * Unstable
**********************************/
void selectSort(int A[], int n){
  int i,j,min;
  for(i = 0; i < n-1; i++){
	min = i;
    for(j = i+1; j < n; j++){
	  if(A[j] < A[min]) min = j;
	}
	if(min != i) exchange(A,min,i);
  }
}

/**********************************
 * Time complexity -------- O(n^2)
 * Space complexity ------- O(1)
 * Stable
**********************************/
void insertSort(int A[], int n){
  int get,i,j;
  for(i = 1; i < n; i++){
    get = A[i];
	j = i - 1;
	while(j >= 0 && A[j] > get){
	  A[j+1] = A[j];
	  j--;
	}
	A[j+1] = get;
  }
}

/**********************************
 * Time complexity -------- O(n^2)
 * Space complexity ------- O(1)
 * Stable
**********************************/
void binaryInsertSort(int A[], int n){
  int i,j,get,left,right,middle;
  for(i = 1; i < n; i++){
    get = A[i];
	left = 0;
	right = i - 1;
	while(left <= right){
	  middle = left + (right-left)/2;
	  if(A[middle] > get) right = middle - 1;
	  else left = middle + 1;
	}
	for(j = i-1; j >= left; j--){
	  A[j+1] = A[j];
	}
	A[left] = get;
  }
}

/**********************************
 * Time complexity -------- O(nlogn) ~ O(n^2)
 * Space complexity ------- O(1)
 * Unstable
**********************************/
void shellSort(int A[], int n){
  int i, j, get, h = 0;
  while(h <= n/3) h = 3*h + 1;
  while(h >= 1){
    for(i = h; i < n; i++){
	  get = A[i];
	  j = i - h;
	  while(j >= 0 && A[j] > get){
	    A[j+h] = A[j];
		j -= h;
	  }
	  A[j+h] = get;
	}
	h = (h-1) / 3;
  }
}

/**********************************
 * Time complexity -------- O(nlogn)
 * Space complexity ------- O(logn ~ n)
 * Unstable
**********************************/
void quickSort(int A[], int left, int right){
  int pivot_idx;
  if(left < right){
    pivot_idx = partition(A, left, right);
	quickSort(A, left, pivot_idx-1);
    quickSort(A, pivot_idx+1, right);
  }
}

int partition(int A[], int left, int right){
  int pivot = A[right];
  int tail = left - 1;
  for(int i = left; i < right; i++){
    if(A[i] <= pivot){
	  tail++;
	  exchange(A, tail, i);
	}
  }
  exchange(A, tail+1, right);
  return tail+1;
}

/**********************************
 * Time complexity -------- O(nlogn)
 * Space complexity ------- O(n)
 * Stable
**********************************/
void mergeSort(int A[], int left, int right){
  int middle = left + (right-left) / 2;
  if(left < right){
    mergeSort(A, left, middle);
	mergeSort(A, middle+1, right);
	merge(A, left, middle, right);
  }
}

void merge(int A[], int left, int middle, int right){
  int L[10];
  int R[10];
  int n1 = middle - left + 1;
  int n2 = right - middle;
  int i, j, k;
  for(i = 0; i < n1; i++) L[i] = A[left + i];
  for(j = 0; j < n2; j++) R[j] = A[middle + 1 + j];
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  i = 0;
  j = 0;
  for(k = left; k <= right; k++){
    if(L[i] <= R[j]){
	  A[k] = L[i];
	  i++;
	}
	else{
	  A[k] = R[j];
	  j++;
	}
  }
}

/**********************************
 * Time complexity -------- O(nlogn)
 * Space complexity ------- O(1)
 * Unstable
**********************************/
int heapSize;
void heapSort(int A[], int n){
  buildMaxHeap(A, n);
  for(int i = n - 1; i >= 1; i--){
    exchange(A, 0, i);
	heapSize--;
	heapify(A, 0);
  }
}

void buildMaxHeap(int A[], int n){
  heapSize = n;
  for(int i = heapSize / 2 - 1; i >= 0; i--)
    heapify(A, i);
}

void heapify(int A[], int i){
  int leftChild = 2 * i + 1;
  int rightChild = 2 * i + 2;
  int largest;
  if(leftChild < heapSize && A[leftChild] > A[i])
	largest = leftChild;
  else
	largest = i;
  if(rightChild < heapSize && A[rightChild] > A[largest])
	largest = rightChild;
  if(largest != i){
    exchange(A, i, largest);
	heapify(A, largest);
  }
}
