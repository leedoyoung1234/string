#include <string>
#include <vector>

class StringSimilarity {
	const int MAX_SCORE = 60;
public:
	int calculateSimilarity(const std::string& str1, const std::string& str2) {
		int similarity = calculatekLengthSimilarity(str1, str2);
		return similarity;
	}
	int calculatekLengthSimilarity(const std::string& str1, const std::string& str2) {
		int longLength = std::max(str1.length(), str2.length());
		int shortLength = std::min(str1.length(), str2.length());
		if (isZeroLength (shortLength)) return 0;
		if (isSameLength(longLength,shortLength))return MAX_SCORE;
		if (isMoreDoblueLenth(longLength, shortLength))return 0;
		return calculatePartialSimilarity(longLength, shortLength);
	}
private :
	int calculatePartialSimilarity(int longLength, int shortLength) {
		double cap = longLength - shortLength;
		return (1 - cap / shortLength) * MAX_SCORE;
	}

	bool isSameLength(int longLength, int shortLength) {
		return (longLength == shortLength);
	}

	bool isMoreDoblueLenth(int longLength, int shortLength) {
		return (longLength >= shortLength * 2);
	}

	bool isZeroLength(int lenght) {
		return (lenght == 0);
	}
};