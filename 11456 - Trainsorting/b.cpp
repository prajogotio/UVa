//idea: similar to LIS O(N log k) version, but can extend both ways
//Proof? idea: we go one by one from beg to end, update only to lower value/ closer value

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;

deque<int> cars;

int main(){
	int TC,val;
	scanf("%d",&TC);
	while(TC--){
		scanf("%d",&val);
		if(cars.empty()){
			cars.push_back(val);
		} else {
			if(val < cars[0]){
				cars.push_front(val);
			} else if(val > cars[cars.size()-1]){
				cars.push_back(val);
			} else {
				//update  NAH