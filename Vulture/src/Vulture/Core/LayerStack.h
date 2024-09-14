#pragma once

#include <vector>

#include "Vulture/Core/Base.h"
#include "Vulture/Core/Layer.h"

namespace ve {

	class VULTURE_API LayerStack {

	public:

		LayerStack();
		~LayerStack();

		void PushLayer(Ref<Layer> layer);
		void PushOverlay(Ref<Layer> overlay);
		void PopLayer(Ref<Layer> layer);
		void PopOverlay(Ref<Layer> overlay);
		void Clear();

		std::vector<Ref<Layer>>::iterator Begin() { return m_Layers.begin(); }
		std::vector<Ref<Layer>>::iterator End() { return m_Layers.end(); }

	private:

		std::vector<Ref<Layer>> m_Layers;
		unsigned int m_LayerInsertIndex = 0;
	};
}
