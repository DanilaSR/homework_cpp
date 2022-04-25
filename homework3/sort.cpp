#include <iostream>
#include <chrono>
#include <array>
#include <cmath>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>

void array_time(){
    std::array<int, 1000> a{};
    for(int i = 0; i < 1000; i++){
        a.at(i) = pow(-1, i)*pow(i, 2);
    }
    auto start = std::chrono::steady_clock::now();
    std::sort(a.begin(), a.end());
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}

void vector_time(){
    std::vector<int> a;
    a.reserve(1000);
    for(int i = 0; i < 1000; i++){
        a.push_back(pow(-1, i)*pow(i, 2));
    }
    auto start = std::chrono::steady_clock::now();
    std::sort(a.begin(), a.end());
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}

void deque_time(){
    std::deque<int> a;
    a.resize(1000);
    for(int i = 0; i < 1000; i++){
        a.push_back(pow(-1, i)*pow(i, 2));
    }
    auto start = std::chrono::steady_clock::now();
    std::sort(a.begin(), a.end());
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}

void list_time(){
    std::list<int> a;
    a.resize(1000);
    for(int i = 0; i < 1000; i++){
        a.push_front(pow(-1, i)*pow(i, 2));
    }
    auto start = std::chrono::steady_clock::now();
    a.sort();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}

void forward_list_time(){
    std::forward_list<int> a;
    a.resize(1000);
    for(int i = 0; i < 1000; i++){
        a.push_front(pow(-1, i)*pow(i, 2));
    }
    auto start = std::chrono::steady_clock::now();
    a.sort();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}

int main() {
    array_time();
    //vector_time();
    //deque_time();
    //list_time();
    //forward_list_time();
}
