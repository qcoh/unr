#include "file_reader.h"
#include "package.h"

#include <iostream>

int main(int argc, char* argv[])
{
    try {
        unr::FileReader reader { argv[1] };
        unr::Package package { reader };
    } catch (std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}