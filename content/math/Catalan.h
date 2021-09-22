/**
 * Author: Paulo Miranda
 * Date: 2020-09-31
 * License: Free
 * Description:
 * Time:
 */
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
ll C(int n, int k){
  if(k > n)
    return 0;
  return (fat[n]*((ifat[k]*ifat[n-k])%MOD))%MOD;
}
ll catalan(int n){
  return (C(2*n, n) - C(2*n, n-1) + MOD)%MOD;
}
ll f(int x1, int y1, int x2, int y2){
  int y = y2 - y1, x = x2 - x1;
  if(y < 0 or x < 0)
    return 0;
  return C(x + y, x);
}
// o = number of '(', c = number of ')', k = fixed prefix of '(' extra
// Catalan Generalization, open[i] >= close[i] for each 0 <= i < o + c + k
// where open[i] is number of '(' in prefix until i
// and close[i] is number of ')'
ll catalan2(int o, int c, int k){
  int x = o + k - c;
  if(x < 0)
    return 0;
  return (f(k, 0, o+k, c) - f(k, 0, o+k-x-1, c + x + 1) + MOD)%MOD;
}
