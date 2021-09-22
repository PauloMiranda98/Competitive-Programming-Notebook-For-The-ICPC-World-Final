/**
 * Author: Paulo Miranda
 * Date: 2020-09-31
 * License: Free
 * Description:
 * Time:
 */
#include <bits/stdc++.h>
using namespace std;
int fastPow(int base, string bigExp, int mod){
  int ans = 1;
  for(char c: bigExp){
    ans = fastPow(ans, 10, mod);
    ans = (ans*1LL*fastPow(base, c-'0', mod))%mod;
  }
  return ans;
}
//\sum_{i = 0}^{n - 1} floor((a * i + b)/m)
// 0 <= n <= 10^9
// 1 <= m <= 10^9
// 0 <= a, b < m
// O(log(a + b + c + d))
ll floor_sum(ll n, ll m, ll a, ll b) {
  ll ans = 0;
  if (a >= m) {
    ans += (n - 1) * n * (a / m) / 2;
    a %= m;
  }
  if (b >= m) {
    ans += n * (b / m);
    b %= m;
  }
  ll y_max = (a * n + b) / m, x_max = (y_max * m - b);
  if (y_max == 0) return ans;
  ans += (n - (x_max + a - 1) / a) * y_max;
  ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
  return ans;
}
void enumeratingAllSubmasks(int mask){
  for (int s = mask; s; s = (s - 1) & mask)
    cout << s << endl;
}
