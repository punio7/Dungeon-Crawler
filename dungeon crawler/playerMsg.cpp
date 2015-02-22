#include "playerMsg.h"

static locale loc;

void playerMsg(string msg, string in0, string in1, string in2, string in3, string in4, string in5, string in6, string in7, string in8, string in9)
{
	bool flagNewLine = true;	// |_ powoduje usuniecie akapitu na koniec tekstu
	Format format = FORMAT_NORMAL;

	if (!in0.empty())
	{
		char c;
		for (int i=0; i < msg.length(); i++)	//uzupe³nianie
		{
			if (c=msg[i] != '|')
				continue;
			c = msg[++i]; //nastepny znak za pa³k¹
			switch (c)
			{
			case '0':
				msg.erase(--i, 2);
				msg.insert(i, in0);
				i += in0.length();
				break;
			case '1':
				msg.erase(--i, 2);
				msg.insert(i, in1);
				i += in1.length();
				break;
			case '2':
				msg.erase(--i, 2);
				msg.insert(i, in2);
				i += in2.length();
				break;
			case '3':
				msg.erase(--i, 2);
				msg.insert(i, in3);
				i += in3.length();
				break;
			case '4':
				msg.erase(--i, 2);
				msg.insert(i, in4);
				i += in4.length();
				break;
			case '5':
				msg.erase(--i, 2);
				msg.insert(i, in5);
				i += in5.length();
				break;
			case '6':
				msg.erase(--i, 2);
				msg.insert(i, in6);
				i += in6.length();
				break;
			case '7':
				msg.erase(--i, 2);
				msg.insert(i, in7);
				i += in7.length();
				break;
			case '8':
				msg.erase(--i, 2);
				msg.insert(i, in8);
				i += in8.length();
				break;
			case '9':
				msg.erase(--i, 2);
				msg.insert(i, in9);
				i += in9.length();
				break;
			default:
				break;
			}
		}
	}

	msg = wersalikuj(msg);

	char c;
	color(HWHITE);
	for (int i=0; i < msg.length(); i++)	//kolorowanie
	{
		if ( (c = msg[i]) != '|')
		{
			switch (format)
			{
			case FORMAT_NEXTUPPER:
				format=FORMAT_NORMAL;
			case FORMAT_UPPERCASE:
				c=toupper(c, loc);
				break;
			case FORMAT_LOWERCASE:
				c=tolower(c, loc);
				break;
			default:
				break;
			}
			cout<<c;
			continue;
		}

		c = msg[++i]; //nastepny znak za pa³k¹
		switch (c)
		{
		case '_':
			flagNewLine = false;
			break;
		case '-':
			if (format == FORMAT_LOWERCASE)
				format = FORMAT_NORMAL;
			else
				format = FORMAT_LOWERCASE;
			break;
		case '+':
			if (format == FORMAT_UPPERCASE)
				format = FORMAT_NORMAL;
			else
				format = FORMAT_UPPERCASE;
			break;
		case '^':
			format = FORMAT_NEXTUPPER;
			break;
		default:
			color(c);
		}
		msg.erase(--i, 2);
		--i;
	}
	color(HWHITE);
	if (flagNewLine)
		cout<<endl;

}

string intToStr(int i)
{
	ostringstream temp;
	temp<<i;
	return temp.str();
}

string floatToStr(float f)
{
	ostringstream temp;
	temp<<f;
	return temp.str();
}

string czystyTekst(string text)
{
	char c;
	for (int i=0; i<text.length(); i++)
	{
		if (text[i] == '|')
		{
			text.erase(i--, 2);
		}
		else
			text[i] = tolower(text[i], loc);
	}
	return text;
}