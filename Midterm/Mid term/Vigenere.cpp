
#include<iostream>
#include"Vigenere.h"

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
Vigenere::Vigenere(const std::string& aKeyword) : fKeywordProvider(aKeyword),
fKeyword(aKeyword) {
	initializeTable();
}
std::string Vigenere::getCurrentKeyword() {
	std::string current_keyword;
	for (int i = 0; i < fKeyword.length(); i++) {
		current_keyword += *fKeywordProvider; 
		fKeywordProvider << *fKeywordProvider;
	}
	return current_keyword;
}
void Vigenere::reset() {
	fKeywordProvider.initialize(fKeyword);
}
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
char Vigenere::decode(char aCharacter) {
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
	int column = 0;
	char decode_key;
	if (isalpha(current_char) && isalpha(current_key)) {
		int row = current_key - 65;
		if (row >= 0 && row < CHARACTERS && column >= 0 && column < CHARACTERS)
		{
			for (int i = 0; i < CHARACTERS; i++) {
				if (fMappingTable[row][i] == current_char) {
					column = i;
					break;
				}
			}
			decode_key = 'A' + column;
			fKeywordProvider << decode_key;
		}
		else {
			decode_key = aCharacter;
		}
	}
	else {
		decode_key = aCharacter;
	}
	if (check) {
		return decode_key;
	}
	else {
		return tolower(decode_key);
	}
}