
#include "Set.h"
#include <cassert>
using namespace std;
#include "iostream"
int main() {
    SetT<int> a;
    a.Add(1);
    a.Add(1);
    a.Add(2);
    a.Add(3);
    a.Add(4);
    a.Add(5);
    assert(a.size() == 5);
    SetT<int> b;
    b.Add(1);
    b.Add(2);
    assert(b.size() == 2);
    a + 6;
    assert(a.size() == 6);
    SetT<int> c = a + b;
    assert(c.size() == 6);
    SetT<int> d = a - b;
    assert(d.size() == 4);
    SetT<int> common_elements = a*b;
    assert(common_elements.size() == 2);
    std::cout<<"All tests passed";
    return 0;
}

