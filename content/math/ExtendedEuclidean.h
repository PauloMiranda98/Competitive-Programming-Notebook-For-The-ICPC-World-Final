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
ll extGcd(ll a, ll b, ll &x, ll &y){
	if (b == 0){
		x = 1, y = 0;
		return a;
	}else{
		ll g = extGcd(b, a % b, y, x);
		y -= (a / b) * x;
		return g;
	}
}
//a*x + b*y = g
//a*(x-(b/g)*k) + b*(y+(a/g)*k) = g
bool dioEq(ll a, ll b, ll c, ll &x0, ll &y0, ll &g){
	g = extGcd(abs(a), abs(b), x0, y0);
	if (c % g) return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0) x0 = -x0;
	if (b < 0) y0 = -y0;
	return true;
}
