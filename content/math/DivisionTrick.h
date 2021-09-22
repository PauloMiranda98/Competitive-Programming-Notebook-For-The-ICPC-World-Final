/**
 * Author: Paulo Miranda
 * Date: 2020-09-31
 * License: Free
 * Description:
 * Time:
 */
// O(sqrt(N))
// sum (n/i)
ll divisionTrick(ll n){
  ll ans = 0;
  for(ll l = 1, r; l <= n; l = r + 1) {
    r = n / (n / l);
    // n / i has the same value for l <= i <= r
    ans += (n/l)*(r-l+1);
  }
  return ans;
}
