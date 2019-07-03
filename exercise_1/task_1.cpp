#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	string words;	
	int vowels = 0, consonants = 0, others = 0;
	
	cout << "Enter words (q to quit)\n";
	while ((cin >> words)&&(words != "q"))
	{
		if (isalpha(words[0]))
		{
			switch (tolower(words[0])) {
			case 'a':
			case 'i':
			case 'e':
			case 'o':
			case 'u':
			case 'y':
				vowels++;
				break;
			default:
				consonants++;
				break;
			}
		}
		else {
			others++;
		}
	}
  
	cout << vowels << " words beginning with vowel\n";
	cout << consonants << " words beginning with consonant\n";
	cout << others << " others";
}
