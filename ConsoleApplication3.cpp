#include <iostream>
#include <cctype>
#include <string>
#include <map>
using namespace std;

string key_func() {
	string key; //first menu to take the secret key as an input and make sure that it is valid

	cout << "enter 5 unique digits to use it as the secret key and don't leave a space between the numbers\n";
	while (true) {
		bool contain_space = false, contain_alpha = false, contain_punc = false, repeated = false, rangenum = false;
		getline(cin, key);

		//the key should be 5 digits so its length must be 5
		if (key.length() != 5) {

			cout << "please enter a 5-digit number: ";
			continue;
		}
		for (char c : key) {                     //checking if the key contain any other things than digits
			if (isspace(c)) {                    // if so i make the flag equal true so i print the right message to the type of the error
				contain_space = true;
				break;
			}
			else if (isalpha(c)) {
				contain_alpha = true;
				break;
			}
			else if (ispunct(c)) {
				contain_punc = true;
				break;
			}
			else if ((int)c - '0' > 5 || (int)c - '0' < 1)
			{
				rangenum = true;
				break;
			}
		}
		for (int i = 0; i < 5; i++)         //all digits of the key must be unique if not i make the flag related with this problem true to print the right error message
		{
			for (int j = i + 1; j < 6; j++)
			{
				if (key[i] == key[j])
				{
					repeated = true;
					break;
				}
			}
		}

		// this part prints the error message related to the specific error and then take the key as an input again
		if (contain_space) {
			cout << "please don't leave a space" << endl;
			continue;
		}
		else if (contain_alpha) {
			cout << "you cannot insert alphabets, please insert numbers only: ";
			continue;
		}
		else if (contain_punc) {
			cout << "you cannot insert punctuation marks, please insert numbers only: ";
			continue;
		}
		else if (repeated)
		{
			cout << "please enter unique digits: ";
			continue;
		}
		else if (rangenum) {
			cout << "please enter numbers in range (1-5): ";
			continue;
		}
		else
		{
			break;
		}
	}
	return key;

}

void enc_func() {

	// this is the encryption function
	// first thing i call the key function and take the key as an input
	string key = key_func();

	char table[6][6];  //declaring the 2D array the first row and column will contain the key and rest will contain the alphabetic letters
	table[0][0] = ' ';

	// put the key in the 2D array
	for (int i = 1; i < 6; i++) {
		table[0][i] = key[i - 1]; // here i put the key in the first row
		table[i][0] = key[i - 1]; // and here in the fisrt column
	}

	 // filing the rest of the array with the alphabetic letters
	char ch = 'A';
	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 6; j++) {
			if (ch == 'J') // skipping the letter j and it will be printed as i
				ch++;
			table[i][j] = ch++; // using the ascii code to fill the array with the letters
		}

	}
	
	// if you want to see how the table will look like

	/*for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cout << table[i][j];
			cout << " ";
		}
		cout << endl;
	}*/



	string encrypted = ""; // the variable where i store the encrypted message
	string message;

	cout << endl << "enter the message you want to encrypt: ";

	getline(cin, message);
	
	// this part where the encryption starts
	 
	for (char c : message) { 
		if (!isalpha(c)) { // if the character isn't alpha don't encrypt it
			encrypted += c;
		}
		// using switch to encrype every letter and return the row/col opposite to it
		switch (toupper(c)) {
		case 'A':
			encrypted += to_string(table[1][0] - '0') + to_string(table[0][1] - '0');  
			break;
		case 'B':
			encrypted += to_string(table[1][0] - '0') + to_string(table[0][2] - '0');
			break;
		case 'C':
			encrypted += to_string(table[1][0] - '0') + to_string(table[0][3] - '0');
			break;
		case 'D':
			encrypted += to_string(table[1][0] - '0') + to_string(table[0][4] - '0');
			break;
		case 'E':
			encrypted += to_string(table[1][0] - '0') + to_string(table[0][5] - '0');
			break;
		case 'F':
			encrypted += to_string(table[2][0] - '0') + to_string(table[0][1] - '0');
			break;
		case 'G':
			encrypted += to_string(table[2][0] - '0') + to_string(table[0][2] - '0');
			break;
		case 'H':
			encrypted += to_string(table[2][0] - '0') + to_string(table[0][3] - '0');
			break;
		case 'I':
			encrypted += to_string(table[2][0] - '0') + to_string(table[0][4] - '0');
			break;
		case 'J':
			encrypted += to_string(table[2][0] - '0') + to_string(table[0][4] - '0');
			break;
		case 'K':
			encrypted += to_string(table[2][0] - '0') + to_string(table[0][5] - '0');
			break;
		case 'L':
			encrypted += to_string(table[3][0] - '0') + to_string(table[0][1] - '0');
			break;
		case 'M':
			encrypted += to_string(table[3][0] - '0') + to_string(table[0][2] - '0');
			break;
		case 'N':
			encrypted += to_string(table[3][0] - '0') + to_string(table[0][3] - '0');
			break;
		case 'O':
			encrypted += to_string(table[3][0] - '0') + to_string(table[0][4] - '0');
			break;
		case 'P':
			encrypted += to_string(table[3][0] - '0') + to_string(table[0][5] - '0');
			break;
		case 'Q':
			encrypted += to_string(table[4][0] - '0') + to_string(table[0][1] - '0');
			break;
		case 'R':
			encrypted += to_string(table[4][0] - '0') + to_string(table[0][2] - '0');
			break;
		case 'S':
			encrypted += to_string(table[4][0] - '0') + to_string(table[0][3] - '0');
			break;
		case 'T':
			encrypted += to_string(table[4][0] - '0') + to_string(table[0][4] - '0');
			break;
		case 'U':
			encrypted += to_string(table[4][0] - '0') + to_string(table[0][5] - '0');
			break;
		case 'V':
			encrypted += to_string(table[5][0] - '0') + to_string(table[0][1] - '0');
			break;
		case 'W':
			encrypted += to_string(table[5][0] - '0') + to_string(table[0][2] - '0');
			break;
		case 'X':
			encrypted += to_string(table[5][0] - '0') + to_string(table[0][3] - '0');
			break;
		case 'Y':
			encrypted += to_string(table[5][0] - '0') + to_string(table[0][4] - '0');
			break;
		case 'Z':
			encrypted += to_string(table[5][0] - '0') + to_string(table[0][5] - '0');
			break;
		}

	}
	cout << endl << "your encrypted message is: " << encrypted << endl;
	cout << "thank you for using our program :)\nEXITING...";

}
void dec_func() {
	// the decryption function

	while (true)
	{
		//the key and the table step is exactly the same as in encryption
		string key = key_func();
		char table[6][6];
		table[0][0] = ' ';
		for (int i = 1; i < 6; i++) {
			table[0][i] = key[i - 1];
			table[i][0] = key[i - 1];
		}

		char ch = 'A';
		for (int i = 1; i < 6; i++) {
			for (int j = 1; j < 6; j++) {
				if (ch == 'J')
					ch++;
				table[i][j] = ch++;
			}
		}
	/*
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				cout << table[i][j];
				cout << " ";
			}
			cout << endl;
		}
		*/


		string message;
		cout << "enter the message you want to decrypt: ";
		//this loop checks if the digits in the message is also in the range from 1-5 or not 
		// and if the message is completed as every letter is stored in 2 digits therefore its length must be even 
		while (true)
		{
			getline(cin, message);
			string withoutspace = ""; //the withoutspace variable is to store the message without any spaces and any other char except digits
			for (char c : message)
			{
				
				if (!isdigit(c))
				{
					withoutspace += "";
				}
				else
				{
					withoutspace += c;
				}
			}

			// checking if every digit is in range 1-5
			bool try_again;
			for (char n : withoutspace)
			{
				try_again = false;
				if ((int)n - '0' > 5 || (int)n - '0' < 1)
				{
					try_again = true;
					break;
				}
				else
				{
					continue;

				}
			}

			if (try_again)
			{
				cout << "ERROR! your message should only contain numbers in range (1-5)\nplease try again: \n";
				continue;
			}

			//checking thr length
			if (withoutspace.length() % 2 == 0)
			{
				break;
			}
			else
			{
				cout << "ERROR! your message is not complete \nplease try again: \n";
			}
				
		}

		//the decryption part starts from here
		string row_col = "", decrypted = "";

		//getting the coordinates of every letter 
		for (char c : message)
		{
			if (!isdigit(c))
			{
				row_col += c;
				continue;
			}
			else
			{
				for (int i = 1; i < 6; i++)  
				{
					if (c == table[i][0])
					{
						row_col += to_string(i);
						break;
					}
				}
			}
		}

		//translate the meesage into letters 
		for (int i = 0; i < row_col.length(); i++)
		{
			if (!isdigit(message[i])) 
			{
				decrypted += message[i];
				continue;

			}
			else
			{
				int row = row_col[i] - '0';  //translateing the coord as the fisrt digit the the row and the second is the col 
				int col = row_col[i + 1] - '0';
				decrypted += tolower(table[row][col]);
				i++;
			}
		}
		cout << endl << "your decrypted message is: " << decrypted << endl << endl;
		cout << "thank you for using our program :)\nEXITING...";
		break;
	}
}

int main() {
	char enc_dec;
	cout << "WELCOME TO POLYBIUS CIPHER\n\nplease pick what you would like to do\n\n";
	cout << "1) encrypt the message\n2) decrypt message\n3) press any other key to exit the program" << endl;
	cin >> enc_dec;
	cin.ignore();
	if (enc_dec == '1')
	{

		enc_func();
	}

	else if (enc_dec == '2')
	{

		dec_func();
	}
	else
	{
		cout << "thank you for using our program :)\nEXITING...";
	}

	return 0;
}