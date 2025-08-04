#include <vector>
using namespace std;

class Solution {
public:
    int doOverlap(vector<int> L1, vector<int> R1, vector<int> L2, vector<int> R2) {
        //l1 is the top left of rectangle one, R1 is the bottom right of rectangle one
        //L2 is the top left of rectangle two, R2 is the bottom right of rectangle two
        
        //The rectangles do not overlap if both
        //One rectangle is above top edge of the other rectangle
        if(R1[1] > L2[1] || R2[1] > L1[1])
        {
            return false;
        }
        //One rectangle is on left side of left edge of other rectangle
        if(L1[0] > R2[0] || L2[0] > R1[0])
        {
            return false;
        }
        
        return true;

    }
};
