/**
 * Author: Paulo Miranda
 * Date: 2020-09-31
 * License: Free
 * Description:
 * Time:
 */
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
template<bool directed=false> struct EulerianPath{
  vector<vector<pii>> adj;
  vector<int> ans, pos;
  vector<bool> used;
  int n, m;
  EulerianPath(int n1){
    n = n1; m = 0;
    adj.assign(n, vector<pii>());
  }
  void addEdge(int a, int b) {
    int at = m++;
    adj[a].push_back({b, at});
    if (!directed) adj[b].push_back({a, at});
  }
  void dfs(int u){
    stack<int> st;
    st.push(u);
    while(!st.empty()){
      u = st.top();
      if(pos[u] < adj[u].size()){
        auto [to, id] = adj[u][pos[u]];
        pos[u]++;
        if(!used[id]){
          used[id] = true;
          st.push(to);
        }
      }else{
        ans.push_back(u);
        st.pop();
      }
    }
  }
  // Remember to call the correct src
  // If you want to check if there is an answer remember to check if all |components| > 1 of the graph are connected
  vector<int> getPath(int src){
    pos.assign(n, 0);
    used.assign(m, false);
    ans.clear();
    dfs(src);
    reverse(ans.begin(), ans.end());
    return ans;
  }
};