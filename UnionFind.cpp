class UnionFind
{
    private:
        vector<int> root, rank;
    public:
        UnionFind(int sz): root(sz), rank(sz)
        {
            for (int index=0; index<sz; index++)
            {
                root[index] = index;
                rank[index] = 1;
            }
        }
    
        int findNode(int x)
        {
            if (x == root[x])
                return x;
            return root[x] = findNode(root[x]);
        }
  
        void unionSet(int x, int y)
        {
            int rootOfX = findNode(x);
            int rootOfY = findNode(y);
            
            if (rootOfX != rootOfY)
            {
                if (rank[rootOfX] > rank[rootOfY])
                {
                    root[rootOfY] = root[rootOfX];
                }
                else if (rank[rootOfX] < rank[rootOfY])
                {
                    root[rootOfX] = root[rootOfY];
                }
                else
                {
                    root[rootOfY] = rootOfX;
                    rank[rootOfX]++;
                }
            }
        }
    
        bool isConnected(int x, int y)
        {
            return findNode(x) == findNode(y);
        }
};
