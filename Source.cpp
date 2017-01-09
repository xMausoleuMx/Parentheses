#include <string>
#include <stack>
#include <iostream>

using namespace std;

int checkParen(string phrase)
{
	std::stack<int> parenStack;
	int counter = 0;
	
	for (int i = 0; i < phrase.size(); i++)
	{
		if (phrase[i] == '(')
		{
			counter++;
			parenStack.push(i);
		}
		else if (phrase[i] == ')')
		{
			counter--;
			if (parenStack.size() > 0)
				parenStack.pop();
		}
		if (counter < 0)
			return i;
	}
	if (counter > 0)
		return parenStack.top();
	else
		return phrase.length();
}

int main()
{
	string phrase;
	while (true)
	{
		std::cin >> phrase;
		if (!phrase.compare("exit"))
			break;
		int n = checkParen(phrase);
		for (int i = 0; i < phrase.size(); i++)
		{
			if (i == n)
				std::cout << "*" << phrase[i] << "*";
			else
				std::cout << phrase[i];
		}
		std::cout << std::endl;
	}

}