#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string replaceText(std::string content, std::string s1, std::string s2)
{
    size_t pos;
    size_t found;
    std::string result;

    pos = 0;
    while ((found = content.find(s1, pos)) != std::string::npos)
    {
        result += content.substr(pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    result += content.substr(pos);

    return result;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Error: wrong number of arguments." << std::endl;
        std::cerr << "Usage: ./sed <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty." << std::endl;
        return 1;
    }

    std::ifstream inputFile(filename);

    if (!inputFile)
    {
        std::cerr << "Error: could not open input file." << std::endl;
        return 1;
    }

    std::ostringstream buffer; //objeto que nos permite acumular texto
    buffer << inputFile.rdbuf(); //nos permite acceder al stream buffer asociado al archivo

    std::string content = buffer.str();

    inputFile.close();

    content = replaceText(content, s1, s2);

    std::ofstream outputFile(filename + ".replace");

    if (!outputFile)
    {
        std::cerr << "Error: could not create output file." << std::endl;
        return 1;
    }

    outputFile << content;

    if (!outputFile)
    {
        std::cerr << "Error: could not write to output file." << std::endl;
        return 1;
    }

    outputFile.close();

    std::cout << "File successfully created: "
              << filename + ".replace" << std::endl;

    return 0;
}
