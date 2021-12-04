// 思路：从后往前减边，如果发现图变成了拓扑排序且只有一个根节点，那么这条边就是冗余边。
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        num = edges.size();
        for (int i = num - 1; i >= 0; i--) {
            if (topology(edges, i)) {
                return edges[i];
            }
        }

        return {};
    }

    bool topology(vector<vector<int>>& edges, int passEdge) {
        vector<vector<int>> graph;
        graph.assign(num + 1, {});  
        vector<int> into(num + 1, 0);    

        for (int i = 0; i< num; i++) {
            if (i == passEdge) {
                continue;
            }
            int start = edges[i][0];
            int end = edges[i][1];
            graph[start].push_back(end);
            into[end]++;
        } 
        queue<int> q;
        for (int i = 1; i <= num; i++) {
            if (into[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;
        if (q.size() != 1) {
            return false;
        }
        
        while (!q.empty()) {
            int cur = q.front();
            cnt++;
            q.pop();
            for (auto next : graph[cur]) {
                if (--into[next] == 0) {
                    q.push(next);
                }
            }
        }
        cout<<cnt<<num<<endl;
        return cnt == num;
    }
    int num;
};