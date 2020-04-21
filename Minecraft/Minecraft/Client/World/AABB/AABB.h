#pragma once
#include <glm/glm.hpp>


//TODO: FINISH CLASS!
class AABB {
public:
	glm::vec3 min;
	glm::vec3 max;

	AABB(glm::vec3 point1, glm::vec3 point2) {
		min.x = std::fminf(point1.x, point2.x);
		min.y = std::fminf(point1.y, point2.y);
		min.z = std::fminf(point1.z, point2.z);
		max.x = std::fmaxf(point1.x, point2.x);
		max.x = std::fmaxf(point1.y, point2.y);
		max.x = std::fmaxf(point1.z, point2.z);
	}
	AABB(glm::vec3 blockXYZ) {
		*this = AABB(blockXYZ, blockXYZ + glm::vec3(1.f));
	}

	inline AABB setMaxY(float newY) {
		max.y = newY;
	}

private:
	
};