#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MAXN = 10 + 5;
int a[MAXN][MAXN], b[MAXN][MAXN];
bool line[MAXN], col[MAXN];
int n1, m1, n2, m2;

bool check () {//判断搜索后的矩阵A是否与B相等
	int I = 1, J;
	for (int i = 1; i <= n1; i ++) {
		if (col[i]) {
			J = 1;
			for (int j = 1; j <= m1; j ++) {
				if (line[j]) {
					if (a[i][j] != b[I][J]) {
						return 0;
					}
					J ++;
				}
			}
			I ++;
		}
	}
	return 1;
}

void dfs_col (int step, int x) {//搜索每一列
	if (step > n2) {
		if (check ()) {
			printf ("Yes");
			exit (0);
		}
		return;
	}
	for (int i = x + 1; i <= n1 - (n2 - step); i ++) {
		if (!col[i]) {
			col[i] = 1;
			dfs_col (step + 1, i);
			col[i] = 0;
		}
	}
}

void dfs_line (int step, int x) {//搜索每一行
	if (step > m2) {
		dfs_col (1, 0);
		return;
	}
	for (int i = x + 1; i <= m1 - (m2 - step); i ++) {
		if (!line[i]) {
			line[i] = 1;
			dfs_line (step + 1, i);
			line[i] = 0;
		}
	}
}

int main () {
	scanf ("%d %d", &n1, &m1);
	for (int i = 1; i <= n1; i ++) {
		for (int j = 1; j <= m1; j ++) {
			scanf ("%d", &a[i][j]);
		}
	}
	scanf ("%d %d", &n2, &m2);
	for (int i = 1; i <= n2; i ++) {
		for (int j = 1; j <= m2; j ++) {
			scanf ("%d", &b[i][j]);
		}
	}
	dfs_line (1, 0);
	printf ("No");
	return 0;
}
