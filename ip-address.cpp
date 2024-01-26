#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::string command;
#ifdef _WIN32
    command = "ipconfig > ip.txt";
#elif __APPLE__
    command = "ifconfig > ip.txt";
#else
    command = "ip a > ip.txt";
#endif
    system(command.c_str());

    std::ifstream file("ip.txt");
    std::string line;
    while (std::getline(file, line))
    {
        if (line.find("inet ") != std::string::npos)
        {
            std::cout << line << std::endl;
            break;
        }
    }
    file.close();
    return 0;
}
