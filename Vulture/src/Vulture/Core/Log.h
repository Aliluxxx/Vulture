#pragma once

#include "Vulture/Core/Base.h"

#undef SPDLOG_ACTIVE_LEVEL
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace ve {

	class VULTURE_API Log {

	public:

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetVulkanLogger() { return s_VulkanLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetOpenGLLogger() { return s_OpenGLLogger; }

	private:

		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		static std::shared_ptr<spdlog::logger> s_VulkanLogger;
		static std::shared_ptr<spdlog::logger> s_OpenGLLogger;
	};
}

#if defined(VULTURE_DIST)
	#define VE_TRACE(...)
	#define VE_DEBUG(...)
	#define VE_INFO(...)
	#define VE_WARN(...)
	#define VE_ERROR(...)
	#define VE_CRITICAL(...)
#else
	#define VE_TRACE(...)         SPDLOG_LOGGER_TRACE(::ve::Log::GetClientLogger(), __VA_ARGS__)
	#define VE_DEBUG(...)         SPDLOG_LOGGER_DEBUG(::ve::Log::GetClientLogger(), __VA_ARGS__)
	#define VE_INFO(...)          SPDLOG_LOGGER_INFO(::ve::Log::GetClientLogger(), __VA_ARGS__)
	#define VE_WARN(...)          SPDLOG_LOGGER_WARN(::ve::Log::GetClientLogger(), __VA_ARGS__)
	#define VE_ERROR(...)         SPDLOG_LOGGER_ERROR(::ve::Log::GetClientLogger(), __VA_ARGS__)
	#define VE_CRITICAL(...)      SPDLOG_LOGGER_CRITICAL(::ve::Log::GetClientLogger(), __VA_ARGS__)
#endif

#if defined(VULTURE_ENGINE) && defined(VULTURE_DIST)
	#define VE_CORE_TRACE(...)
	#define VE_CORE_DEBUG(...)
	#define VE_CORE_INFO(...)
	#define VE_CORE_WARN(...)
	#define VE_CORE_ERROR(...)
	#define VE_CORE_CRITICAL(...)
#elif defined(VULTURE_ENGINE)
	#define VE_CORE_TRACE(...)    SPDLOG_LOGGER_TRACE(::ve::Log::GetCoreLogger(), __VA_ARGS__)
	#define VE_CORE_DEBUG(...)    SPDLOG_LOGGER_DEBUG(::ve::Log::GetCoreLogger(), __VA_ARGS__)
	#define VE_CORE_INFO(...)     SPDLOG_LOGGER_INFO(::ve::Log::GetCoreLogger(), __VA_ARGS__)
	#define VE_CORE_WARN(...)     SPDLOG_LOGGER_WARN(::ve::Log::GetCoreLogger(), __VA_ARGS__)
	#define VE_CORE_ERROR(...)    SPDLOG_LOGGER_ERROR(::ve::Log::GetCoreLogger(), __VA_ARGS__)
	#define VE_CORE_CRITICAL(...) SPDLOG_LOGGER_CRITICAL(::ve::Log::GetCoreLogger(), __VA_ARGS__)
#endif
