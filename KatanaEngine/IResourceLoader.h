#pragma once

namespace KatanaEngine
{
	class IResourceLoader
	{

	public:

		template <typename T>
		bool Load(const std::string &path, ResourceManager *pManager, T &resource) = 0;

	};
}