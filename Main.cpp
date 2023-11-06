#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int getBulls(string secret, string guess) {
    int bulls = 0;
    for (int i = 0; i < 4; ++i) {
        if (secret[i] == guess[i]) {
            bulls++;
        }
    }
    return bulls;
}

int getCommon(string secret, string guess) {
    int common = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i != j && secret[i] == guess[j]) {
                common++;
            }
        }
    }
    return common;
}

bool hasRepeatingDigits(string guess) {
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            if (guess[i] == guess[j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    srand(time(0));

    string secret = to_string(1000 + rand() % 9000);

    int attempts = 0;
    cout << "Welcome to Bulls and Cows game! Try to guess the 4-digit number." << endl;

    while (true) {
        string guess;
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess.length() != 4 || guess.find_first_not_of("0123456789") != string::npos || hasRepeatingDigits(guess)) {
            cout << "Please enter a valid 4-digit number without repeating digits." << endl;
            continue;
        }

        int bulls = getBulls(secret, guess);
        int common = getCommon(secret, guess);
        int cows = common - bulls;

        attempts++;

        if (bulls == 4) {
            cout << "Congratulations! You've guessed the number " << secret << " in " << attempts << " attempts." << endl;
            break;
        }
        else {
            cout << "Bulls: " << (cows > 0 ? cows : bulls) << (cows > 0 ? ", Cows: " + to_string(cows) : "") << endl;
        }
    }

    return 0;
}