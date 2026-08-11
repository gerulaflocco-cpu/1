#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> result;
    for(double score : student_scores) {
        result.push_back(static_cast<int>(score));
    }
    return result;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) 
{
    int man = 0;        
    for(int score : student_scores) 
    {
        if (score <= 40 )
        {
                ++man;    
        }
    }
    return man;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    int increment = (highest_score - 40) / 4;
    return {41, 41 + increment, 41+ 2*increment, 41+ 3*increment};
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> result;
    for(int x = 0; x < student_scores.size(); x++)
        {
        result.push_back(std::to_string(x + 1 ) + ". "  + student_names[x] + ": " + std::to_string(student_scores[x]));
        }
    return result;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,

                          std::vector<std::string> student_names) {
     for(int x = 0; x < student_scores.size(); x++)
         {
         if (student_scores[x] == 100)
             return student_names[x];
         }
    return "";
}
