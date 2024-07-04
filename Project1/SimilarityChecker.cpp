#include <string>
#include <vector>

using namespace std;

class SimilarityChecker
{
public:
    int getScoreOfCharacters(const string& str1, const string& str2)
    {
        bool letters[27] = { };

        for (int i = 0; i < str1.length(); i++)
        {
            for (int j = 0; j < str2.length(); j++)
            {
                if (str1[i] == str2[j])
                {
                    letters[str1[i] - 'A'] = true;
                }
            }
        }

        int sameCount = 0;

        for (int i = 0; i < str1.length(); i++)
        {
            if (letters[str1[i] - 'A'] == true)
            {
                sameCount++;
            }
        }

        for (int i = 0; i < str2.length(); i++)
        {
            if (letters[str2[i] - 'A'] == true)
            {
                sameCount++;
            }
        }

        int totoalCount = str1.length() + str2.length();

        return sameCount * MAX_SCORE_OF_CHARACTER / totoalCount;
    }

    int getScoreOfLength(const string& str1, const string& str2)
    {
        int shorterLength = min(str1.length(), str2.length());
        int longerLength = max(str1.length(), str2.length());

        if (true == isSame(shorterLength, longerLength))
        {
            return MAX_SCORE_OF_LENGTH;
        }

        if (true == isOverDouble(shorterLength, longerLength))
        {
            return 0;
        }

        return getLengthPoint(shorterLength, longerLength);
    }

private:
    const int MAX_SCORE_OF_LENGTH = 60;
    const int MAX_SCORE_OF_CHARACTER = 40;

    int getLengthPoint(int shorterLength, int longerLength)
    {
        return ((2 * shorterLength - longerLength) * MAX_SCORE_OF_LENGTH / shorterLength);
    }

    bool isSame(int shorterLength, int longerLength)
    {
        return shorterLength == longerLength;
    }

    bool isOverDouble(int shorterLength, int longerLength)
    {
        return (2 * shorterLength) <= longerLength;
    }
};