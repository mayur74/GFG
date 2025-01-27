//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  private:
    
    int capacity;
    list<pair<int,int>> dll;
    unordered_map<int , list<pair<int,int>>:: iterator> cache;
    
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        // code here
        capacity = cap;
        
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // your code here
        if(cache.find(key) == cache.end()){
            return -1;
        }
        
        auto it = cache[key];
        int value = it->second;
        dll.erase(it);
        dll.push_front({key,value});
        cache[key] = dll.begin();
        return value;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // your code here
        if(cache.find(key) != cache.end()){
            auto it = cache[key];
            dll.erase(it);
        }
        else if(dll.size() == capacity){
            auto last = dll.back();
            cache.erase(last.first);
            dll.pop_back();
        }
        dll.push_front({key , value});
        cache[key] = dll.begin();
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