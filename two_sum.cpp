// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TwoSum {
public:
       void test_case_one();
       void test_case_two();
       std::vector<int> solution(const std::vector<int>& nums, int target);
};

std::vector<int> TwoSum::solution(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> nums_map;
    int nums_size = nums.size();

    for (int i = 0; i < nums_size; i++) {
        int sum_num = target - nums[i];
        if (nums_map.count(sum_num)) {
            return {nums_map[sum_num], i};
        }
        nums_map[nums[i]] = i;
    }

    return {};
}

void TwoSum::test_case_one() {
    TwoSum two_sum;
    
    auto test_one = two_sum.solution({2,7,11,15}, 9);
    
    std::vector<int> solution_one = {0, 1};
    std::vector<int> solution_two = {1, 0};
    
    if (test_one == solution_one || test_one == solution_two) {
        cout<<"Test Case One: Success";
    } else {
        cout<<"Test Case One: Failure";
    }
}

void TwoSum::test_case_two() {
    TwoSum two_sum;
    
    auto test_two = two_sum.solution({3, 2, 4}, 6);
    
    std::vector<int> solution_one = {1, 2};
    std::vector<int> solution_two = {2, 1};
    
    if (test_two == solution_one || test_two == solution_two) {
        cout<<"Test Case One: Success";
    } else {
        cout<<"Test Case One: Failure";
    }
}


int main() {
    TwoSum two_sum;
    
    two_sum.test_case_one();
    cout<<"\n";
    two_sum.test_case_two();

    return 0;
}