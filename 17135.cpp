/*
 * 가정: 궁수 3명, 턴마다 궁수는 한 명의 적 공격, 모든 궁수는 동시에 공격 가능,
 * 가정: 궁수 공격이 끝나면 적은 한 칸 아래로 이동, 성이 있는 칸은 이동한 경우에서 제외
 *
 * 입력: 격자판 행 N, 열 M, 공격 거리 제한 D \n 격자판의 상태 0 or 1
 * 출력: 궁수의 공격으로 제거할 수 있는 적의 최대 수
 * 제한: 3 ≤ N, M ≤ 15, 1 ≤ D ≤ 10
 */

#include <iostream>
using namespace std;

int N,M,D;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> D;

    return 0;
}
