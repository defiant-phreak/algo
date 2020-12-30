
bool next_combination(vector<int> &a,int k,int n){
	for(int i=k-1; i>=0; i--){
		if(a[i]<=n-k+i){
			a[i]++;
			for(int j=i+1; j<k; j++) a[j]=a[j-1]+1;
			return true;
		}
	}
	return false;
}

