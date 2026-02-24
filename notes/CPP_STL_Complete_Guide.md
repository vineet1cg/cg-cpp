# C++ STL (Standard Template Library) -- Complete In‑Depth Guide

------------------------------------------------------------------------

# 📌 Table of Contents

1.  Introduction to STL
2.  Sequence Containers
    -   vector
    -   deque
    -   list
    -   forward_list
    -   array
3.  Associative Containers (Ordered)
    -   set / multiset
    -   map / multimap
4.  Unordered Containers (Hash-based)
    -   unordered_set / unordered_multiset
    -   unordered_map / unordered_multimap
5.  Container Adaptors
    -   stack
    -   queue
    -   priority_queue
6.  Iterators
7.  Algorithms
8.  Numeric Library
9.  Function Objects
10. Utilities
11. Complexity Comparison
12. Best Practices & Cautions

------------------------------------------------------------------------

# 1️⃣ Introduction to STL

STL = Generic library of: - Containers - Iterators - Algorithms -
Function Objects - Utilities

Header files commonly used:

``` cpp
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
```

------------------------------------------------------------------------

# 2️⃣ Sequence Containers

These store elements in linear order.

------------------------------------------------------------------------

## 🔹 std::vector

Dynamic array (contiguous memory).

### Characteristics

-   Random access O(1)
-   push_back O(1) amortized
-   insert/erase in middle O(n)
-   Resizable

### Syntax

``` cpp
std::vector<int> v;
```

### Important Functions

``` cpp
v.push_back(10);
v.pop_back();
v.size();
v.capacity();
v.reserve(100);
v.resize(5);
v.clear();
v.empty();
v.front();
v.back();
v.at(2);
v[2];
v.insert(v.begin(), 5);
v.erase(v.begin());
```

### Example

``` cpp
std::vector<int> v = {1,2,3};
v.push_back(4);
```

### Use Cases

-   Default container
-   Competitive programming
-   Dynamic arrays

### Cautions

-   Insertion in middle is expensive
-   Reallocation invalidates iterators

### Alternatives

-   deque (if frequent front insertion)
-   list (if heavy middle insertion)

------------------------------------------------------------------------

## 🔹 std::deque

Double-ended queue.

### Characteristics

-   Fast insertion at both ends
-   Random access O(1)
-   Not fully contiguous

### Syntax

``` cpp
std::deque<int> dq;
dq.push_front(1);
dq.push_back(2);
dq.pop_front();
dq.pop_back();
```

### Use Case

-   Sliding window problems
-   When both ends insertion required

------------------------------------------------------------------------

## 🔹 std::list

Doubly linked list.

### Characteristics

-   No random access
-   Fast insert/erase anywhere O(1)

### Syntax

``` cpp
std::list<int> l;
l.push_back(10);
l.push_front(5);
l.remove(10);
l.sort();
l.reverse();
```

### Caution

-   High memory usage
-   Slower iteration than vector

------------------------------------------------------------------------

## 🔹 std::forward_list

Singly linked list.

``` cpp
std::forward_list<int> fl;
fl.push_front(1);
fl.insert_after(fl.begin(), 5);
```

Use when minimal memory required.

------------------------------------------------------------------------

## 🔹 std::array

Fixed-size array.

``` cpp
std::array<int,5> arr = {1,2,3,4,5};
arr.size();
arr.fill(10);
```

Use when size known at compile time.

------------------------------------------------------------------------

# 3️⃣ Associative Containers (Ordered)

Implemented using Red-Black Tree.

------------------------------------------------------------------------

## 🔹 std::set

Unique sorted elements.

``` cpp
std::set<int> s;
s.insert(10);
s.erase(10);
s.find(10);
s.count(10);
s.lower_bound(5);
s.upper_bound(5);
```

Complexity: O(log n)

------------------------------------------------------------------------

## 🔹 std::multiset

Allows duplicates.

------------------------------------------------------------------------

## 🔹 std::map

Key-value pairs (unique keys).

``` cpp
std::map<std::string,int> m;
m["a"] = 1;
m.insert({"b",2});
m.erase("a");
m.find("b");
m.at("b");
```

------------------------------------------------------------------------

## 🔹 std::multimap

Allows duplicate keys.

------------------------------------------------------------------------

# 4️⃣ Unordered Containers

Hash table based.

Average O(1), worst O(n).

------------------------------------------------------------------------

## 🔹 std::unordered_set

``` cpp
std::unordered_set<int> us;
us.insert(10);
us.find(10);
```

------------------------------------------------------------------------

## 🔹 std::unordered_map

``` cpp
std::unordered_map<std::string,int> um;
um["a"] = 5;
um.find("a");
```

### Caution

-   No ordering
-   Custom hash needed for custom objects

------------------------------------------------------------------------

# 5️⃣ Container Adaptors

------------------------------------------------------------------------

## 🔹 std::stack

LIFO

``` cpp
std::stack<int> st;
st.push(1);
st.pop();
st.top();
```

------------------------------------------------------------------------

## 🔹 std::queue

FIFO

``` cpp
std::queue<int> q;
q.push(1);
q.pop();
q.front();
q.back();
```

------------------------------------------------------------------------

## 🔹 std::priority_queue

Max heap by default.

``` cpp
std::priority_queue<int> pq;
pq.push(10);
pq.top();
pq.pop();
```

Min heap:

``` cpp
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
```

------------------------------------------------------------------------

# 6️⃣ Iterators

``` cpp
v.begin();
v.end();
v.rbegin();
v.rend();
```

Types: - Input - Output - Forward - Bidirectional - Random access

------------------------------------------------------------------------

# 7️⃣ Algorithms

Include `<algorithm>`

## Searching

``` cpp
std::find(v.begin(), v.end(), 10);
std::binary_search(v.begin(), v.end(), 10);
std::count(v.begin(), v.end(), 5);
```

## Sorting

``` cpp
std::sort(v.begin(), v.end());
std::stable_sort(v.begin(), v.end());
std::nth_element(v.begin(), v.begin()+2, v.end());
```

## Removing (Erase-Remove Idiom)

``` cpp
v.erase(std::remove(v.begin(), v.end(), 5), v.end());
```

## Rearranging

``` cpp
std::reverse(v.begin(), v.end());
std::rotate(v.begin(), v.begin()+1, v.end());
std::next_permutation(v.begin(), v.end());
```

------------------------------------------------------------------------

# 8️⃣ Numeric Library `<numeric>`

``` cpp
std::accumulate(v.begin(), v.end(), 0);
std::iota(v.begin(), v.end(), 1);
std::partial_sum(v.begin(), v.end(), v.begin());
```

------------------------------------------------------------------------

# 9️⃣ Function Objects `<functional>`

``` cpp
std::greater<int>();
std::less<int>();
std::plus<int>();
```

Custom comparator:

``` cpp
std::sort(v.begin(), v.end(), [](int a, int b){
    return a > b;
});
```

------------------------------------------------------------------------

# 🔟 Utilities

## pair

``` cpp
std::pair<int,int> p = {1,2};
std::make_pair(3,4);
```

## tuple

``` cpp
std::tuple<int,int,int> t = {1,2,3};
std::get<0>(t);
```

## optional (C++17)

``` cpp
std::optional<int> op;
op = 5;
```

## variant (C++17)

``` cpp
std::variant<int,std::string> v;
v = 10;
```

------------------------------------------------------------------------

# 1️⃣1️⃣ Complexity Overview

  Container       Insert     Find       Access
  --------------- ---------- ---------- --------
  vector          O(n)       O(n)       O(1)
  deque           O(n)       O(n)       O(1)
  list            O(1)       O(n)       ❌
  set/map         O(log n)   O(log n)   ❌
  unordered_map   O(1)\*     O(1)\*     ❌

------------------------------------------------------------------------

# 1️⃣2️⃣ Best Practices & Cautions

✔ Prefer vector by default\
✔ Use unordered_map for fast lookup\
✔ Use map/set if sorted order required\
✔ Reserve capacity in vector when size known\
✔ Avoid unnecessary copies (use references)\
✔ Prefer algorithms over manual loops

------------------------------------------------------------------------

# 🚀 Final Advice

-   Master vector + unordered_map first
-   Learn erase-remove idiom
-   Understand iterator invalidation rules
-   Use emplace functions for efficiency

------------------------------------------------------------------------

END OF GUIDE
