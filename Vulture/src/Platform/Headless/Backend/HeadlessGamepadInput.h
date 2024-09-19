#pragma once

#include "Vulture/Core/Base.h"
#include "Vulture/Core/GamepadInput.h"

namespace ve {

	class VULTURE_API HeadlessGamepadInput : public GamepadInput {

	protected:

		virtual Vector2f GetAxisOffsetImpl(GamepadID id, GamepadAxisCode axis) override;
		virtual float GetAxisXOffsetImpl(GamepadID id, GamepadAxisCode axis) override;
		virtual float GetAxisYOffsetImpl(GamepadID id, GamepadAxisCode axis) override;
		virtual bool IsButtonPressedImpl(GamepadID id, GamepadButtonCode button) override;
	};
}
