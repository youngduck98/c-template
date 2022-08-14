#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

// 섬 연결하기 prim's 알고리즘으로 풀기
int solution(int n, vector<vector<int>> costs) {
	int answer = 0;

	vector<vector<int>> graph(n, vector<int>(n));
	for (int i = 0; i < costs.size(); i++)
	{
		graph[costs[i][0]][costs[i][1]] = costs[i][2];
		graph[costs[i][1]][costs[i][0]] = costs[i][2];
	}

	//set 구분
	vector<int> visited; // 방문한 지점
	vector<int> unvisited; // 방문하지 않은 지점

	visited.push_back(0); // 0번째 점부터 시작
	for (int i = 1; i < n; i++)
		unvisited.push_back(i);

	//step 3
	for (int i = 1; i < n; i++)//남은 점이 n-1개 이므로
	{
		int min = INT_MAX;
		int min_index = 0;

		for (int j = 0; j < i; j++)//visited에 넣는 점이 i개 이므로
		{
			for (int k = 0; k < n - i; k++)// unvisited에 남은 점이 n-i개 이므로
			{
				//두 점 사이에 간선이 있다 && min 값보다 해당 간선의 cost가 더 낮다.
				if (graph[visited[j]][unvisited[k]] > 0 && min > graph[visited[j]][unvisited[k]])
				{
					//min에 해당 간선을 집어 넣는다.
					min = graph[visited[j]][unvisited[k]];
					min_index = k;
				}
			}
		}

		//확정된 min을 visited에 넣어주고 unvisited에서 빼준다.
		visited.push_back(unvisited[min_index]);
		unvisited.erase(unvisited.begin() + min_index);
		answer += min;
	}

	return answer;
}

//출처: https://ansohxxn.github.io/algorithm/mst/