\*
Author: allannozomu
Runtime: 4 ms
Memory: 8.6 MB*\

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m - 1; i >= 0; --i){
            nums1[nums1.size() - m + i] = nums1[i];
        }
        int index1 = 0, index2 = 0, index = 0;
        
        while(index1 < m && index2 < n){
            int num1 = nums1[index1 + nums1.size() - m];
            int num2 = nums2[index2];
            
            if (num1 < num2){
                nums1[index] = num1;
                index1++;
            } else {
                nums1[index] = num2;
                index2++;
            }
            index++;
        }
        while(index1 < m){
            nums1[index++] = nums1[index1++ + nums1.size() - m];
        }
        while(index2 < n){
            nums1[index++] = nums2[index2++];
        }
    }
};