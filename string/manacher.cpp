
template <typename T>
vector<int> manacher(const T &s, int n = -1){
	if(n <= 0) {
		n = s.size();
		if(n <= 0) return vector<int>();
	}
	vector<int> res((n << 1) - 1, 0);
	int l = -1, r = -1;
	for (int k = 0; k < (n << 1) -1; k++){
		int i = (k+1) >> 1;
		int j = k >> 1;
		int p = (i >= r ? 0 : min(r-i, res[((l+r) << 1) -k]));
		while (j+p+1 < n && i-p >= 1){
			if(s[j+p+1] != s[i-p-1]) break;
			p++;
		}
		res[k] = p;
		if(j+p > r) l = i-p, r = i+p;
	}
	// Check if res[x] is not equal to 0
	// Calculate i = (x+1) >> 1 and j = x >> 1
	// Palindrome from i-res[x] to j+res[x]
	// Note: If i > j, that is a even length palindrome
	return res;
}

