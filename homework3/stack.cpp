#include <iostream>
#include <stack>
#include <chrono>

void printStack(std::stack<int> &s){
    std::stack<int> s1(s);
    while(!s.empty()){
        std::cout << s.top() << std::endl;
        s.pop();
    }
    s1.swap(s);
}

int main() {
    std::stack<int> a;
    for (int i = 0; i < 10; i++){
        a.push(i);
    }
    printStack(a);
}

//auto begin std::chrono::