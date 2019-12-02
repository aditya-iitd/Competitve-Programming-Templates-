/*
    Created By - Aditya Singh
 */
#include <bits/stdc++.h>
using namespace std;

const int mod = (int) 1e9 + 7;

/*   Matrix Exponentiation   */;
using Matrix = vector<vector<int>>;

Matrix multiply(Matrix A , Matrix B) {
    int nA = A.size() , mA = A[0].size();
    int nB = B.size() , mB = B[0].size();
    assert(mA == nB);
    Matrix C(nA , vector<int>(mB));
    for(int i = 0; i < nA; i++) {
        for(int j = 0; j < mB; j++) {
            for(int k = 0; k < mA; k++) {
                C[i][j] += A[i][k] * B[k][j] % mod;
                C[i][j] %= mod;
            }
        }
    }
    return C;
}

/* b-th Power of Matrix A */
Matrix binpow(Matrix A , int b) {
    int n = (int) A.size();
    Matrix ret(n , vector<int>(n));
    for(int i = 0; i < n; i++) {
        ret[i][i] = 1;
    }
    while(b) {
        if(b & 1) {
            ret = multiply(ret , A);
        }
        A = multiply(A , A);
        b >>= 1;
    }
    return ret;
}

/* Solve Linear Recurrence using Matrix Exponentiation */
/* Note : Base is f(1) not f(0) [This calculates from f(1) : calculate f(0) by hand] */
int solveLinearRecurrence(vector<int> scheme , int n) {
    // if f(n) = f(n - 1) + 2f(n - 2) + 3f(n - 3)... then : scheme = {1 , 2 , 3 ,...}
    int k = (int) scheme.size();
    Matrix current(k , vector<int>(k));
    for(int j = 0; j < k; j++) {
        current[k - 1][j] = scheme[k - 1 - j];
    }
    for(int i = 0; i < k - 1; i++) {
        current[i][i + 1] = 1;
    }
    
    Matrix nxt = binpow(current , n);
    assert((int) nxt.size() > 0 and (int) nxt[0].size() > 0);
    return nxt[k - 1][k - 1];
}

signed main() {
    fio;
    int n; cin >> n;
    vector<int> scheme{1 , 1 , 1 , 1 , 1 , 1};
    
    cout << solveLinearRecurrence(scheme , n) << endl;
    
    return 0;
}
