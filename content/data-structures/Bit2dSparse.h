/**
 * Author: Paulo Miranda
 * Date: 2020-09-31
 * License: Free
 * Description:
 * Time:
 */
#include <bits/stdc++.h>
// Time complexity : O(Q log(N)^2)
// Space complexity : O(Q log(N))
namespace Bit2d{
  OrderedSet bit[MAXN];
  void add(int x, int y){
    for(int i = x; i < MAXN; i += i & -i)
      bit[i].insert(mp(y, x));
  }
  void remove(int x, int y){
    for(int i = x; i < MAXN; i += i & -i)
      bit[i].erase(mp(y, x));
  }
  int get(int x, int y){
    int ans = 0;
    for(int i = x; i > 0; i -= i & -i)
      ans += bit[i].order_of_key(mp(y+1, 0));
    return ans;
  }
};
