#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

void Prim_Using_Heap() {
	priority_queue<pair<int, int>> PQ;

	//PQ에 정점 1과 관련한 간선 저장
	for (int i  = 0; i  < Cost[1].size(); i++) {
		int Next  = Cost[1][i].first;
		int Distance  = Cost[1][i].second;
		PQ.push(make_pair(-Distance, Next));
	}
	Visit[1] = true;

	while (PQ.empty() == 0) {
		int Distance  = -PQ.top().first;
		int Cur  = PQ.top().second;
		PQ.pop();

		//해당 점이 아직 set에 포함되지 않았다면
		if (Visit[Cur] == false) {
			Visit[Cur] = true;
			Answer  = Answer  + Distance;

			//해당 점을 기준으로 간선들 넣기
			for (int i  = 0; i  < Cost[Cur].size(); i++) {
				int nDistance  = Cost[Cur][i].second;
				int Next  = Cost[Cur][i].first;
				if (Visit[Next] == false) PQ.push(make_pair(-nDistance, Next));
			}
		}
	}
}
