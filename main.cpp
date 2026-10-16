/*******************************************************************************************
Program: MathTutorV3
Programmers: Benjamin Dickinson, Keston Krupicka
Section 2 - 10:00 AM
Date: 10/17/2026
Github Repo: https://github.com/bendickinson15/MathTutorV3
Description: It's a wizard themed math tutor program that displays a greeting, ASCII art,
and some wizard/magic themed jokes.

*It generates two random numbers between 1-10 and then randomly selects operators to be used
based on third random number, It also accounts for things like negative numbers and fractions
in the answer and prevents those.

*Uses an inner while loop to validate the user's input for

*Uses an outer while loop to continue until the user wants to quit "Do you want to continue?"
accepting y, yes, n, no as valid input

*Uses a for loop to give the user 3 attempts to answer the question correctly. After the third
attempt, display the correct answer.

*After answering 3 correct answers in a row, level up increasing the range by 10

*After answering 3 incorrect answers in a row, level down by the range of 10

*Uses a while loop to validate numeric input
********************************************************************************************/
#include <iostream> //required for cout and cin
#include <cstdlib> //required for random number generators
#include <string> //required for get line function
#include <ctime> //required for seeding random number generators
#include <limits> //required to use numeric_limits
#include <cctype> //required for lower casing

using namespace std; //sets standard namespace

//start of the main function
int main() {
    //initializing variables
    string userName = "unknown";
    int leftNum = 0;
    int rightNum = 0;
    int userAnswer = 0;
    enum MathType {MT_ADD = 1, MT_SUBTRACT = 2, MT_MULTIPLY = 3, MT_DIVIDE = 4};
    MathType mathType = MT_ADD;
    int correctAnswer = 0;
    int tempNum = 0;
    char mathSymbol = '?';
    const int MAX_ATTEMPTS = 3;
    const int LEVEL_RANGE_CHANGE = 10;
    int numCorrect = 0;
    int numIncorrect = 0;
    int mathLevel = 1;
    int levelRange = LEVEL_RANGE_CHANGE;
    string userInput = "?";

    //seeding the random number generators later on
    srand(time(0));

    //aesthetic header
    cout <<"(*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*]" << endl;
    cout <<"                       {*} Welcome to the tower of the wizard of magical math tutoring! (V3) {*}" << endl;
    cout << R"(
,---.    ,---.   ____   ,---------. .---.  .---.    .--.      .--..-./`)  ____..--'   ____    .-------.     ______
|    \  /    | .'  __ `.\          \|   |  |_ _|    |  |_     |  |\ .-.')|        | .'  __ `. |  _ _   \   |    _ `''.
|  ,  \/  ,  |/   '  \  \`--.  ,---'|   |  ( ' )    | _( )_   |  |/ `-' \|   .-'  '/   '  \  \| ( ' )  |   | _ | ) _  \
|  |\_   /|  ||___|  /  |   |   \   |   '-(_{;}_)   |(_ o _)  |  | `-'`"`|.-'.'   /|___|  /  ||(_ o _) /   |( ''_'  ) |
|  _( )_/ |  |   _.-`   |   :_ _:   |      (_,_)    | (_,_) \ |  | .---.    /   _/    _.-`   || (_,_).' __ | . (_) `. |
| (_ o _) |  |.'   _    |   (_I_)   | _ _--.   |    |  |/    \|  | |   |  .'._( )_ .'   _    ||  |\ \  |  ||(_    ._) '
|  (_,_)  |  ||  _( )_  |  (_(=)_)  |( ' ) |   |    |  '  /\  `  | |   |.'  (_'o._)|  _( )_  ||  | \ `'   /|  (_.\.' /
|  |      |  |\ (_ o _) /   (_I_)   (_{;}_)|   |    |    /  \    | |   ||    (_,_)|\ (_ o _) /|  |  \    / |       .'
'--'      '--' '.(_,_).'    '---'   '(_,_) '---'    `---'    `---` '---'|_________| '.(_,_).' ''-'   `'-'  '-----'`

                                                                                                                                 )" << endl;
    cout <<"(*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*]" << endl;
    cout <<R"(A wise wizards words:
        (*) What's a wizard's favorite school subject? spell-gebra!
        (*) Why did the sorcerer break his calculator? He wanted to do math-a-magics in his head!
        (*) What is a witch's favorite shape? A Hex-agon!
        (*) What do you call a snake that is 3.14 feet long? A Pi-thon!)"<< endl << endl;
    cout <<"(*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*]" << endl;

    //obtaining user's full name
    cout <<"What is your name young apprentice?"<< endl;
    getline(cin, userName);

    //math question and answer
    cout <<"Ah... "<< userName << "! So you have finally found me. If you truly seek the knowledge hidden within these" << endl << "ancient halls, you must first prove your mind is sharp." << endl;

    do {
        //setting numbers to random values
        mathType = static_cast<MathType>(rand() % 4 + 1);
        leftNum = rand() % levelRange+ 1;
        rightNum = rand() % levelRange+ 1;

        //switch for symbol cases
        switch (mathType) {
            //addition case
            case MT_ADD:
                mathSymbol = '+';
                correctAnswer = leftNum + rightNum;
                break;
                //subtraction case
            case MT_SUBTRACT:
                mathSymbol = '-';
                //if statement to avoid negative result
                if (leftNum < rightNum) {
                    tempNum = rightNum;
                    rightNum = leftNum;
                    leftNum = tempNum;
                }
                correctAnswer = leftNum - rightNum;
                break;
                //multiplication case
            case MT_MULTIPLY:
                mathSymbol = '*';
                correctAnswer = leftNum*rightNum;
                break;
                //division case
            case MT_DIVIDE:
                mathSymbol = '/';
                //avoids fractions by multiplying by rightNum every time
                correctAnswer = leftNum;
                leftNum = rightNum * leftNum;
                break;
                //error statements if mathType isn't a number between 1 and 4
            default:
                cout<<"Error! Invalid Math Type:"<< mathType << endl;
                cout << "Program ended with an error -1" << endl;
                cout << "Please report this error to Debbie Johnson." << endl;
                return -1;
        }
        cout <<"What is " << leftNum << mathSymbol << rightNum << " = ";

        for (int i = 1; i <= MAX_ATTEMPTS; i++) {
            //loop until user's answer is a valid number
            while (!(cin >> userAnswer)) {
                cin.clear(); //clear cin error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignores max input up to \n

                //output asking for a valid number
                cout <<"\tInvalid wizardry!"<< endl;
                cout <<"\tEnter a valid spell!" << endl;
            } //end of loop
            //if statement to check userAnswer for correctness
            if (userAnswer == correctAnswer) {
                //correct
                cout << "Good job! You Got The Spell Right!" << endl << endl;
                numCorrect++;
                break;
            } else if (i == 3){
                //incorrect with no attempts left
                cout << "My apologies young apprentice, but you have failed too many times." << endl << endl;
            } else {
                //incorrect with attempts left
                cout << "Wrong, but you may try again " << MAX_ATTEMPTS-i << " more time(s)."  << endl << endl;
                numIncorrect++;
            }
        }

        if (numCorrect == 3) {
            mathLevel += 1;
            numIncorrect = 0;
            numCorrect = 0;
            levelRange += LEVEL_RANGE_CHANGE;
            cout << "Congrats! Your on Level " << mathLevel << ". Your new range is " << levelRange << endl;
        } // end of if loop

    while (true) {
        cout<< "Would you like to continue to expand your knowledge apprentice?" <<endl;
        cin >> userInput;
        for (int i = 0; i < userInput.length(); i++) {
            userInput.at(i) = tolower(userInput.at(i));
        } // end of while true statement

        if (userInput == "yes" || userInput == "y" || userInput == "no" || userInput == "n") {
            break;
        }else {
            cout << "Invalid Input" << endl;
        } // end of else statement
    } // end of while loop

    } while (userInput == "yes" || userInput == "y"); // end of do while loop

    //end program message
    cout <<"This is all for our program! I hope you had a fantastic time!" << endl;
    cout << "The Wizard math V4 Be Out Shortly!" << endl;
    return 0;
}