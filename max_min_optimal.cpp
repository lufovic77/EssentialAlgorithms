#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <limits.h>
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
	cout<<"minimum: "<<mini<<" maximum: "<<maxi<<endl;
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
	}
	else{ //size is odd
		mini = maxi = array[0];
		for(int i=1;i<array.size();i+=2){	
			mini = min(array[i], array[i+1]);
			maxi = max(array[i], array[i+1]);
		}
	}
	cout<<"minimum: "<<mini<<" maximum: "<<maxi<<endl;
}
int main(){
	vector <int> array;
	srand(time(NULL));
	for(int i=0;i<100;i++){
		array.push_back(rand()%100);
	}
	is_it_optimal(array); //O(2n)
	faster_one(array);	//O(3|_n/2_|) accurately, floor of (n/2). 
}
