#include <bits/stdc++.h>
#define ii pair<int,int>

using namespace std;

map<int,int> m;

int least_charge(vector<int>& times, int minIndex) {
	if (m.find(minIndex) != m.end()) {
		return m[minIndex];
	}

	if (minIndex >= times.size()) {
		return 0;
	}

	int result = INT_MAX;
	int currentTime = times[minIndex];

	int newIndex = minIndex+1;
	while (newIndex < times.size() && times[newIndex] - currentTime < 24*60) {
		newIndex++;
	}
	result = min(result, 50 + least_charge(times, newIndex));

	newIndex = minIndex+1;
	while (newIndex < times.size() && times[newIndex] - currentTime < 6*60) {
		newIndex++;
	}
	result = min(result, 20 + least_charge(times, newIndex));

	newIndex = minIndex+1;
	while (newIndex < times.size() && times[newIndex] - currentTime < 60) {
		newIndex++;
	}
	result = min(result, 5 + least_charge(times, newIndex));

	result = min(result, 2 + least_charge(times, minIndex+1));
	m[minIndex] = result;
	return result;
}

int main() {
	int N;
	cin >> N;
	int total = 0;
	vector<int> times;
	int prev = 0;
	for (int i = 0; i < N; i++) {
		m.clear();
		int num;
		cin>>num;
		times.push_back(num);
		int least = least_charge(times, 0);
		cout << (least - prev) << endl;
		prev = least;
	}
}


