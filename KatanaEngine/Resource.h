
/*	 ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗ 
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \=========================================,
   `^^^^^^^^^^^^^^^^^^^ /---------------------------------------"
        Katana Engine \/ © 2012 - Shuriken Studios LLC              */

#pragma once

namespace KatanaEngine
{
	class ResourceManager;

	/** @brief Base class for all resource types to be managed by the ResourceManager class. */
	class Resource
	{
		friend class ResourceManager;

	public:

		virtual ~Resource() { }

		/** @brief Load the desired resource into memory.
			@param path The path to the desired resource.
			@param pManager A pointer to the ResourceManager that will manage the resource.
			@return Returns true if the resource was loaded, false otherwise. */
		virtual bool Load(const std::string &path, ResourceManager *pManager) = 0;

		/** @brief Gets the ID of the resource.
			@return The id of the resource. */
		unsigned short GetResourceID() const { return m_id; }


	protected:

		/** @brief Splits a string into a vector of strings.
			@param line The string that will be split.
			@param elements The vector where the string elements will be stored.
			@param delimeter The character that will determine the split locations. */
		//void Split(const std::string &line, std::vector<std::string> &elements,
			//const char delimeter = ',');

		template <typename T>
		bool TryParse(const std::string &text, std::vector<T> &elements,
			const char delimeter = ',')
		{
			if (text.empty()) return false;
			elements.clear();
			std::stringstream ss(text);
			std::string item;
			while (std::getline(ss, item, delimeter))
				elements.push_back(fromString<T>(item));
			return true;
		}

		/** @brief Removes c-style, single-line comments from a line of text.
			@param line The line to remove the comments from. */
		void ParseComments(std::string &line);

		/** @brief Removes WHITE-space at the front and end of a line of text.
			@param line The line to remove the WHITE-space from. */
		void TrimLine(std::string &line);

		/** @brief Gets a pointer to the ResourceManager that was used to load the resource.
			@return Returns a pointer to the ResourceManager. */
		ResourceManager *GetResourceManager() { return m_pResourceManager; }

		/** @brief Used to determine if the resource is cloneable.
			@return Returns true if the resource is clonable, false otherwise.
			@remark Resources that are stateless should not be cloneable; i.e. Fonts, Textures, etc. Resources
			that do contain state should be cloned to prevent state duplication. For example, an %Animation that
			is shared (not cloned) would share the current frame. This would mean that they would always be
			playing in sync.*/
		virtual bool IsCloneable() const = 0;

		/** @brief Clones a resource.
			@return Returns a pointer to a clone if the resource is cloneable.
			Otherwise a pointer to \"this\" is returned. */
		virtual Resource *Clone() { return this; };


	private:

		unsigned short m_id = 0;

		ResourceManager *m_pResourceManager = nullptr;


		template<typename T>
		T fromString(const std::string &str);

		// Implementations
		template<>
		int fromString(const std::string &str)
		{
			return std::stoi(str);
		}

		template<>
		float fromString(const std::string &str)
		{
			return std::stof(str);
		}
	};
}