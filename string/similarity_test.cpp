#include "gmock/gmock.h"
#include "similarity.cpp"

/*
TEST(SimilarityTest, TestLevenshteinDistance) {
	EXPECT_EQ(levenshtein_distance("kitten", "sitting"), 3);
	EXPECT_EQ(levenshtein_distance("flaw", "lawn"), 2);
	EXPECT_EQ(levenshtein_distance("intention", "execution"), 5);
	EXPECT_EQ(levenshtein_distance("", ""), 0);
	EXPECT_EQ(levenshtein_distance("abc", ""), 3);
	EXPECT_EQ(levenshtein_distance("", "abc"), 3);
}
*/

class SimilarityTest : public ::testing::Test {
public:
	StringSimilarity similarity;
	void calculateSimilarity(const std::string& str1, const std::string& str2, int expected) {
		EXPECT_EQ(expected, similarity.calculateSimilarity(str1, str2));
	}
};

TEST_F(SimilarityTest, SameLength1) {
	calculateSimilarity("ASD", "DSA", 60);
}
TEST_F(SimilarityTest, DifferentLength1) {
	calculateSimilarity("A", "BB", 0);
}
TEST_F(SimilarityTest, DifferentLength2) {
	calculateSimilarity("AAABB", "BAA", 20);
}
TEST_F(SimilarityTest, DifferentLength3) {
	calculateSimilarity("AA", "AAE", 30);
}
int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}