//just implementation
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int A[4],B[4];
	cin >> n;
	for (int i = 0; i < n; i++) {
		bool check = 1;
		scanf("%d.%d %d.%d %d.%d %d.%d", A, B, A + 1, B + 1, A + 2, B + 2, A + 3, B + 3);
		for (int j = 0; j < 4; j++) {
			if (A[j] + B[j] == 0) {
				check = 0;
			}
		}
		if (!check) {
			printf("NOT ATTENDED\n");
			continue;
		}
		A[0] = A[0] + A[1] + A[2] + A[3];
		B[0] = B[0] + B[1] + B[2] + B[3];
		A[0] *= 100;
		B[0] *= 10;
		A[0] = (A[0] + B[0]) / 4;
		if (A[0] % 100 < 25) {
			printf("%d.0\n", A[0]/100);
		}
		else if (A[0] % 100 < 75) {
			printf("%d.5\n", A[0] / 100);
		}
		else {
			printf("%d.0\n", A[0] / 100 + 1);
		}
	}
	return 0;
}
