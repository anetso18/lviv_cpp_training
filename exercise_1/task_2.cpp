#include <iostream>
#include <fstream>

void word_count(std::string words, int& vowels, int& consonants, int& others);

void  word_count(std::string words, int& vowels, int& consonants, int& others)
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

int main(int argc, char* argv[]) {
	if (argc < 2)
		
		std::cout << "Please specify name of the file by command line argument" << std::endl;
	else {

		int vowels = 0, consonants = 0, others = 0;
		// argv[1] is a filename to open
		std::ifstream myfile(argv[1]);
		if (myfile.is_open())
		{
			std::string word;
			while ((myfile >> word) && (word != "q"))
			{
				word_count(word, vowels, consonants, others);
			}
			myfile.close();
		}
		else
		{
			std::cout << "Unable to open file";
		}
		std::cout << vowels << " words beginning with vowel"<<std::endl;
		std::cout << consonants << " words beginning with consonant" << std::endl;
		std::cout << others << " others" << std::endl;
	}
	return EXIT_SUCCESS;
}
