#pragma once

#define BIND_FN(x) std::bind(&x, this, std::placeholders::_1)

namespace utils
{
	bool IsPointInRect(const glm::vec2& point, const glm::vec4& rect);
	bool IsOverlapping(const glm::vec4& r1, const glm::vec4& r2);
}