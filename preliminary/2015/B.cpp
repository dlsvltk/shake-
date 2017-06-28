//just implementation
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t,n,g;
	char S[101];
	int p;
	bool check[101];
	cin >> t;
	while (t--) {
		cin >> n >> g;
		char beer[101][101];
		memset(beer, 0, 101 * 101);
		for (int i = 0; i < n; i++) {
			cin >> beer[i];
			check[i] = 1;
		}
		for (int i = 0; i < g; i++) {
			cin >> p >> S;
			if (p > 100) {
				for (int k = 0; k < n; k++) check[k] = 0;
			}
			for (int k = 0; k < n; k++) {
				if (check[k]) {
					int index = 0;
					bool equal = 0;
					while (S[index] != 0) {
						if (beer[k][p - 1] == S[index]) {
							equal = 1;
						}
						index++;
					}
					check[k] = equal;
				}
			}
		}
		int c = 0;
		int idx = -1;
		for (int i = 0; i < n; i++) {
			if (check[i]) {
				c++;
				idx = i;
			}
		}
		if (c == 0) printf("DEAD DRUNK\n");
		else if (c == 1) {
			printf("%s\n", beer[idx]);
		}
		else {
			printf("YOU KNOW NOTHING\n");
		}
	}
	return 0;
}
