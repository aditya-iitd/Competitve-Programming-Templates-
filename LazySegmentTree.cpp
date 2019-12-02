
/*
 Created By - Aditya Singh
 */
#include <bits/stdc++.h>
using namespace std;

/* Segment Tree with Lazy Propagation */
template <typename T>
class Segtree {
public:
    struct node_t {
        T sumv;
        node_t() {
            sumv = (T) 0;
        };
        node_t(T value) {
            sumv = value;
        }
        
        void operator+= (const T other) {
            sumv += other;
        }
        
        friend ostream& operator<<(ostream &os , const node_t node) {
            return os << "[ " << node.sumv << " ]";
        }
    };
    
    int n;
    vector<node_t> t;
    vector<T> lazy;
    const int INF = (int) 1e9 + 7;
    node_t defaultValue = { (T) 0 };
    Segtree(int n) : n(n) {
        t.resize(4 * n);
        lazy.resize(4 * n);
    }
    
    node_t merge(node_t left , node_t right) {
        node_t mergedNode;
        mergedNode.sumv = left.sumv + right.sumv;
        return mergedNode;
    }
    
    void push(int id , int L , int R) {
        if(lazy[id] == 0) {
            return;
        }
        t[id] += (R - L + 1) * lazy[id];
        if(L != R) {
            lazy[id << 1] += lazy[id];
            lazy[id << 1 | 1] += lazy[id];
        }
        lazy[id] = 0;
    }
    
    /* Range Addition */
    void update(int id , int L , int R , int queryL , int queryR , T value) {
        if(L > queryR or R < queryL) return;
        push(id , L , R);
        if(L >= queryL and R <= queryR) {
            lazy[id] += value;
            push(id , L , R);
            return;
        }
        int mid = (L + R) >> 1;
        update(id << 1 , L , mid , queryL , queryR , value);
        update(id << 1 | 1 , mid + 1 , R , queryL , queryR , value);
        t[id] = merge(t[id << 1] , t[id << 1 | 1]);
    }
    
    /* Range Query */
    node_t get(int id , int L , int R , int queryL , int queryR) {
        if(L > queryR or R < queryL) {
            return defaultValue;
        }
        push(id , L , R);
        if(L >= queryL and R <= queryR) {
            return t[id];
        }
        int mid = (L + R) >> 1;
        node_t getL = get(id << 1 , L , mid , queryL , queryR);
        node_t getR = get(id << 1 | 1 , mid + 1 , R , queryL , queryR);
        return merge(getL , getR);
    }
};





