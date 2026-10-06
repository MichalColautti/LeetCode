class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return -1001;

        sort(nums.begin(), nums.end());

        int result = nums[0] + nums[1] + nums[nums.size() - 1];

        for (int i = 0; i < (int)nums.size(); i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target) {
                    return sum;
                }
                
                int closenes = target - sum;
                if(abs(closenes) < abs(target - result)) {
                    result = sum;
                }

                if(closenes < 0) {
                    k--;
                }
                else if (closenes > 0)
                {
                    j++;
                }
            }
        }
        
        return result;
    }
};