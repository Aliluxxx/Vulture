#pragma once

#include <filesystem>

#include "Vulture/Core/Base.h"
#include "Vulture/Core/InputStream.h"

namespace ve {

	class VULTURE_API FileInputStream : public InputStream {

	public:

		FileInputStream() = default;
		~FileInputStream() override = default;

		bool Open(const std::filesystem::path& path);
		virtual Int64 Read(void* data, Int64 size) override;
		virtual Int64 Seek(Int64 position) override;
		virtual Int64 Tell() override;
		virtual Int64 GetSize() override;

	private:

		struct FileCloser {

			void operator()(std::FILE* file);
		};

		std::unique_ptr<std::FILE, FileCloser> m_File;
	};
}
