#include <cstdio>
#include <memory.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n, m;
char map[1501][1501];
char cc;
int d1_x, d1_y, d2_x, d2_y;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
bool dist[1501][1501];

queue<pair<int, int>> water, q, q2;

void icing() {
	int ws = water.size();

	while (ws--) {
		int w_x = water.front().first;
		int w_y = water.front().second;
		water.pop();

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + w_x;
			int ny = dy[i] + w_y;
			if (map[nx][ny] == '.') continue;
			if (map[nx][ny] == 'L') continue;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			water.push(make_pair(nx, ny));
			map[nx][ny] = '.';
		}
	}
}


int main() {
	int day = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1s", &map[i][j]);
			if (map[i][j] == 'L') {
				if (d1_x != 0) {
					d2_x = i;
					d2_y = j;
					water.push(make_pair(i, j));
				}
				else {
					d1_x = i;
					d1_y = j;
					water.push(make_pair(i, j));
				}
			}
			if (map[i][j] == '.') {
				water.push(make_pair(i, j));
			}
		}
	}

	bool flag = false;


	dist[d1_x][d1_y] = 1;
	q.push(make_pair(d1_x, d1_y));

	while (1) {
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

				if (map[nx][ny] != 'X' && dist[nx][ny] == 0) {
					if (map[nx][ny] == 'L') {
						printf("%d\n", day);
						return 0;
					}
					dist[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
				if (map[nx][ny] == 'X' && dist[nx][ny] == 0) {
					dist[nx][ny] = 1;
					q2.push(make_pair(nx, ny));
				}
			}

		}


		icing();
		day++;

		q = q2;
		while (!q2.empty()) {
			q2.pop();
		}

	}

	return 0;
}