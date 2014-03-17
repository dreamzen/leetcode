#include <iostream>
using namespace std;

struct CacheLine
{
    int key;
    int value;
    CacheLine *before;
    CacheLine *next;
    CacheLine(int x, int y): key(x), value(y), before(NULL), next(NULL) {}
};

class LRUCache
{
public:
    int cap;//capacity
    int items;//number of cache lines
    CacheLine *head;
    CacheLine *tail;
    
    LRUCache(int capacity)
    {
        cap = capacity;
        items = 0;
        head = NULL;
        tail = NULL; 
    }
    
    int get(int key)
    {
        //serch O(n)
        int value = -1;
        CacheLine *tmp = head;
        for(int i = 0; i < items; i++)
        {
            if(tmp->key == key)
            {
                value = tmp->value;
                break;
            }
            tmp = tmp->next;
        }
        //get() effects cache too!
        if(value != -1)//move tmp to the head of cache
        {
            //avoid searching again!
            update(key, value, tmp);
        }
        return value;
    }
    
    //update tmp to (key, value) O(1)
    void update(int key, int value, CacheLine *tmp)
    {
        tmp->value = value;
        if(tmp->key == head->key)//do nothing
        {
        }
        else if(tmp->key == tail->key)//move tail to the head of cache
        {
            tail->next = head;
            head->before = tail;
            head = tail;
            tail = tail->before;
            head->before = NULL;
            tail->next = NULL;
            
        }
        else//move the cache line to the head of cache
        {
            tmp->before->next = tmp->next;
            tmp->next->before = tmp->before;
            tmp->next = head;
            head->before = tmp;
            head = tmp;
            head->before = NULL;
        }
    }

    void set(int key, int value)
    {
        //serch O(n)
        bool found = false;
        CacheLine *tmp = head;
        for(int i = 0; i < items; i++)
        {
            if(tmp->key == key)
            {
                found = true;
                break;
            }
            tmp = tmp->next;
        }
        if(found)//if found, then just update the value AND update the cache
        {
            update(key, value, tmp);
        }
        else//not found
        {
            if(items < cap)//just insert to head
            {
                CacheLine *tmp = new CacheLine(key, value);
                if(items == 0)
                {
                    head = tmp;
                    tail = tmp;
                    items++;
                }
                else
                {
                    tmp->next = head;
                    head->before = tmp;
                    head = tmp;
                    head->before = NULL;
                    tail->next = NULL;
                    items++;
                }
            }
            else//delete the tail and insert to head.ATTENTION: must insert FISRT in case capacity is 1!
            {
                CacheLine *tmp = new CacheLine(key, value);
                tmp->next = head;
                head->before = tmp;
                head = tmp;

                tail = tail->before;
                delete tail->next;
                tail->next = NULL;
                
            }
        }
    }
};

int main()
{
    LRUCache cache(1);
    cout << cache.get(1) << endl;
    cache.set(1, 1);
    cache.set(2, 2);
    cache.set(3, 3);
    cache.set(4, 4);
    cache.set(5, 5);
    cache.set(6, 6);
    cout << cache.get(1) << endl;
    cout << cache.get(4) << endl;
    cache.set(5, 10);
    cout << cache.get(5) << endl;

    return 0;
}
