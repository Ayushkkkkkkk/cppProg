#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
//using namespace chrono;



//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
template <typename T = int>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



#define fastio() ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define set_bits __builtin_popcountll
#define lower(s1) transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
#define upper(s1) transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define vt vector
#define decimal cout << fixed << setprecision(15) ;

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;


void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(unordered_set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T> void _print(multiset <T> v);


template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}


template<class T> bool umin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template<class T> bool umax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

string to_string(char c) {
	return string(1, c);
}
string to_string(bool b) {
	return b ? "true" : "false";
}
string to_string(const char* s) {
	return string(s);
}
string to_string(string s) {
	return s;
}
string to_string(vt<bool> v) {
	string res;
	FOR(sz(v))
	res += char('0' + v[i]);
	return res;
}

template<size_t S> string to_string(bitset<S> b) {
	string res;
	FOR(S)
	res += char('0' + b[i]);
	return res;
}
template<class T> string to_string(T v) {
	bool f = 1;
	string res;
	EACH(x, v) {
		if (!f)
			res += ' ';
		f = 0;
		res += to_string(x);
	}
	return res;
}


ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while (lb < rb) {
		ll mb = (lb + rb) / 2;
		f(mb) ? rb = mb : lb = mb + 1;
	}
	return lb;
}
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
	while (lb < rb) {
		ll mb = (lb + rb + 1) / 2;
		f(mb) ? lb = mb : rb = mb - 1;
	}
	return lb;
}


void solve() {
	ll n ; cin >> n ;
	ll a[n] ; for (int i = 0 ; i < n ; i++) cin >> a[i];
	ll bit[30]; for (int i = 0 ; i < 30; i++) bit[i] = 0;
	for (ll i = 0 ; i < 30 ; i++){
		ll num = (1LL << i);
		for (ll j = 0 ; j < n ; j++){
			if((a[j] & num)!=0) bit[i]++;
		}
	}
	for (ll k = 1 ; k <= n ; k++){
		bool flag = 0;
		for (ll i = 0 ; i < 30 ; i++){
			if((bit[i] % k) != 0){
				flag = 1;
				break;
			}
		}
		if(flag == 0) cout << k << " ";
	}
	cout << nline;
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}












