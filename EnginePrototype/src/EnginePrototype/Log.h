#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace EnginePrototype {

	class ENGINE_PROTOTYPE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}

// Core log macros
#define ENGINE_CORE_TRACE(...) ::EnginePrototype::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ENGINE_CORE_INFO(...)  ::EnginePrototype::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ENGINE_CORE_WARN(...)  ::EnginePrototype::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ENGINE_CORE_ERROR(...) ::EnginePrototype::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ENGINE_CORE_FATAL(...) ::EnginePrototype::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define ENGINE_TRACE(...)      ::EnginePrototype::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ENGINE_INFO(...)       ::EnginePrototype::Log::GetClientLogger()->info(__VA_ARGS__)
#define ENGINE_WARN(...)       ::EnginePrototype::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ENGINE_ERROR(...)      ::EnginePrototype::Log::GetClientLogger()->error(__VA_ARGS__)
#define ENGINE_FATAL(...)      ::EnginePrototype::Log::GetClientLogger()->critical(__VA_ARGS__)
