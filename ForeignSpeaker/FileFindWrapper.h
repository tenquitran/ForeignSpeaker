#pragma once


namespace ForeignSpeakerApp
{
	class FileFindWrapper
	{
	public:
		explicit FileFindWrapper(HANDLE hFile);

		virtual ~FileFindWrapper();

		operator HANDLE();

	private:
		HANDLE m_hFile;
	};
}
