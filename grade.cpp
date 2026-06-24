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

   // STEP 01. GET STUDENT'S INFORMATION

   std::string name, section, subject;
   int student_number, year_level;

   std::cout << std::endl;
   std::cout << "WELCOME TO THE SCIENCE GRADE PREDICTOR!" << std::endl;
   std::cout << std::endl;
   std::cout << "=====================================================" << std::endl;
   std::cout << std::endl;

   std::cout << "What is your name?: ";
   getline(std::cin, name); // use this to accept strings with whitespace

   std::cout << std::endl;
   std::cout << "What is your student number?: ";
   std::cin >> student_number;

   std::cout << std::endl;
   std::cout << "What is your year level?: ";
   std::cin >> year_level;

   std::cin.ignore();  // clear leftover newline
   
   std::cout << std::endl;
   std::cout << "What is your section?: ";
   getline(std::cin, section);

   std::cout << std::endl;

   std::cout << "=====================================================" << std::endl;

   int academic_task;

   std::cout << std::endl;

   std::cout << "Academic Tasks" << std::endl;

   std::cout << "[1] Written Works"<< std::endl;
   std::cout << "[2] Performance Tasks" << std::endl;
   std::cout << "[3] Quarterly Assessment" << std::endl;

   std::cout << std::endl;
   std::cout << "=====================================================" << std::endl;

   std::cout << "Choose the academic task: ";
   std::cin >> academic_task;

   std::vector <int> scores;
   std::vector <int> items;
   int total_scores = 0;
   int total_items = 0;

   while (true) {

      int score = 0;
      int item = 0;

      std::cout << "Enter score: ";
      std::cin >> score;

      std::cout << "Enter items: ";
      std::cin >> item;

      scores.push_back(score);
      items.push_back(item);

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
   for (const auto& score : scores) {
      file << score << ' ';
   }

   file << "\nItems: ";
   for (const auto& item : items) {
      file << item << ' ';
   }

   file << "\nTotal Scores: ";
   for (const auto& list_of_scores : scores) {
      total_scores += list_of_scores;
   }
   file << total_scores;

   file << "\nTotal items: ";
   for (const auto& list_of_items : items) {
      total_items += list_of_items;
   }
   file << total_items;

   double weight = (static_cast<double>(total_scores) / total_items) * 40;
   std::cout << std::fixed << std::setprecision(2) << weight;
   
   return 0;

}

/*

   
*/
