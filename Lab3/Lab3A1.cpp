
#include <iostream>
#include <iomanip>
#include <string>

void modify_seats(char seats[][5], int row, int col);
void display(char seats[][5]);
bool checkSeat(char seats[][5], std::string user_input);

int main() {
    // Initialise max number of seats available
    const int MAX_SEATS = 28;
    // Initialise the amount of taken seats at 0
    int taken = 1;
    // Create a 2d array of type char
    char seats[7][5] = {
        {'1','A', 'B', 'C', 'D'},
        {'2','A', 'B', 'C', 'D'},
        {'3','A', 'B', 'C', 'D'},
        {'4','A', 'B', 'C', 'D'},
        {'5','A', 'B', 'C', 'D'},
        {'6','A', 'B', 'C', 'D'},
        {'7','A', 'B', 'C', 'D'}
    };
    // Display 2D Array
    display(seats);

    std::string user_input;
    // Ask the user for a seat number
    std::cout << "\nPlease enter the seat you want to reserve, for example (1A) or type '0' to end the program\n";
    std::cin >> user_input;
    // If user inputs q exit program
    if (user_input == "q") {
        return 0;
    }
    // While taken seats are less than the max available seats
    // Check if the seat is available to reserve
    while (taken < MAX_SEATS) {

        if (user_input == "q") {
            break;
        }

        if (user_input.size() > 2) {
            std::cout << "\nYour input is too long, please try again\n";
        }
        else {
            if (checkSeat(seats, user_input)) {
                ++taken;
                display(seats);
            }
        }
        std::cout << "\nPlease enter the seat you want to reserve, for example (1A) or type '0' to end the program" << std::endl;
        std::cin >> user_input;
        display(seats);
    }
    return 0;
}

bool checkSeat(char seats[][5], std::string input) {
    // Check char in string at locaiton 0 and 1
    // If any result in being true print invalid seat
    if (input[0] > '7' || input[0] < '1' || input[1]>'D' || input[1] < 'A') {
        std::cout << "invalid seat\n";
        return false;
    }

    for (int i = 0; i < 7; i++) {
        if (seats[i][0] == input[0]) {
            int row = i;
            for (int j = 0; j < 5; j++) {
                if (seats[row][j] == input[1]) {
                    int col = j;
                    modify_seats(seats, row, col);
                    return true;
                }
            }
        }
    }
    std::cout << "Seat taken";
    return false;
}
// Set the seat that has been chosen with the value 'X'
void modify_seats(char seats[][5], int row, int col) {
    std::cout << "\nYour seat is valid. We marked the seat with an X\n";
    seats[row][col] = 'X';
    return;
}

// Display 2D array
void display(char seats[][5]) {
    for (int i = 0; i < 7; i++) {
        std::cout << "\n";
        for (int j = 0; j < 5; j++)
            std::cout << seats[i][j];
    }
}