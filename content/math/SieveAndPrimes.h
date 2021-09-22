/**
 * Author: Paulo Miranda
 * Date: 2020-09-31
 * License: Free
 * Description:
 * Time:
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mobius[1000010];
void sieveMobius(ll l) {
  sieve(l);
  mobius[1] = 1;
  for(int i=2; i<=l; i++)
    mobius[i] = 0;
  for(ll p: primes){
    if(p > l) break;
    for(ll j = p; j <= l; j += p){
      if(mobius[j] != -1){
        mobius[j]++;
        if(j%(p*p) == 0)
          mobius[j] = -1;
      }
    }
  }
  for(int i=2; i<=l; i++){
    if(mobius[i] == -1)
      mobius[i] = 0;
    else if(mobius[i]%2 == 0)
      mobius[i] = 1;
    else
      mobius[i] = -1;
  }
}
