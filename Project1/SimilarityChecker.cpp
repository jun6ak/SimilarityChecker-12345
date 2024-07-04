#include <string>
#include <vector>

using namespace std;

class SimilarityChecker
{
public:
    int getScoreOfCharacters(const string& str1, const string& str2)
    {
        int sameCount = 0;
        int totalCount = 0;

        updateExistedLetters(str1, str2);

        sameCount += getSameCount(str1);
        sameCount += getSameCount(str2);

        totalCount = str1.length() + str2.length();

        return sameCount * MAX_SCORE_OF_CHARACTER / totalCount;
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
    bool letters[27];

    const int MAX_SCORE_OF_LENGTH = 60;
    const int MAX_SCORE_OF_CHARACTER = 40;

    int getLengthPoint(int shorterLength, int longerLength)
    {
        return ((2 * shorterLength - longerLength) * MAX_SCORE_OF_LENGTH / shorterLength);
    }

    bool isSame(int comp1, int comp2)
    {
        return comp1 == comp2;
    }

    bool isOverDouble(int shorterLength, int longerLength)
    {
        return (2 * shorterLength) <= longerLength;
    }

    int getSameCount(const std::string& str)
    {
        int sameCount = 0;

        for (int i = 0; i < str.length(); i++)
        {
            if (letters[str[i] - 'A'] == true)
            {
                sameCount++;
            }
        }

        return sameCount;
    }

    void updateExistedLetters(const std::string& str1, const std::string& str2)
    {
        memset(letters, 0, sizeof(letters));

        for (int i = 0; i < str1.length(); i++)
        {
            for (int j = 0; j < str2.length(); j++)
            {
                if (false == isSame(str1[i], str2[j])) continue;

                letters[str1[i] - 'A'] = true;
            }
        }
    }
};