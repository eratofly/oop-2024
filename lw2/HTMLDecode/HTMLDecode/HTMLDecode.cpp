#include <iostream>
#include <utility>
#include "HTMLDecode.h"

using namespace std;

struct Entity
{
	std::string encoded;
	char decoded;
};

Entity htmlEntitites[] = {
	{ "&quot;", '"' },
	{ "&apos;", '\'' },
	{ "&lt;", '<' },
	{ "&gt;", '>' },
	{ "&amp;", '&' }
};

string HtmlDecode(const string& html)
{
	string result;
	
	for (size_t pos = 0; pos < html.length(); ++pos)
	{
		if (html[pos] == '&')
		{
			bool found = false;
			for (const Entity& entity : htmlEntitites)
			{
				if (html.compare(pos, entity.encoded.length(), entity.encoded) == 0)
				{
					result += entity.decoded;
					pos += entity.encoded.length() - 1;
					found = true;
					break;
				}
			}
			if (!found)
			{
				result += '&' ;
			}
		}
		else
		{
			result += html[pos];
		}
	}

	return result;
}
