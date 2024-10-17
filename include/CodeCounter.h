//
// Created by YEZI on 2024/5/20.
//

#ifndef CODECOUNTER_H
#define CODECOUNTER_H
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class CodeCounter {
    int lines = 0;
    std::vector<std::string> excludes;
    // 检查是否是排除的目录
    bool isExcluded(std::string path) {
        for (auto& exclude : excludes) {
            if (exclude == path)
                return true;
        }
        return false;
    }
    // 检查是否是代码文件
    static bool isCodeFile(const std::filesystem::path& path) {
        // 常见代码文件后缀
        static const std::vector<std::string> extensions = {
            ".thrift", ".cpp", ".hpp", ".c",  ".h",
            ".java",   ".py",  ".cs",  ".js", ".go"};
        // 检查路径是否存在
        if (std::filesystem::exists(path) == false) {
            std::cerr << "There is no file " << path << std::endl;
            return false;
        }
        // 检查是否是文件
        if (is_regular_file(path) == false) {
            std::cerr << path << " is no a file." << std::endl;
            return false;
        }
        std::string extension = path.extension().string();
        for (const auto& e : extensions) {
            if (e == extension) {
                return true;
            }
        }
        return false;
    }

    void countCodeFile(const std::filesystem::path& filePath) {
        // 检查是否是代码文件
        if (isCodeFile(filePath) == false)
            return;
        std::ifstream file(filePath);
        // 检查文件是否可以打开
        if (file.is_open() == false) {
            std::cerr << "Error opening file: " << filePath << std::endl;
            return;
        }
        std::string trash;
        int count = 0;
        while (std::getline(file, trash)) {
            ++count;
        }
        lines += count;
        std::cout << filePath << " Lines: " << count << " Sum: " << lines
                  << std::endl;
    }

    void countDirectory(const std::filesystem::path& path) {
        // 检查是否是目录
        if (is_directory(path) == false || isExcluded(path.string())) {
            return;
        }
        for (const auto& entry : std::filesystem::directory_iterator(path)) {
            if (entry.is_directory())
                countDirectory(entry.path());
            else
                countCodeFile(entry.path());
        }
    }

   public:
    void countThis(const std::filesystem::path& path) {
        if (is_directory(path))
            countDirectory(path);
        else
            countCodeFile(path);
        std::cout << "Code Lines: " << lines;
    }
    CodeCounter(std::vector<std::string> excludes) : excludes(move(excludes)) {}
};
#endif  // CODECOUNTER_H
