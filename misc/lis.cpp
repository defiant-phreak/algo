
template <typename T>
int lis(const vector<T> &a){
	vector<T> v;
	for(const T &x : a){
		if(v.empty() || x > *(v.end()-1))
			v.push_back(x);
		else{
			auto it = lower_bound(v.begin(), v.end(), x);
			*it = x;
		}
	}
	return (int) v.size();
}

