#include <iostream>
#include <vector>
using namespace std;
void pointer_convert(int * a){
	*a = 1976079305;
}

void refer_convert(int & a){
	a = 785922;
}
void twoD_vector(vector <int> two []){
	for(int i=0;i<5;i++){
		cout<<two[i][0]<<endl;
	}
}
void change(bool flag[100]){
	flag[0] = true;
}
void ptr_change(int* p){
	cout<<&p<<endl;
	/*
	 *address changes. why ? */
	return ;
}
int main(){
	//1. Poiner&reference passing (works same)
	cout<<"1. Poiner&reference passing (works same)"<<endl;
	int num = 2016311600;
	pointer_convert(&num);
	cout<<num<<endl;
	refer_convert(num);
	cout<<num<<endl;

	//2. 2D vector passing
	cout<<"2. 2D vector passing"<<endl;
	vector <int> twoD [5];
	for(int i=0;i<5;i++)
		twoD[i].push_back(i);
	twoD_vector(twoD);	

	//3. 1D array passing
	cout<<"3. 1D array passing"<<endl;
	bool flag[100];
	flag[0] = false;
	change(flag);
	cout<<flag[0]<<endl;

	//4. Pointer address integrity
	cout<<"4. Pointer address integrity"<<endl;
	int* p1;
	cout<<&p1<<endl;
	ptr_change(p1);
}
