#include <bits/stdc++.h>
#define ii pair<int,int>

using namespace std;

// last element is id for union-find
vector<tuple<double,double,double,int>> ss;
int main() {
	int H,W,N;
	cin>>H>>W>>N;
	ss.resize(N);
	for (int i = 0; i < N; i++) {
		cin>>get<0>(ss[i])>>get<1>(ss[i])>>get<2>(ss[i]);
		// Unique union-find id.
		get<3>(ss[i]) = i+100;
		bool coverTop = get<1>(ss[i]) - get<2>(ss[i]) <= 0;
		bool coverBottom = get<1>(ss[i]) + get<2>(ss[i]) >= H;

		if (coverTop) {
			get<3>(ss[i]) = 1;
		}

		if (coverBottom) {
			get<3>(ss[i]) = 2;
		}

		// if covers top and bottom, already screwed.
		if (coverTop && coverBottom) {
			cout << "NO CAKE" << endl;
			return 0;
		}
	}

	// Try joining every pair of sprinklers.
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			double dx = get<0>(ss[i]) - get<0>(ss[j]);
			double dy = get<1>(ss[i]) - get<1>(ss[j]);
			double dist = sqrt(dx*dx+dy*dy);
			// sprinklers overlap.
			if (dist <= get<2>(ss[i]) + get<2>(ss[j])) {
				int id1 = get<3>(ss[i]);
				int id2 = get<3>(ss[j]);

				if (id1 != id2) {
					if (id1 == 1 && id2 == 2 || id1 == 2 && id2 == 1) {
						cout << "NO CAKE" << endl;
						return 0;
					} else {
						if (id1 == 1 || id1 == 2) {
							for (int k = 0; k < N; k++) {
								if (get<3>(ss[k]) == id2) {
									get<3>(ss[k]) = id1;
								}
							}
						} else {
							for (int k = 0; k < N; k++) {
								if (get<3>(ss[k]) == id1) {
									get<3>(ss[k]) = id2;
								}
							}
						}
					}
				}
			}
		}
	}

	cout << "CAKE" <<endl;
}


