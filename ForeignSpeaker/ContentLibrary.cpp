#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace ForeignSpeakerApp;

//////////////////////////////////////////////////////////////////////////

// If the file includes several dialogs, they should be separated by this string.
const wchar_t DialogSeparator[] = L"***";

// An individual sentence in a dialog can (but not obliged to) be prefixed by one of these:
const wchar_t HyphenPrefix[]       = L"- ";
const wchar_t NamePrefixSentinel[] = L": ";

//////////////////////////////////////////////////////////////////////////


ContentLibrary::ContentLibrary()
{
#if 1
	// TODO: temp
	parseDialogFiles(L"D:\\natProgs\\utilities\\ForeignSpeakerWinApi\\content");
#endif

	int tmp = 1;

	// TODO: temp
#if 0
	Dialog dlg1;
	dlg1.addSentence(L"Hello, Bob!"/*, ESpeakerRole::A*/);
	dlg1.addSentence(L"Hello, Alice!"/*, ESpeakerRole::B*/);
	dlg1.addSentence(L"How are you?"/*, ESpeakerRole::A*/);
	dlg1.addSentence(L"Fine, thanks! And you?"/*, ESpeakerRole::B*/);

	bool isEmpty = dlg1.empty();

	m_dialogs.emplace_back(dlg1);

	dlg1.clear();

	isEmpty = dlg1.empty();

	for (Dialog::SentenceItr itr = dlg1.cbegin(); itr != dlg1.cend(); ++itr)
	{
#ifdef _DEBUG
		std::wstring str = itr->getText();
		str.append(L"\n");
		OutputDebugStringW(str.c_str());
		//std::wcout << itr->getText() << '\n';
#endif
	}

	int tmp = 1;
#endif
}

ContentLibrary::~ContentLibrary()
{
}

ContentLibrary::DialogItr ContentLibrary::cbegin() const
{
	return m_dialogs.cbegin();
}

ContentLibrary::DialogItr ContentLibrary::cend() const
{
	return m_dialogs.cend();
}

bool ContentLibrary::parseDialogFiles(const std::wstring& directoryPath)
{
	std::wstring searchMask(directoryPath);
	searchMask.append(L"\\*");

	WIN32_FIND_DATA ffd = {};

	FileFindWrapper fileFind(FindFirstFile(searchMask.c_str(), &ffd));
	if (INVALID_HANDLE_VALUE == fileFind)
	{
		std::wcerr << L"FindFirstFile() failed: " << GetLastError() << L", " << directoryPath << '\n';
		assert(false); return false;
	}

	do
	{
		if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{   // Directories

			// Skip the "." and ".." directories.
			if (   0 != wcscmp(L".",  ffd.cFileName)
				&& 0 != wcscmp(L"..", ffd.cFileName))
			{
				std::wstring tmpPath(directoryPath);
				tmpPath.append(L"\\");
				tmpPath.append(ffd.cFileName);

				parseDialogFiles(tmpPath);
			}
		}   // Directories
		else
		{   // Files

			std::wstring filePath(directoryPath);
			filePath.append(L"\\");
			filePath.append(ffd.cFileName);

			if (!parseFile(filePath))
			{
				std::wcerr << L"Failed to parse file \"" << filePath << '\n';
				assert(false); return false;
			}

		}   // Files

	} while (0 != FindNextFile(fileFind, &ffd));


	DWORD err = GetLastError();

	if (ERROR_NO_MORE_FILES != err)
	{
		std::wcerr << L"Error while enumerating files and directories: " << err << '\n';
		assert(false); return false;
	}

	return true;
}

bool ContentLibrary::parseFile(const std::wstring& filePath)
{
	std::wifstream inFile(filePath.c_str());

	if (!inFile.good())
	{
		std::wcerr << L"Failed to open file \"" << filePath << '\n';
		assert(false); return false;
	}

	Dialog dlg;

	std::wstring line;

	while (getline(inFile, line))
	{
		if (line.empty())
		{
			continue;
		} 
		else if (-1 != line.find(DialogSeparator))    // next dialog in the file
		{
			if (!dlg.empty())
			{
				m_dialogs.emplace_back(dlg);
			}

			dlg.clear();
			continue;
		}

		removePrefix(line);

		dlg.addSentence(line);

#if 0//def _DEBUG
		line.append(L"\n");
		OutputDebugStringW(line.c_str());
#endif
	}

	if (!dlg.empty())
	{
		m_dialogs.emplace_back(dlg);
	}

	inFile.close();
	return true;
}

void ContentLibrary::removePrefix(std::wstring& line)
{
	// WARNING: we assume that if the line has a prefix, this prefix is one of those listed below.

	// 1) Remove the hyphen prefix if exists.

	std::wstring::size_type pos = line.find(HyphenPrefix);

	if (std::wstring::npos != pos)
	{
		line.erase(line.begin(), line.begin() + wcslen(HyphenPrefix));
	}
	else
	{
		// 2) Remove the "<name>: " prefix if exists.

		pos = line.find(NamePrefixSentinel);
		if (std::wstring::npos != pos)
		{
			line.erase(line.begin(), line.begin() + pos + wcslen(NamePrefixSentinel));
		}
	}
}
