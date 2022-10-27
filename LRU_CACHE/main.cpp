#include<bits/stdc++.h>
using namespace std;

class LRU
{
    class node
    {
      public:
        int key;
        int val;
        node *prev;
        node *next;
            node( int _key, int _val )
            {
                this->key = _key;
                this->val = _val;
            }
    };
    
    unordered_map< int, node* >store;
    int capacity;
    
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    
    public:
    
    LRU( int v )
    {
        this->capacity = v;
        head->next = tail;
        tail->prev = head;
    }
    
    void put( int _key, int _val )
    {
        if( store.find( _key ) != store.end() )
        {
            node *temp = store[_key];
            store.erase( _key );
            deleteNode( temp );
        }
        if( capacity == store.size() )
        {
            store.erase( tail->prev->key );
            deleteNode( tail->prev);
        }
        addNode( new node(_key, _val) );
        store[_key] = head->next;
    }
    
    int get( int _key )
    {
        if( store.find(_key) != store.end() )
        {
            node *temp = store[_key];
            int ans = temp->val;
            store.erase(_key);
            deleteNode(temp);
            addNode(temp);
            store[_key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void addNode( node *cur )
    {
        node *temp = head->next;
        head->next = cur;
        cur->next = temp;
        temp->prev = cur;
        cur->prev = head;
    }
    
    void deleteNode( node *temp )
    {
        node *delPrev = temp->prev;
        node *delNext = temp->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    
    void print()
    {
        node *temp = head;
        while( temp->next != nullptr )
        {
            if( temp->key != -1 )
            cout<<"( "<<temp->key<<" - "<<temp->val<<" )"<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    LRU l(2);
    l.put(1,1 );l.print();
    l.put(2, 2);l.print();
    l.get(1);   l.print();
    l.put(3,3); l.print();
    l.get(2);   l.print();
    l.put(4,4); l.print();
    l.get(1);   l.print();
    l.get(3);   l.print();
    l.get(4);   l.print();
}
