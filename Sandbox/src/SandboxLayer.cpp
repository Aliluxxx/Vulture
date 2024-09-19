#include "SandboxLayer.h"

void SandboxLayer::OnAttach() {


}

void SandboxLayer::OnDetach() {


}

void SandboxLayer::OnUpdate(ve::Time ts) {


}

void SandboxLayer::OnImGuiRender() {

#ifndef VULTURE_HEADLESS

#endif
}

void SandboxLayer::OnEvent(ve::Event& event) {

	ve::EventDispatcher dispatcher(event);
	dispatcher.Dispatch<ve::KeyPressedEvent>([](ve::KeyPressedEvent& event) {

		switch (event.GetKeyCode()) {

			case ve::Key::Escape:
				ve::Application::Close();
				break;
		}

		return false;
	});

	VE_TRACE("{0}", event.ToString());
}
