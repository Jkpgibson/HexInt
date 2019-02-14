#include "HexInt.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
#include <algorithm>

int main(int argc, char const *argv[])
{

    if (argc < 3){
        std::cout << "Missing arguments\n";
        return 1;
    }

    std::string line;
    std::ofstream outfile;
    std::ifstream infile;
    infile.open(argv[1]);
    outfile.open(argv[2]);

    std::string left; // std string which will hold the left side and be converted to a c-style string
    std::string right; // std string which will hold the right side and be converted to a c-style string
    

    while (getline(infile, line)){

        int plusPos = line.find("+");
        // In this section I'm getting rid of newline chracters since they mess up the add function
        if (line.find('\r') != std::string::npos || line.find('\n') != std::string::npos) {
            line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
            line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        }

        left = line.substr(0, plusPos);
        right = line.substr(line.find("+") + 1);

        HexInt* lhs = new HexInt(left.c_str());
        HexInt* rhs = new HexInt(right.c_str());
        HexInt* sum = HexInt::add(*lhs, *rhs);

        outfile << sum->toTrimmedString() << '\n';

        delete lhs;
        delete rhs;
        delete sum;
    }

    infile.close();
    outfile.close();

    return 0;
}
