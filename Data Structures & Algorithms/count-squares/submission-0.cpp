class CountSquares {
    private:
    //mapping a combined key of coordinates to their count
    unordered_map<long,int> ptsCount;
    //vector containing points
    vector<vector<int>> pts;
    //combines two integers into a long key
    long getKey(int x,int y){
        return(static_cast<long>(x)<<32)|(static_cast<long>(y));
    }
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        long key = getKey(point[0],point[1]);
        ptsCount[key]++; //increment count for this pt
        pts.push_back(point); //add point to vectors
    }
    
    int count(vector<int> point) {
        int res = 0;
        int px = point[0],py = point[1];

        //iterates over all points to find potential square corners
        for(const auto& pt: pts){
            int x =pt[0],y=pt[1];
            //skip if square is not formed (length!=breadth)
            if(abs(py-y)!=abs(px-x) || x == px || y==py){
                continue;
            }
            //check for other two corners of the square 
            res+= ptsCount[getKey(x,py)] * ptsCount[getKey(px,y)];
        }
        return res;
    }
};
