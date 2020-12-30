
// Usage example : sparsetab<int> st(v, [&](int i, int j) { return min(i, j); });
template <typename T, class F = function<T(const T&, const T&)>>
class sparsetab {
	public:
	int n;
	vector<vector<T>> mat;
	F fun;

	sparsetab(const vector<T> &a, const F &f) : fun(f){
		n = a.size();
		int logn = 32 - __builtin_clz(n);
		mat.resize(logn);
		mat[0] = a;
		for(int j = 1; j < logn; j++) {
			mat[j].resize(n - (1 << j) + 1);
			for (int i = 0; i <= n- (1 << j); i++)
				mat[j][i] = fun(mat[j-1][i], mat[j-1][i + (1 << (j-1))]);
		}
	}
	T get(int from, int to){
		int lg = 32 - __builtin_clz(to-from+1) - 1;
		return fun(mat[lg][from], mat[lg][to - (1 << lg) +1]);
	}
};

