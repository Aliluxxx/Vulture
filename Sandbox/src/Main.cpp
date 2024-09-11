#include <Vulture/Core/Log.h>

int main() {

	ve::Log::Init();

	VE_TRACE("Hello World!");
	VE_DEBUG("Hello World!");
	VE_INFO("Hello World!");
	VE_WARN("Hello World!");
	VE_ERROR("Hello World!");
	VE_CRITICAL("Hello World!");
	VE_ASSERT(true, "Hello World!");
}
