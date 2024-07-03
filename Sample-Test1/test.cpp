#include "pch.h"
#include "../Project1/SimilarityChecker.cpp"

TEST(SimilarityTest, GetScoreOfLength) {
    string str1 = "ASD";
    string str2 = "DSA";

    SimilarityChecker checker;
    EXPECT_EQ(60, checker.getScoreOfLength(str1, str2));
}
