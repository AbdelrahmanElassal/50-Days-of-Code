class Twitter
{
    unordered_map<int, unordered_set<int>> fol;
    vector<pair<int, int>> posts;

public:
    Twitter()
    {
    }

    void postTweet(int userId, int tweetId)
    {
        this->posts.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        int count = 0;
        vector<int> feed(10);
        for (int i = this->posts.size() - 1; i >= 0; i--)
        {
            if (this->fol[userId].count(this->posts[i].first) || this->posts[i].first == userId)
            {
                feed[count++] = this->posts[i].second;
            }
            if (count == 10)
                break;
        }
        feed.resize(count);
        return feed;
    }

    void follow(int followerId, int followeeId)
    {
        this->fol[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        this->fol[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */