class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph.assign(numCourses, {});
        into.assign(numCourses, 0);
        for (auto &edge : prerequisites) {
            int start = edge[1];
            int end = edge[0];
            graph[start].push_back(end);
            into[end]++;
        }

        vector<int> finish;
        for (int i = 0; i < numCourses; i++) {
            if (into[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            finish.push_back(cur);
            q.pop();
            for (auto next : graph[cur]) {
                into[next]--;
                if (into[next] == 0) {
                    q.push(next);
                }
            }
        }

        if (finish.size() == numCourses) {
            return finish;
        }

        return {};
    }

    vector<vector<int>> graph;
    queue<int> q;
    vector<int> into;
};