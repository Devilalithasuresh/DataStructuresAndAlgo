class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0;
        int r=heights.size()-1;
        int area=0;
        while(l<r){
            area=max(area,(r-l)*min(heights[l],heights[r]));
            if(heights[r]>heights[l]){
                l++;
            }
            else{
              r--;
            }
        }
        return area;
    }
};
