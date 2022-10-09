#include<bits/stdc++.h>
#include "Player.hpp"
#include "Box.hpp"
using namespace std;

class Board
{
    int boardSize;
    int emptyCells;
    vector< vector<Box> >box;
    public :
        Board( int _size, int cells )
        {
            this->boardSize = _size;
            this->emptyCells = cells;
        }
        
        void initialize()
        {
            for( int i =0; i<boardSize; i++ )
            {
                vector<Box>temp;
                for( int j =0; j<boardSize; j++ )
                {
                    temp.push_back( Box(i, j, 0 ) );
                }
                box.push_back( temp );
            }
            insertRandom();
            insertRandom();
            printState();
        }
        
        
        void startGame()
        {
            char ch;
            while( emptyCells )
            {
                cout<<"Enter your side : ";
                cin>>ch;
                if( ch == 'l' )
                    moveLeft();
                else if( ch == 'r' )
                    moveRight();
                
                insertRandom();
                printState();
            }
        }
        
        void printState()
        {
            int n = box.size();
            int m = box[0].size();
            
            for(int i =0; i<n; i++)
            {
                for( int j = 0; j<m; j++ )
                {
                    cout<<box[i][j].currentDigit()<<" ";
                }
                cout<<endl;
            }
        }
        
        void insertRandom()
        {
            srand ( time(0) );
            char arrayNum[2] = {2, 4};
            int idx = rand() % 2;
            
            int n = box.size();
            int m = box[0].size();
            
            vector< pair<int, int > >emptySpaces;
            for( int i = 0; i<n; i++ )
            {
                for( int j = 0; j<m; j++ )
                {
                    if( !box[i][j].currentDigit() )
                        emptySpaces.push_back( {i, j} );
                }
            }
            int maxi = emptySpaces.size()-1;
            int mini = 0;
            int empty_idx = rand()%(maxi-mini + 1) + mini;
            auto it = emptySpaces[empty_idx];
            box[it.first][it.second].setDigit( arrayNum[idx] );
        }
        
        void moveLeft()
        {
            int n = box.size();
            int m = box[0].size();
            for( int i = 0; i <n; i++ )
            {
                for( int j = 1; j<m; j++ )
                { 
                    int k = j;
                    while(  k>0 && box[i][k].currentDigit() && 
                             box[i][k].currentDigit() == box[i][k-1].currentDigit() )
                    {
                        box[i][k-1].setDigit( box[i][k].currentDigit()*2 );
                        box[i][k].setDigit(0);
                        k--;
                    }
                    
                    while( k>0 && box[i][k].currentDigit() && !box[i][k-1].currentDigit() )
                    {
                        box[i][k-1].setDigit( box[i][k].currentDigit() );
                        box[i][k].setDigit(0);
                        k--;
                    }
                }
            }
        }
        
        void moveRight()
        {
            int n = box.size();
            int m = box[0].size();
            for( int i = n-1; i >=0; i-- )
            {
                for( int j = m-2; j>=0; j-- )
                { 
                    int k = j;
                    while(  k < m-1 && box[i][k].currentDigit() && 
                             box[i][k].currentDigit() == box[i][k+1].currentDigit() )
                    {
                        box[i][k+1].setDigit( box[i][k].currentDigit()*2 );
                        box[i][k].setDigit(0);
                        k++;
                    }
                    
                    while( k < m-1 && box[i][k].currentDigit() && !box[i][k+1].currentDigit() )
                    {
                        box[i][k+1].setDigit( box[i][k].currentDigit() );
                        box[i][k].setDigit(0);
                        k++;
                    }
                }
            }
        }
};
