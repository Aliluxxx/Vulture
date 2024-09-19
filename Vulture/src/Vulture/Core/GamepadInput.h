#pragma once

#include <vector>

#include "Vulture/Core/Base.h"
#include "Vulture/Math/Vector2.h"
#include "Vulture/Core/GamepadCodes.h"

namespace ve {

	typedef int GamepadID;

	class VULTURE_API GamepadInput {

	public:

		static const Uint32 Count = 16;
		static const GamepadID Invalid = -1;

		static std::vector<GamepadID> GetAvailableGamepads() {

			return std::vector<GamepadID>(s_Instance->m_GamepadSlots.begin(), s_Instance->m_GamepadSlots.end());
		}

		static Vector2f GetAxisOffset(GamepadID id, GamepadAxisCode axis) {

			return s_Instance->GetAxisOffsetImpl(id, axis);
		}

		static float GetAxisXOffset(GamepadID id, GamepadAxisCode axis) {

			return s_Instance->GetAxisXOffsetImpl(id, axis);
		}

		static float GetAxisYOffset(GamepadID id, GamepadAxisCode axis) {

			return s_Instance->GetAxisYOffsetImpl(id, axis);
		}

		static bool IsButtonPressed(GamepadID id, GamepadButtonCode button) {

			return s_Instance->IsButtonPressedImpl(id, button);
		}

	protected:

		GamepadInput();

		static void AddGamepad(GamepadID id);
		static void RemoveGamepad(GamepadID id);
		static GamepadID GetCurrentEmptySlot();

		virtual Vector2f GetAxisOffsetImpl(GamepadID id, GamepadAxisCode axis) = 0;
		virtual float GetAxisXOffsetImpl(GamepadID id, GamepadAxisCode axis) = 0;
		virtual float GetAxisYOffsetImpl(GamepadID id, GamepadAxisCode axis) = 0;
		virtual bool IsButtonPressedImpl(GamepadID id, GamepadButtonCode button) = 0;

		static Scope<GamepadInput> s_Instance;

		std::array<GamepadID, Count> m_GamepadSlots;
		GamepadID m_CurrentEmptySlot = 0;
	};
}
