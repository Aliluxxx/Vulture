#pragma once

#include <cstdint>
#include <memory>

#ifdef VULTURE_DEBUG
	#ifdef VULTURE_PLATFORM_WINDOWS
		#define VE_DEBUGBREAK() __debugbreak()
	#elif defined(VULTURE_PLATFORM_LINUX)
		#include <signal.h>
		#define VE_DEBUGBREAK() raise(SIGTRAP)
	#elif defined(VULTURE_PLATFORM_MACOSX)
		#include <TargetConditionals.h>
		#define VE_DEBUGBREAK() abort()
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define VE_ENABLE_ASSERTS
#else
	#define VE_DEBUGBREAK()
#endif

#ifndef VULTURE_STATIC
	#ifdef VULTURE_PLATFORM_WINDOWS
		#ifdef VULTURE_BUILD_DLL
			#define VULTURE_API __declspec(dllexport)
		#else
			#define VULTURE_API __declspec(dllimport)
		#endif
		#ifdef _MSC_VER
			#pragma warning(disable : 4251)
		#endif
	#else
		#error Vulture only supports Windows!
	#endif
#else
	#define VULTURE_API
#endif

#define VE_EXPAND_MACRO(x) x
#define VE_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define VE_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace ve {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args) {

		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args) {

		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	// 8 bits unsigned integer type
	using byte = std::uint8_t;

	// 8 bits signed integer type
	using Int8 = std::int8_t;

	// 8 bits unsigned integer type
	using Uint8 = std::uint8_t;

	// 16 bits signed integer type
	using Int16 = std::int16_t;

	// 16 bits unsigned integer type
	using Uint16 = std::uint16_t;

	// 32 bits signed integer type
	using Int32 = std::int32_t;

	// 32 bits unsigned integer type
	using Uint32 = std::uint32_t;

	// 64 bits signed integer type
	using Int64 = std::int64_t;

	// 64 bits unsigned integer type
	using Uint64 = std::uint64_t;
}

#include "Vulture/Core/Log.h"
#include "Vulture/Core/Assert.h"
