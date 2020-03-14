#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
int LEFT  (int i){ return 2*i; }
int RIGHT (int i){ return 2*i+1; }
int PARENT(int i){ return i/2; }

int heap_size = 0;
void max_heapify(vector<int> & heap, int index){
	int l = LEFT(index);
	int r = RIGHT(index);
	int largest = index;
	if( l <= heap_size && heap[l] > heap[index]){ 
		/*
		 * Check if l is not out of range, 
		 * index node violates the max-heap property.
		 * */
		largest = l;
	}
	else
		largest = index;
	if( r <= heap_size && heap[r] > heap[index]){
		largest = r;
	}
	if(largest != index){//should swap. 
		swap(heap[index], heap[largest]);
		max_heapify(heap, largest); //keep going down. index node goes down to largest position.
	}
}

void build_max_heap(vector <int> &heap){//argument passing using reference
	heap_size = heap.size();
	for(int i= heap.size()/2 ; i>=1; i--)//traverse without leaves cause leaf nodes are max-heap by itself... prove it!
		max_heapify(heap, i);	
}

int main(){ //max-heap sorting implementation
	vector <int> heap;
	srand(time(NULL));
	for(int i=0;i<=100;i++){ //heap[0] is dummy value
		heap.push_back(rand()%100);
	}//make randomized input
	build_max_heap(heap);

	for (auto a : heap){
		/*
		 * compile with -std=c++11 flag!
		 */
		cout<<a<<" ";
	}
	cout<<endl<<endl<<"now sorting ..."<<endl<<endl;
	for(int i= heap_size ; i>=1; i--){
		swap(heap[1], heap[heap_size]);
		cout<<heap[heap_size--]<<" ";
	}

}
