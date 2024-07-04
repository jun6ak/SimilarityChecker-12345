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
    }

    void checkScoreOfCharacters(string str1, string str2, int score)
    {
        EXPECT_EQ(score, similarityChecker.getScoreOfCharacters(str1, str2));
    }
};

TEST_F(SimilarityCheckTestFixture, GetScore_ASD_DSA) {
    string str1 = "ASD";
    string str2 = "DSA";

    checkScoreOfLength(str1, str2, 60);
    checkScoreOfCharacters(str1, str2, 40);
}

TEST_F(SimilarityCheckTestFixture, GetScoreOfLength_A_BB) {
    string str1 = "A";
    string str2 = "BB";

    checkScoreOfLength(str1, str2, 0);
    checkScoreOfCharacters(str1, str2, 0);
}

TEST_F(SimilarityCheckTestFixture, GetScoreOfLength_A_BBB) {
    string str1 = "A";
    string str2 = "BBB";

    checkScoreOfLength(str1, str2, 0);
    checkScoreOfCharacters(str1, str2, 0);
}

TEST_F(SimilarityCheckTestFixture, GetScoreOfLength_AAABB_BAA) {
    string str1 = "AAABB";
    string str2 = "BAA";
    checkScoreOfLength(str2, str1, 20);
    checkScoreOfCharacters(str1, str2, 40);
}

TEST_F(SimilarityCheckTestFixture, GetScoreOfLength_AA_AAE) {
    string str1 = "AA";
    string str2 = "AAE";

    checkScoreOfLength(str2, str1, 30);
    checkScoreOfCharacters(str2, str1, 32);
}

TEST_F(SimilarityCheckTestFixture, GetScoreOfLength_AaA_AAE) {
    string str1 = "AaA";
    string str2 = "AAE";

    checkScoreOfLength(str2, str1, 60);
    checkScoreOfCharacters(str2, str1, 32);
}
