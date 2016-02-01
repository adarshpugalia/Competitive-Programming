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
#define max_size 102
#define max_sieve_size 1000005
#define max_log 17
#define INF 1000000000000000000
#define MOD 1000000007
#define EPS 0.00000001
#define mod(a) ((a)%MOD)
 
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
 * NOTE: The matrix does not perform modular arithmetic. For mod, use the 
 * Long class, and change the type of mat[][] to Long.
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
		void get_identity() { rep(i,0,rows) { rep(j,0,cols) { if(i==j) { mat[i][j] = 1; } else { mat[i][j] = 0;} } } }


		/* 
		 * This method overloads the * (product) operator for matrices.
		 *
		 * NOTE: The method assumes that the matrices can be multiplied.
		 */
		Matrix operator *(const Matrix& a) {
			Matrix temp(rows, cols);
			rep(i,0,rows) rep(j,0,a.cols) rep(k,0,cols) temp.mat[i][j] = temp.mat[i][j] + mat[i][k]*a.mat[k][j];
			return temp;
		}


		/* This method exponentiates the matrix. */
		void pow(ll p) { 
			Matrix res(rows,cols); res.get_identity();
			while(p) { if(p&1) res = res*(*this); *this = (*this)*(*this); p /= 2; }
			*this = res;
		}
};

int main() {
	return 0;
}