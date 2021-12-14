// map管理user集合，每一个使用set记录关注对象，用list存储博文id，获取最新10个推文时，等价为合并k个链表，用大顶堆实现
struct User {
    int userId;
    unordered_set<int> followList;
    list<pair<int, int>> tweetList;
    User(int userId): userId(userId) {}
};

struct News {
    int time;
    int userId;
    list<pair<int, int>>::iterator iter;
    News(int time, int userId, list<pair<int, int>>::iterator iter): time(time), userId(userId), iter(iter) {}
};

bool operator<(const struct News &na, const struct News &nb) {
    return na.time < nb.time;
}

class Twitter {
public:
    Twitter() {
        timeCount = 0;
	maxNewsFeed = 10;
    }
    
    void postTweet(int userId, int tweetId) {
        if (userManager.find(userId) == userManager.end()) {
            initUser(userId);
        }   
        struct User *cur = userManager[userId];
        cur->tweetList.push_front({tweetId, timeCount++});
    }
    
    vector<int> getNewsFeed(int userId) {
        if (userManager.find(userId) == userManager.end()) {
            return {};
        }
        vector<int> tweetList;
        priority_queue<struct News> minHeap;
        struct User *cur = userManager[userId];
        list<pair<int, int>>::iterator iter = cur->tweetList.begin();
        if (iter != cur->tweetList.end()) {
            minHeap.push({iter->second, userId, iter});
        }
        for (auto followeeId : cur->followList) {
            if (followeeId == userId) {
                continue;
            }
            cur = userManager[followeeId];
            iter = cur->tweetList.begin();
            if (iter != cur->tweetList.end()) {
                minHeap.push({iter->second, followeeId, iter});
            }
        }

        int count = 0;
        while (!minHeap.empty()) {
            struct News curNew = minHeap.top();
            minHeap.pop();
            tweetList.push_back(curNew.iter->first);
            if (++count == maxNewsFeed) {
                break;
            } 
            cur = userManager[curNew.userId];
            if (++curNew.iter != cur->tweetList.end()) {
                minHeap.push({curNew.iter->second, curNew.userId, curNew.iter});
            }
        }
        return tweetList;
    }
    
    void follow(int followerId, int followeeId) {
        if (userManager.find(followerId) == userManager.end()) {
            initUser(followerId);
        } 
        if (userManager.find(followeeId) == userManager.end()) {
            initUser(followeeId);
        }
        struct User *cur = userManager[followerId];
        cur->followList.insert(followeeId); 
    }
    
    void unfollow(int followerId, int followeeId) {
        if (userManager.find(followerId) == userManager.end()) {
            initUser(followerId);
        } 
        if (userManager.find(followeeId) == userManager.end()) {
            initUser(followeeId);
        }
        struct User *cur = userManager[followerId];
        cur->followList.erase(followeeId); 
    }

    void initUser(int userId) {
        struct User *newUser= new struct User(userId);
        userManager[userId] = newUser;
    }

private:
    int timeCount;
    int maxNewsFeed;
    unordered_map<int, struct User*> userManager;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
