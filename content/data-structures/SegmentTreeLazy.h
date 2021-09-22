/**
 * Author: Paulo Miranda
 * Date: 2020-09-31
 * License: Free
 * Description:
 * Time:
 */
#include <bits/stdc++.h>
using namespace std;
namespace SegTreeLazy{
	typedef long long Node;
	Node st[MAXN];
	long long lazy[MAXN];
	int v[MAXN];
	int n;
	Node neutral = 0;
	inline Node join(Node a, Node b){
		return a + b;
	}
	inline void upLazy(int &node, int &i, int &j){
		if (lazy[node] != 0){
			st[node] += lazy[node] * (j - i + 1);
			//st[node] += lazy[node];
			if (i != j){
				lazy[(node << 1)] += lazy[node];
				lazy[(node << 1) + 1] += lazy[node];
			}
			lazy[node] = 0;
		}
	}
	void build(int node, int i, int j){
		if (i == j){
			st[node] = v[i];
			return;
		}
		int m = (i + j) / 2;
		int l = (node << 1);
		int r = l + 1;
		build(l, i, m);
		build(r, m + 1, j);
		st[node] = join(st[l], st[r]);
	}
	Node query(int node, int i, int j, int a, int b){
		upLazy(node, i, j);
		if ((i > b) or (j < a))
			return neutral;
		if ((a <= i) and (j <= b)){
			return st[node];
		}
		int m = (i + j) / 2;
		int l = (node << 1);
		int r = l + 1;
		return join(query(l, i, m, a, b), query(r, m + 1, j, a, b));
	}
	void update(int node, int i, int j, int a, int b, Node value){
		upLazy(node, i, j);
		if ((i > j) or (i > b) or (j < a))
			return;
		if ((a <= i) and (j <= b)){
			lazy[node] = value;
			upLazy(node, i, j);
		}else{
			int m = (i + j) / 2;
			int l = (node << 1);
			int r = l + 1;
			update(l, i, m, a, b, value);
			update(r, m + 1, j, a, b, value);
			st[node] = join(st[l], st[r]);
		}
	}
};
