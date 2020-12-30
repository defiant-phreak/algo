
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
	#ifdef LOCAL
		~debug() { cerr << endl; }
		eni(!=) cerr << boolalpha << i; ris; }
		eni(==) ris << range(begin(i), end(i)); }
		sim, class b dor(pair < b, c > d) {
		  ris << "(" << d.fi << ", " << d.se << ")";
		}
		template <class... b dor(tuple<b...> d){
			apply( 
				[&](auto const&... ps) { 
					*this << "("; 
					int k=0; 
					((*this << ", "+2*(0==k++) << ps ), ...);
				},
			d);
			ris << ")";
		}
		sim dor(rge<c> d) {
			*this << "[";
			for (auto it = d.b; it != d.e; ++it) 
				*this << ", " + 2 * (it == d.b) << *it;
			ris << "]";
		}
	#else
		sim dor(const c&) { ris; }
	#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
