#define CATCH_CONFIG_MAIN
#define _USE_MATH_DEFINES
#include <math.h>
#include "../../../catch.hpp"
#include "../Bodies/IShape.h"
#include "../Bodies/Circle.h"
#include "../Bodies/Rectangle.h"
#include "../Bodies/ShapesController.h"

SCENARIO("Using shapes utils")
{
	WHEN("read shapes from empty input")
	{
		auto controller = std::make_unique<ShapesController>();
		controller->ParseShape("");
		THEN("shapes are empty")
		{
			CHECK(controller->GetShapes().empty());
		}
	}

	WHEN("read and print shapes")
	{
		auto controller = std::make_unique<ShapesController>();
		auto input = std::istringstream("line 1 2 3 4 abcdef\n"
								   "triangle 10 0 20 0 30 30\n\n"
								   "circle 1 2 3 ffffff 123456\n"
								   "rectangle 1.2 2 3 0 987654");
		for (std::string line; std::getline(input, line);)
		{
			controller->ParseShape(line);
		}
		const auto& shapes = controller->GetShapes();
		THEN("shapes are correct")
		{
			CHECK(shapes[0]->ToString() == "line segment: (1.000000, 2.000000) (3.000000, 4.000000) abcdef");
			CHECK(shapes[1]->ToString() == "triangle: (10.000000, 0.000000) (20.000000, 0.000000) (30.000000, 30.000000) 0 0");
			CHECK(shapes[2]->ToString() == "circle: (1.000000, 2.000000) 3.000000 ffffff 123456");
			CHECK(shapes[3]->ToString() == "rectangle: (1.200000, 2.000000) (3.000000, 0.000000) 987654 0");
		}
	}
}

bool ApproximatelyEquals(double a, double b)
{
	return std::abs(a - b) < 1e-10;
}

TEST_CASE("Operations with shapes")
{
	uint32_t outlineColor = 0xF62681;
	uint32_t fillColor = 0xFF00FF;

	SECTION("Operations with points")
	{

		SECTION("Calculate distance between two points")
		{
			Point p1(3, 4);
			Point p2(0, 0);

			SECTION("Calculate distance between same points")
			{
				auto distance = GetDistance(p1, p1);
				REQUIRE(ApproximatelyEquals(distance, 0));
			}

			SECTION("Calculate distance between different points")
			{
				auto distance = GetDistance(p1, p2);
				REQUIRE(ApproximatelyEquals(distance, 5));
			}
		}
	}

	SECTION("Operations with line segment")
	{
		Point start(0, 1);
		Point end(2, 7);
		LineSegment line(start, end, outlineColor);

		SECTION("Calculate line perimeter")
		{
			double expected = GetDistance(start, end);
			REQUIRE(ApproximatelyEquals(line.GetPerimeter(), expected));
		}
	}

	SECTION("Operations with circle")
	{
		Point center(5, 5);
		double radius = 3;
		Circle circle(center, radius, outlineColor, fillColor);

		SECTION("Calculate circle area")
		{
			double expected = M_PI * radius * radius;
			REQUIRE(ApproximatelyEquals(circle.GetArea(), expected));
		}

		SECTION("Calculate circle perimeter")
		{
			double expected = 2 * M_PI * radius;
			REQUIRE(ApproximatelyEquals(circle.GetPerimeter(), expected));
		}
	}

	SECTION("Operations with rectangle")
	{
		Point leftTop(11, 12);
		Point rightBottom(14, 5);
		MyRectangle rectangle(leftTop, rightBottom, outlineColor, fillColor);

		SECTION("Calculate width and height")
		{
			double expectedWidth = rightBottom.x - leftTop.x;
			REQUIRE(ApproximatelyEquals(rectangle.GetWidth(), expectedWidth));

			double expectedHeight = leftTop.y- rightBottom.y;
			REQUIRE(ApproximatelyEquals(rectangle.GetHeight(), expectedHeight));
		}

		SECTION("Calculate rectangle area")
		{
			double expected = (rightBottom.x - leftTop.x) * (leftTop.y - rightBottom.y);
			REQUIRE(ApproximatelyEquals(rectangle.GetArea(), expected));
		}

		SECTION("Calculate rectangle perimeter")
		{
			double expected = 2 * ((rightBottom.x - leftTop.x + (leftTop.y - rightBottom.y)));
			REQUIRE(ApproximatelyEquals(rectangle.GetPerimeter(), expected));
		}
	}

	SECTION("Operations with triangle")
	{
		Point vertex1(0, 0);
		Point vertex2(2, 0);
		Point vertex3(2, 3);
		Triangle triangle(vertex1, vertex2, vertex3, outlineColor, fillColor);

		SECTION("Calculate triangle area")
		{
			double expected = GetDistance(vertex1, vertex2) * GetDistance(vertex2, vertex3) / 2;
			REQUIRE(ApproximatelyEquals(triangle.GetArea(), expected));
		}

		SECTION("Calculate triangle perimeter")
		{
			double expected = GetDistance(vertex1, vertex2) + GetDistance(vertex2, vertex3) + GetDistance(vertex3, vertex1);
			REQUIRE(ApproximatelyEquals(triangle.GetPerimeter(), expected));
		}
	}
}