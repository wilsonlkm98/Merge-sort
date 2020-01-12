#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;

void merge(int *a, int size, int s,int e){
    
	//Midpoint of the array.
	int mid = (s + e)/2;
    
    int i = s;       // Initial point.
    int j = mid+1;   // Point after midpoint.
    int k = s;       
    
	//Set the temp object size.
    int temp[size];
    
    while((i <= mid) && (j <= e)){
		if(a[i] < a[j]){  			
            temp[k++] = a[i++];
        }
        else{						
            temp[k++] = a[j++];
        }
    }
    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j<=e){
        temp[k++]  = a[j++];
    }
    
    //Copy all element from temp(sorted) to original arrays.
    for(int i=s;i<=e;i++){
        a[i] = temp[i];
    } 
}

void mergeSort(int array[], int size, int s, int e){
	//Base case - if array has 1 or 0 elements
	if(s >= e){
		//Do nothing.
		//No need to sort.
		return;
	}
	
	//Divide.
	//Find the midpoint of the array.
	int mid = (s + e)/2;
	
	//Recursively the arrays.
	mergeSort(array, size, s, mid);
	mergeSort(array, size, mid + 1, e);
	
	//Merge the two parts.
	merge(array, size, s, e);
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
	mergeSort(array, size, 0, size-1);
	//printArray(array, size);
	auto end = chrono::system_clock::now();
	chrono::duration<double> duration = end - start;
	cout << "Duration: " << duration.count() << "s\n";
	
	return 0;
}



