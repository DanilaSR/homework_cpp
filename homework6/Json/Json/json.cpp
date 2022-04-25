#include <filesystem>
#include <fstream>
#include <iomanip>
#include <istream>
#include <locale>
#include <ostream>
#include <iostream>

#include "C:\Libs\json.hpp"

using nlohmann::json;

int main(int argc, char** argv)
{

	std::string firstName;
	std::string lastName;
	int age;

	std::cout << "Enter your name\n";
	std::cin >> firstName;
	std::cout << "Enter your surname\n";
	std::cin >> lastName;
	std::cout << "Age\n";
	std::cin >> age;

	std::filesystem::path path_output = "person.json";

	json j;

	std::cout << std::setw(4) << j << std::endl;

	
	
	j["Firs_Name"] = firstName;
	j["Last_Name"] = lastName;
	j["Age"] = age;


	for (auto iterator = j.begin(); iterator != j.end(); ++iterator)
	{
		std::cout << iterator.key() << " : " << iterator.value() << "\n";
	}

	for (auto& element : j.items())
	{
		std::cout << element.key() << " : " << element.value() << "\n";
	}

	for (auto& [key, value] : j.items()) // C++17 bindings
	{
		std::cout << key << " : " << value << "\n";
	}

	std::fstream fout(path_output.string(), std::ios::out);

	fout << std::setw(4) << j;

	fout.close();

	system("pause");

	return EXIT_SUCCESS;
}