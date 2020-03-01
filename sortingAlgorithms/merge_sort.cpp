#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
void merge(int [], int, int, int);
void  merge_sort(int input[], int left, int right){
	if( left >= right)
		return ;
	else{
		int pivot = (int)(left+right)/2;
		merge_sort(input, left, pivot);
		merge_sort(input, pivot+1, right);
		merge(input, left, pivot, right);
	}
}
void merge (int input[], int l, int p, int r){
/*
	|l|....|p|....|r|
*/
	int A[100]; //left area
	int B[100]; //right area (from pivot)
	/*
		Be aware to set correct index variables. 
		Because we divide the original problem to two subproblems(left~pivot, pivot+1~right), also merging them should be done with same indexing.
		Merging process consists of comparing two sorted array and making one sorted array. 
	*/
	for(int i=0;i<=p-l;i++)
		A[i] = input[i+l];
	A[p-l+1] = 2100000000;
	for(int i=0 ;i<r-p;i++)
		B[i] = input[i+p+1];
	B[r-p] = 2100000000; //dummy value
	int indexA = 0;
	int indexB = 0;
	for (int k=l; k<=r ; k++){
		if(A[indexA] <= B[indexB]){
			input[k] = A[indexA];
			indexA++;
		}
		else{
			input[k] = B[indexB];
			indexB++;
		}
	}
	return ;
}


int main(){
	srand((unsigned int) time(0));
	int input [100]; 
	for(int i=0;i<100;i++)
		input[i] = (rand() %100 +1);
	merge_sort(input, 0, 99);
	for (int i=0;i<100;i++){
		cout << input[i] <<" ";
	}
}
