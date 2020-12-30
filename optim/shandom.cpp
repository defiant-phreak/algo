
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myrand(ll B) {return (ull)rng()%B;}
#define ruffle(x) random_shuffle(all(x),myrand)


