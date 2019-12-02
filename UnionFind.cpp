/*
    Created By - Aditya Singh
 */
#include <bits/stdc++.h>
using namespace std;

struct dsu {
    int n;
    vector<int> parent;
    vector<int> size;
    int components = 0;
    
    dsu(int n) : n(n) {
        parent.resize(n);
        size.assign(n , 1);
        components = n;
        iota(parent.begin() , parent.end() , 0LL);
    }
    
    int get(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        components--;
        return true;
    }
};
