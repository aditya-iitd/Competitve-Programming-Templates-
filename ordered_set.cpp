// ORDERED_SET : https://codeforces.com/blog/entry/11080

// Functions -->
// find_by_order(i) : returns iterator pointing to i-th element of the set
// order_of_key(element) : return index of element in the set
// end(X) : end of set X

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;

typedef tree<pair<int , int>,null_type,less<pair<int , int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
