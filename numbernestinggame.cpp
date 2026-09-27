#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int randomNumber;
    int guess;
    int attempts = 0;
    int score;

    srand(time(0));

    randomNumber = rand() % 100 + 1;

    cout << "NUMBER GUESSING GAME" << endl;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "Try to guess it!" << endl;

    do
    {
        cout << "\nEnter your guess: ";
        cin >> guess;
        attempts++;
        if (guess < randomNumber)
        {
            cout << "Too Low! Try a higher number." << endl;
        }
        else if (guess > randomNumber)
        {
            cout << "Too High! Try a lower number." << endl;
        }
        else
        {
            cout << "\nCorrect! You guessed the number." << endl;
        }
    }

     while (guess != randomNumber);
    score = 100 - ((attempts - 1) * 10);
    if (score < 0)
    {
        score = 0;
    }
    cout << "FINAL RESULT" << endl;
    cout << "Random Number : " << randomNumber << endl;
    cout << "Attempts      : " << attempts << endl;
    cout << "Final Score   : " << score << endl;

    if (attempts == 1)
    {
        cout << "Excellent! Perfect Guess!" << endl;
    }
    else if (attempts <= 5)
    {
        cout << "Great Job!" << endl;
    }
    else
    {
        cout << "Good Try! Keep Practicing." << endl;
    }
    return 0;
}