#include <string>
#include <vector>
#include <set>

class StringSimilarity {
public:
	int calculateSimilarity(const std::string& str1, const std::string& str2) {
		int similarity = calculateLengthSimilarity(str1, str2);
		return calculateLengthSimilarity(str1, str2) + calculateAlphabetSimilarity(str1, str2);
	}

private :
	const int MAX_LENGTH_SCORE = 60;
	const int MAX_ALPHBET_SCORE = 40;
	int calculateAlphabetSimilarity(const std::string& str1, const std::string& str2) {
		std::set<char> charSet1 = getcharSet(str1);
		std::set<char> charSet2 = getcharSet(str2);

		if (isSameAlphabet(charSet1, charSet2)) return MAX_ALPHBET_SCORE;
		
		return calculatePartialAlphabetSimilarity(charSet1, charSet2);
	}

	int calculatePartialAlphabetSimilarity(const std::set<char>& charSet1, const std::set<char>& charSet2) {
		int score = 0;
		std::set<char> mergedCharSet2 = mergeSet(charSet1, charSet2);
		int towSetSum = charSet1.size() + charSet2.size();
		int totalCnt = mergedCharSet2.size();
		int sameCnt = towSetSum - totalCnt;

		return (sameCnt * 40) / totalCnt;
	}

	std::set<char> getcharSet(const std::string& str) {
		std::set<char> charSet;
		for (char ch : str) {
			charSet.insert(ch);
		}
		return charSet;
	}
	bool isSameAlphabet(std::set<char> charSet1, std::set<char> charSet2) {
		return (charSet1 == charSet2);
	}

	std::set<char> mergeSet(const std::set<char>& charSet1, const std::set<char>& charSet2) {
		std::set<char> mergedSet;
		for (char ch : charSet1) {
			mergedSet.insert(ch);
		}
		for (char ch : charSet2) {
			mergedSet.insert(ch);
		}
		return mergedSet;
	}

	int calculateLengthSimilarity(const std::string& str1, const std::string& str2) {
		int longLength = std::max(str1.length(), str2.length());
		int shortLength = std::min(str1.length(), str2.length());
		if (isZeroLength(shortLength)) return 0;
		if (isSameLength(longLength, shortLength))return MAX_LENGTH_SCORE;
		if (isMoreDoblueLenth(longLength, shortLength))return 0;
		return calculatePartialLengthSimilarity(longLength, shortLength);
	}

	int calculatePartialLengthSimilarity(int longLength, int shortLength) {
		double cap = longLength - shortLength;
		return (1 - cap / shortLength) * MAX_LENGTH_SCORE;
	}

	bool isSameLength(int longLength, int shortLength) {
		return (longLength == shortLength);
	}

	bool isMoreDoblueLenth(int longLength, int shortLength) {
		return (longLength >= shortLength * 2);
	}

	bool isZeroLength(int lengh) {
		return (lengh == 0);
	}
};