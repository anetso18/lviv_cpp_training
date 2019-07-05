#include <iostream>
#include <cctype>

int main()
{
	std::string words;	
	int vowels = 0, consonants = 0, others = 0;
	
	std::cout << "Enter words (q to quit)"<<std::endl;
	while ((std::cin >> words)&&(words != "q"))
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
				++vowels;
				break;
			default:
				++consonants;
				break;
			}
		}
		else {
			++others;
		}
	}
  
	std::cout << vowels << " words beginning with vowel"<<std::endl;
	std::cout << consonants << " words beginning with consonant"<<std::endl;
	std::cout << others << " others"<<std::endl;
	
	return EXIT_SUCCESS;
}
