#pragma once

#include "Vulture/Core/Base.h"

namespace ve {

	class VULTURE_API InputStream {

	public:

		virtual ~InputStream() {}

		virtual Int64 Read(void* data, Int64 size) = 0;
		virtual Int64 Seek(Int64 position) = 0;
		virtual Int64 Tell() = 0;
		virtual Int64 GetSize() = 0;
	};
}
