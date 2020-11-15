// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

void prime();
void game();
void birthday();

int main()
{

    int num;
    for (num = 1; num < 101; num++) {
        if (num % 3 == 0) {
            cout << "Fizz" << endl;
        }
        else if (num % 5 == 0) {
            cout << "Buzz" << endl;
        }
        else {
            cout << num << endl;
        }
    }

    prime();
    game();
    birthday();
    return 0;
}

// https://stackoverflow.com/questions/5200879/printing-prime-numbers-from-1-through-100#:~:text=Write%2C%20run%2C%20and%20test%20a,not%20equally%20divisible%20by%20n.
// Accessed on 17:49 30th October
// Based on response from Carthi
void prime() {
    cout << "\n";
    int i; int j;
    for (i = 2; i < 100; i++) {
        bool prime = true;
        for (j = 2; j <= i - 1; j++) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }
        if (prime) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void game() {
    cout << "\n";
    srand(time(NULL));
    int numgames, loss = 0, win = 0;
    for (numgames = 1; numgames <= 10000; numgames++) {
        int die1, die2, sum, point;
        die1 = rand() % 6 + 1;
        die2 = rand() % 6 + 1;
        sum = die1 + die2;
        if (sum == 7 || sum == 11) {
            win += 1;
        }
        else if (sum == 2 || sum == 3 || sum == 12) {
            loss += 1;
        }
        else {
            point = sum;
            sum = 0;
            while (sum != point || sum == 7) {
                die1 = rand() % 6 + 1;
                die2 = rand() % 6 + 1;
                sum = die1 + die2;
                if (sum == point) {
                    win += 1;
                    break;
                }
                else if (sum == 7) {
                    loss += 1;
                    break;
                }
                else {
                    continue;
                }
            }
        }
    }
    cout << "Your chances at winnning are: " << fixed << setprecision(4) << (double)win / numgames << endl;
}


bool sameDay(int birthdays[], int numpeople);

// https://stackoverflow.com/questions/32289294/c-birthday-paradox-using-a-boolean-function
// Accessed on 01/10/2020
// Based on the original poster
void birthday()
{
    cout << "\n";
    const int MAX_PEOPLE = 50;
    const int TRIALS = 5000;
    const int DAYS_IN_YEAR = 365;
    int count = 0;
    int people = 2;
    int birthdays[MAX_PEOPLE];
    double probability = 0;
    srand(time(NULL));
    // Increase amount of people that might have the same birthday by 1 for each run
    for (people = 2; people <= MAX_PEOPLE; people++) {
        // reinitialise counter to 0 when amount of people is incremented
        count = 0;
        // For every trial generate birthday for 50 people
        for (int trial = 0; trial < TRIALS; trial++) {
            for (int birthday = 0; birthday < MAX_PEOPLE; birthday++) {
                birthdays[birthday] = (rand() % 365 + 1);
            }
            // Pass in array of birthdays and amount of people

            if (sameDay(birthdays, people) == true)
                count++;
        }
        probability = ((double)count / TRIALS);
        cout << "For " << people << ", the probability of two birthdays is about " << fixed << setprecision(4) << probability << endl;
    }
}
bool sameDay(int birthdays[], int people)
{
    //Use this function to search the birthday array and check if at least two people have matching birthdays for any trial
    for (int x = 0; x < people; x++)
    {
        for (int y = x + 1; y < people; y++)
        {
            if (birthdays[y] == birthdays[x])
            {
                return true;
            }
        }
    }
    return false;
}