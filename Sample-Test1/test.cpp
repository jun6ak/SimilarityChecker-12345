#include "pch.h"
#include "../Project1/SimilarityChecker.cpp"
#include <string>

using namespace std;

class SimilarityCheckTestFixture : public testing::Test {
protected:
    SimilarityChecker similarityChecker;

    void checkScoreOfLength(string str1, string str2, int score)
    {
        EXPECT_EQ(score, similarityChecker.getScoreOfLength(str1, str2));
        EXPECT_EQ(score, similarityChecker.getScoreOfLength(str2, str1));
    }
};

TEST_F(SimilarityCheckTestFixture, GetMaxScoreWhenSameLength) {
    string str1 = "ASD";
    string str2 = "DSA";

    checkScoreOfLength(str1, str2, 60);
}

TEST_F(SimilarityCheckTestFixture, GetScoreOfLength_A_BB) {
    string str1 = "A";
    string str2 = "BB";

    checkScoreOfLength(str1, str2, 0);
}

TEST_F(SimilarityCheckTestFixture, GetScoreOfLength_AAABB_BAA) {
    string str1 = "AAABB";
    string str2 = "BAA";
    checkScoreOfLength(str2, str1, 20);
}

TEST_F(SimilarityCheckTestFixture, GetScoreOfLength_AA_AAE) {
    string str1 = "AA";
    string str2 = "AAE";

    checkScoreOfLength(str2, str1, 30);
}