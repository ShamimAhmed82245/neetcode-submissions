class Solution {
public:
    int calHours(vector<int>& piles,int k){
        int h =0;
        for(auto i:piles){
            h+=(i/k);
            if(i%k!=0) h+=1;
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 1000000000;
        int mid;
        while(low<high){
            mid = low + (high - low) / 2;
            cout<<mid<<endl;
            if(calHours(piles,mid)<=h) high=mid;
            else low = mid+1;
        }
        cout<<mid<<" "<<low<<" "<<high<<endl;
        return low;
    }
};
