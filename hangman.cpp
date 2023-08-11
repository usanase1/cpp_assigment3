#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

bool ExistIn(char c, char a[], int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] == c) {
            return true;
        }
    }
    return false;
}

int main() {
    string word_list[]{"Nalty", "Claire", "Frisun", "Noella", "Shyaka", "Henry", "Philos"};
    char answer[100]{};
    char word[100]{};
    char vowels[]{'a', 'i', 'u', 'o', 'e'};
    char consonants[]{'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z'};
    srand(time(0));
    int n = rand();
    int k = sizeof(word_list) / sizeof(word_list[0]);
    n = n % k;
    string random_word = word_list[n];
    for (int i = 0; i < random_word.length(); i++) {
        word[i] = tolower(random_word[i]);
    }

    for (int i = 0; i < random_word.length(); i++) {
        answer[i] = '_';
    }

    cout << "You are going to guess this word: ";
    for (int i = 0; i < random_word.length(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    int lives = 6;
    int warnings = 3;

    while (ExistIn('_', answer, random_word.length()) && lives > 0) {
        char guess;
        cout << "Guess a letter in the word.\n> ";
        cin >> guess;
        guess = tolower(guess);

        if (ExistIn(guess, answer, random_word.length()) || (!ExistIn(guess, consonants, sizeof(consonants)) && !ExistIn(guess, vowels, sizeof(vowels)))) {
            if (warnings > 0) {
                warnings--;
            } else {
                lives--;
            }
            if (ExistIn(guess, answer, random_word.length())) {
                cout << "Warning: You have already input '" << guess << "'" << endl;
            } else {
                cout << "Please enter a valid letter of the Alphabet." << endl;
            }
        } else if (!ExistIn(guess, word, random_word.length())) {
            cout << "'" << guess << "' is not in the word." << endl;
            if (ExistIn(guess, consonants, sizeof(consonants))) {
                lives--;
            } else {
                lives -= 2;
            }
        } else {
            for (int i = 0; i < random_word.length(); i++) {
                if (answer[i] == '_' && word[i] == guess) {
                    answer[i] = guess;
                }
            }
        }

        cout << "Progress: ";
        for (int i = 0; i < random_word.length(); i++) {
            cout << answer[i] << " ";
        }
        cout << endl << "Remaining Life: " << lives << endl << endl;
    }

    if (lives <= 0) {
        if (lives < 0) {
            lives = 0;
        }
        cout << "You lose." << endl;
    } else {
        cout << "Congratulations, You Win!" << endl;
        cout << "Score: " << lives * random_word.length() << endl;
        cout << "Perfection(%): " << lives * 100 / 6 << "%" << endl;
    }
    cout << "Word: ";
    for (int i = 0; i < random_word.length(); i++) {
        cout << word[i];
    }
    cout << endl;
    return 0;
}
