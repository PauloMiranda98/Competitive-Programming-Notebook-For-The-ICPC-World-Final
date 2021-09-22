/**
 * Author: Paulo Miranda
 * Date: 2020-09-31
 * License: Free
 * Description:
 * Time:
 */
#include <bits/stdc++.h>
using namespace std;
// "abcabcd" is [0,0,0,1,2,3,0]
// "aabaaab" is [0,1,0,1,2,2,3]
vector<int> kmp(string s) {
  int n = (int)s.length();
  // pi[i] is the length of the longest proper prefix of the substring
  // s[0..i] which is also a suffix of this substring.
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i-1];
    while (j > 0 and s[i] != s[j])
      j = pi[j-1];
    if (s[i] == s[j])
      j++;
    pi[i] = j;
  }
  return pi;
}
int K = 26;
inline int getID(char c){
  return c-'a';
}
vector<vector<int>> computeAutomaton(string s) {
  s += '#';
  int n = s.size();
  vector<int> pi = kmp(s);
  vector<vector<int>> aut(n, vector<int>(26));
  for(int i = 0; i < n; i++){
    for(int c = 0; c < K; c++){
      if(i > 0 and c != getID(s[i]))
        aut[i][c] = aut[pi[i-1]][c];
      else
        aut[i][c] = i + (c == getID(s[i]));
    }
  }
  return aut;
}
