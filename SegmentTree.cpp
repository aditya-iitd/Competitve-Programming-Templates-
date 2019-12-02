#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Segtree {
public:
    struct node_t {
        T minv , maxv , sumv;
        node_t() {
            minv = maxv = sumv = (T) 0;
        };
        node_t(T value) {
            minv = maxv = sumv = value;
        }
        node_t(T minv , T maxv , T sumv) : minv(minv) , maxv(maxv) , sumv(sumv) {}
        
        friend ostream& operator<<(ostream &os , const node_t node) {
            return os << "[ " << node.minv << " " << node.maxv << " " << node.sumv << " ]";
        }
    };
    
    int n;
    vector<node_t> t;
    const int INF = (int) 1e9 + 7;
    node_t defaultValue = { (T) INF , (T) -INF , (T) 0 };
    Segtree(int n) : n(n) {
        t.resize(4 * n);
    }
    
    node_t merge(node_t left , node_t right) {
        node_t mergedNode;
        mergedNode.minv = min(left.minv , right.minv);
        mergedNode.maxv = max(left.maxv , right.maxv);
        mergedNode.sumv = left.sumv + right.sumv;
        return mergedNode;
    }
    
    /* Point Updates */
    void update(int id , int L , int R , int where , T value) {
        if(L == R) {
            t[id] = node_t(value);
            return;
        }
        int mid = (L + R) >> 1;
        if(where <= mid) {
            update(id << 1 , L , mid , where , value);
        } else {
            update(id << 1 | 1 , mid + 1 , R , where , value);
        }
        t[id] = merge(t[id << 1] , t[id << 1 | 1]);
    }
    
    /* Range Query */
    node_t get(int id , int L , int R , int queryL , int queryR) {
        if(L > queryR or R < queryL) {
            return defaultValue;
        }
        if(L >= queryL and R <= queryR) {
            return t[id];
        }
        int mid = (L + R) >> 1;
        node_t getL = get(id << 1 , L , mid , queryL , queryR);
        node_t getR = get(id << 1 | 1 , mid + 1 , R , queryL , queryR);
        return merge(getL , getR);
    }
};

