#pragma once


namespace ForeignSpeakerApp
{
	// Parses dialog files and stores the dialogs.
	class ContentLibrary
	{
		typedef std::vector<Dialog> DialogColl;

	public:
		typedef std::vector<Dialog>::const_iterator DialogItr;

	public:
		ContentLibrary();

		virtual ~ContentLibrary();

		// Parse the files that contain dialogs.
		bool parseDialogFiles(const std::wstring& directoryPath);

		size_t getDialogCount() const;

		Dialog operator[](size_t index) const;

	private:
		bool parseFile(const std::wstring& filePath);

		// Remove line prefix, if any.
		void removePrefix(std::wstring& line);

	private:
		std::vector<Dialog> m_dialogs;
	};
}
