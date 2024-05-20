#include <iostream>
#include"CodeCounter.h"

int main(int argc, char *argv[]) {
    CodeCounter code_counter;
    std::string path;
    if (argc == 2)
        path.assign(argv[1]);
    else
        std::getline(std::cin, path);
    code_counter.countThis(path);
    return 0;
}
