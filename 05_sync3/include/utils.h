#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <string>


    std::recursive_mutex out_mtx;
    void println()
    {
        std::lock_guard<std::recursive_mutex> lg{out_mtx};
        std::cout << std::endl;
    }
    template <typename T, typename... Rest>
    void println(const T &word, const Rest &... rest)
    {
        std::lock_guard<std::recursive_mutex> lg{out_mtx};
        std::cout << word << ' ';
        println(rest...);
    }
