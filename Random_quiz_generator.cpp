#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// Define a struct to store the question and its correct answer
struct Question {
    string question;
    string answer;
};

int main() {
    // Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Define a list of questions and answers
    vector<Question> quiz = {
        {"What is the capital of France?", "Paris"},
        {"What is 5 + 7?", "12"},
        {"Which planet is known as the Red Planet?", "Mars"},
        {"What is the largest ocean on Earth?", "Pacific"},
        {"Who wrote 'Hamlet'?", "Shakespeare"}
    };

    int score = 0;
    int numQuestions = quiz.size();
    
    // Ask 5 random questions (or as many as you have in the quiz)
    for (int i = 0; i < 5; ++i) {
        // Randomly pick an index
        int randomIndex = rand() % numQuestions;
        Question currentQuestion = quiz[randomIndex];
        
        // Ask the question
        cout << currentQuestion.question << endl;
        string userAnswer;
        getline(cin, userAnswer);
        
        // Check the answer
        if (userAnswer == currentQuestion.answer) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Incorrect. The correct answer is: " << currentQuestion.answer << endl;
        }
        
        // Optional: Remove the question from the list after it is asked (to avoid repeats)
        quiz.erase(quiz.begin() + randomIndex);
        numQuestions = quiz.size(); // Update the number of remaining questions
    }

    // Output the final score
    cout << "Your score: " << score << " out of 5" << endl;

    return 0;
}



