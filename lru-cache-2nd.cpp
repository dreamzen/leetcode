#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache
{
private:
    struct CacheLine
    {
        int key;
        int value;
        CacheLine *next;
        CacheLine *pre;
        CacheLine(int k, int v) : key(k), value(v), next(NULL), pre(NULL) {}
    };
    unordered_map<int, CacheLine *> mappingCache;
    CacheLine *head;
    CacheLine *tail;
    int cap;
    int num;
public:
    LRUCache(int capacity)
    {
        cap = capacity;
        num = 0;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key)
    {
        unordered_map<int, CacheLine *>::iterator ite = mappingCache.find(key);
        if(ite == mappingCache.end())
        {
            return -1;
        }
        else
        {
            update(ite->second);
            return ite->second->value;
        }
    }
    
    void set(int key, int value)
    {
        unordered_map<int, CacheLine *>::iterator ite = mappingCache.find(key);
        if(ite != mappingCache.end())
        {
            ite->second->value = value;
            update(ite->second);
        }
        else
        {
            if(num < cap)//insert
            {
                num++;
                CacheLine *cacheline = new CacheLine(key, value);
                mappingCache[key] = cacheline;
                if(num == 1)
                {
                    head = cacheline;
                    tail = cacheline;
                }
                else
                {
                    cacheline->next = head;
                    head->pre = cacheline;
                    head = cacheline;
                }
            }
            else if(num == cap)
            {
                //insert to head and remove tail
                CacheLine *cacheline = new CacheLine(key, value);
                mappingCache[key] = cacheline;
                cacheline->next = head;
                head->pre = cacheline;
                head = cacheline;
                //remove tail
                CacheLine *tmp = tail;
                tail = tail->pre;
                tail->next = NULL;
                mappingCache.erase(mappingCache.find(tmp->key));
                delete tmp;
            }
            else// cap < 0
            {
                return;
            }
        }
    }
    
    void update(CacheLine *p)
    {
        if(p == head)
        {
            return;
        }
        if(p == tail)
        {
            tail = tail->pre;
            tail->next = NULL;
            head->pre = p;
            p->next = head;
            p->pre = NULL;
            head = p;
        }
        else
        {
            p->pre->next = p->next;
            p->next->pre = p->pre;
            head->pre = p;
            p->next = head;
            p->pre = NULL;
            head = p;
        }
    }
};

int main()
{
	return 0;
}
