//topology sort?
#include<bits/stdc++.h>
using namespace std;
int visit[101];
int indge[101];
vector<int> adj[101];
queue<int> q;
bool topo_sort(int n) {
	for (int i = 1; i <= n; i++) {
		if (indge[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		visit[v] = 1;
		for (int i = 0; i < adj[v].size(); i++) {
			int next = adj[v][i];
			if (visit[next] == 0) {
				indge[next]--;
				if (indge[next] == 0) q.push(next);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (visit[i] == 0) return 0;
	}
	return 1;
}

int main() {
	int n, a, v;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		while (a--) {
			cin >> v;
			adj[i].push_back(v);
			indge[v]++;
		}
	}
	if (topo_sort(n)) printf("Yes");
	else printf("No");
	return 0;
}
