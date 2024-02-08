#include <bits/stdc++.h>
class Node
{

    Node *links[26];
    bool flag = false;

public:
    bool containskey(char c)
    {
        return links[c - 'a'] != NULL;
    }
    void put(char c, Node *node)
    {
        links[c - 'a'] = node;
    }
    Node *get(char c)
    {
        return links[c - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *r = root;
        for (auto x : word)
        {
            if (!r->containskey(x))
                r->put(x, new Node());
            r = r->get(x);
        }
        r->setEnd();
    }

    bool search(string word)
    {
        Node *r = root;
        for (auto x : word)
        {
            if (!r->containskey(x))
                return false;
            r = r->get(x);
        }
        return r->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *r = root;
        for (auto x : prefix)
        {
            if (!r->containskey(x))
                return false;
            r = r->get(x);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */