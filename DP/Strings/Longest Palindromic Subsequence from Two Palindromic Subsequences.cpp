/*
 * Author: Adarsh Pugalia
 * Problem: Longest palindromic subsequence from two palindromic subsequences.
 * Link: https://www.hackerrank.com/contests/codeagon/challenges/jesse-and-two-strings-
 */
#include <bits/stdc++.h>
 
#define ll long long int
#define llu long long int unsigned
#define vi vector <int>
#define vl vector <ll> 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector <pii >
#define vpll vector <pll >
 
 
#define f first
#define s second
 
#define sd(n) scanf("%d", &n)
#define sl(n) scanf("%lld", &n)
#define slf(n) scanf("%lf", &n)
 
#define pd(n) printf("%d", n);
#define pl(n) printf("%lld", n);
#define ps printf(" ")
#define pe printf("\n")
 
#define rep(i,j,k) for(int i=j; i<=k; i++)
#define repd(i,j,k) for(int i=j; i>=k; i--)
 
#define sz(n) (int)n.size()-1
#define all(n) n.begin(), n.end()
 
#define pb push_back
#define pob pop_back
#define mp make_pair
 
#define max_size 3005
#define max_sieve_size 1000005
#define max_log 17
 
#define INF 1000000000000000000
#define MOD 1000000007
#define EPS 0.00000001
 
#define mod(a) ((a)%MOD)
#define swap(a, b) a += b, b = a-b, a -= b
 
using namespace std;

void preprocess() {

}

/* variables for the original strings. */
string a, b;

/*
 * lpsa, lpsb stores the longest palindromic subsequence from individual strings.
 * alpha, tempa, tempb is used to see for a middle element if lps from the individual
 * strings are both odd. 
 */
int lpsa[max_size][max_size], lpsb[max_size][max_size];
int alpha[26][2];
int tempa[max_size][max_size], tempb[max_size][max_size];


/* This method computes the lps of first string. */
int get_lpsa(int start, int end) {
	if(end<start)
		return 0;

	if(end==start)
		return 1;

	if(lpsa[start][end]!=-1)
		return lpsa[start][end];

	int ret = 0;
	if(a[start]==a[end])
		ret = 2 + get_lpsa(start+1, end-1);

	ret = max(ret, get_lpsa(start+1, end));
	ret = max(ret, get_lpsa(start, end-1));

	lpsa[start][end] = ret;
	return ret;
}


/* This method computes the lps of second string. */
int get_lpsb(int start, int end) {
	if(end<start)
		return 0;

	if(end==start)
		return 1;

	if(lpsb[start][end]!=-1)
		return lpsb[start][end];

	int ret = 0;
	if(b[start]==b[end])
		ret = 2 + get_lpsb(start+1, end-1);

	ret = max(ret, get_lpsb(start+1, end));
	ret = max(ret, get_lpsb(start, end-1));

	lpsb[start][end] = ret;
	return ret;
}


/* This method checks for middle elements for lps of first string. */
void checka(int start, int end, int val) {
	if(end<start)
		return;

	if(end==start) {
		if(val==1)
			alpha[a[start]-'a'][0]++;
	
		return;
	}

	if(tempa[start][end])
		return;

	tempa[start][end] = 1;
	if(a[start]==a[end])
		checka(start+1, end-1, val-2);

	if(get_lpsa(start+1, end)==val)
		checka(start+1, end, val);

	if(get_lpsa(start, end-1)==val)
		checka(start, end-1, val);
}


/* This method checks for middle elements for lps of second string. */
void checkb(int start, int end, int val) {
	if(end<start)
		return;

	if(end==start) {
		if(val==1)
			alpha[b[start]-'a'][1]++;
		return;
	}

	if(tempb[start][end])
		return;

	tempb[start][end] = 1;
	if(b[start]==b[end])
		checkb(start+1, end-1, val-2);

	if(get_lpsb(start+1, end)==val)
		checkb(start+1, end, val);

	if(get_lpsb(start, end-1)==val)
		checkb(start, end-1, val);
}


void init() {

}


void solve(int test_case) {
	init();

	cin>>a>>b;
	memset(lpsa, -1, sizeof(lpsa));
	memset(lpsb, -1, sizeof(lpsb));

	/* calculating the lps of both strings. */
	int la = get_lpsa(0, a.length()-1);
	int lb = get_lpsb(0, b.length()-1);

	/*
	 * if both lps are odd, we need to check if their exists middle elements
	 * from both lps that are equal. If so happens, the ans is la+lb, else
	 * la+lb-1.
	 */
	if((la&1) && (lb&1)) {
		memset(tempa, 0, sizeof(tempa));
		memset(tempb, 0, sizeof(tempb));
		memset(alpha, 0, sizeof(alpha));

		checka(0, a.length()-1, la);
		checkb(0, b.length()-1, lb);

		int diff = 1;
		for(int i=0; i<26; i++) {
			if(alpha[i][0] && alpha[i][1]) {
				diff = 0;
				break;
			}
		}

		cout<<la+lb-diff<<endl;
	}
	else {
		cout<<la+lb<<endl;
	}
}


int main() {
	preprocess();
	int t = 1;
	sd(t);
 
	rep(i,1,t) {
		solve(i);
	}
	return 0;
}
