#include<bits/stdc++.h>
#include "Box.hpp"
#include "Player.hpp"
using namespace std;

class Gameboard
{
    private :
        int boardSize;
        queue<Player> playerQ;
        int totalCells;
        vector< vector<Box> >box;
        string name;
        
    public:
       Gameboard( queue<Player> allPlayers, int _size, int _tot )
       {
           playerQ = allPlayers;
           this->boardSize = _size;
           this->totalCells = _tot;
       }
       
       void initialize()
       {
           for( int i = 0; i<boardSize; i++ )
           {
               vector<Box>temp;
               for( int j = 0; j<boardSize; j++ )
               {
                  temp.push_back( Box(i, j, '.') );
               }
               box.push_back( temp );
           }
       }
       
       void gameStart()
       {
           int start, end;
           char ch;
           bool isFormed = false;
           
           while( totalCells )
           {
               Player currentPlayer = playerQ.front();
               playerQ.pop();
               
               name = currentPlayer.getPlayerName();
               cout<<"It's "<<name<<" turn"<<endl;
               cout<<"choose the box : "<<endl;
               
               cin>>start>>end;
               cin>>ch;
               
               box[start][end].setSign( ch );
               
               cout<<"------------------------------"<<endl;
               for( int i = 0; i<boardSize; ++i )
               {
                   for( int j = 0; j<boardSize; ++j )
                    cout<< box[i][j].getSign()<<" ";
                    cout<<endl;
               }
               cout<<"------------------------------"<<endl;
               
               bool isColumn = true;
               for( int i = 0; i<boardSize; i++ )
               {
                   if( box[i][end].getSign() != box[start][end].getSign() )
                   {
                        isColumn = false;
                        break;
                   }
               }
               
               bool isRow = true;
               for( int i = 0; i<boardSize; i++ )
               {
                   if( box[start][i].getSign() != box[start][end].getSign() )
                   { 
                        isRow = false;
                        break;
                   }
               }
               
               bool isLeftDiagonal = true;
               int i=0, j = 0;
               while( i < boardSize && j < boardSize )
               {
                   if( box[i][j].getSign() != box[start][end].getSign() )
                   { 
                        isLeftDiagonal = false;
                        break;
                   }
                   i++; j++;
               }
               
               bool isRightDiagonal = true;
               i=0, j = boardSize-1;
               while( i < boardSize  && j >= 0 )
               {
                   if( box[i][j].getSign() != box[start][end].getSign() )
                   { 
                        isRightDiagonal = false;
                        break;
                   }
                   i++; j--;
               }
               
               if( isRightDiagonal || isLeftDiagonal || isColumn || isRow )
               {
                   cout<<name<<" has won the game Hurray !!! "<<endl;
                   break;
               }
               playerQ.push( currentPlayer );
               totalCells--;
           }
           if( !totalCells )
                cout<<"Match has drawn !! "<<endl;
       }
};
