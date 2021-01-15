#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      int num_size = nums.size();
      vector<int> missing_elements;
      for(int i=0; i<num_size; i++){
	int position = nums[i];
	if(nums[abs(position)-1]>0){
	  nums[abs(position)-1] *= -1;
	  }
	  
	}

      for(int j = 0; j<num_size ; j++){
	if(nums[j]>0){
	  missing_elements.push_back(j+1);
	}
      }
      
      return missing_elements;
      
    }
};


int main(){
  Solution soln;
  vector<int> nums={4,3,2,7,8,2,3,1};
  soln.findDisappearedNumbers(nums);
  return 0;
}
