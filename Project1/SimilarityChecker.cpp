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

        return 0;
    }

private:
    const int MAX_SCORE_OF_LENGTH = 60;
};