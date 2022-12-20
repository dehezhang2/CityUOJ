#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
const int LEN = 1000;
using namespace std;
int main(){
  string arr[LEN];
  int len;
  for(len = 0;cin>>arr[len];len++);
  sort(arr,arr+len);
  for(int i=0 ;i<len;i++){
    int cnt = 0;
    for(;(cnt + i + 1 < len && arr[i]==arr[i+cnt+1]);cnt++);
	i += cnt;
    cout << arr[i] << " " << cnt+1 << endl;
  }
  return 0;
}
