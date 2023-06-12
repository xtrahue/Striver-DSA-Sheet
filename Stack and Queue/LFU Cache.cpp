class LFUCache {
public:
    class node{
        public:
        int key;
        int val ;
        int cnt ;
        node *next ;
        node *prev ;

        node(int _key,int _val){
            key=_key ;
            val=_val ;
            cnt=1 ;
        }
    };
    class list{
        public:
        int siz ;
        node *head ;
        node *tail ;

        list(){
            head=new node(-1,-1) ;
            tail=new node(-1,-1) ;
            head->next = tail ;
            tail->prev=head ;
            siz=0 ;
        }

        void addnode(node *newnode){
            newnode->next = head->next ;
            head->next->prev=newnode ;
            head->next = newnode ;
            newnode->prev=head ;
            siz++ ;
        }
        void delnode(node *del){
            node *left=del->prev ;
            node *right=del->next ;
            left->next = right ;
            right->prev=left ;
            siz-- ;
        }

    };

    unordered_map<int,node*>nodeof ;
    unordered_map<int, list*>freq ;
    int cap ;
    int minf ;
    int curr_cap ;

    void update(node *newnode){
        nodeof.erase(newnode->key) ;
        freq[newnode->cnt]->delnode(newnode) ;

        //check after deleting the node if the list becomes empty or not
        if(minf==newnode->cnt && freq[newnode->cnt]->siz==0){
            minf++ ;
        }

        list *newlist=new list() ;
        
        if(freq.find(newnode->cnt+1)!=freq.end()){
            newlist=freq[newnode->cnt+1] ;
        }

        newnode->cnt+=1 ;
        newlist->addnode(newnode) ;
        freq[newnode->cnt]=newlist ;     
        nodeof[newnode->key]=newnode ;
    }
    
    LFUCache(int capacity) {
        cap =capacity ;
        minf=0 ;
        curr_cap=0 ;
    }
    
    int get(int _key) {
        if(nodeof.find(_key)!=nodeof.end()){
            node *temp=nodeof[_key] ;
            int res=temp->val ;
            update(temp) ;
            return res ;
        }
        return -1 ;
    }
    
    void put(int _key, int _value) {
        if(cap==0){
            return ;
        }
        if(nodeof.find(_key)!=nodeof.end()){
            node *newnode=new node(_key,_value) ;
            newnode = nodeof[_key];
            newnode->val=_value ;
            update(newnode) ;
        }
        else{
            if(curr_cap==cap){
                list *newlist = new list() ;
                newlist=freq[minf] ;
                nodeof.erase(newlist->tail->prev->key) ;
                newlist->delnode(newlist->tail->prev) ;
                curr_cap-- ;
            }
            curr_cap++ ;
            minf=1 ;//1 new node is being added ;
            list *newlist = new list() ;
            
            if(freq.find(minf)!=freq.end()){
                newlist=freq[minf] ;
            }

            node *newnode= new node(_key,_value) ;

            newlist->addnode(newnode) ;
            nodeof[_key]=newnode ;
            freq[minf]=newlist ;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
