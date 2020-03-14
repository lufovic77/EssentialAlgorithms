#include <iostream>
using namespace std;
void pointer_convert(int * a){
	*a = 1976079305;
}

void refer_convert(int & a){
	a = 785922;
}
int main(){
	int num = 2016311600;
	pointer_convert(&num);
	cout<<num<<endl;
	refer_convert(num);
	cout<<num;
	//works same 
}
