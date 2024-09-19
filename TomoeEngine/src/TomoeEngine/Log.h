#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace TomoeEngine {

	typedef std::shared_ptr<spdlog::logger> logsp;

	class TOMOE_API Log
	{
	public:
		static void Init();

		inline static logsp& GetCoreLogger() { return s_CoreLogger; }
		inline static logsp& GetClientLogger() { return s_ClientLogger; }

	private:
		static logsp s_CoreLogger;
		static logsp s_ClientLogger;
	};

}

// Core log macros
#define TOMOE_CORE_TRACE(...) ::TomoeEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TOMOE_CORE_INFO(...)  ::TomoeEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TOMOE_CORE_WARN(...)  ::TomoeEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TOMOE_CORE_ERROR(...) ::TomoeEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TOMOE_CORE_FATAL(...) ::TomoeEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define TOMOE_TRACE(...)      ::TomoeEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TOMOE_INFO(...)       ::TomoeEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define TOMOE_WARN(...)       ::TomoeEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TOMOE_ERROR(...)      ::TomoeEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define TOMOE_FATAL(...)      ::TomoeEngine::Log::GetClientLogger()->critical(__VA_ARGS__)
