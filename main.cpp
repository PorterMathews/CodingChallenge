#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <cctype>

using namespace std;

//This checks to see if the letter is in the vector of letters
bool letterChecker(char letter, const vector<char> &vecOfletters){
    for (char c: vecOfletters){
        if (c == letter){
            return true;
        }
    }
    return false;
}

//Asks the player if they would like to play again
bool playAgain(){
    string response;

    //Early return keeps the while loop from running forever
    while (true) {
        cout << "Would you like to play again? Y/n" << endl;
        cin >> response;
        if (response == "Y" || response == "y" || response == "yes" || response == "Yes" || response == "YES")
            return true;
        else if (response == "N" || response == "n" || response == "no" || response == "No" || response == "NO")
            return false;
        else {
            cout << response << " is not a valid response." << endl;
        }
    }
}


//The main work of the game happens here
void hangman(string &codeWord,vector<char> &wordToGuess,vector<char> &guessProgress ){
    int guesses = 0, correctGuess = 0, incorrectGuess = 0;
    char letter;
    vector<char> guessedLetters = {};

    cout << "The word is " << wordToGuess.size() << " letters long." << endl;

    //This while loop keeps the player guessing until they complete the word
    while (wordToGuess != guessProgress) {


        cout << "Guess a letter: " << endl;
        cin >> letter;

        //Checks to see if the cin is a letter and gets rid of any junk if not
        if (!isalpha(letter) || cin.get() != '\n') {
            cout << "That is not a valid entry. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        //Converts the input into lowercase for checking
        letter = tolower(letter);

        //Checks to see if the letter has been guessed before
        if (letterChecker(letter, guessedLetters)){
            for (char l : guessedLetters){
                if (l == letter) {
                    cout << "You already guessed the letter " << letter << ". Please pick another letter." << endl;
                    continue;
                }
            }
        }

        //Checks to see if the letter is in the codeWord
        else if (letterChecker(letter, wordToGuess)){
            int index = 0;
            for (char a : wordToGuess){
                if (a == letter) {
                    guessProgress[index] = letter;
                }
                index++;
            }
            guesses++;
            correctGuess++;
            cout << " Correct! "<< letter << " is part of the word." << endl;
            cout << "Word Progress: ";
            for (char c : guessProgress){
                cout << c;
            }
            cout << endl;
            cout << "You have made " << guesses << " total guess(es). You have made " << correctGuess << " correct guess(es). You have made " << incorrectGuess << " incorrect guess(es)." << endl;
        }

        //Marks the guess as not correct
        else {
            guesses++;
            incorrectGuess++;
            cout << " Incorrect! "<< letter << " is not part of the word." << endl;
            cout << "Word Progress: ";
            for (char c : guessProgress){
                cout << c;
            }
            cout << endl;
            cout << "You have made " << guesses << " total guess(es). You have made " << correctGuess << " correct guess(es). You have made " << incorrectGuess << " incorrect guess(es)." << endl;
        }

        //Adds the letter to the guess letters vector
        guessedLetters.push_back(letter);
    }
    //Message for when they complete the word
    cout << "Congrats you guessed " << codeWord << " in " << guesses << " guesses." << endl;
}

int main() {

    cout << "!!Welcome to Hangman!!" << endl;

    //word pool
    vector<string> possibleWords = {"apple", "banana", "jazz", "plaza", "happy", "oit", "chocolate", "hippopotomonstrosesquipedaliophobia", "inconceivable", "smurf"}; //

    //Loop brakes only when playAgain = False
    while (true) {

        //Checks to see if player has used every word in word pool
        if (possibleWords.empty()){
            cout << "No more words." << endl;
            break;
        }

        //Random number gen between 0 and the size of possible words
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, possibleWords.size() - 1);
        int randomNumber = dis(gen);

        //Gets word for hangman
        string wordToGuess = possibleWords[randomNumber];
        //cout << "Word: " << wordToGuess << endl;

        //Removes chosen word from possible words, so the same word is never chosen twice
        possibleWords.erase(possibleWords.begin() + randomNumber);

        //Creates two vectors and fills them
        vector<char> vectorToGuess; // A vector with the letters of the wordToGuess in Order
        vector<char> guessProgress; // A vector of "_"s the size of the wordToGuess
        for (char c: wordToGuess) {
            vectorToGuess.push_back(c);
            guessProgress.push_back('_');
        }

        //Calls the hangman function
        hangman(wordToGuess, vectorToGuess, guessProgress);

        //Allows the player to exit the game
        if (!playAgain())
            break;

    }

    cout << "Thanks for playing!" << endl;
    return 0;
}