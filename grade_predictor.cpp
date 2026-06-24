/*

   Science Grade Predictor

   Scopes:
      1. It allows to get basic information of the student such as their name, id, year level, course, and section.
      2. It allows to calculate or predict their grade based on their scores.

   Limitations:
      1. It is only limited to one subject.
      2. It is only limited to one academic term.
      3. It is only limited to one student.

   PROGRAM LOGIC

   1. Get the student's information.
   2. Ask what summative test the student wants to add.
   3. Enter the score and items, and add them to their specific vectors.
   4. Ask them infinitely until they want to stop.

*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

class Summative_Tests {
   public:
      std::string summative_test;
      std::vector <int> scores;
      std::vector <int> items;
      int total_scores = 0;
      int total_items = 0;
      int percentage = 0;
      double weight = 00.00;

      std::vector<int> add_scores() {
         int score = 0;

         std::cout << "Enter score: ";
         std::cin >> score;

         scores.push_back(score);

         return scores;
      }

      std::vector<int> add_items() {

         int item = 0;

         std::cout << "Enter items: ";
         std::cin >> item;

         items.push_back(item);

         return items;
      }

      void changeValues(std::string summative_test_value, int percentage_value) {
         summative_test = summative_test_value;
         percentage = percentage_value;
      }

      double calculate_weight() {

         for (const auto& list_of_scores : scores) {
            total_scores += list_of_scores;
         }

         for (const auto& list_of_items : items) {
            total_items += list_of_items;
         }
      
         std::cout << summative_test << " Total Scores: " << total_scores << std::endl;

         std::cout << summative_test << " Total Items: " << total_items << std::endl;

         weight = (static_cast<double>(total_scores) / total_items) * percentage;
         
         weight = round(weight * 100) / 100;

         return weight;
      }
};

class Written_Works : public Summative_Tests {
   public:
      Written_Works() {
         changeValues("Written Works", 40);
      }
};

class Performance_Tasks : public Summative_Tests {
   public:
      Performance_Tasks() {
         changeValues("Performance Tasks", 40);
      }
};

class Quarterly_Assessments : public Summative_Tests {
   public:
      Quarterly_Assessments() {
         changeValues("Quarterly Assessments", 20);
      }
};

double task_1() {
   std::string summative_test;

   std::cout << std::endl;

   std::cout << "=====================================================" << std::endl;
   std::cout << std::endl;

   std::cout << "Summative Tests" << std::endl;
   std::cout << std::endl;


   std::cout << "Written Works"<< std::endl;
   std::cout << "Performance Tasks" << std::endl;
   std::cout << "Quarterly Assessment" << std::endl;

   std::cout << std::endl;
   std::cout << "=====================================================" << std::endl;
   std::cout << std::endl;

   std::cin.ignore();  // clear leftover newline

   std::cout << "Choose the academic task (Please type exactly what's there): ";
   getline(std::cin, summative_test); 
   std::cout << std::endl;
   std::cout << "=====================================================" << std::endl;
   std::cout << std::endl;

   Written_Works written_works;
   std::vector <int> written_works_scores;
   std::vector <int> written_works_items;
   double ww_weight = 00.00;

   
   std::vector <int> performance_tasks_scores;
   std::vector <int> performance_tasks_items;
   int pt_total_scores = 0;
   int pt_total_items = 0;

   std::vector <int> quarterly_assessment_scores;
   std::vector <int> quarterly_assessment_items;
   int qa_total_scores = 0;
   int qa_total_items = 0;

   if (summative_test == "Written Works") {
      while (true) {
         written_works_scores = written_works.add_scores();
         written_works_items = written_works.add_items();

         int choice;

         std::cout << "Do you want to continue? (1 if yes, 0 if no): ";
         std::cin >> choice;

         std::cout << std::endl;
         std::cout << "=====================================================" << std::endl;
         std::cout << std::endl;

         if (choice == 0) {
            break;
         }
      }

      std::cout << written_works.calculate_weight();
   } else if (summative_test == "Performance Tasks") {
      
   } else if (summative_test == "Quarterly Assessment") {

   } else {
      std::cout << "Error!";
      std::cout << std::endl;
      std::cout << "=====================================================" << std::endl;
      std::cout << std::endl;
   }

   return 00.00;
}


int main() {

   // STEP 01. GET STUDENT'S INFORMATION

   // std::string name, section, subject;
   // int student_number, year_level;

   // std::cout << std::endl;
   // std::cout << "WELCOME TO THE SCIENCE GRADE PREDICTOR!" << std::endl;
   // std::cout << std::endl;
   // std::cout << "=====================================================" << std::endl;
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

   double grade = 00.00;
   double ww_weight = 00.00;
   double pt_weight = 00.00;
   double qa_weight = 00.00;

   while(true) {
      
      int task;

      std::cout << std::endl;
      std::cout << "=====================================================" << std::endl;
      std::cout << std::endl;

      std::cout << "[1] Add scores" << std::endl;
      std::cout << "[2] View scores" << std::endl;
      std::cout << "[3] Predict Grade" << std::endl;
      std::cout << "[4] Exit" << std::endl;
      std::cout << std::endl;

      std::cout << "What do you want to do today?: ";
      std::cin >> task;

      if(task == 1) {
         std::cout << task_1();
      } else if (task == 2) {
         std::cout << std::endl;
         std::cout << "=====================================================" << std::endl;
         std::cout << std::endl;
         std::cout << "Please see the .txt file to see your scores and grade." << std::endl;
      } else if (task == 3) {
         grade = ww_weight + pt_weight + qa_weight;
      } else if (task == 4) {
         break;
      } else {
         std::cout << std::endl;
         std::cout << "=====================================================" << std::endl;
         std::cout << std::endl;
         std::cout << "Option does not exist." << std::endl;
      }
   }

   std::cout << std::endl;
   std::cout << "=====================================================" << std::endl;
   std::cout << std::endl;

   std::cout << "THANK YOU FOR USING THE SCIENCE GRADE CALCULATOR!";
   std::cout << std::endl; 

   std::cout << std::endl;
   std::cout << "=====================================================" << std::endl;
   std::cout << std::endl;
   
   return 0;

}