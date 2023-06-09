class LRUCache {
public:
    class node{
    public:
        int key ;
        int val ;
        node *prev ;
        node* next ;

        node(int _key,int _val){
            key=_key ;
            val=_val ;
        }
    };

    node *head=new node(-1,-1) ;
    node *tail=new node(-1,-1) ;

    unordered_map<int, node*>mp ;
    int cap ;

    LRUCache(int capacity) {
        cap=capacity ;
        head->next = tail ;
        tail->prev=head ;
    }

    void addnode(node *newnode){
        node *temp =head->next ;
        newnode->next = temp ;
        newnode->prev = head ;
        head->next=newnode ;
        temp->prev=newnode ;
    }

    void deletenode(node * delnode) {
        node * delprev = delnode -> prev;
        node * delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }
    
    int get(int _key) {
        if(mp.find(_key)!=mp.end()){
            node *response = mp[_key] ;
            int res=response->val ;
            mp.erase(_key) ;

            deletenode(response) ;
            addnode(response) ;

            mp[_key]=head->next ;

            return res ;
        }
        return -1 ;
    }
    
    void put(int _key, int _value) {
        if(mp.find(_key)!=mp.end()){
            node *del=mp[_key] ;
            deletenode(del) ;
            mp.erase(_key) ;
        }
        if(mp.size()<cap){
            node *newnode=new node(_key,_value) ;
            addnode(newnode) ;
            mp[_key]=head->next ;
        }
        else{
            node *newnode=new node(_key,_value) ;
            addnode(newnode) ;
            node *del=tail->prev ;
            mp.erase(del->key) ;
            deletenode(del) ;
            mp[_key] =head->next ;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
