#pragma once

#include "Vulture/Core/Base.h"
#include "Vulture/Core/Time.h"
#include "Vulture/Events/Event.h"

namespace ve {

	class VULTURE_API Layer {

	public:

		Layer(const std::string& debug_name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Time ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

#ifndef VULTURE_DIST
		inline const std::string& GetName() const {

			return m_DebugName;
		}
#else
		inline std::string GetName() const {

			return "";
		}
#endif

	protected:

#ifndef VULTURE_DIST
		std::string m_DebugName;
#endif
	};
}
