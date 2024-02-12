// Given an integer array height of length n, find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.

#include <iostream>
#include <vector>

using namespace std;

class maxArea {
public:
  int solution(const std::vector<int>& height);

  void test_case_one();
  void test_case_two();
  void test_case_three();
};

int maxArea::solution(const std::vector<int>& height) {
    int max_area = 0;
    int left_index = 0;
    int right_index = height.size() - 1;

    while (left_index < right_index) {
	    int current_area = std::min(height[left_index], height[right_index]) * (right_index - left_index);
	    max_area = std::max(max_area, current_area);

	    if (height[left_index] < height[right_index]) {
		    left_index++;
	    } else {
		    right_index--;
		}
	}
    return max_area;
}

void maxArea::test_case_one() {
    maxArea max_area;
    
    const int test_one = max_area.solution({1,8,6,2,5,4,8,3,7});
    const int solution_one = 49;
    
    if (test_one == solution_one) {
        cout << "Test One: Success!";
    } else {
        cout << "Test One: Failure.";
    }
}

void maxArea::test_case_two() {
    maxArea max_area;
    
    const int test_two = max_area.solution({12,3,2,1,5,3,8,10});
    const int solution_two = 70;
    
    if (test_two == solution_two) {
        cout << "Test One: Success!";
    } else {
        cout << "Test One: Failure.";
    }
}

void maxArea::test_case_three() {
    maxArea max_area;
    
    const int test_three = max_area.solution({1,1});
    const int solution_three = 1;
    
    if (test_three == solution_three) {
        cout << "Test One: Success!";
    } else {
        cout << "Test One: Failure.";
    }
}


int main () {
  maxArea max_area;
  
  max_area.test_case_one();
  cout << "\n";
  max_area.test_case_two();
  cout << "\n";
  max_area.test_case_three();

  return 0;
}