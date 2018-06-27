#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace ForeignSpeakerApp;

//////////////////////////////////////////////////////////////////////////


FileFindWrapper::FileFindWrapper(HANDLE hFile)
	: m_hFile(hFile)
{
}

FileFindWrapper::~FileFindWrapper()
{
	if (INVALID_HANDLE_VALUE != m_hFile)
	{
		FindClose(m_hFile);
	}
}

FileFindWrapper::operator HANDLE()
{
	return m_hFile;
}
