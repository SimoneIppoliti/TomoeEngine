#include "tomoepch.h"
#include "Layer.h"

namespace TomoeEngine {

	Layer::Layer(const std::string& debugName)
		: m_DebugName(debugName) {}

	Layer::~Layer() {}
}