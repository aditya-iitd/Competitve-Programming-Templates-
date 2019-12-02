
/*
 Created By - Aditya Singh
 */
#include <bits/stdc++.h>
using namespace std;

int n , q;

/* 3-Dimensional Fenwick Tree */
struct Fenwick3D {
    int n;
    vector<vector<vector<int>>> bit;
    
    Fenwick3D(int _n) : n(_n) {
        bit.assign(n + 1 , vector<vector<int>>(n + 1 , vector<int>(n + 1 , 0LL)));
    }
    // point updates
    void add(int a , int b , int c , int delta){
        for(int i = a; i <= n; i += i & -i){
            for(int j = b; j <= n; j += j & -j){
                for(int k = c; k <= n; k += k & -k){
                    bit[i][j][k] += delta;
                }
            }
        }
    }
    
    // range query
    int get(int a , int b , int c){
        int ret = 0;
        for(int i = a; i > 0; i -= i & -i){
            for(int j = b; j > 0; j -= j & -j){
                for(int k = c; k > 0; k -= k & -k){
                    ret += bit[i][j][k];
                }
            }
        }
        return ret;
    }
    
    int get(int x1 , int y1 , int z1 , int x2 , int y2 , int z2){
        int ret = get(x2 , y2 , z2);
        ret -= get(x2 , y1 - 1 , z2);
        ret -= get(x1 - 1 , y2 , z2);
        ret += get(x1 - 1 , y1 - 1 , z2);
        ret -= get(x2 , y2 , z1 - 1);
        ret += get(x1 - 1 , y2 , z1 - 1);
        ret += get(x2 , y1 - 1 , z1 - 1);
        ret -= get(x1 - 1 , y1 - 1 , z1 - 1);
        return ret;
    }
};

signed main() {
    cin >> n;
    Fenwick3D ft(n);
    while(true){
        int type; cin >> type;
        if(type == 1){
            int x , y , z , delta; cin >> x >> y >> z >> delta;
            ft.add(x + 1 , y + 1 , z + 1 , delta);
        } else if(type == 2) {
            int x1 , y1 , z1 , x2 , y2 , z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            cout << ft.get(x1 + 1 , y1 + 1 , z1 + 1 , x2 + 1 , y2 + 1 , z2 + 1) << endl;
        } else {
            return 0;
        }
    }
    
    
    return 0;
    
}


