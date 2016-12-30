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
#define pq priority_queue
 
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
#define max_size 100005
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

using namespace std;

/*
 * This class implements the union find algorithm.
 * The algorithm has an amortized log(n) complexity per query.
 *
 * NOTE: The array is 1-indexed.
 */ 
class UnionFind {
	static const int MAX_SIZE = 66;

	public:
		/*
		 * @data n: the size of the array/nodes.
		 * @data parent: stores the parent of each node.
		 * @data rank: stores the number of nodes in the component rooted at a given node.
		 * @data num_components: current number of components.	
		 */
		int n, parent[MAX_SIZE], rank[MAX_SIZE], num_components;


		/*
		 * This method initialized the structure.
		 * It sets the size of the array, sets each node as its parent and the rank as 1.
		 * Also, sets the number of components as the size of the array.
		 */
		void init(int n_) {
			n = n_;
			rep(i,1,n) { parent[i] = i; rank[i] = 1; }
			num_components = n;
		}


		/*
		 * This method finds the root for the component for the current node.
		 * @path node: the node whose root is to be found.
		 */
		int find(int node) {
			if(parent[node] != node) {
				parent[node] = find(parent[node]);
			}

			return parent[node];
		}


		/*
		 * This method merges two components.
		 * @param node_x: node from one of the components.
		 * @param node_y: node from the other component.
		 * return bool: return a boolean denoting whether actual merging took place
		 *				or not. returns false if both the nodes where in the same
		 *				component initially.
		 */
		bool merge(int node_x, int node_y) {
			int parent_x = find(node_x);
			int parent_y = find(node_y);

			if(parent_x == parent_y)
				return false;

			if(rank[parent_x] > rank[parent_y]) {
				merge(node_y, node_x);
				return true;
			}

			parent[parent_x] = parent_y;
			rank[parent_y] += rank[parent_x];
			num_components--;
			return true;
		}


		/* This method copies the union find structure from another object. */
		void copy(UnionFind union_find) {
			n = union_find.n;
			rep(i,1,n) {
				parent[i] = union_find.parent[i];
				rank[i] = union_find.rank[i];
				num_components = union_find.num_components;
			}
		}
}uf;

int main() {
	return 0;
}