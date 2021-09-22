/**
 * Author: Paulo Miranda
 * Date: 2020-09-31
 * License: Free
 * Description:
 * Time:
 */
#include <bits/stdc++.h>
using namespace std;
string min_cyclic_string(string s){
  s += s;
  int n = s.size();
  int i = 0, ans = 0;
  while (i < n / 2){
    ans = i;
    int j = i + 1, k = i;
    while (j < n && s[k] <= s[j]){
      if (s[k] < s[j])
        k = i;
      else
        k++;
      j++;
    }
    while (i <= k)
      i += j - k;
  }
  return s.substr(ans, n / 2);
}