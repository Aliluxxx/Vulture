#pragma once

#include <string>
#include <filesystem>

#include "Vulture/Core/Base.h"

namespace ve {

	struct FileDialogFilter {

		std::string Name;
		std::string Ext;
	};

	struct FileDialogSpecification {

		std::vector<FileDialogFilter> FilterList;
		std::filesystem::path DefaultFile;
		std::filesystem::path DefaultPath;
	};

	class VULTURE_API FileDialog {

	public:

		static std::filesystem::path OpenFile(const FileDialogSpecification& spec);
		static std::filesystem::path SaveFile(const FileDialogSpecification& spec);
		static std::filesystem::path PickFolder(const FileDialogSpecification& spec);

	private:

		static void* CreateFilters(const std::vector<FileDialogFilter>& filters);
	};
}
