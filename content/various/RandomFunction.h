/**
 * Author: Paulo Miranda
 * Date: 2020-09-31
 * License: Free
 * Description:
 * Time:
 */
#include <bits/stdc++.h>
using namespace std;
mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
inline int rand(int l, int r){
  return uniform_int_distribution<int>(l, r)(rng);
}
void randomShuffle(vector<int> v){
  shuffle(v.begin(), v.end(), rng);
}
