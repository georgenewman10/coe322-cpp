// George Newman / 10-10-2018
// K-shift cipher program / encrypts or decrypts a user defined message

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::getline;   		// apparently this is needed for proper input
using std::endl;
using std::isdigit;

int encrypt(string text, int shift, string &eMessage){
	int j = text.length();  // we'll iterate through this number
	for(int i=0; i<j; i++){
		if (isalpha(text[i])){
			int b = 97;	 	// starting decimal value for lowercase chars in ascii table
			if (isupper(text[i])) // I'm leaving the uppercase letters uppercase, so the message can be decrypted
				b = 65;		// upper case chars start at 65
			int decimalValue = (((int)text[i] - b + shift) % 26) + b;	// subtract away b so that our math works
			eMessage = eMessage + (char)decimalValue;  // 
		}
		else
			eMessage = eMessage + text[i]; // if symbol isn't a letter, leave it unchanged
	}
	return 0;
}



int decrypt(string text, int shift, string &dMessage) {
	int j = text.length();										// Everything here is similar to encrypt method, 
	for (int i=0; i<j; i++){									// except we start at Z and subtract the shift 
		if (isalpha(text[i])){									// number from the current value.
			int b = 122;
			if (isupper(text[i]))
				b = 90;
			int decimalValue = (((int)text[i] - b - shift) % 26) + b;		
			dMessage = dMessage + (char)decimalValue;
		}
		else
			dMessage = dMessage + text[i];
	}
	return 0;
}





int main(){
	string message, dM, eM;
	char type;
	int k;

	cout << "Encryption or decryption? (e/d): ";
	cin >> type;		
	cin.ignore();

	cout << "Enter message: ";
	getline(cin, message);   // input message

	cout << "Shift key: ";
	cin >> k;


	if (type=='e'){     // do I get extra points for passing by reference
		encrypt(message, k, eM);
		cout << "Encrypted message: " << eM << endl; 
	}  
	else if (type=='d'){  
		decrypt(message, k, dM);
		cout << "Decrypted message: " << dM << endl;
	}	
	else
		cout << "Try again" << endl;
	return 0;
}
