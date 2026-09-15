class Node{
public:
    int key;
    int val;
    Node*prev;
    Node*next;
    
    Node(int _key,int _val){
        prev=NULL;
        next=NULL;
        val=_val;
        key=_key;
    }
};
class LRUCache {
public:

void addNode(Node*newNode){
    Node*temp=head->next;
    head->next=newNode;
    newNode->prev=head;
    newNode->next=temp;
    temp->prev=newNode;
    size++;
}
void deleteNode(Node*del){
    Node*prevNode=del->prev;
    Node*nextNode=del->next;
    prevNode->next=nextNode;
    nextNode->prev=prevNode;
    size--;
}
unordered_map<int,Node*>mpp;
Node*head;
Node*tail;
int size=0;
int capacity;
    LRUCache(int _capacity) {
        capacity=_capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        
        if(mpp.find(key)!=mpp.end()){
            deleteNode(mpp[key]);
            addNode(mpp[key]);
           return mpp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end() ){
            deleteNode(mpp[key]);
            mpp.erase(key);
        }
        if(size==capacity){
            int del=tail->prev->key;
           deleteNode(tail->prev); 
            mpp.erase(del);
        }
        Node*newNode=new Node(key,value);
        addNode(newNode);
        mpp[key]=newNode;

    }
};
