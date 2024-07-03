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

        if ((shorterLength == 3) && (longerLength == 5))
        {
            return 20;
        }

        if ((shorterLength == 2) && (longerLength == 3))
        {
            return 30;
        }

        return 0;
    }

private:
    const int MAX_SCORE_OF_LENGTH = 60;
};