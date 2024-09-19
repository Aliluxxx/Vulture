#pragma once

#include "Vulture.h"

class SandboxLayer : public ve::Layer {

public:

	SandboxLayer()
		: ve::Layer("Sandbox")

	{}

	virtual ~SandboxLayer() = default;

	virtual void OnAttach();
	virtual void OnDetach();
	virtual void OnUpdate(ve::Time ts);
	virtual void OnImGuiRender();
	virtual void OnEvent(ve::Event& event);
};
