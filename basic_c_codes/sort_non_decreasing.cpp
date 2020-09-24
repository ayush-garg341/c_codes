#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int>Merge_numbers(A.size());
        int leftPointer{0};
        int rightPointer{static_cast<int>(A.size()-1)};
        int index{rightPointer};
        while(leftPointer<=rightPointer){
            int leftSquare = A[leftPointer]*A[leftPointer];
            int rightSquare = A[rightPointer]*A[rightPointer];
            if(leftSquare>rightSquare){
                Merge_numbers[index]=leftSquare;
                leftPointer++;
                index--;
            }
            else{
                Merge_numbers[index]=rightSquare;
                rightPointer--;
                index--;
            }
        }
        
        return Merge_numbers;
    }
        
};

int main(){
  Solution soln;
  vector<int> A={-4,-1,0,3,10};
  soln.sortedSquares(A);
  return 0;
}
