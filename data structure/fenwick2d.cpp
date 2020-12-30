
template <typename T>
class fenwick2d {
	public:
	vector<vector<T>> tree;
	int n, m;
	fenwick2d(vector<vector<T>> &v, int _n = -1, int _m = -1) : n(_n), m(_m){
		n = v.size();
		m = v[0].size();
		tree.resize(n);
		for(int i = 0; i < n; i++)
			tree[i].resize(m);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
					add(i, j, v[i][j]);
	}
	T sum(int k, int r){
		T s{};
		while(k >= 0){
			int l = r;
			while(l >= 0){
				s += tree[k][l];
				l = (l & (l+1)) -1;
			}
			k = (k & (k+1)) -1;
		}
		return s;
	}
	void add(int k, int r, T x){
		while (k < n){
			int l = r;
			while (l < m){
				tree[k][l] += x;
				l |= (l+1);
			}
			k |= (k+1);
		}
	}
	// Sum from upper-left(a, b) to lower-right(c, d)
	T sum_rge(int a, int b, int c, int d){
		return sum(c, d) + sum(a-1, b-1) - sum(c, b-1) - sum(a-1, d);
	}
};

