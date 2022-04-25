#include <iostream>
#include <vector>

//Память в векторе выделяется по степеням двойки
void memory1(){
    std::vector<int> a;
    for (int i = 0; i < 100; i++){
        a.push_back(i);
        std::cout << a.capacity() << std::endl;
    }

}

//Заранее выделенная память увеличивается в 2 раза
void memory2(){
    std::vector<int> a;
    a.reserve(25);
    for (int i = 0; i < 100; i++){
        a.push_back(i);
        std::cout << a.capacity() << std::endl;
    }
}

//Это сложно проанализировать
void memory3(){
    std::vector<int> a;
    for (int i = 0; i < 999999; i++){
        a.push_back(i);
        std::cout << a.capacity() << std::endl;
    }

}
int main() {
    memory1();
}

//auto begin std::chrono::