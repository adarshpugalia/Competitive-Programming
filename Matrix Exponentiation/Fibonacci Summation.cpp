/*
 * Author:	Adarsh Pugalia
 * Problem:	Summation(F(i)(K^i)) for 1 to n, given n and K.
 * Link:	https://www.codechef.com/problems/FIBEQN
 */
#include <bits/stdc++.h>

/* Data types and structures. */
#define ll long long int
#define llu long long int unsigned
#define vi vector <int>
#define vl vector <ll> 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector <pii >
#define vpll vector <pll >
 
/* Data structure helpers. */ 
#define f first
#define s second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define sz(n) (int)n.size()-1
#define all(n) n.begin(), n.end()
#define has(it,s) if(it!=s.end())
 
/* Input output defines. */
#define sd(n) scanf("%d", &n)
#define sl(n) scanf("%lld", &n)
#define slf(n) scanf("%lf", &n) 
#define pd(n) printf("%d", n);
#define pl(n) printf("%lld", n);
#define plf(n) printf("%0.9lf", n);
#define ps printf(" ")
#define pe printf("\n")

/* loops */
#define rep(i,j,k) for(int i=j; i<=k; i++)
#define repd(i,j,k) for(int i=j; i>=k; i--)
#define iter(it, s) for(auto it=s.begin(); it!=s.end(); it++)

/* constraints. */ 
#define max_size 5
#define max_sieve_size 1000005
#define max_matrix_size 100
#define max_log 17
#define INF 1000000000000000000
#define MOD 1000000007
#define EPS 0.0000000001
#define GCD_EPS 0.0001
#define PI 3.14159265358979323846
#define mod(a) ((a)%MOD)

#define bcnt __builtin_popcount 

ll ciel(double a) { ll ret = a; if(a-ret>EPS) ret++; return ret; }
ll gcd(ll a, ll b) { if(a<b)return gcd(b, a); if(a%b==0)return b; return gcd(b, a%b); }
ll pow(ll n, ll p) {if(p==0)return 1; if(n<=1)return n;ll res = 1;while(p){if(p&1) res = mod(res*n);n = mod(n*n);p /= 2;} return res;}

double fgcd(double a, double b) { if(fabs(a)<fabs(b)) return fgcd(b, a); if(fabs(b)<GCD_EPS) return a; return fgcd(b, fmod(a,b)); }

bool db_db_cmp(double a, double b) { return (a+EPS>b && a-EPS<b); }
bool db_ll_cmp(double a, ll b) { bool ret = (a+EPS>b && a-EPS<b); if(ret) return ret; b++; return (a+EPS>b && a-EPS<b); }
 
using namespace std;

/*
 * This class defines the matrix object. Initialize the matrix
 * with the number of rows and columns.
 *
 * The available operations are:
 * get_identity	: converts the current matrix into identity matrix.
 * a*b 			: multiplies two matrices (assuming they can be multiplied).
 * pow			: exponentiates the matrix.
 *
 * NOTE: The matrix performs modular arithmetic.
 */
class Matrix {
	public:
		int rows, cols;
		ll mat[max_size][max_size];

		/* This is the default constructor. */
		Matrix() {}


		/*
		 * This is the parameterised constructor which takes
		 * rows and columns as the parameter and initializes all values
		 * to 0.
		 *
		 * NOTE: It initializes the matrix as [0...rows][0....cols]
		 */
		Matrix(int n, int m) { rows = n, cols = m; rep(i,0,n) rep(j,0,m) mat[i][j] = 0; }


		/* This sets the matrix to be identity matrix. */
		void set_identity() { rep(i,0,rows) { rep(j,0,cols) { if(i==j) { mat[i][j] = 1; } else { mat[i][j] = 0;} } } }


		/* 
		 * This method overloads the * (product) operator for matrices.
		 *
		 * NOTE: The method assumes that the matrices can be multiplied.
		 */
		Matrix operator *(const Matrix& a) {
			Matrix temp(rows, cols);
			rep(i,0,rows) rep(j,0,a.cols) rep(k,0,cols) temp[i][j] = mod(temp[i][j] + mod(mat[i][k]*a.mat[k][j]));
			return temp;
		}


		/* This method exponentiates the matrix. */
		Matrix pow(ll p) { 
			Matrix res(rows,cols); res.set_identity();
			while(p) { if(p&1) res = res*(*this); *this = (*this)*(*this); p /= 2; }
			return res;
		}

		
		/* This overloads the subscript operator for easier access. */
		ll* operator[](int index) { return mat[index]; }
}mat;


void preprocess() {
}

void init() {
}

void solve(int test_case) {
	init();

	ll n, k;
	sl(n); sl(k);
	ll ans;

	Matrix mat2 = Matrix(3, 1);

	if(n<2) {
		if(n==1)
			ans = mod(k);
		else
			ans = 0;
	}
	else {
		mat = Matrix(3, 3);
		mat[0][0] = 1, mat[0][1] = mod(k), mat[0][2] = mod(mod(k)*mod(k));
		mat[1][0] = 0, mat[1][1] = mod(k), mat[1][2] = mod(mod(k)*mod(k));
		mat[2][0] = 0, mat[2][1] = 1, mat[2][2] = 0;

		mat = mat.pow(n-1);
		mat2[0][0] = mod(k), mat2[1][0] = mod(k), mat2[2][0] = 0;

		mat2 = mat*mat2;
		ans = mat2[0][0];
	}

	printf("%lld\n", ans);
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
