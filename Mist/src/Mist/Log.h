#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Mist 
{
	class MIST_API Log
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
#define MT_CORE_TRACE(...) ::Mist::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MT_CORE_INFO(...)  ::Mist::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MT_CORE_WARN(...)  ::Mist::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MT_CORE_ERROR(...) ::Mist::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MT_CORE_CRIT(...)  ::Mist::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define MT_TRACE(...)      ::Mist::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MT_INFO(...)       ::Mist::Log::GetClientLogger()->info(__VA_ARGS__)
#define MT_WARN(...)       ::Mist::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MT_ERROR(...)      ::Mist::Log::GetClientLogger()->error(__VA_ARGS__)
#define MT_CRIT(...)       ::Mist::Log::GetClientLogger()->critical(__VA_ARGS__)