//https://school.programmers.co.kr/learn/courses/30/lessons/42861

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int parent[101];
//index -> V
//value -> set number(parent)

//cost ������ sort�� ���
bool cmp(vector<int> a, vector<int> b) {
    if (a[2] < b[2])
        return true;
    return false;
}

//�ش� graph�� parent�� ���ϴ� ����
int getParent(int node) {
    if (parent[node] == node) return node;
    return parent[node] = getParent(parent[node]);
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    sort(costs.begin(), costs.end(), cmp);

    //100���� set�� ������ ����
    for (int i = 0; i < n; i++)
        parent[i] = i;


    for (int i = 0; i < costs.size(); i++) {
        //start���� set��ȣ
        int start_nd = getParent(costs[i][0]);
        //end���� set ��ȣ
        int end_nd = getParent(costs[i][1]);
        //start - end cost
        int cost = costs[i][2];

        //start�� end�� set������ �ٸ� ���
        if (start_nd != end_nd) {
            //���� �߰�
            answer += cost;
            //end�� set�� start�� set�� ����
            parent[end_nd] = start_nd;
        }
    }
    return answer;
}

//��ó: https://github.com/Amuguna/Algorithm-study/blob/main/CLUG_study/%EC%84%AC%EC%97%B0%EA%B2%B0%ED%95%98%EA%B8%B0.cpp
