#include <iostream>
#include <stdlib.h>
using namespace std;

void Snapshot(int * A, int r) {
	cout<<"Sorted array :";
	for (int i = 0; i < r; i++)
		cout << A[i] << " ";
}

void exchange(int *A, int S, int E) {
	int temp = A[S];
	A[S] = A[E];
	A[E] = temp;
}
int Partition(int *A, int p, int r) {
	for (int j = p; j < r; j++) {
		if (A[j] <= A[r]) {
			p++;
			exchange(A, p - 1, j);
		}
	}exchange(A, p, r); 
	return p;
}
int RandomizedPartition(int *A, int p, int r) {
	int i = rand() % (r-p+1)+p;
	exchange(A, i, r);
	return Partition(A, p, r);
}
void QuickSort(int *A, int p, int r) {
	if (p < r) {
		int q = RandomizedPartition(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q + 1, r);
	}
}

int main(int argc, char **argv) {
	int arraySize;
cout<<"\nEnter the size of array : ";
	cin >> arraySize;
	int* Sequence = new int[arraySize];
cout<<"\n\n\tElements in array ";
	for (int i = 0; i < arraySize; i++)
	{
	cout<<"\nElement no "<<i+1<<" : ";
		cin >> Sequence[i];
}
	QuickSort(Sequence, 0, arraySize - 1);
	Snapshot(Sequence, arraySize); // for printing

	delete[] Sequence;
}
