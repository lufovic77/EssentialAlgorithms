#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; 

int main(){
	srand((unsigned int) time(0));
	int input[100];
	for(int i=0;i<100;i++)
		input[i] = rand() % 100 + 1;
	//let me use integer array length 100, with random input

	for(int i=1; i<100;i++){
		int key = input[i];
		int index = i-1;
		/*
		Now, insert key in to input[0~i-1], which is sorted area. 
		*/
		while(index >=0 && input[index]>=key){
			input[index+1] = input[index];
			index --;
		}
		input[index+1] = key;
	}
	for(int i=0;i<100;i++){
		cout<<input[i]<<" ";
	}
}
