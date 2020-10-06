#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
      vector<int> sortedHeights(heights.size());
	int arrSize{static_cast<int>(heights.size())};
        int positions{0};
	for(int i{0}; i<arrSize; i++){
	  sortedHeights[i]=heights[i];
        }
        for(int i{0}; i<arrSize; i++){
            for(int j{i+1}; j < arrSize; j++){
                if(heights[j]<=heights[i]){
		  swap(heights[i], heights[j]);
                }
            }
        }
        
        for(int i{0}; i<arrSize; i++){
            if(heights[i]!=sortedHeights[i]){
                positions += 1;
            }
        }
        
        return positions;
    }
};

int main(){
  Solution soln;
  vector<int> A={1,1,4,2,1,3};
  cout << soln.heightChecker(A) << "\n";
  
  return 0;
}
