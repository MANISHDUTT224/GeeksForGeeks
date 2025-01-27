//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way
class Node{
    public:
    int key,value;
    Node *prev,*next;
    Node(int ke,int val){
        key=ke;
        value=val;
        next=NULL,prev=NULL;
    }
};
class LRUCache {
  private:
  public:
  Node *head=new Node(-1,-1);
  Node *tail=new Node(-1,-1);
  int capacity;
  map<int,Node*>mp;
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        // code here
        capacity=cap;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(Node *newnode){
        Node *temp=head->next;
        head->next=newnode;
          newnode->prev=head;
        newnode->next=temp;
         temp->prev=newnode;
    }
    void deletenode(Node *deletenode){
        Node *delprev=deletenode->prev;
        Node *delnext=deletenode->next;
        delnext->prev=delprev;
        delprev->next=delnext;
    }
    // Function to return value corresponding to the key.
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node *resnode=mp[key];
            int res=resnode->value;
            mp.erase(key);
            deletenode(resnode);
            addnode(resnode);
            mp[key]=head->next;
            return res;
        }
        return -1;// your code here
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node *existingnode=mp[key];
            mp.erase(key);
            deletenode(existingnode);
        }
        if(mp.size()==capacity){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new Node(key,value));
        mp[key]=head->next;
        
        // your code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends