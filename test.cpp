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

void add_scores(std::vector <int>& group_of_scores, std::vector <int>& group_of_items, int total_scores, int total_items) {

   total_scores = 0;
   total_items = 0;

   while (true) {

      int score = 0;
      int items = 0;

      std::cout << "Enter score: ";
      std::cin >> score;

      std::cout << "Enter items: ";
      std::cin >> items;

      std::cout << std::endl;
      std::cout << "=====================================================" << std::endl;
      std::cout << std::endl;

      group_of_scores.push_back(score);
      group_of_items.push_back(items);


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
}

double predict_grade(std::vector <int>& list_of_scores, std::vector <int>& list_of_items, int total_scores, int total_items, int percentage) {
   
   for (const auto& list_of_scores_loop : list_of_scores) {
      total_scores += list_of_scores_loop;
   }

   for (const auto& list_of_items_loop : list_of_items) {
      total_items += list_of_items_loop;
   }


   double weight = (static_cast<double>(total_scores) / total_items) * percentage;
   
   return weight;

}

void add_scores_to_files(std::string academic_task, std::vector <int>& list_of_scores, std::vector <int>& list_of_items, int total_scores, int total_items, int percentage) {

   std::ofstream file("test.txt", std::ios::app);

   total_scores = 0;
   total_items = 0;

   file << "\n" << academic_task << std::endl;

   file << "Scores: ";
   for (const auto& individual_scores : list_of_scores) {
      file << individual_scores << ' ';
   }

   file << "\nItems: ";
   for (const auto& individual_items : list_of_items) {
      file << individual_items << ' ';
   }

   file << "\nTotal Scores: ";
   for (const auto& list_of_scores_loop : list_of_scores) {
      total_scores += list_of_scores_loop;
   }
   file << total_scores;

   file << "\nTotal items: ";
   for (const auto& list_of_items_loop : list_of_items) {
      total_items += list_of_items_loop;
   }
   file << total_items;
   file << "\n";


   double weight = (static_cast<double>(total_scores) / total_items) * percentage;
   file << "Current weight: " << std::fixed << std::setprecision(2) << weight;
   file << "\n";

   std::cout << "Current weight: " << std::fixed << std::setprecision(2) << weight;
   std::cout << std::endl;
}

double ww_weight = 00.00;
double pt_weight = 00.00;


double task_1() {
   std::string academic_task;

   std::cout << std::endl;

   std::cout << "=====================================================" << std::endl;
   std::cout << std::endl;

   std::cout << "Academic Tasks" << std::endl;
   std::cout << std::endl;


   std::cout << "Written Works"<< std::endl;
   std::cout << "Performance Tasks" << std::endl;
   std::cout << "Quarterly Assessment" << std::endl;

   std::cout << std::endl;
   std::cout << "=====================================================" << std::endl;
   std::cout << std::endl;

   std::cin.ignore();  // clear leftover newline

   std::cout << "Choose the academic task (Please type exactly what's there): ";
   getline(std::cin, academic_task); 
   std::cout << std::endl;
   std::cout << "=====================================================" << std::endl;
   std::cout << std::endl;

   std::vector <int> written_works_scores;
   std::vector <int> written_works_items;
   int ww_total_scores = 0;
   int ww_total_items = 0;
   
   std::vector <int> performance_tasks_scores;
   std::vector <int> performance_tasks_items;
   int pt_total_scores = 0;
   int pt_total_items = 0;

   std::vector <int> quarterly_assessment_scores;
   std::vector <int> quarterly_assessment_items;
   int qa_total_scores = 0;
   int qa_total_items = 0;

   if (academic_task == "Written Works") {
      add_scores(written_works_scores, written_works_items, ww_total_scores, ww_total_items);
      ww_weight = predict_grade(written_works_scores, written_works_items, ww_total_scores, ww_total_items, 40);
      add_scores_to_files(academic_task, written_works_scores, written_works_items, ww_total_scores, ww_total_items, 40);
   } else if (academic_task == "Performance Tasks") {
      add_scores(performance_tasks_scores, performance_tasks_items, pt_total_scores, pt_total_items);
      pt_weight = predict_grade(written_works_scores, written_works_items, ww_total_scores, ww_total_items, 40);
      add_scores_to_files(academic_task, performance_tasks_scores, performance_tasks_items, pt_total_scores, pt_total_items, 40);
   } else if (academic_task == "Quarterly Assessment") {
      add_scores(quarterly_assessment_scores, quarterly_assessment_items, qa_total_scores, qa_total_items);
      add_scores_to_files(academic_task, quarterly_assessment_scores, quarterly_assessment_items, qa_total_scores, qa_total_items, 20);
   } else {
      std::cout << "Error!";
      std::cout << std::endl;
      std::cout << "=====================================================" << std::endl;
      std::cout << std::endl;
   }

   return ww_weight + pt_weight;
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
         task_1();
      } else if (task == 2) {
         std::cout << std::endl;
         std::cout << "=====================================================" << std::endl;
         std::cout << std::endl;
         std::cout << "Please see the .txt file to see your scores and grade." << std::endl;
      } else if (task == 3) {
         grade = ww_weight + pt_weight;
         std::cout << grade;
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