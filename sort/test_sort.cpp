#include<iostream>
#include"sort.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

void print(int A[], int n){
  for(int i = 0; i < n; i++)
	  cout<<A[i]<<' ';
  cout<<endl;
}

int main(){
  int A[] = {8,5,2,6,9,3,1,4,0,7};
  int n = sizeof(A) / sizeof(int);
  int whichSort = 1;
  bool isPrint = true;
  while(whichSort!=0){
    cout<<"Please select the sort algorithm:\n  1 = bubbleSort \n  2 = selectSort \n  3 = insertSort \n  4 = binaryInsertSort \n  5 = shellSort \n  6 = quickSort \n  7 = mergeSort \n  8 = heapSort \n  0 = quit \n";
    cin>>whichSort;
    switch(whichSort){
	  case 0: {
		isPrint = false;
		break; }
      case 1: {
  	    bubbleSort(A,n);
  	    cout<<"The bubbleSort result:"<<endl;
  	    break; }
  	  case 2: {
  	    selectSort(A,n);
  	    cout<<"The selectSort result:"<<endl;
  	    break; }
  	  case 3: {
  	    insertSort(A,n);
  	    cout<<"The insertSort result:"<<endl;
  	    break; }
  	  case 4: {
  	    binaryInsertSort(A,n);
  	    cout<<"The binaryInsertSort result:"<<endl;
  	    break; }
      case 5: {
  	    shellSort(A,n);
  	    cout<<"The shellSort result:"<<endl;
  	    break; }
	  case 6: {
		quickSort(A,0,n-1);
		cout<<"The quickSort result:"<<endl;
		break; }
	  case 7: {
		mergeSort(A,0,n-1);
		cout<<"The mergeSort result:"<<endl;
		break; }
	  case 8: {
		heapSort(A, n);
		cout<<"The heapSort result:"<<endl;
		break; }
  	  default: {
  	    isPrint = false;
  	    cout<<"Wrong number. Please input again:"<<endl;		 
  	  } 
    }
    if(isPrint) print(A,n);
    isPrint = true;
  }
  return 0;
}
