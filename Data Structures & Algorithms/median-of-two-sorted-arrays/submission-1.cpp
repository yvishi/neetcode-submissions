class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<int> total;
        int i=0,j=0;
        while(i<n && j<m){
            if (nums1[i] <= nums2[j])
                total.push_back(nums1[i++]);
            else
                total.push_back(nums2[j++]);
        }
        while(i<n){
            total.push_back(nums1[i++]);
        }
        while(j<m){
            total.push_back(nums2[j++]);
        }
        if((n+m)%2==0){
            return((double)(total[(n+m)/2-1]+total[(n+m)/2])/2);
        }
        return((total[(n+m+1)/2-1]));
                
    }
};
