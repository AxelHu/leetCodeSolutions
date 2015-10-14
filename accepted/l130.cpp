// "l130.cpp" -*- C++ -*-
// surrounded regions

int bfsBorder(vector<vector<char> >& board, int oriRow, int oriCol)
{
  int rows = board.size();
  int cols = board[0].size();
  deque<pair<int, int> > wait_list;
  wait_list.push_back(make_pair(oriRow, oriCol));
  board[oriRow][oriCol] = 'V'; // already visited
  while(!wait_list.empty())
  {
    pair<int, int> curNode = wait_list.front();
    wait_list.pop_front();
    pair<int, int> surNode[4] = { {curNode.first-1, curNode.second},
      {curNode.first, curNode.second-1},
      {curNode.first+1, curNode.second},
      {curNode.first, curNode.second+1}};
    for(int i = 0; i < 4; i++)
    {
      int tempRow = surNode[i].first;
      int tempCol = surNode[i].second;
      // if the coordinate is available
      if((tempRow >= 0 ) && (tempRow < rows) && (tempCol >= 0) && (tempCol < cols) 
        && (board[tempRow][tempCol] == 'O'))
      {
        wait_list.push_back(surNode[i]);
        board[tempRow][tempCol] = 'V'; // already visited
      }
    }
  }
  return 0;
}

class Solution {
public:
    void solve(vector<vector<char>>& board) {
          int rows = board.size();
  if(rows == 0)
    return;
  int cols = board[0].size();
  if(cols == 0)
    return;
  
  // do bfs for border first
  for(int i = 0; i < rows; i++)
  {
    if(board[i][0] == 'O')
      bfsBorder(board, i, 0);
    if(board[i][cols-1] == 'O')
      bfsBorder(board, i, cols-1);
  }
  for(int j = 0; j < cols; j++)
  {
    if(board[0][j] == 'O')
      bfsBorder(board, 0, j);
    if(board[rows-1][j] == 'O')
      bfsBorder(board, rows-1, j);
  }
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      if(board[i][j] == 'O')
        board[i][j] = 'X';
      else if (board[i][j] == 'V')
        board[i][j] = 'O';
    }
  }
    }
};