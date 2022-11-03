#include <iostream>
#include <jsoncpp/json/json.h>
#include<bits/stdc++.h>

using namespace std;

int totRectangles;
char mat[105][105];
map<pair<int, int>, stack<pair<int, char> > > snapshot;
map<int, pair<pair<int, int>, pair<int, int> > > idToCoordinatesMap;
map<int, char> idToCharMap;


void printRectangle(int n, int m) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      pair<int, int> posx = make_pair(i, j);
      char val = snapshot[posx].top().second;
      cout << val << " ";
    }
    cout << endl;
  }
  cout << endl;
}

//  class board
{
     int m, n;
     vector< vector<box> >
}

class Rectangle
{
   int startX;
   int startY;
   int desX;
   int desY;
   char val;
   string color;
}

class box
{
   int x;
   int y;
   stack< pair<int, char> > st;
}

class paint()
{
    abstract drawRectangle;
    abstract bringToFront;
}

void drawRectangle(char ch, int sx, int sy, int dx, int dy) {
  totRectangles++;
  idToCharMap[totRectangles] = ch;
  pair<int, int> topLeft = make_pair(sx, sy);
  pair<int, int> bottomRight = make_pair(dx, dy);
  pair<pair<int, int>, pair<int, int> > valp = make_pair(topLeft, bottomRight);
  idToCoordinatesMap[totRectangles] = valp;
  for(int i = sx; i <= dx; i++) {
    for(int j = sy; j <= dy; j++) {
      pair<int, int> posx = make_pair(i, j);
      snapshot[posx].push(make_pair(totRectangles, ch));
    }
  } 
}

void eraseArea(int sx, int sy, int dx, int dy) {
  for(int i = sx; i <= dx; i++) {
    for(int j = sy; j <= dy; j++) {
      pair<int, int> posx = make_pair(i, j);
      while(snapshot[posx].size()) {
        snapshot[posx].pop();
      }
    }
  }
}

void removeOldState(pair<int, int> topLeft, pair<int, int> bottomRight, int id) {
  stack<pair<int, char> > tempStack;
  for(int i = topLeft.first; i <= bottomRight.first; i++) {
    for(int j = topLeft.second; j <= bottomRight.second; j++) {
      pair<int, int> curPos = make_pair(i, j);
      while(snapshot[curPos].size()) {
        if(snapshot[curPos].top().first == id) {
          snapshot[curPos].pop();
          break;
        }
        tempStack.push(snapshot[curPos].top());
        snapshot[curPos].pop();
      }
      while(tempStack.size()) {
        snapshot[curPos].push(tempStack.top());
        tempStack.pop();
      }
    }
  }
}

void dragAndDrop(int sx, int sy, int dx, int dy) {
  int diffx = sx - dx;
  int diffy = dy - dy;
  pair<int, int> curPos = make_pair(sx, sy);
  int topRectangelId = snapshot[curPos].top().first;
  pair<int, int> topLeftPos = idToCoordinatesMap[topRectangelId].first;
  pair<int, int> bottomRight = idToCoordinatesMap[topRectangelId].second;
  removeOldState(topLeftPos, bottomRight, topRectangelId);
  for(int i = topLeftPos.first; i <= bottomRight.first; i++) {
    for(int j = topLeftPos.second; j <= bottomRight.second; j++) {
      int newi = i + diffx;
      int newj = j + diffy;
      pair<int, int> newPos = make_pair(newi, newj);
      snapshot[newPos].push({topRectangelId, idToCharMap[topRectangelId]});
    }
  }
}


void updateState(int i, int j) {
  pair<int, int> cur = make_pair(i, j);
 stack<pair<int, char> > tempStack;
  
  if(snapshot[cur].size() == 0) return;
  
  while(snapshot[cur].size()) {
    tempStack.push(snapshot[cur].top());
    snapshot[cur].pop();
  }
  
  pair<int, char> topx = tempStack.top();
  tempStack.pop();
  
  while(tempStack.size()) {
    snapshot[cur].push(tempStack.top());
    tempStack.pop();
  }
  
  snapshot[cur].push(topx);
  
}

void bringToFront(int sx, int sy) {
  pair<int, int> cur = make_pair(sx, sy);
  stack<pair<int, char> > tempStack;
  
  if(snapshot[cur].size() == 0) return;
  
  while(snapshot[cur].size()) {
    tempStack.push(snapshot[cur].top());
    snapshot[cur].pop();
  }
  
  int id = tempStack.top().first;
  
  while(tempStack.size()) {
    snapshot[cur].push(tempStack.top());
    tempStack.pop();
  }
  
  pair<pair<int, int>, pair<int, int> > corners = idToCoordinatesMap[id];
  
  pair<int, int> topLeft = corners.first;
  pair<int, int> bottomRight = corners.second;
  
  for(int i = topLeft.first; i <= bottomRight.first; i++) {
    for(int j = topLeft.second; j <= bottomRight.second; j++) {
      updateState(i, j);
    }
  }
  
}



int main() {
}
//column start , row start, column end , row end
