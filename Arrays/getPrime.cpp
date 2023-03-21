vector<bool> getPrime(ll val) {
    vector<bool> sieve((ll)val + 1, 1);
    for(int i=2;i<=val;i+=2) sieve[i] = 0;
    for(int i=3;i<=sqrt(val); i++) {
        for(int j=i*i; j<= val; j+=i) sieve[j] = 0;
    }
    return sieve;
}