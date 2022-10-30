nt timeStamp=0;

class Tweet
{
    public:

    int id;
    int time;
	Tweet *next;
         Tweet(int id)
         {
			this->id = id;
			time = timeStamp++;
			next = nullptr;
		}
};

class User
{
    public:
    int id;
    set<int> followList;
    Tweet *tweet_head;
        User( int id)
        {
            this->id = id;
            follow(id);
            tweet_head = nullptr;
        }

        void follow( int id )
        {
            followList.insert(id);
        }

        void unfollow( int id )
        {
            followList.erase( id );
        }

        void post( int id )
        {
            Tweet *t = new Tweet(id);
            t->next = tweet_head;
            tweet_head = t;
        }
};

class mycompare
{
    public:
        bool operator()( Tweet *a, Tweet *b )
        {
            return a->time < b->time;
        }
};

class Twitter {
public:
    unordered_map< int, User > userMap;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) 
    {
        if( userMap.find(userId) == userMap.end() )
        {
            User u(userId);
            
            userMap.insert({userId, u});
        }
        userMap.find(userId)->second.post(tweetId);
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        vector<int> feed;

		if( userMap.find(userId) == userMap.end() )
            return feed;

		set<int> followList = userMap.find( userId )->second.followList;
		priority_queue< Tweet* ,  std::vector<Tweet*>, mycompare >p;

        for(int user: followList)
        {
			Tweet *t =  userMap.find( user )->second.tweet_head;
			if(t != nullptr)
				p.push(t);
		}
		int n=0;
		while(!p.empty() && n<10)
        {
		  Tweet *t = p.top();
          p.pop();
		  feed.push_back( t->id );
		  n++;
		  if( t->next )
			p.push( t->next );
		}

		return feed;
    }
    
    void follow(int followerId, int followeeId) 
    {
        if(userMap.find(followerId) == userMap.end() )
        {
			User u(followerId);
			userMap.insert( {followerId, u} );
		}

        if(userMap.find(followeeId) == userMap.end() )
        {
			User u(followeeId);
			userMap.insert( {followeeId, u} );
		}
        userMap.find( followerId )->second.follow( followeeId );
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        if( userMap.find(followerId) == userMap.end() || followerId==followeeId)
			return;
        userMap.find( followerId )->second.unfollow( followeeId );
    }
};
