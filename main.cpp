#include <iostream>
#include <vector>
#include <string>
#include <algorithm>        //for find() function


using namespace std;

int main() {
    
    string userInput;
    
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    vector<pair<char, char>> whaleTalk;   //Pair to store both characters and both cases
    vector<string> result;
    
    
    cout << "Please enter a sentence: ";
    getline(cin, userInput);
    cout << "Your original sentence was: " << userInput << "\n";
    

    for (int i = 0; i < userInput.size(); i++) {
        char currentCharacter = userInput[i];       
        char currentCharacterLower = tolower(currentCharacter);     // Get lowercase for comparison
        
        if (find(vowels.begin(), vowels.end(), currentCharacterLower) != vowels.end()) {
            // Check if the character is a vowel
            if (find_if(whaleTalk.begin(), whaleTalk.end(), 
                        [currentCharacterLower](const pair<char, char>& p) { 
                            return p.first == currentCharacterLower; 
                        }) == whaleTalk.end()) {
                // Check if the lowercase version of the character is not already in whaleTalk
                whaleTalk.push_back(make_pair(currentCharacterLower, currentCharacter)); // Store both the lowercase and original character
                whaleTalk.push_back(make_pair(currentCharacterLower, currentCharacter)); // Duplicate with the same case
            }
        }
    }
    

    
    
    cout << "That same sentence would be pronounced like this in whale talk: ";
    for (const auto& p: whaleTalk) {   // declares variable c that is a char data type to represent each element of whaletalk vector. The : is used to iterate over the elements in the vector.
        cout << p.second;
    }
    
    
    
    return 0;
}
