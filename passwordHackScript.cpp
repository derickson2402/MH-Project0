#include <iostream>
#include <string>
#include <fstream>
#include <vector>

/*#############################################################################

This script is created by Dan Erickson for a Michigan Hackers project

The script generates a .txt file with a list of potential passwords     
that fulfill the parameters set in the Project 0: Forgot Your Password? 
.pdf file included in this repository.

NOTE:
As a general rule, scalability here is preferred to speed. It is assumed that
if one has the computing power to try all of these combinations, then one
should also have the computing power to generate this list. Additionally, in
the future it may be useful to allow a user to input a list of words or other
parameters from the command line or a file, in which case a vector would be
more adaptable.

##############################################################################*/

using namespace std;

int main() {
    
    string fileName = "daniel_erickson_pass.txt"; // The specified filename to save the password list to

    // Open the specified file
    ofstream file; file.open(fileName, ofstream::out | ofstream::trunc);
    if (!file.is_open()) {cout << "Error: Couldn't open file: " << fileName; return 1;}

    // Define all possible words, numbers, and ending characters
    vector <string> words = {"michigan", "hackers", "security", "password"};
    vector <string> endChars = {"?", "!"};
    vector <string> numbers;
    
    // Create all possible two digit numbers. This is necessary for "00" through "09" due to the int to string conversion
    for (int num = 0; num<10; ++num) {
        numbers.push_back("0" + to_string(num));
    }
    for (int num = 10; num<100; ++num) {
        numbers.push_back(to_string(num));
    }

    // Run the loop for each end character
    for (int c=0; c < endChars.size(); ++c) {

        // Cycle through all single word passwords
        for (int w=0; w < words.size(); ++w) {
            
            // Cycle through all positions for the numbers
            for (int n=0; n < numbers.size(); ++n){
                file << numbers[n] << words[w] << endChars[c] << endl;
                file << words[w] << numbers[n] << endChars[c] << endl;
            }
        }

        // Cycle through double word passwords
        for (int w=0; w < words.size(); ++w) {
            
            // Cycle through for the second word
            for(int w2=0; w2 < words.size(); ++w2) {
                
                // Cancel this cycle if the words are the same
                if (!(w==w2)) {
                    
                    // Cycle through all positions for the numbers
                    for (int n=0; n < numbers.size(); ++n){
                        file << numbers[n] << words[w] << words[w2] << endChars[c] << endl;
                        file << words[w] << numbers[n] << words[w2] << endChars[c] << endl;
                        file << words[w] << words[w2] << numbers[n] << endChars[c] << endl;
                    }
                }
            }
        }
        
        // Cycle through triple word passwords
        for (int w=0; w < words.size(); ++w) {
            
            // Cycle through for the second word
            for(int w2=0; w2 < words.size(); ++w2) {
                
                // Cycle through for the third word
                for(int w3=0; w3 < words.size(); ++w3) {
                    
                    // Cancel this cycle if the words are the same
                    if (!(w==w2 | w==w3 | w2==w3)) {

                        // Cycle through all positions for the numbers
                        for (int n=0; n < numbers.size(); ++n){
                            file << numbers[n] << words[w] << words[w2] << words[w3] << endChars[c] << endl;
                            file << words[w] << numbers[n] << words[w2] << words[w3] << endChars[c] << endl;
                            file << words[w] << words[w2] << numbers[n] << words[w3] << endChars[c] << endl;
                            file << words[w] << words[w2] << words[w3] << numbers[n] << endChars[c] << endl;
                        }
                    }
                }
            }
        }

        // Cycle through quadruple word passwords
        for (int w=0; w < words.size(); ++w) {
            
            // Cycle through for the second word
            for(int w2=0; w2 < words.size(); ++w2) {
                
                // Cycle through for the third word
                for(int w3=0; w3 < words.size(); ++w3) {

                    // Cycle through for the fourth word
                    for(int w4=0; w4 < words.size(); ++w4) {

                        // Cancel this cycle if the words are the same
                        if (!(w==w2 | w==w3 | w==w4 | w2==w3 | w2==w4 | w3==w4)) {
                            // Cycle through all positions for the numbers
                            for (int n=0; n < numbers.size(); ++n){
                                file << numbers[n] << words[w] << words[w2] << words[w3] << words[w4] << endChars[c] << endl;
                                file << words[w] << numbers[n] << words[w2] << words[w3] << words[w4] << endChars[c] << endl;
                                file << words[w] << words[w2] << numbers[n] << words[w3] << words[w4] << endChars[c] << endl;
                                file << words[w] << words[w2] << words[w3] << numbers[n] << words[w4] << endChars[c] << endl;
                                file << words[w] << words[w2] << words[w3] << words[w4] << numbers[n] << endChars[c] << endl;
                            }
                        }
                    }
                }
            }
        }
    }

    // Close the file when finished, and print a completion message with some basic statistics
    file.close(); cout << "Done!\n";
}