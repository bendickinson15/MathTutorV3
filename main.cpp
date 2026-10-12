/*****************************************************************************************
Program: MathTutorV2
Programmers: Benjamin Dickinson, Ian Mensah
Section 2 - 10:00 AM
Date: 9/28/2026
Github Repo: https://github.com/bendickinson15/MathTutorV2.0.git
Description: It's a wizard themed math tutor program that displays a greeting, ASCII art,
and some wizard/magic themed jokes. It generates random numbers and operators to be used
in one equation that the user can solve. The user's answer is checked for correctness
and a result is given based on that. The program has a switch that results in an error
statement for if an operator is chosen that is outside of +, -, *, or /. It also accounts
for things like negative numbers and fractions in the answer and prevents those.
******************************************************************************************/
#include <iostream> //required for cout and cin
#include <cstdlib> //required for random number generators
#include <string> //required for get line function
#include <ctime> //required for seeding random number generators

using namespace std; //sets standard namespace

//start of the main function
int main() {
    //initializing variables
    string userName = "unknown";
    int leftNum = 0;
    int rightNum = 0;
    int userAnswer = 0;
    int mathType = 0;
    int correctAnswer = 0;
    int tempNum = 0;
    char mathSymbol = '?';

    //seeding the random number generators later on
    srand(time(0));

    //aesthetic header
    cout <<"(*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*](*)[*]{*}[*]" << endl;
    cout <<"                       {*} Welcome to the tower of the wizard of magical math tutoring! (V1) {*}" << endl;
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

    //setting numbers to random values
    mathType = rand() % 4 + 1;
    leftNum = rand() % 10 + 1;
    rightNum = rand() % 10 + 1;

    //switch for symbol cases
    switch (mathType) {
        //addition case
        case 1:
            mathSymbol = '+';
            correctAnswer = leftNum + rightNum;
            break;
        //subtraction case
        case 2:
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
        case 3:
            mathSymbol = '*';
            correctAnswer = leftNum*rightNum;
            break;
        //division case
        case 4:
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

    //obtaining user's full name
    cout <<"What is your name young apprentice?"<< endl;
    getline(cin, userName);

    //math question and answer
    cout <<"Ah... "<< userName << "! So you have finally found me. If you truly seek the knowledge hidden within these" << endl << "ancient halls, you must first prove your mind is sharp." << endl;
    cout <<"What is " << leftNum << mathSymbol << rightNum << " = ";
    cin >> userAnswer;

    //if statement to check userAnswer for correctness
    if (userAnswer == correctAnswer) {
        //correct
        cout << "Good job! You Got The Question Right!" << endl << endl;
    } else {
        //incorrect
        cout << "I'm So Disappointed In You Apprentice" << endl << endl;
    }

    //end program message
    cout <<"This is all for our program! I hope you had a fantastic time!" << endl;
    cout << "The Wizard math V3 Be Out Shortly!" << endl;
    return 0;
}