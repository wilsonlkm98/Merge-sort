#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;

void merge(int A[], int Temp[], int p, int m, int r){
	int i, j;
	for (i = m + 1; i > p; i--)
		Temp[i - 1] = A[i - 1];
		for (j = m; j < r; j++)
			Temp [r + m - j] = A[j + 1];
  
	for (int k = p; k <= r; k++)
		if (Temp[j] < Temp [i])
			A[k] = Temp[j--];
		else
			A[k] = Temp[i++];
}

void mergesort(int A[], int Temp[], int p, int r){
	// Put your code here!
	if (p < r){     
		int m = (r + p) / 2;     
		mergesort(A, Temp, p, m);     
		mergesort(A, Temp, m + 1, r);     
		merge(A, Temp, p, m, r);   
  }
}

void startMergeSort(int A[], int n){
	int* Temp = new int[n];
	mergesort (A, Temp, 0, n-1);
	delete [] Temp;
}

void printArray (int A[], int n){
	for (int i = 0; i < n; ++i)
		cout << A[i] << ' ';
	cout << endl;
}

int main(){
	int size;
	cout << "Enter the array size: ";
	cin >> size;
	
	int array[size];
	
	//Init random number generator.
	srand (time(0));  
	//Assign random number to the array.
	for(int i = 0; i < size; i++)
		array[size] = rand()%RAND_MAX;
	
	//cout << "Before sort : ";
	//printArray(array, size);
	
	auto start = chrono::system_clock::now();
	//cout << "After sorted: ";
	startMergeSort(array,size);
	//printArray(array, size);
	auto end = chrono::system_clock::now();
	chrono::duration<double> duration = end - start;
	cout << "Duration: " << duration.count() << "s\n";
	
	return 0;
}