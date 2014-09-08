#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
string ch;
int sz;

void build(string str, int len){
  if(len == sz){
    cout << str << endl;
    return;
  }
  for(int i=0;i<=len;++i){
    string temp1 = str.substr(0,i);
    string temp2 = str.substr(i,len-i);
    build(temp1+ch[len]+temp2, len+1);
  }
}

int main(){
  bool flag = false;
  while(cin >> ch){
    if(flag) printf("\n");
    sz = ch.size();
    build(string(), 0);
    flag = true;
  }
  return 0;
}