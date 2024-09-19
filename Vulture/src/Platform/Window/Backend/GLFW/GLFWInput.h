#pragma once

#include "Vulture/Core/Base.h"
#include "Vulture/Core/Input.h"

namespace ve {

	class VULTURE_API GLFWInput : public Input {

	protected:

		virtual bool IsKeyPressedImpl(KeyCode keycode) override;
		virtual bool IsMouseButtonPressedImpl(MouseCode button) override;
		virtual ve::Vector2i GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};
}
