#include <ctime>
#include <string>
#include <iostream>
using namespace std;

int main(){
	string str="";
	string temp;
	cout << "Test \n"<<endl;
	clock_t t = clock();
	string k="1";
	for(int i=0;i<1024000; ++i){
		str += k;
	}
	for(int i=0;i<100000; ++i){
		temp = str;
	}
	clock_t n = clock() - t;
	cout << ((double)n / CLOCKS_PER_SEC ) << endl;
	return 0;
}