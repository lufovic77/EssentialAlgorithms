#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
	srand((unsigned int) time(0));
	cout<<rand()%10; //random 0~9
}
