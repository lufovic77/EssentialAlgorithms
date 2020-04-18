#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <time.h>
using namespace std;
/*
 * Please compile with -std=c++11
 */
void is_it_optimal(vector <int> array){
	int mini = INT_MAX;
	int maxi = INT_MIN;
	for(auto item : array)
		if(mini > item)
			mini = item;
	for(auto item : array)
		if(maxi < item)
			maxi = item;
	cout<<"2n comparisons -> minimum: "<<mini<<" maximum: "<<maxi<<endl; //2n comparisons
	return ;
}
void faster_one(vector <int> array){
	int mini, maxi;
	int tmin, tmax;
	if(array.size() %2 ==0){ //size is even
		mini = min(array[0], array[1]);
		maxi = max(array[0], array[1]);
		for(int i=2;i<array.size();i+=2){
			if(array[i] >= array[i+1]){
				tmin = array[i+1];
				tmax = array[i];
			}
			else{
				tmin = array[i];
				tmax = array[i+1];
			}
			mini = min(mini, tmin);
			maxi = max(maxi, tmax);
		}
	} // 3(n-2)/2 comparisons.
	else{ //size is odd
		mini = maxi = array[0];
		for(int i=1;i<array.size();i+=2){
			if(array[i] >= array[i+1]){
				tmin = array[i+1];
				tmax = array[i];
			}
			else{
				tmin = array[i];
				tmax = array[i+1];
			}
			mini = min(mini, tmin);
			maxi = max(maxi, tmax);
		}
	}//3n/2 comparisons.
	cout<<"faster one -> minimum: "<<mini<<" maximum: "<<maxi<<endl;
}
int main(){
	vector <int> array;
	srand(time(NULL));
	for(int i=0;i<10000000;i++){
		array.push_back(rand()%100);
	}
	float s, e;
	s = clock();
	is_it_optimal(array); 
	e = clock();
	printf("slow one: %10f\n\n", (float)(e-s)/CLOCKS_PER_SEC);
	s = clock();
	faster_one(array);
	e = clock();
	printf("faster one: %10f\n", (float)(e-s)/CLOCKS_PER_SEC);
/*	
	slow output: 0.2258sec
	optimal outpur: 0.1682sec
*/
}
