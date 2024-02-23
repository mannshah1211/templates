#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define pb push_back

const int MOD = 1e9 + 7;

struct Mint {
	int val;
	Mint() {
		
	}
	Mint(int _val) {
		val = _val;
		val %= MOD;
	}
};

void operator+=(Mint& x, Mint y) {
	x.val += y.val, x.val %= MOD;
	assert(0 <= x.val && x.val < MOD);
}

Mint operator+(Mint x, Mint y) {
	Mint ret(x.val + y.val);
	assert(0 <= ret.val && ret.val < MOD);
	return ret;
}

void operator-=(Mint& x, Mint y) {
	x.val -= y.val, x.val += MOD, x.val %= MOD;
	assert(0 <= x.val && x.val < MOD);
}

Mint operator-(Mint x, Mint y) {
	Mint ret(x.val - y.val + MOD);
	assert(0 <= ret.val && ret.val < MOD);
	return ret;
}

void operator*=(Mint& x, Mint y) {
	x.val *= y.val, x.val %= MOD;
	assert(0 <= x.val && x.val < MOD);
}

Mint operator*(Mint x, Mint y) {
	Mint ret(x.val * y.val);
	assert(0 <= ret.val && ret.val < MOD);
	return ret;
}

Mint mpow(Mint a, int b) {
	Mint res = 1;
	while (b) {
		if (b & 1) {
			res *= a;
		}
		a = a * a;
		b >>= 1;
	}
	assert(0 <= res.val && res.val < MOD);
	return res;
}

void operator/=(Mint& x, Mint y) {
	x *= mpow(y.val, MOD - 2), x.val %= MOD;
	assert(0 <= x.val && x.val < MOD);
}

Mint operator/(Mint x, Mint y) {
	Mint ret(mpow(y.val, MOD - 2).val * x.val);
	assert(0 <= ret.val && ret.val < MOD);
	return ret;
}

void operator+=(Mint& x, int y) {
	y %= MOD;
	x.val += y, x.val %= MOD;
	assert(0 <= x.val && x.val < MOD);
}

Mint operator+(Mint x, int y) {
	y %= MOD;
	Mint ret(x.val + y);
	assert(0 <= ret.val && ret.val < MOD);
	return ret;
}

void operator-=(Mint& x, int y) {
	y %= MOD;
	x.val -= y, x.val += MOD, x.val %= MOD;
	assert(0 <= x.val && x.val < MOD);
}

Mint operator-(Mint x, int y) {
	y %= MOD;
	Mint ret(x.val - y + MOD);
	assert(0 <= ret.val && ret.val < MOD);
	return ret;
}

void operator*=(Mint& x, int y) {
	y %= MOD;
	x.val *= y, x.val %= MOD;
	assert(0 <= x.val && x.val < MOD);
}

Mint operator*(Mint x, int y) {
	y %= MOD;
	Mint ret(x.val * y);
	assert(0 <= ret.val && ret.val < MOD);
	return ret;
}

Mint mpow(int a, int b) {
	Mint res = 1;
	while (b) {
		if (b & 1) {
			res *= a;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

void operator/=(Mint& x, int y) {
	y %= MOD;
	x *= mpow(y, MOD - 2);
	assert(0 <= x.val && x.val < MOD);
}

Mint operator/(Mint x, int y) {
	y %= MOD;
	Mint ret(x.val * mpow(y, MOD - 2));
	assert(0 <= ret.val && ret.val < MOD);
	return ret;
}

void operator+=(int& x, Mint y) {
	x += y.val, x %= MOD;
	assert(0 <= x && x < MOD);
}

Mint operator+(int x, Mint y) {
	Mint ret(x + y.val);
	assert(0 <= ret.val && ret.val < MOD);
	return ret;
}

void operator-=(int& x, Mint y) {
	x -= y.val, x %= MOD, x += MOD, x %= MOD;
	assert(0 <= x && x < MOD);
}

Mint operator-(int x, Mint y) {
	Mint ret(x - y.val + MOD);
	assert(0 <= ret.val && ret.val < MOD);
	return ret;
}

void operator*=(int& x, Mint y) {
	x *= y.val, x %= MOD;
	assert(0 <= x && x < MOD);
}

Mint operator*(int x, Mint y) {
	Mint ret(x * y.val);
	assert(0 <= ret.val && ret.val < MOD);
	return ret;
}

void operator/=(int& x, Mint y) {
  x *= mpow(y, MOD - 2).val, x %= MOD;
	assert(0 <= x && x < MOD);
}

Mint operator/(int x, Mint y) {
	Mint ret(x * mpow(y, MOD - 2).val);
	assert(0 <= ret.val && ret.val < MOD);
	return ret;
}

ostream& operator<<(ostream& out, Mint a) {
	out << a.val;
	return out;
}

istream& operator>>(istream& in, Mint& a) {
	in >> a.val;
	return in;
}

vector<Mint> facs;

void precalc(int mx) {
	Mint prv = 1;
	facs.pb(prv);
	for (int i = 1; i <= mx; i++) {
		prv *= i;
		facs.pb(prv);
	}
}

Mint bin(int n, int r) {
	if (n < r) return Mint(0);
	if (n < facs.size()) {
		Mint num = facs[n], denom = facs[r] * facs[n - r];
		return num / denom;
	}
	Mint res = 1;
	if (r >= n - r) {
		r = n - r;
	}
	for (int i = n; i >= n - r + 1; i--) res *= i;
	Mint denom = 1;
	if (r < facs.size()) denom = facs[r];
	else {
		for (int i = 1; i <= r; i++) denom *= i;
	}
	return res / denom;
}

void solve() {
	
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int tt = 1;
	cin >> tt;
	while (tt--) {
		solve();
	}
}

/*
 * Never call Mint(int, int), as it doesn't exist (except bin).
 * Remember to change the modulo at the top!
 * Remember to actually precalc if you want it precalculated.
 */
