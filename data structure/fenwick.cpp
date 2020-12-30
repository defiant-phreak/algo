
template <typename T>
class fenwick {
	public:
	vector<T> tree;
	int n;
	fenwick(vector<T> &v, int _n = -1) : n(_n){
		if(n < 0) n = v.size();
		tree.resize(n);
		for(int i = 0; i < n; i++){
			add(i, v[i]);
		}
	}
	T sum(int k){
		T s{};
		while(k >= 0){
			s += tree[k];
			k = (k & (k+1)) -1;
		}
		return s;
	}
	void add(int k, T x){
		while (k < n){
			tree[k] += x;
			k |= (k+1);
		}
	}
	// Sum range
	T sum_rge(int i, int j){
		return sum(j) - sum(i-1);
	}
	// Search for a sum, returns index
	int search_sum(T v){
		T sum = 0;
		int pos = 0, i = 0;
		while((1 << i) <= n) i++;
		for(; i >= 0; i--){
			if((pos + (1 << i) < n) && ((sum + tree[pos+(1 << i)-1]) < v)){
				sum += tree[pos+(1 << i)-1];
				pos += (1 << i);
			}
		}
		return pos;
	}
};

