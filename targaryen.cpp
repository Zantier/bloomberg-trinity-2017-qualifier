#include <bits/stdc++.h>
#define ii pair<int,int>

using namespace std;

int main() {
	int N;
	string s;
	cin>>N>>s;
	int matched = 0;
	int result = 0;
	for (int i = 0; i < N; i++) {
		if (matched == 0 && s[i] == '0') {
			matched++;
		} else if (matched == 1 && s[i] == '1') {
			matched++;
		} else if (matched == 2 && s[i] == '0') {
			result++;
			matched = 0;
		} else {
			matched = 0;
		}
	}

	cout << result << endl;
}


