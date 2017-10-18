#include <bits/stdc++.h>
#define ii pair<int,int>

using namespace std;

bool isCap(char c) {
	return c >= 'A' && c <= 'Z';
}

int main() {
	int N,M;
	cin>>N>>M;
	vector<string> lines(N);
	for (int i = 0; i < N; i++) {
		cin >> lines[i];
	}

	bool result = true;
	// horizontal
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M-1; j++) {
			if (lines[i][j] != lines[i][j+1] && isCap(lines[i][j]) == isCap(lines[i][j+1])) {
				result = false;
			}
		}
	}

	// vert
	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < M; j++) {
			if (lines[i][j] != lines[i+1][j] && isCap(lines[i][j]) == isCap(lines[i+1][j])) {
				result = false;
			}
		}
	}

	if (result) {
		cout << "VALID" << endl;
	} else {
		cout << "INVALID" << endl;
	}
}
