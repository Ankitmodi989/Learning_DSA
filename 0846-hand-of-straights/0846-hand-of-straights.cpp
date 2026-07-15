class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;
        map<int, int> mp;
        for (int card : hand) {
            mp[card]++;
        }

        for (auto it = mp.begin(); it != mp.end(); it++) {
            int currentCard = it->first;
            int count = it->second;

            if (count > 0)
                for (int i = 0; i < groupSize; i++) {
                    int nextCard = currentCard + i;

                    if (mp[nextCard] < count) {
                        return false;
                    }

                    mp[nextCard] -= count;
                }
        }
        return true;
    }
};