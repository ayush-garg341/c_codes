#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()<3){
            return false;
        }   
        
        int decreasingFound{0};
        
        for(int i{1}; i<A.size();i++){
            if(A[i]>A[i-1] && i!=A.size()-1 && !decreasingFound){
                continue;
            }
            else if(A[i] < A[i-1] && i!=1){
                decreasingFound = 1;
                continue;
            }
            else{
                return false;
            }
        }
        
        return true;
        
    }
};


int main(){
  Solution soln;
  vector<int> A={0, 1, 2, 3, 4, 5, 4, 2, 2, 1};
  cout << soln.validMountainArray(A) << "\n";
  
  return 0;
}
