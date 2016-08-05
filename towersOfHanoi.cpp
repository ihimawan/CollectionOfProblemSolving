class sortTower{
    private:
        stack<int> towers[3];
    public:
        sortTower(){ //initiliatizing the towers
        
           for (int j = maxSize; j > 0; j--){
               towers[0].push(j);
           }
            
        }
        
        void moveTowers(int n, int from, int through, int to){
        
            if (n==1){
                towers[to].push_back(towers[from].top());
                towers[from].pop();
            }
            
            moveTowers(n-1, from, to, through);
            moveTowers(1, from , through, to);
            moveTowers(n-1, through, from ,to);
        }
};
