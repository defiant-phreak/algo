
class ufs{
	public:
	vector<int> link;
	vector<int> size;
	int n;
	// Caution : 0 indexed
	ufs(int _n) : n(_n){
		link.resize(n);
		for(int i=0; i < n; i++) link[i] = i;
		size.resize(n,1);
	}
	inline int find(int x){
		while(x != link[x]){
			link[x] = link[link[x]];
			x = link[x];
		}
		return x;
	}
	inline void unite(int a, int b){
		a = find(a);
		b = find(b);
		if(size[a] < size[b]) swap(a, b);
		size[a] += size[b];
		link[b] = a;
	}
};
