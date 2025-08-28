public class Solution {
    public void dfs1(int i, List<bool> vis, Stack<int> st, List<List<int>> adj) {
        vis[i] = true;
        foreach (var j in adj[i]) {
            if (!vis[j]) {
                dfs1(j, vis, st, adj);
            }
        }
        st.Push(i);
    }
    public void dfs2(int i,ref bool flag, List<bool> vis1, List<bool> vis2, List<List<int>> adj) {
        vis1[i] = true;
        vis2[i] = true;
        Console.WriteLine(i);
        foreach (var j in adj[i]) {
            if (!vis1[j]) {
                dfs2(j,ref flag, vis1, vis2, adj);
                vis2[j] = false;
            }
            else if (vis1[j]  && vis2[j]) {
                Console.WriteLine("a");
                flag = true;
                return;
            }
        }
    }
    public bool CanFinish(int numCourses, int[][] pre) {
        int n = pre.Length;
        List<List<int>> adj = Enumerable.Range(0, numCourses + 1).Select(_ => new List<int>()).ToList();
        for (int i = 0;i < n; i++) {
            adj[pre[i][0]].Add(pre[i][1]);
        }
        List<bool> vis1 = Enumerable.Repeat(false, numCourses + 1).ToList();
        List<bool> vis2 = Enumerable.Repeat(false, numCourses + 1).ToList();
        List<bool> vis = Enumerable.Repeat(false, numCourses + 1).ToList();
        bool flag = false;
        Stack<int> st = new Stack<int>();
        for (int i = 0;i < numCourses; i++) {
            if (!vis[i]) {
                dfs1(i, vis, st, adj);
            }
        }
        while (st.Count != 0) {
            int i = st.Pop();
            if (!vis1[i]) {
                dfs2(i,ref flag, vis1, vis2, adj);
            }
        }
        return !flag;
    }
}