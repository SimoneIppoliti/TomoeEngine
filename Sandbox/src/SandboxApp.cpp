#include <TomoeEngine.h>

class Sandbox : public TomoeEngine::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

TomoeEngine::Application* TomoeEngine::CreateApplication() {
	return new Sandbox();
}