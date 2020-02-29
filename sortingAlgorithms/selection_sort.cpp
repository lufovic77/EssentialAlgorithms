#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std; 

int main(){
	srand((unsigned int) time(0));
	vector <int> input;
	for(int i=0;i<100;i++)
		input.push_back( rand() % 100 + 1 );
	//let me use integer vector, with random input
	int length = input.size();
	for(int i=0; i<length;i++){
		int min = i;
		/*
		Find smallest (or largest) number in the unsorted area and exchange it with the rightmost element in sorted area. 
		|...sorted...|(pivot)|...unsorted...|
		*/
		for(int k=i+1;k<length;k++){
			if(input[k] <= input[min])
				min = k;
		}
		swap(input[i], input[min]);
	}	
	for(int i=0;i<length;i++){
		cout<<input[i]<<" ";
	}
}
