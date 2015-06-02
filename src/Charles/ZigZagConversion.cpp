#include <iostream>
#include <string>

/**
 *The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)


 *P   A   H   N
 *A P L S I I G
 *Y   I   R
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:

 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */


/**
 * What's zigzag
 *
 * An example:
 *
 * string "PAYPALISHIRING", numRows = 4
 * P  I  N
 * A LS IG
 * YA HR
 * P  I
 */

class Solution 
{
public:
    std::string convert(std::string s, int numRows) 
    {
        
        if (numRows == 1)
        {
            return s;
        }
        
        int eachTriangle = 2 * numRows - 2;
        int numTriangles = s.size() / eachTriangle;
        
        int maxCols = (numTriangles + 1) * (numRows - 1);
        char data[numRows][maxCols];
        int row = 0;
        int col = 0;
        int index = 0;
        std::string r;
        
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < maxCols; j++)
            {
                data[i][j] = ' ';
            }
        }
        
        
        for (int i = 0; i < numTriangles + 1; i++)
        {
            for (int j = 0; j < numRows && index < s.size(); j++)
            {
                data[j][col] = s[index++];
            }
            for (int k = 0; k < numRows - 2 && index < s.size(); k++)
            {
                col++;
                data[numRows-k-2][col] = s[index++];
            }
            col++;
        }
        
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < maxCols; j++)
            {
                if (data[i][j] != ' ')
                {
                    r.push_back(data[i][j]);
                }
            }
        }
        
        return r;
    }
};

int main(void)
{
    //test cases
    std::string s1("abcde");
    int numRows1 = 10;
    std::string s2("PAYPALISHIRING");
    int numRows2 = 3;

    Solution test;
    
    std::cout << test.convert(s1, numRows1) << std::endl;
    std::cout << test.convert(s2, numRows2) << std::endl;
}

