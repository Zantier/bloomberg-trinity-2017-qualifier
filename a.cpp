#include <bits/stdc++.h>
#define ii pair<int,int>

using namespace std;

//suspect, room, weapon,  time
// pair: type index, then index in that type
unordered_map<string, ii> nameIndexes(4);
vector<string> suspectNames;

// For each type, for each index, for each type it can be linked to, the item it is or isn't linked to.
vector<vector<vector<pair<bool,int>>>> evidence;

int main() {
	int N;
	cin >> N;
	suspectNames.resize(N);
	evidence.resize(4);
	for (int i = 0; i < 4; i++) {
		evidence[i].resize(N);
		for (int j = 0; j < N; j++) {
			evidence[i][j].resize(4, -1);
			string name;
			cin >> name;
			nameIndexes[name] = make_pair(i,j);
			if (i == 0) {
				suspectNames[j] = name;
			}
		}
	}

	cerr << "done " << endl;

	string line;
	getline(cin, line);
	getline(cin, line);

	while (line[0] != '#') {
		istringstream ss(line);
		string first, second;
		bool isEqual = true;
		if (line.find("!") != string::npos) {
			isEqual = false;
			getline(ss, first, '!');
		} else {
			isEqual = true;
			getline(ss, first, '=');
		}

		ss.ignore(1);
		getline(ss, second);

		cerr << first << ", " << second << endl;

		ii firstii = nameIndexes[first];
		ii secondii = nameIndexes[second];
		evidence[firstii.first][firstii.second][secondii.first] = make_pair(isEqual, secondii.second);
		evidence[secondii.first][secondii.second][firstii.first] = make_pair(isEqual, firstii.second);

		getline(cin, line);
	}

	string toFind(line.begin()+2, line.end());
	ii toFindii = nameIndexes[toFind];
}


