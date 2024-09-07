//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Function to perform topological sort on the graph
vector<int> topological_sort(int N, vector<int> adj[]) {
    vector<int> indegree(N, 0);

    // Calculate in-degrees of all nodes
    for (int i = 0; i < N; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    // Add nodes with in-degree 0 to the queue
    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;

    // Process nodes in topological order
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        // Decrease in-degrees of neighbors
        for (auto i : adj[node]) {
            indegree[i]--;
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
    }

    // Check if the topological sort includes all nodes
    if (ans.size() == N) return ans;
    return {};  // Return empty if a cycle is detected
}

// Function to find the order of characters in an alien language
string findOrder(string dict[], int n, int k) {
    vector<int> adj[k];  // Graph with k nodes for k characters

    // Build the graph by comparing adjacent words in the dictionary
    for (int i = 0; i < n - 1; i++) {
        string s1 = dict[i];
        string s2 = dict[i + 1];

        // Compare characters of the two words until a mismatch is found
        int length = min(s1.size(), s2.size());
        for (int j = 0; j < length; j++) {
            if (s1[j] != s2[j]) {
                // Map characters to indices (0-indexed)
                int u = s1[j] - 'a';
                int v = s2[j] - 'a';

                adj[u].push_back(v);  // Add directed edge
                break;  // Only the first differing character matters
            }
        }
    }

    // Perform topological sort on the graph to get the character order
    vector<int> ans = topological_sort(k, adj);
    
    // Convert the topological sort result to a string of characters
    string s = "";
    for (int i = 0; i < ans.size(); i++) {
        s += (char)(ans[i] + 'a');  // Map indices back to characters
    }

    return s;  // Return the character order
}
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends