#include <string>
#include <vector>

using namespace std;

class SimilarityChecker
{
public:
    int getScoreOfCharacters(const string& str1, const string& str2)
    {
        updateBothExistedLetters(str1, str2);

        int sameCount = 0;
        sameCount += getSameCountWithBothExistedLetters(str1);
        sameCount += getSameCountWithBothExistedLetters(str2);

        int totalCount = 0;
        totalCount += getCapitalLettersCount(str1);
        totalCount += getCapitalLettersCount(str2);

        return ((sameCount * MAX_SCORE_OF_CHARACTER) / totalCount);
    }

    unsigned long long getCapitalLettersCount(const std::string& str)
    {
        int count = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (false == isCapitalLetter(str[i])) continue;

            count++;
        }

        return count;
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

    int getSameCountWithBothExistedLetters(const std::string& str)
    {
        int sameCount = 0;

        for (int i = 0; i < str.length(); i++)
        {
            if (false == letters[getCapitalIndex(str[i])]) continue;
            if (false == isCapitalLetter(str[i])) continue;

            sameCount++;
        }

        return sameCount;
    }

    int getCapitalIndex(const char ch)
    {
        return (ch - 'A');
    }

    void updateBothExistedLetters(const std::string& str1, const std::string& str2)
    {
        memset(letters, 0, sizeof(letters));

        for (int i = 0; i < str1.length(); i++)
        {
            for (int j = 0; j < str2.length(); j++)
            {
                if (false == isSame(str1[i], str2[j])) continue;
                if (false == isCapitalLetter(str1[i])) continue;

                letters[getCapitalIndex(str1[i])] = true;
            }
        }
    }

    bool isCapitalLetter(char ch)
    {
        return (('A' <= ch) && (ch <= 'Z'));
    }
};