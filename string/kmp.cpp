
template <typename T>
vector<int> kmp_list(const T &s){
	int n = s.size();
	vector<int> lps(n, 0);
	for(int i = 1; i < n; i++){
		int j = lps[i-1];
		while(j > 0 && s[i] != s[j])
			j = lps[j-1];
		if(s[i]==s[j]) j++;
		lps[i] = j;
	}
	return lps;
}
template <typename T>
vector<int> kmp_search(const T &s, const T &p, vector<int> &lps){
	int n = s.size();
	int m = p.size();
	vector<int> res;
	assert(n >= 1 && (int)lps.size() == n);
	int j = 0;
	for(int i = 0; i < m; i++){
		while(j > 0 && (j == n || p[i] != s[j]))
			j = lps[j-1];
		if(p[i] == s[j]) j++;
		if(j == n) res.push_back(i-n+1);
	}
	return res;
}
// Usage: kmp_search(pattern, text)
template <typename T>
vector<int> kmp_search(const T &s, const T &p){
	vector<int> lps = kmp_list(s);
	return kmp_search(s, p, lps);
}

