#include "vepch.h"

#include "GamepadInput.h"

namespace ve {

	GamepadInput::GamepadInput() {

		for (int i = 0; i < Count; i++)
			m_GamepadSlots[i] = Invalid;
	}

	void GamepadInput::AddGamepad(GamepadID id) {

		VE_ASSERT(id != Invalid, "Cannot add an Invalid value");

		s_Instance->m_GamepadSlots[s_Instance->m_CurrentEmptySlot] = id;

		for (int i = 0; i < Count; i++) {

			if (s_Instance->m_GamepadSlots[i] == Invalid) {

				s_Instance->m_CurrentEmptySlot += i;
				break;
			}
		}
	}

	void GamepadInput::RemoveGamepad(GamepadID id) {

		s_Instance->m_GamepadSlots[id] = Invalid;
		s_Instance->m_CurrentEmptySlot = id;
	}

	GamepadID GamepadInput::GetCurrentEmptySlot() {

		return s_Instance->m_CurrentEmptySlot;
	}
}
