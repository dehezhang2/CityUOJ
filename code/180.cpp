#include<iostream>
using namespace std;
long long arr[51];
int main() {
	int n;
	while (cin>>n&&n!=0) {
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		long long step = 0;
		for (int i = n - 1; i > 0; i--) {
			step += arr[i];
			for (int j = 0; j < i; j++)
				arr[j] += arr[i];
		}
		cout << step + arr[0] << endl;
	}
	return 0;
}