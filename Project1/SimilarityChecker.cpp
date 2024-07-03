#include <string>

using namespace std;

class SimilarityChecker
{
public:
    int getScoreOfLength(const string& str1, const string& str2)
    {
        int shorterLength = min(str1.length(), str2.length());
        int longerLength = max(str1.length(), str2.length());;

        if (shorterLength == longerLength)
        {
            return MAX_SCORE_OF_LENGTH;
        }

        if ((shorterLength == 1) && (longerLength == 2))
        {
            return 0;
        }

        return ((2 * shorterLength - longerLength) * MAX_SCORE_OF_LENGTH / shorterLength);
    }

private:
    const int MAX_SCORE_OF_LENGTH = 60;
};