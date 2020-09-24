#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int>Negative_numbers_square;
        vector<int>Positive_numbers_square;
        vector<int>Merge_numbers;
        unsigned int array_length{static_cast<unsigned int>(A.size())};
        for(int i{0}; i<array_length; i++){
            if(A[i]<0){
	      //cout<<A[i]<<"  "<<A[i]*A[i]<<"\n";
	      Negative_numbers_square.insert(Negative_numbers_square.begin(), A[i]*A[i]);
            }
            else{
	      //cout<<A[i]<<"  "<<A[i]*A[i]<<"\n";
                Positive_numbers_square.push_back(A[i]*A[i]);
            }
        }
        
        if(Positive_numbers_square.size()==0){
            return Negative_numbers_square;
        }
        
        if(Negative_numbers_square.size()==0){
            return Positive_numbers_square;
        }
        
        unsigned int j{0};
        unsigned int k{0};
	//cout<<"positive number size "<< Positive_numbers_square.size() << "\n";
	//cout<<"negative number size "<< Negative_numbers_square.size() << "\n";
        while(j<Negative_numbers_square.size() && k<Positive_numbers_square.size()){
            if(Negative_numbers_square[j] < Positive_numbers_square[k]){
                Merge_numbers.push_back(Negative_numbers_square[j]);
                j++;
            }
            else{
                Merge_numbers.push_back(Positive_numbers_square[k]);
                k++;
            }
        }

	//cout<<"j "<<j<<"\n";
	//cout<<"k "<<k<<"\n";
	
        if(k==Positive_numbers_square.size()){
            while(j<Negative_numbers_square.size()){
                Merge_numbers.push_back(Negative_numbers_square[j]);
                j++;
            }
        }
        else if(j==Negative_numbers_square.size()){
            while(k<Positive_numbers_square.size()){
                Merge_numbers.push_back(Positive_numbers_square[k]);
                k++;
            }
        }

	for(int l{0} ; l< Merge_numbers.size();l++){
	  cout<<Merge_numbers[l]<<"\n";
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
