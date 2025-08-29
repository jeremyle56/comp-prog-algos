#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<class T, class E>
using OST = tree<T, E, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;