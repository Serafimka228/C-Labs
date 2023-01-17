#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <exception>

class CheckIfBracketsCorrect 
{
public:
    
    void CheckTxtFile(std::ifstream& fileToCheck, std::ofstream& fileToWrite)
    {
        std::string string;
        int numberOfString = 0;
        while (std::getline(fileToCheck, string))
        {
            std::string str = string;
            bool isCorrect = CheckString(str);
            if (isCorrect)
            {
                std::cout << ++numberOfString << "] " << string + " - [Correct]" << std::endl;
                fileToWrite << string + " - [Correct]" << std::endl;
                _stack.clear();
            }

            if (!isCorrect)
            {
                std::cout << ++numberOfString << "] " << string + " - [Incorrect]" << std::endl;
                fileToWrite << string + " - [Incorrect]" << std::endl;
                _stack.clear();
            }
        }
    }

    bool CheckString(std::string string)
    {
        int k = sizeof(char) * string.size();
        for (int i = 0; i < k; i++)
        {
            if (string[i] == '(')
                _stack.push_back(string[i]);
            
            if (string[i] == ')')
                if (!(_stack.empty()))
                    if (_stack.back() != '(')
                        return false;
                    else
                        _stack.pop_back();
                else
                    return false;
            else
                _stack.size();
        }
        if(_stack.empty())
            return true;
        return false;
    }

private:

    std::vector<char> _stack;
};

int main()
{
    CheckIfBracketsCorrect check;
    try
    {
        std::ifstream file1;
        file1.open("file1.txt");
        std::cout << "file1.txt is open:" << std::endl;
        std::ofstream file2;
        file2.open("file2.txt");
        check.CheckTxtFile(file1, file2);
        file1.close();
        file2.close();
    }
    catch (std::exception& exception)
    {
        std::cout << exception.what();
    }
}

