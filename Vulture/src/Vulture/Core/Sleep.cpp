#include "vepch.h"

#include "Time.h"
#ifndef VULTURE_STATIC
const ve::Time ve::Time::Zero;
#endif
#include "Sleep.h"

namespace ve {

	void VULTURE_API Sleep(Time duration) {

		std::this_thread::sleep_for(std::chrono::microseconds(duration.AsMicroseconds()));
	}
}
