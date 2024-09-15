#include "SandboxLayer.h"

void SandboxLayer::OnAttach() {


}

void SandboxLayer::OnDetach() {


}

void SandboxLayer::OnUpdate(ve::Time ts) {

	VE_TRACE("{}", 1.0f / ts.AsSeconds());
}

void SandboxLayer::OnImGuiRender() {

#ifndef VULTURE_HEADLESS

#endif
}

void SandboxLayer::OnEvent(ve::Event& event) {


}
