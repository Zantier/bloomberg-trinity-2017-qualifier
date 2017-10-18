#include <bits/stdc++.h>
#define ii pair<int,int>

using namespace std;

int main() {
	int N;
	cin>>N;
	for (int i = 0; i < N; i++) {
		string s;
		cin>>s;
		int num = 1;
		int total = 0;
		for (int j = 0; j < s.length(); j++) {
			total += num * (s[j] - '0');
			if (num == 1) {
				num = 3;
			} else {
				num = 1;
			}
		}

		if (total % 10 == 0) {
			cout << "VALID";
		} else {
			cout << "NOT VALID";
		}
		cout << endl;

	}
}
