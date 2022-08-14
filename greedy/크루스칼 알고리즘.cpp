//https://school.programmers.co.kr/learn/courses/30/lessons/42861

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int parent[101];
//index -> V
//value -> set number(parent)

//cost 순으로 sort시 사용
bool cmp(vector<int> a, vector<int> b) {
    if (a[2] < b[2])
        return true;
    return false;
}

//해당 graph의 parent를 구하는 과정
int getParent(int node) {
    if (parent[node] == node) return node;
    return parent[node] = getParent(parent[node]);
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    sort(costs.begin(), costs.end(), cmp);

    //100개의 set을 가지고 시작
    for (int i = 0; i < n; i++)
        parent[i] = i;


    for (int i = 0; i < costs.size(); i++) {
        //start쪽의 set번호
        int start_nd = getParent(costs[i][0]);
        //end쪽의 set 번호
        int end_nd = getParent(costs[i][1]);
        //start - end cost
        int cost = costs[i][2];

        //start와 end의 set집합이 다를 경우
        if (start_nd != end_nd) {
            //선을 긋고
            answer += cost;
            //end쪽 set을 start쪽 set에 넣음
            parent[end_nd] = start_nd;
        }
    }
    return answer;
}

//출처: https://github.com/Amuguna/Algorithm-study/blob/main/CLUG_study/%EC%84%AC%EC%97%B0%EA%B2%B0%ED%95%98%EA%B8%B0.cpp
