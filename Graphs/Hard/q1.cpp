// If any set 'O' is connected to the boundary then it cannot be surrounding then it cannot be surrounded by X.

//Algorithm:
// start from boundary O's & apply DFS or BFS then they will not be connected.

// class Solution {
// public:
//     void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&mat,int delrow[],int delcol[])
//     {
//         vis[row][col] = 1;
//         int n = mat.size();
//         int m = mat[0].size();

//         //check for top,right,bottom,left
//         for(int i =0;i<4;i++)
//         {
//             int nrow = row+delrow[i];
//             int ncol = col+delcol[i];
//             if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O'){
//                 dfs(nrow,ncol,vis,mat,delrow,delcol);
//             }
//         }
//     }
//     void solve(vector<vector<char>>& mat) {
//         int n = mat.size();
//         int m = mat[0].size();
//         vector<vector<int>>vis(n,vector<int>(m,0));

//         int delrow[]={-1,0,0,1};
//         int delcol[]={0,1,-1,0};
//         //we will do boundary traversal
//         for(int j =0;j<m;j++)
//         {
//             //first row
//             if(!vis[0][j] && mat[0][j] == 'O')
//             {
//                 dfs(0,j,vis,mat,delrow,delcol);
//             }

//             //last row
//             if(!vis[n-1][j] && mat[n-1][j]  == 'O')
//             {
//                 dfs(n-1,j,vis,mat,delrow,delcol);
//             }
//         }

//         for(int i =0;i<n;i++)
//         {
//             //first column
//             if(!vis[i][0] && mat[i][0] == 'O')
//             {
//                 dfs(i,0,vis,mat,delrow,delcol);
//             }

//             //last column
//             if(!vis[i][m-1] && mat[i][m-1]=='O')
//             {
//                 dfs(i,m-1,vis,mat,delrow,delcol);
//             }
//         }

//         for(int i =0;i<n;i++)
//         {
//             for(int j =0;j<m;j++)
//             {
//                 if(!vis[i][j] && mat[i][j] == 'O')
//                 {
//                     mat[i][j] = 'X';
//                 }
//             }
//         }
//     }
// };