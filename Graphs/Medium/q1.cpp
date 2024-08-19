//Basic bfs/dfs question solved myself

// class Solution {
// public:
//     void bfs(vector<vector<int>>& isConnected, queue<int>& q, vector<int>& vis) {
//         while (!q.empty()) {
//             int node = q.front();
//             q.pop();

//             for (int i = 0; i < isConnected.size(); i++) {
//                 if (isConnected[node][i] == 1 && !vis[i]) {
//                     vis[i] = 1;
//                     q.push(i);
//                 }
//             }
//         }
//     }

//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int m = isConnected.size();
//         vector<int> vis(m, 0);
//         int cnt = 0;

//         for (int i = 0; i < m; i++) {
//             if (!vis[i]) {
//                 vis[i] = 1;
//                 queue<int> q;
//                 q.push(i);
//                 bfs(isConnected, q, vis);
//                 cnt++;
//             }
//         }

//         return cnt;
//     }
// };
