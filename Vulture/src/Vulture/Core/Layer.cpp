#include "vepch.h"

#include "Layer.h"

namespace ve {

#ifdef VULTURE_DIST
	Layer::Layer(const std::string& debug_name) {}
#else
	Layer::Layer(const std::string& debug_name)
		: m_DebugName(debug_name)
	{}
#endif

	Layer::~Layer() {}
}
