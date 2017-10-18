#include <bits/stdc++.h>
#define ii pair<int,int>

using namespace std;

int main() {
	string mon,_,dec;
	cin>>mon>>_>>_>>_>>_>>dec;
	cout << ((mon[0] - dec[0] + 26) % 26) << endl;
}
