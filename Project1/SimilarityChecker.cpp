#include <string>

using namespace std;

class SimilarityChecker
{
public:
    int getScoreOfLength(const string& str1, const string& str2)
    {
        if (str1.length() == str2.length())
        {
            return MAX_SCORE_OF_LENGTH;
        }

        if (((str1.length() == 1) && (str2.length() == 2))
            || ((str1.length() == 2) && (str2.length() == 1)))
        {
            return 0;
        }

        if (((str1.length() == 5) && (str2.length() == 3))
            || ((str1.length() == 3) && (str2.length() == 5)))
        {
            return 20;
        }

        if (((str1.length() == 2) && (str2.length() == 3))
            || ((str1.length() == 3) && (str2.length() == 2)))
        {
            return 30;
        }

        return 0;
    }

private:
    const int MAX_SCORE_OF_LENGTH = 60;
};