#include <iostream>
#include <string>
#include <cctype>
#include "Vigenere.h"

using namespace std;

// Initialize the mapping table
void Vigenere::initializeTable()
{
    for (char row = 0; row < CHARACTERS; row++)
    {
        char lChar = 'B' + row;
        for (char column = 0; column < CHARACTERS; column++)
        {
            if (lChar > 'Z')
                lChar = 'A';
            fMappingTable[row][column] = lChar++;
        }
    }
}

// Constructor initializes the keyword provider and mapping table
Vigenere::Vigenere(const std::string& aKeyword) : fKeyword(aKeyword), fKeywordProvider(KeyProvider(aKeyword))
{
    initializeTable();
}

// Return the current keyword without modifying the provider
std::string Vigenere::getCurrentKeyword()
{
    std::string current_keyword;
    for (size_t i = 0; i < fKeyword.length(); i++)
    {
        current_keyword += *fKeywordProvider;
    }
    return current_keyword;
}

// Reset the keyword provider to its initial keyword
void Vigenere::reset()
{
    fKeywordProvider.initialize(fKeyword);
}

// Encode a character using the current keyword character and update the keyword
char Vigenere::encode(char aCharacter) {
    bool check = false;
    char current_char;
    if (isupper(aCharacter)) {
        current_char = aCharacter;
        check = true;
    }
    else {
        current_char = toupper(aCharacter);
        check = false;
    }
    char current_key = *fKeywordProvider;
    char encode_key;
    if (isalpha(current_char) && isalpha(current_key)) {
        fKeywordProvider << aCharacter;
        int row = current_key - 65;
        int column = current_char - 65;
        if (row >= 0 && row < CHARACTERS && column >= 0 && column < CHARACTERS)
        {
            //cout << fMappingTable[row][column];
            encode_key = fMappingTable[row][column];
        }
        else {
            encode_key = aCharacter;
        }
    }
    else {
        encode_key = aCharacter;
    }
    if (check) {
        return encode_key;
    }
    else {
        return tolower(encode_key);
    }
}


// Decode a character using the current keyword character and update the keyword
char Vigenere::decode(char aCharacter)
{
    if (isalpha(aCharacter))
    {
        bool isLower = islower(aCharacter);
        char encoded = toupper(aCharacter);
        char decoded = 0;

        // Find the column that matches the encoded character
        for (char column = 0; column < CHARACTERS; column++)
        {
            if (fMappingTable[*fKeywordProvider - 'A'][column] == encoded)
            {
                decoded = static_cast<char>(column + 'A');
                break;
            }
        }

        fKeywordProvider << decoded;
        if (isLower)
        {
            return static_cast<char>(tolower(decoded));
        }
        return decoded;
    }
    return aCharacter;
}



