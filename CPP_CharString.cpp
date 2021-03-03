#include <iostream>
using namespace std;

void part1()
{
	char c = 'A';
	cout << c << endl;
	cout << (int)c;
}


void part2()
{
	char c;
	// Њечать всех символов таблицы ASCII
	for (int i = 0; i <= 255; i++)
	{
		//c = i;
		cout << (char)i << "  " << i << '\t';
	}

	char symbol = 'A';
	if (symbol >= 'A' && symbol <= 'Z')
		cout << symbol << " - is uppercase letter";
}

void part3()
{
	// Њроверка, €вл€етс€ ли слово палиндромом
	//char s[100] = "KAZAK";
	char s[100] = "No Lemon, no Melon";
	//s[6] = '\0';

	cout << endl << s;
	_strlwr_s(s);

	// preprocessing to remove spaces
	for (size_t i = 0; i < strlen(s); i++)
	{

		if (isspace(s[i]))
		{
			for (size_t j = i; j < strlen(s); j++)
			{
				s[j] = s[j + 1];
			}
		}
	}


	cout << endl << s;
	cout << endl << strlen(s);


	//cout << endl << s[25];
	bool flag = true;
	for (size_t i = 0; i < strlen(s) / 2; i++)
	{
		if (s[i] != s[strlen(s) - 1 - i])
		{
			flag = false;
			break;
		}
	}

	cout << endl;
	if (flag == true)
		cout << "Palindrome";
	else
		cout << "Not a palindrome";

	cout << endl;
	cout << (flag == false ? "Not a " : "") << "palindrome";
}

void part4()
{
	char c;
	// ѕереворот строки
	char s1[255] = "qwertyuiop";
	//	s1[10] = '\0';
	cout << endl << s1;
	for (size_t i = 0; i < strlen(s1) / 2; i++)
	{
		c = s1[i];
		s1[i] = s1[strlen(s1) - 1 - i];
		s1[strlen(s1) - 1 - i] = c;
	}
	cout << endl << s1;

	cout << endl << _strrev(s1) << endl;

	// ѕоиск в строке
	cout << endl << "t is at: " << strchr(s1, 't') - s1;
	cout << endl << "tr is at: " << strstr(s1, "tr") - s1;
	s1[5] = 'T';
	cout << endl << "In \"" << s1 << "\" char \"tr\" is at ";
	if (strstr(s1, "tr") != NULL)
		cout << strstr(s1, "tr") - s1;
	else
		cout << "Not found";

	cout << "\n\n\n";
}

void part5()
{
	cout << "Processing char type:" << endl;

	char s1[255] = "TTTest senttenceee...hereee     yoooou haveee !!!! ";
	char s2[255];
	char s3[255];
	char c;
	unsigned int i, j, k, n;
	s2[0] = '\0';
	s3[0] = '\0';
	printf("\nS1: %40s\tLength: %d", s1, strlen(s1));
	printf("\nS2: %40s\tLength: %d", s2, strlen(s2));
	printf("\nS3: %40s\tLength: %d", s3, strlen(s3));
	printf("\n----------------------------------------\n");

	strcpy_s(s2, s1);
	strncpy_s(s3, s1, 15);
	//s3[15] = '\0';
	printf("\nS1: %40s\tLength: %d", s1, strlen(s1));
	printf("\nS2: %40s\tLength: %d", s2, strlen(s2));
	printf("\nS3: %s\tLength: %d", s3, strlen(s3));
	printf("\n----------------------------------------\n");
	i = 1, j = 1; // Deleting of all the same multiple symbols (1 way)
	c = s2[0];
	s3[0] = '\0';
	s3[0] = s2[0];
	while (s2[i] != '\0')
	{
		if ((s2[i] != c || c == '.'))
		{
			s3[j] = s2[i];
			j++;
			c = s2[i];
		}
		i++;
	}
	s3[j] = '\0';


	i = 1; // Deleting of all the same multiple symbols (2 way)
	c = s2[0];
	while (s2[i] != '\0')
	{
		if ((s2[i] == c && c != '.'))
		{
			for (k = i; k < (strlen(s2) - 1); k++)
				s2[k] = s2[k + 1];
			s2[k] = '\0';
			i--;
		}
		c = s2[i];			// берЄм новый символ дл€ сравнени€ на повтор€емость
		i++;
	}
	printf("\nS1: %40s\tLength: %d", s1, strlen(s1));
	printf("\nS2: %s\tLength: %d", s2, strlen(s2));
	printf("\nS3: %s\tLength: %d", s3, strlen(s3));
	printf("\n----------------------------------------\n");
	i = 0; // Reversing S1
	n = strlen(s1);
	while (i < (n / 2))
	{
		c = s1[i];
		s1[i] = s1[n - i - 1];
		s1[n - i - 1] = c;
		i++;
	}
	//s1[n] = '\0';  // необ€зательное в данном случае добавление 0-терминатора  
	i = 0; // Doubling every symbol in S2
	n = strlen(s2);
	for (i = 0; i < n * 2; i += 2)
	{
		s2[n + i + 1] = '\0';
		for (k = n + i + 1; k > i; k--)
			s2[k] = s2[k - 1];
	}

	i = strchr(s3, ' ') - s3 - 1;   //  вычисление позиции первого пробела слева как разность между адресом первого пробела и адресом начала строки
									//Inserting 5 "_" instead of every 1 space
	while ((s3[i] != '\0') && (i > 0))
	{
		if (s3[i] == ' ')
		{
			n = strlen(s3);
			s3[n + 5] = '\0';
			for (k = n + 5 - 1; k > i; k--)
				s3[k] = s3[k - 4];
			for (k = 0; k < 5; k++)
				s3[i + k] = '_';
			i += 5;
		}
		i++;
	}
	printf("\nS1: %40s\tLength: %d", s1, strlen(s1));
	printf("\nS2: %40s\tLength: %d", s2, strlen(s2));
	printf("\nS3: %40s\tLength: %d", s3, strlen(s3));
	printf("\n----------------------------------------\n");

	cin.clear();
}

void part6()
{
	cout << endl << endl << "Processing string type:" << endl;

	string s1 = "123", s2 = "456qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq", s3;
	cout << (s1 + s2).length();
	cout << endl << (s3 = s1 + s2).c_str();
	cout << "\nSymbol 4 is at " << s3.find_first_of('4', 0);

	cout << endl << s3.c_str();
	s3.replace(1, 3, "ww", 3);
	cout << endl << s3.c_str();

	cout << endl;
	char douplicates[] = { ' ', ',' , '-', ';' };
	unsigned int dsize = sizeof(douplicates);
	string s = "!This is an example,it is beautiful.     Ready ?    Let's try to correct it   . Go!";
	cout << s.c_str();


	for (size_t k = 0; k < dsize; k++)
	{
		for (size_t i = 1; i < s.length(); i++)
			while (s[i] == douplicates[k] && s[i + 1] == douplicates[k])
				s.erase(i, 1);
	}

	for (size_t i = 1; i < s.length(); i++)
	{
		if (ispunct(s[i]) && s[i - 1] == ' ')
			s.erase(i - 1, 1);

		if (ispunct(s[i]) && s[i] != '\'' && s[i] != '\"' && s[i + 1] != ' ')
			s.insert(i + 1, 1, ' ');
	}

	cout << endl << s.c_str() << endl << endl;
	return;
}

void part7()
{

}

void part8()
{

}

void part9()
{

}

void part10()
{

}


int main()
{
	part1();
	part2();
	part3();
	part4();
	part5();
	//	part6();
	//	part7();
	//	part8();
	//	part9();
	//	part10();

	/*
	char number[] = "123 234";
	cout << number;
	int n = atoi(number);
	cout << endl << n;
	_itoa_s(n, number, 10);
	cout << endl<<number;
	*/
}
