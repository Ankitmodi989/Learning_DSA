class LFUCache {
public:
    int size;

    map<int, list<vector<int>>> freq;
    unordered_map<int, list<vector<int>>::iterator> mp;

    int n;
    LFUCache(int capacity) {
        n = capacity;
        size = 0;
    }

    void makeitfront(int key) {
        auto& vec = *(mp[key]);
        int value = vec[1];
        int f = vec[2];

        freq[f].erase(mp[key]);

        if (freq[f].empty())
            freq.erase(f);

        f++;

        freq[f].push_front(vector<int>({key, value, f}));

        mp[key] = freq[f].begin();
    }
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        auto& vec = (*(mp[key]));

        int value = vec[1];

        makeitfront(key);

        return value;
    }

    void put(int key, int value) {
         if(n == 0)
            return;
        
        if(mp.find(key) != mp.end()) {
            auto &vec = (*(mp[key]));
            vec[1] = value;
            makeitfront(key);
        }
        else if(size < n) {
            size++;
            freq[1].push_front(vector<int>({key, value, 1}));
            mp[key] = freq[1].begin();
        }
        else { //Time to remove LFU or LRU if tie
            
            auto &kaun_sa_list = freq.begin()->second;
            
            int key_delete = (kaun_sa_list.back())[0]; 
            kaun_sa_list.pop_back();
            
            if(kaun_sa_list.empty())
                freq.erase(freq.begin()->first);
            
            freq[1].push_front(vector<int>({key, value, 1}));
            
            mp.erase(key_delete);
            mp[key] = freq[1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */