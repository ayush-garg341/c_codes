#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int> umap;
        
        int nums_size = nums.size();
        
        vector<int> missing_elements; 
        
        for(int i=0; i<nums_size; i++){
            umap[i+1] = 0;
        }
        
        
        for(int j = 0; j< nums_size; j++){
            umap[nums[j]] += 1;
        }
        
        for (auto& it: umap) {
            if(it.second == 0){
                missing_elements.push_back(it.first);
            }  
        }
	
        return missing_elements;
        
    }
};


int main(){
  Solution soln;
  vector<int> nums={1, 2, 1};
  soln.findDisappearedNumbers(nums);
  return 0;
}
