#include<bits/stdc++.h>
using namespace std;

class userInterface
{
    public:
        virtual void notify( string msg ) = 0;
};

class group
{
    private:
        list< userInterface* > users;
        
    public :
        void subscribe( userInterface * user )
        {
            users.push_back( user );
        }
        
        void unsubscribe( userInterface * user )
        {
            users.remove( user );
        }
        
        void notify( string msg )
        {
            for( auto i : users )
            {
                i->notify( msg );
            }
        }
};

class user : public userInterface
{
    private:
        int userId;
        
    public:
    
        user( int id )
        {
            this->userId = id;
        }
        
        void notify( string msg )
        {
            cout<<"user "<<userId<<" received "<<msg<<endl;
        }
};

int main()
{
    group *g = new group();
    
    user *u1 = new user(1);
    user *u2 = new user(2);
    user *u3 = new user(3);

    g->subscribe(u1);
    g->subscribe(u2);
    g->subscribe(u3);

    g->notify("hi");
    
    g->unsubscribe(u2);
    
    g->notify("how are you");

    return 0;
}
