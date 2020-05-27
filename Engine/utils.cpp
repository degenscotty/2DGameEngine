#include "pch.h"
#include "utils.h"

bool utils::IsPointInRect(const glm::vec2& point, const glm::vec4& rect)
{
	return (point.x > rect.x && point.x < rect.x + rect.z &&
		point.y > rect.y && point.y < rect.y + rect.w);
}

bool utils::IsOverlapping(const glm::vec4& r1, const glm::vec4& r2)
{
	// If one rectangle is on left side of the other
	if ((r1.x + r1.z) <= r2.x || (r2.x + r2.z) <= r1.x)
	{
		return false;
	}

	// If one rectangle is under the other
	if (r1.y >= (r2.y + r2.w) || r2.y >= (r1.y + r1.w))
	{
		return false;
	}

	return true;
}

float utils::Distance(const glm::vec2& position1, const glm::vec2& position2)
{
	return sqrt(pow(position1.x - position2.x, 2) + pow(position1.y - position2.y, 2));
}

float utils::Distance(float position1, float position2)
{
	return abs(position2 - position1);
}