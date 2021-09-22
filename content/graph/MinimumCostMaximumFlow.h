/**
 * Author: Paulo Miranda
 * Date: 2020-09-31
 * License: Free
 * Description:
 * Time:
 */
#include <bits/stdc++.h>
using namespace std;
//O(MaxFlow * path) or
//O(N * M * Path) = O(N^2*M^2) or O(N*M^2*log(n)) or O(N^3*M)
//                    SPFA          Dijkstra        Dijkstra
template <class T = int>
class MCMF{
private:
  struct Edge{
    int to;
    T cap, cost;
    Edge(int a, T b, T c) : to(a), cap(b), cost(c) {}
  };
  int n;
  vector<vector<int>> edges;
  vector<Edge> list;
  vector<int> from;
  vector<T> dist, pot;
  vector<bool> visit;
  pair<T, T> augment(int src, int sink){
    pair<T, T> flow = {list[from[sink]].cap, 0};
    for (int v = sink; v != src; v = list[from[v] ^ 1].to){
      flow.first = std::min(flow.first, list[from[v]].cap);
      flow.second += list[from[v]].cost;
    }
    for (int v = sink; v != src; v = list[from[v] ^ 1].to){
      list[from[v]].cap -= flow.first;
      list[from[v] ^ 1].cap += flow.first;
    }
    return flow;
  }
  queue<int> q;
  bool SPFA(int src, int sink){
    T INF = numeric_limits<T>::max();
    dist.assign(n, INF);
    from.assign(n, -1);
    q.push(src);
    dist[src] = 0;
    while (!q.empty()){
      int on = q.front();
      q.pop();
      visit[on] = false;
      for (auto e : edges[on]){
        auto ed = list[e];
        if (ed.cap == 0)
          continue;
        T toDist = dist[on] + ed.cost + pot[on] - pot[ed.to];
        if (toDist < dist[ed.to]){
          dist[ed.to] = toDist;
          from[ed.to] = e;
          if (!visit[ed.to]){
            visit[ed.to] = true;
            q.push(ed.to);
          }
        }
      }
    }
    return dist[sink] < INF;
  }
  void fixPot(){
    T INF = numeric_limits<T>::max();
    for (int i = 0; i < n; i++){
      if (dist[i] < INF)
        pot[i] += dist[i];
    }
  }
public:
  MCMF(int size){
    n = size;
    edges.resize(n);
    pot.assign(n, 0);
    dist.resize(n);
    visit.assign(n, false);
  }
  pair<T, T> solve(int src, int sink){
    pair<T, T> ans(0, 0);
    // Remove negative edges: Johnson's Algorithm
    if (!SPFA(src, sink))
      return ans;
    fixPot();
    // Can use dijkstra to speed up depending on the graph
    while (SPFA(src, sink)){
      auto flow = augment(src, sink);
      // When the priority is the minimum cost and not the flow 
      // if(flow.second >= 0)
      //   break;
      ans.first += flow.first;
      ans.second += flow.first * flow.second;
      fixPot();
    }
    return ans;
  }
  void addEdge(int u, int to, T cap, T cost){
    edges[u].push_back(list.size());
    list.push_back(Edge(to, cap, cost));
    edges[to].push_back(list.size());
    list.push_back(Edge(u, 0, -cost));
  }
};