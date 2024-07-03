#include "pch.h"
#include "../Project1/SimilarityChecker.cpp"

TEST(SimilarityTest, GetMaxScoreWhenSameLength) {
    string str1 = "ASD";
    string str2 = "DSA";

    SimilarityChecker checker;
    EXPECT_EQ(60, checker.getScoreOfLength(str1, str2));
}

TEST(SimilarityTest, GetScoreOfLength_A_BB) {
    string str1 = "A";
    string str2 = "BB";

    SimilarityChecker checker;
    EXPECT_EQ(0, checker.getScoreOfLength(str1, str2));
}

TEST(SimilarityTest, GetScoreOfLength_AAABB_BAA) {
    string str1 = "AAABB";
    string str2 = "BAA";

    SimilarityChecker checker;
    EXPECT_EQ(20, checker.getScoreOfLength(str1, str2));
}

TEST(SimilarityTest, GetScoreOfLength_AA_AAE) {
    string str1 = "AA";
    string str2 = "AAE";

    SimilarityChecker checker;
    EXPECT_EQ(30, checker.getScoreOfLength(str1, str2));
}