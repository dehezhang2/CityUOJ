#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <set>
#include <sstream>
using namespace std;
char change(char ch){
    if(ch<='Z'&&ch>='A'){
        return ch - 'A' + 'a';
    }
    else if(ch<='z'&&ch>='a'){
        return ch;
    }
    else return ' ';
}
set<string> st;
int main(){
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    string temp;
    while(cin>>temp){
        transform(temp.begin(), temp.end(), temp.begin(), ::change);
        stringstream input(temp);
        while(input>>temp) st.insert(temp);
    }
    for(auto str:st) cout << str << endl;
    return 0;
}