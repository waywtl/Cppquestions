#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

//图像渲染
class Solution {
public:
    void Helper(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor)
    {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size()
            || image[sr][sc] != oldColor || image[sr][sc] == newColor)
            return;
        image[sr][sc] = newColor;
        Helper(image, sr - 1, sc, newColor, oldColor);
        Helper(image, sr, sc + 1, newColor, oldColor);
        Helper(image, sr, sc - 1, newColor, oldColor);
        Helper(image, sr + 1, sc, newColor, oldColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        Helper(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};

//被围绕的区域
//方法1：使用额外空间做标记
class Solution {
public:
    void dfs(vector<vector<char>>& board, int curX, int curY, vector<vector<int>>& book, int row, int col)
    {
        if (curX < 0 || curY < 0 || curX >= row || curY >= col
            || book[curX][curY] == 1 || board[curX][curY] == 'X')
            return;
        book[curX][curY] = 1;
        dfs(board, curX - 1, curY, book, row, col);
        dfs(board, curX, curY - 1, book, row, col);
        dfs(board, curX, curY + 1, book, row, col);
        dfs(board, curX + 1, curY, book, row, col);
    }

    void solve(vector<vector<char>>& board)
    {
        if (board.size() <= 2 || board[0].size() <= 2)
            return;
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> book(row, vector<int>(col, 0));
        for (int i = 0; i < col; ++i)
        {
            if (board[0][i] == 'O')
                dfs(board, 0, i, book, row, col);
            if (board[row - 1][i] == 'O')
                dfs(board, row - 1, i, book, row, col);
        }
        for (int i = 1; i < row - 1; ++i)
        {
            if (board[i][0] == 'O')
                dfs(board, i, 0, book, row, col);
            if (board[i][col - 1] == 'O')
                dfs(board, i, col - 1, book, row, col);
        }
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (book[i][j] == 0 && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};

//方法2：不使用额外空间
class Solution {
public:
    void dfs(vector<vector<char>>& board, int curX, int curY, int row, int col)
    {
        if (curX < 0 || curY < 0 || curX >= row || curY >= col
            || board[curX][curY] == 'X' || board[curX][curY] == 'o')
            return;
        board[curX][curY] = 'o';
        dfs(board, curX - 1, curY, row, col);
        dfs(board, curX, curY - 1, row, col);
        dfs(board, curX, curY + 1, row, col);
        dfs(board, curX + 1, curY, row, col);
    }

    void solve(vector<vector<char>>& board)
    {
        if (board.size() <= 2 || board[0].size() <= 2)
            return;
        int row = board.size();
        int col = board[0].size();
        //vector<vector<int>> book(row, vector<int>(col, 0));
        for (int i = 0; i < col; ++i)
        {
            if (board[0][i] == 'O')
                dfs(board, 0, i, row, col);
            if (board[row - 1][i] == 'O')
                dfs(board, row - 1, i, row, col);
        }
        for (int i = 1; i < row - 1; ++i)
        {
            if (board[i][0] == 'O')
                dfs(board, i, 0, row, col);
            if (board[i][col - 1] == 'O')
                dfs(board, i, col - 1, row, col);
        }
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (board[i][j] == 'o')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};

//岛屿的数量
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int curX, int curY, int row, int col)
    {
        if (curX < 0 || curY < 0 || curX >= row || curY >= col
            || grid[curX][curY] == '2' || grid[curX][curY] == '0')
            return;
        grid[curX][curY] = '2';
        dfs(grid, curX - 1, curY, row, col);
        dfs(grid, curX, curY + 1, row, col);
        dfs(grid, curX, curY - 1, row, col);
        dfs(grid, curX + 1, curY, row, col);
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j, row, col);
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};

//岛屿的最大面积
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int curX, int curY, int row, int col, int& area)
    {
        if (curX < 0 || curY < 0 || curX >= grid.size() || curY >= grid[0].size()
            || grid[curX][curY] == 2 || grid[curX][curY] == 0)
            return;
        grid[curX][curY] = 2;
        ++area;
        dfs(grid, curX - 1, curY, row, col, area);
        dfs(grid, curX, curY + 1, row, col, area);
        dfs(grid, curX, curY - 1, row, col, area);
        dfs(grid, curX + 1, curY, row, col, area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        int maxArea = 0;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == 1)
                {
                    int area = 0;
                    dfs(grid, i, j, row, col, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};