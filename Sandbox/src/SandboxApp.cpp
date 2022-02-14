#include <EnginePrototype.h>

class Sandbox : public EnginePrototype::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

EnginePrototype::Application* EnginePrototype::CreateApplication() {
	return new Sandbox();
}