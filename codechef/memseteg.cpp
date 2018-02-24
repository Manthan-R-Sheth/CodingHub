#include <iostream>
#include <cstring>

int main()
{
    std::vector<int> a[20];
    std::memset(a, 0, sizeof a);
    for (int i=0;i<a.size();i++) std::cout << a[i];
}