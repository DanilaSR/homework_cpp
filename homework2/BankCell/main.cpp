#include <iostream>
#include <memory>

class BankCell{
private:
    int id;
public:
    BankCell(int id_0){
        id = id_0;
        std::cout << "Bank Cell " << id << " was created\n";
    }
    ~BankCell() {
        std::cout << "Bank Cell "  << id << " was deleted";
    }
    int get_id() const{
        return id;
    }
};

class Human {
private:
    std::string name;
    std::shared_ptr<BankCell> cell;
public:
    Human(std::string name_0) {
        name = std::move(name_0);
        std::cout << "Human " << name << " was created\n";
    }
    void createBankCell(int id){
        cell = std::make_shared<BankCell>(id);
    }

    void addBankCell(std::shared_ptr<BankCell> cell_0){
        cell = std::move(cell_0);
    }

    std::shared_ptr<BankCell> getBankCell(){
        return cell;
    }

    ~Human() {
        std::cout << "Human " << name << " was deleted\n";
    }
};



int main() {
    //std::unique_ptr<Student> p = std::make_unique<Student> ("Petya");
    Human ivan ("Ivan");
    ivan.createBankCell(123);
    {
        Human peter("Peter");
        peter.addBankCell(ivan.getBankCell());
    }
    //std::cout << Peter.getBankCell()->get_id() << "\n";
    std::cout << ivan.getBankCell()->get_id() << "\n";

}
