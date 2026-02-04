#include <string>
#include <iostream>
#include <fstream>

static bool open_files(std::string& nameInputFile, std::string& nameOutputFile,
    std::ifstream& inputFile, std::ofstream& outputFile)
{
    inputFile.open(nameInputFile, std::ios::in);
    outputFile.open(nameOutputFile, std::ios::out);
    if (!inputFile || !outputFile)
    {
        std::cerr << "Failed to open files" << std::endl;
        inputFile.close();
        outputFile.close();
        return (false);
    }
    return (true);
}

static void read_and_replace(char** argv, std::ifstream& inputFile,
    std::ofstream& outputFile)
{
    std::string oldStr = argv[2];
    std::string newStr = argv[3];
    std::string line;
    size_t pos = 0;
    size_t prev = 0;
    std::string replacedLine;

    if (oldStr.empty())
        return;

    while(std::getline(inputFile, line))
    {   
        replacedLine.clear();
        prev = 0;
        
        while ((pos = line.find(oldStr, prev) ) != std::string::npos)
        {
            replacedLine.append(line, prev, pos - prev);
            replacedLine.append(newStr);
            prev = pos + oldStr.length();
        }
        replacedLine.append(line.substr(prev));
        
        if(!inputFile.eof())
            outputFile << replacedLine << std::endl;
        else
            outputFile << replacedLine;
    }
}

int main(int argc, char** argv)
{
    std::string nameInputFile;
    std::string nameOutputFile;
    std::ifstream inputFile;
    std::ofstream outputFile;

    (void)argv;
    if (argc != 4)
        return (std::cerr << "ERROR: wrong number of argument!!\n", 1); 
    nameInputFile = argv[1];
    nameOutputFile = std::string(argv[1]) + ".replace";
    if(!open_files(nameInputFile, nameOutputFile, inputFile, outputFile))
        return (1);
    read_and_replace(argv, inputFile, outputFile);
    inputFile.close();
    outputFile.close();
    return (0);
}
