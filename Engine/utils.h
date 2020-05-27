#pragma once

#define BIND_FN(x) std::bind(&x, this, std::placeholders::_1)

namespace utils
{
	bool IsPointInRect(const glm::vec2& point, const glm::vec4& rect);
	bool IsOverlapping(const glm::vec4& r1, const glm::vec4& r2);
	float Distance(const glm::vec2& position1, const glm::vec2& position2);
	float Distance(float position1, float position2);
}