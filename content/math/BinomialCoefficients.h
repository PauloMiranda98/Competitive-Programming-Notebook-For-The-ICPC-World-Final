/**
 * Author: Paulo Miranda
 * Date: 2020-09-31
 * License: Free
 * Description:
 * Time:
 */
#include <bits/stdc++.h>
#include "./basic_math.h"
#include "./modular.h"
using namespace std;
typedef long long ll;

//O(P*log(P))
//C4(n, k, p) = Comb(n, k)%p
vector<int> changeBase(int n, int p){
  vector<int> v;
  while (n > 0){
    v.push_back(n % p);
    n /= p;
  }
  return v;
}
int C4(int n, int k, int p){
  auto vn = changeBase(n, p);
  auto vk = changeBase(k, p);
  int mx = max(vn.size(), vk.size());
  vn.resize(mx, 0);
  vk.resize(mx, 0);
  prevC3(p - 1, p);
  int ans = 1;
  for (int i = 0; i < mx; i++)
    ans = (ans * 1LL * C3(vn[i], vk[i], p)) % p;
  return ans;
}
//O(P^k)
//C5(n, k, p, pk) = Comb(n, k)%(p^k)
int fat_p(ll n, int p, int pk){
	vector<int> fat1(pk, 1);
    int res = 1;
    for(int i=1; i<pk; i++){
		if(i%p == 0)
			fat1[i] = fat1[i-1];
		else
			fat1[i] = (fat1[i-1]*1LL*i)%pk;
	}
	while(n > 1){
		res = (res*1LL*fastPow(fat1[pk-1], n/pk, pk))%pk;
		res = (res*1LL*fat1[n%pk])%pk;
		n /= p;
	}
	return res;
}
ll cnt(ll n, int p){
	ll ans = 0;
	while(n > 1){
		ans += n/p;
		n/=p;
	}
	return ans;
}
int C5(ll n, ll k, int p, int pk){
	ll exp = cnt(n, p) - cnt(n-k, p) - cnt(k, p);
	int d = (fat_p(n-k, p, pk)*1LL*fat_p(k, p, pk))%pk;
	int ans = (fat_p(n, p, pk)*1LL*inv(d, pk))%pk;
	return (ans*1LL*fastPow(p, exp, pk))%pk;
}
