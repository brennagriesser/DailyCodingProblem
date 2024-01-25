class LengthOfLongestSubstring:
    def solution(self, s: str) -> int:
        starting_index = max_length = 0
        char_array = {}
        for i, character in enumerate(s):
            if char_array.get(character, -1) >= starting_index:
                starting_index = char_array[character] + 1
            max_length = max(max_length, i - starting_index + 1)
            char_array[character] = i
        return max_length

    def test_one(self) -> str:
        max_length = self.solution("abcabcbb")
        if max_length == 3:
            return "Test One: Success"
        else:
            return "Test One: Failure"

    def test_two(self) -> str:
        max_length = self.solution("bbbbb")
        if max_length == 1:
            return "Test Two: Success"
        else:
            return "Test Two: Failure"

    def test_three(self) -> str:
        max_length = self.solution("pwwkew")
        if max_length == 3:
            return "Test Three: Success"
        else:
            return "Test Three: Failure"

    def test_four(self) -> str:
        max_length = self.solution("dvdf")
        if max_length == 3:
            return "Test Four: Success"
        else:
            return "Test Four: Failure"



longest_sub_string = LengthOfLongestSubstring();
print(longest_sub_string.test_one())
print(longest_sub_string.test_two())
print(longest_sub_string.test_three())
print(longest_sub_string.test_four())
