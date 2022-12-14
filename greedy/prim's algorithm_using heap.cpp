#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int solution(int n, vector<vector<int>> costs) {
	vector<vector<int>> graph(n, vector<int>(n, 0));
	priority_queue<pair<int, int>,vector<pair<int, int>>, cmp> PQ;
	vector<bool> visited(n, 0);
	int answer = 0;

	for (int i = 0; i < costs.size(); i++) {
		graph[costs[i][0]][costs[i][1]] = costs[i][2];
		graph[costs[i][1]][costs[i][0]] = costs[i][2];
	}

	for (int i = 0; i < graph[0].size(); i++) {
		if (graph[0][i] != 0) {
			int next = i;
			int cost = graph[0][i];
			PQ.push(make_pair(next, cost));
		}
	}

	visited[0] = true;

	while (!PQ.empty()) {
		int cur = PQ.top().first;
		int distance = PQ.top().second;
		PQ.pop();

		if (visited[cur] == false) {
			answer += distance;
			visited[cur] = true;

			for (int i = 0; i < graph[cur].size(); i++) {
				if (graph[cur][i] != 0 && visited[i] != true) {
					PQ.push(make_pair(i, graph[cur][i]));
				}
			}
		}
	}

	return answer;
}

int main() {
	vector<vector<int>> costs = { {0, 1, 1} ,{0, 2, 2},{1, 2, 5},{1, 3, 1},{2, 3, 8} };
	int n = 4;
	cout << solution(n, costs) << endl;
}