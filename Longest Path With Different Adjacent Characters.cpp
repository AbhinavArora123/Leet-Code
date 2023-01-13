class Solution {
int maxPath=0;
public:
    int longestPath(vector<int>& parent, string s) {

        // Creating adjacency list
        vector<vector<int>> a(parent.size());
    
        for (int i = 1; i < parent.size(); i++) {
            a[parent[i]].push_back(i);
        }

        // dfs from root node
        dfs(0, a, s);

        return maxPath + 1;  // since we have to return no. of vertices in path length, so adding +1
    }

        int dfs(int root, vector<vector<int>>& a, string& s) {
        int maxPath1=0;//first longest Path
        int maxPath2=0;//second longest Path
        for(int child:a[root]){
            int pathlength=dfs(child,a,s); //longest path for children node
            pathlength=s[child]==s[root]?0:pathlength+1;
                
            if(pathlength>=maxPath1){
                maxPath2=maxPath1;
                maxPath1=pathlength;
            }
            else if(pathlength>=maxPath2)
                maxPath2=pathlength;
        }
        maxPath = max(maxPath,maxPath1+maxPath2); //updating global maxPath

        return maxPath1; //return longest path for children node
    }
};