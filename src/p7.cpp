#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ofstream myfile;
    myfile.open("../plik.txt");
    myfile << "grzyb";
    myfile.close();

    std::ifstream myfile2("../plik.txt");
    if (myfile2.is_open())
    {
        std::string line;
        while (std::getline(myfile2, line))
        {
            std::cout << line;
        }
    }

    return 0;
}
