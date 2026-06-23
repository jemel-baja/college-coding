/*

   Science Grade Predictor

   Scopes:
      1. It allows to get basic information of the student such as their name, id, year level, course, and section.
      2. It allows to calculate or predict their grade based on their scores.

   Limitations:
      1. It is only limited to one subject.
      2. It is only limited to one academic term.
      3. It is only limited to one student.

*/

// I used the grading system in high school since the college grading system is so fucking confusing.

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>



int main() {

   // Get student's information

   // std::string name, section, subject;
   // int student_number, year_level;

   // std::cout << std::endl;
   // std::cout << "WELCOME TO THE SCIENCE GRADE PREDICTOR!" << std::endl;
   // std::cout << std::endl;
   // std::cout << "--------------------------------------------------" << std::endl;
   // std::cout << std::endl;

   // std::cout << "What is your name?: ";
   // getline(std::cin, name); // use this to accept strings with whitespace

   // std::cout << std::endl;
   // std::cout << "What is your student number?: ";
   // std::cin >> student_number;

   // std::cout << std::endl;
   // std::cout << "What is your year level?: ";
   // std::cin >> year_level;

   // std::cin.ignore();  // clear leftover newline
   
   // std::cout << std::endl;
   // std::cout << "What is your section?: ";
   // getline(std::cin, section);

   // // std::cout << std::endl;
   // // std::cout << "What subject you want to predict your grade in: ";
   // // getline(std::cin, subject);

   // std::cout << std::endl;

   // std::cout << "--------------------------------------------------" << std::endl;

   // std::cout << std::endl;

   std::vector <int> written_works_scores;
   std::vector <int> written_works_items;
   int written_works_total_scores = 0;
   int written_works_total_items = 0;
   


   while (true) {

      int score = 0;
      int items = 0;

      std::cout << "Enter score: ";
      std::cin >> score;

      std::cout << "Enter items: ";
      std::cin >> items;

      written_works_scores.push_back(score);
      written_works_items.push_back(items);

      int choice;

      std::cout << "Do you want to continue? (1 if yes, 0 if no): ";
      std::cin >> choice;

      if (choice == 0) {
         break;
      }
   }


   // Create file

   std::ofstream file("science_grades.txt");

   file << "Written Works: " << std::endl;

   file << "Scores: ";
   for (const auto& scores : written_works_scores) {
      file << scores << ' ';
   }

   file << "\nItems: ";
   for (const auto& items : written_works_items) {
      file << items << ' ';
   }

   file << "\nTotal Scores: ";
   for (int list_of_scores : written_works_scores) {
      written_works_total_scores += list_of_scores;
   }
   file << written_works_total_scores;

   file << "\nTotal items: ";
   for (const auto& total_items : written_works_items) {
      written_works_total_items += total_items;
   }
   file << written_works_total_items;

   double written_works_weight = (static_cast<double>(written_works_total_scores) / written_works_total_items) * 40;
   std::cout << std::fixed << std::setprecision(2) << written_works_weight;
   
   return 0;

}