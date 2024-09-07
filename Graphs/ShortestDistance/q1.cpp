
// Optimised (Using Dijkstra) : 
// In this particular problem, since there is no adjacency list we can 
// say that the adjacent cell for a coordinate is 
// that cell which is either on the top, bottom, left, or right of the 
// current cell i.e, a cell can have a maximum of 4 cells adjacent to it 
// and can only move in these directions.


// Initial configuration:

// Queue: Define a Queue which would contain pairs of the type {diff, (row, col) }, 
// where ‘dist’ indicates the currently updated value of difference from source to the cell.
// Distance Matrix: Define a distance matrix that would contain the minimum difference from the source cell to that particular cell. 
// If a cell is marked as ‘infinity’ then it is treated as unreachable/unvisited.
// The Algorithm consists of the following steps :

// Start by creating a queue that stores the distance-node pairs in the form {dist,(row, col)} and 
// a dist matrix with each cell initialized with a very large number ( to indicate that they’re unvisited initially) and the source cell marked as ‘0’.
// We push the source cell to the queue along with its distance which is also 0.
// Pop the element at the front of the queue and look out for its adjacent nodes (left, right, bottom, and top cell).
//  Also, for each cell, check the validity of the cell if it lies within the limits of the matrix or not.
// If the current difference value of a cell from its parent is better than the previous difference indicated by the distance matrix,
//  we update the difference in the matrix and push it into the queue along with cell coordinates.
// A cell with a lower difference value would be at the front of the queue as opposed to a node with a higher difference. 
// The only difference between this problem and Dijkstra’s Standard problem is that 
// there we used to update the value of the distance of a node from the source and here we update the absolute difference of a node from its parent.
// We repeat the above three steps until the queue becomes empty or until we encounter the destination node.
// Return the calculated difference and stop the algorithm from reaching the destination node.
//  If the queue becomes empty and we don’t encounter the destination node, return ‘0’ indicating there’s no path from source to destination.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;//{dif,{row,col}}

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            //while taking out of queue if reached dest then that is ans;
            if(row == n-1 && col == m-1)return diff;

            for(int i=0;i<4;i++)
            {
                int newr = row + dr[i];
                int newc = col + dc[i];
                if(newr>=0 && newc>=0 && newr <n && newc<m)
                {
                    int newEffort = max(abs(heights[row][col]-heights[newr][newc]),diff);
                    if(newEffort<dist[newr][newc])
                    {
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort,{newr,newc}});
                    }   
                }
            }
        }
       return 0; //unreachable
    }
};