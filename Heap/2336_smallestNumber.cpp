#include <bits/stdc++.h>
class SmallestInfiniteSet
{
public:
    priority_queue<int, vector<int>, greater<int>> v;
    const int n = 1001;
    vector<int> fg;
    SmallestInfiniteSet()
    {
        for (int i = 1; i <= 1000; i++)
            v.push(i), fg.push_back(0);
    }

    int popSmallest()
    {
        int x = v.top();
        fg[x] = 1;
        v.pop();
        return x;
    }

    void addBack(int num)
    {
        if (num < n && fg[num] == 1)
            v.push(num), fg[num] = 0;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */