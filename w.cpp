
#include <iostream>
#include <vector>
#include <fstream>

int main() {
    std::string name;
    std::string section = "Righteous";
    int year_level = 10;
    int student_number = 1800346;
    std::vector <int> scores = {14, 16, 17, 19, 20, 29,};
    std::vector <int> items = {20, 20, 20, 20, 20, 30};
    int total_items = 0;
    int total_scores = 0;

    std::cout << "Enter your full name: ";
    getline(std::cin, name);


    std::ofstream file("grade_predictor.txt");

   file << "Science Grade Predictor" << "\n";
   file << "\n";

   file << "Name: " << name << "\n";
   file << "Year and Section: " << year_level << " - " << section << "\n";

   file << "Student Number: " << student_number << "\n";
   std::cout << "\n";
   std::cout << "\n";

   
}