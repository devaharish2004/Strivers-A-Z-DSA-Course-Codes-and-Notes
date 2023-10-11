class Solution {
public:
	//Function to return list containing vertices in Topological order.
	bool findCycle(int V, vector<int> adj[])
	{
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

        int count = 0;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			count++;
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

        if(count == V)
        {
            return false;
        }

        return true;

	}
};