#include "../HTMLDecode/HTMLDecode.h"
#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include <iostream>

TEST_CASE("Decoding an empty string")
{
	std::string str = "";
	std::string result = HtmlDecode(str);
	std::string expected = "";
	CHECK(result == expected);
}

TEST_CASE("Decoding string without HTML entitites")
{
	std::string str = "String for test";
	std::string result = HtmlDecode(str);
	std::string expected = "String for test";
	CHECK(result == expected);
}

TEST_CASE("Decoding string = \"Cat &lt; says &gt; &quot; Meow &quot;.M&amp; M&apos;s\" into = \"Cat <says> \" Meow \". M&M’s\" that means all required HTML entities")
{
	std::string str = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s that means all required HTML entities";
	std::string result = HtmlDecode(str);
	std::string expected = "Cat <says> \"Meow\". M&M's that means all required HTML entities";
	CHECK(result == expected);
}

TEST_CASE("Decoding string with incorrect HTML entities")
{
	std::string str = "&ap;";
	std::string result = HtmlDecode(str);
	std::string expected = "&ap;";
	CHECK(result == expected);
}

TEST_CASE("Decoding doubled string")
{
	std::string str = "&lt;&lt;";
	std::string result = HtmlDecode(str);
	std::string expected = "<<";
	CHECK(result == expected);
}

TEST_CASE("Decoding doubled string with & in the end")
{
	std::string str = "&lt;&lt;&";
	std::string result = HtmlDecode(str);
	std::string expected = "<<&";
	CHECK(result == expected);
}

TEST_CASE("Decoding string misprint")
{
	std::string str = "&amp&gt;";
	std::string result = HtmlDecode(str);
	std::string expected = "&amp>";
	CHECK(result == expected);
}
