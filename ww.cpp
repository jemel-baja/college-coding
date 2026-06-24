#include <iostream>

class Summative_Tests {
   protected:
      int percentage;
   public:
      std::vector <int> scores;
      std::vector <int> items;
      int total_scores = 0;
      int total_items = 0;
      int percentage; 

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
};

class Written_Works : public Summative_Tests {
   public:
      double calculate_weight() {
         return total_scores / total_items * 40;
      }
};

class Performance_Tasks : public Summative_Tests {
   public:
      double calculate_weight() {
         return total_scores / total_items * 40;
      }
};

class Quarterly_Assessments : public Summative_Tests {
   public:
      double calculate_weight() {
         return total_scores / total_items * 40;
      }
};

int main() {
   return 0;
}