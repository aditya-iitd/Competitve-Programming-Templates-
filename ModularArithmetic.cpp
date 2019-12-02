#include <bits/stdc++.h>
using namespace std;

const int mod = (int)1e9 + 7;

// MODULAR ARITHMETIC
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1LL * y) % mod;}
inline int binpow(int a, int b){
    int x = 1 % mod;
    while(b){
        if(b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline int inv(int a){ return binpow(a, mod - 2);}
