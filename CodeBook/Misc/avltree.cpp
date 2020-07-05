#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds; 
using namespace std; 
  

/*
<<declare>>
tree<
    key_type, 
    mapped_type, 
    Cmp_func(default std::less<Key>), 
    rb_tree_tag, 
    tree_order_statistics_node_update
    >
*/

tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> p;
//tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>::iterator it;
auto it = t.begin(); 
//支援操作：lower_bound, upper_bound, insert, erase, find, begin, end, size
//<<insert>>
tree.insert(key)
p.insert(1);

// The index is from 0 to ...
// <<find by order>>
// 找第k+1小的數字，如果沒有，返回end().+'*'取數字
*p.find_by_order(k) ->返回該數字
p.find_by_order(k) ->返回該數字的位置

// <<order of key>>
// 查詢比k小的數字的個數
p.order_of_key(k)

//<find>
t.find(x) // 返回x所在的it