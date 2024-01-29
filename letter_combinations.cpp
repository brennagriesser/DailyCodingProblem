// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

#include <iostream>
#include <vector>

using namespace std;

class LetterCombinations {
public:
  std::vector < string > solution (string digits);
  void test_case_one ();
  void test_case_two ();
  void test_case_three ();
};

std::vector<std::string> LetterCombinations::solution (std::string digits) {
    if (digits.empty ()) return {};

    std::vector<std::string> phone_pad =
        { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    std::vector<std::string> letter_combo;
    letter_combo.push_back("");

    for (auto num : digits) {
	// Iterate through digits to get number
	int key = num - '0';
	std::vector < string > temp;
        for (auto option:phone_pad[key]) {
            // Iterate through phone pad to get letter options
            for (auto combo:letter_combo) {
                // Iterate through letter combo to add onto start of combo
                temp.push_back (combo + option);
            }
	}
	letter_combo.clear ();
	letter_combo = temp;
    }
    return letter_combo;
}

void LetterCombinations::test_case_one() {
    LetterCombinations letter_combinations;

    const std::vector<std::string> test_one = letter_combinations.solution("23");
    const std::vector<std::string> solution_one = {"ad","bd","cd","ae","be","ce","af","bf","cf"};

    if (test_one == solution_one) {
        cout << "Test One: Success";
    } else {
        cout << "Test One: Failure";
    }
}

void LetterCombinations::test_case_two() {
    LetterCombinations letter_combinations;

    const std::vector<std::string> test_two = letter_combinations.solution("");
    const std::vector<std::string> solution_two = {};

    if (test_two == solution_two) {
        cout << "Test One: Success";
    } else {
        cout << "Test One: Failure";
    }
}

void LetterCombinations::test_case_three() {
    LetterCombinations letter_combinations;

    const std::vector<std::string> test_three = letter_combinations.solution("78");
    const std::vector<std::string> solution_three = {"pt","qt","rt","st","pu","qu","ru","su","pv","qv","rv","sv"};

    if (test_three == solution_three) {
        cout << "Test Three: Success";
    } else {
        cout << "Test Three: Failure";
    }
}


int main () {
    LetterCombinations letter_combinations;

    letter_combinations.test_case_one();
    cout << "\n";
    letter_combinations.test_case_two();
    cout << "\n";
    letter_combinations.test_case_three();

    return 0;
}
