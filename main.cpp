#include <string.h>
#include <iostream>
#include "CodeCounter.h"

int main(int argc, char* argv[]) {
    if (argc > 1) {
        std::string path;
        path.assign(argv[1]);
        std::vector<std::string> excludes;  // 用于存储 -exclude 后面的参数
        // 检查命令行参数
        for (int i = 2; i < argc; ++i) {
            // 检查是否为 -exclude 参数
            if (strcmp(argv[i], "-exclude") == 0) {
                // 从下一个参数开始收集
                while (i + 1 < argc && argv[i + 1][0] != '-') {
                    excludes.push_back(argv[i + 1]);  // 存储参数
                    ++i;  // 继续移动到下一个参数
                }
            }
        }
        CodeCounter code_counter(excludes);
        code_counter.countThis(path);
    } else {
        std::cout << "wrong uses of counter";
    }
    return 0;
}
