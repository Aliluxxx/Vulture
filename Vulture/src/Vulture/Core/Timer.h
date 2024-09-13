#pragma once

#include "Vulture/Core/Base.h"
#include "Vulture/Core/Time.h"

namespace ve {

	class VULTURE_API Timer {

	public:

		Timer();
		Timer(const Timer& other) = delete;

		void Restart();
		Time GetElapsedTime() const;

	private:

		std::chrono::time_point<std::chrono::steady_clock> m_Timer;
	};
}
