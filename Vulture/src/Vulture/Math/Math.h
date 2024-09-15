#pragma once

#include "Vulture/Math/Color.h"
#include "Vulture/Math/Matrix3.h"
#include "Vulture/Math/Matrix4.h"
#include "Vulture/Math/Vector2.h"
#include "Vulture/Math/Vector3.h"
#include "Vulture/Math/Vector4.h"

namespace ve {

	namespace Math {

		bool VULTURE_API DecomposeTransform(const Matrix4f& transform, Vector3f& translation, Vector3f& rotation, Vector3f& scale);
	}
}
