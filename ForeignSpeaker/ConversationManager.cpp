#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace ForeignSpeakerApp;

//////////////////////////////////////////////////////////////////////////

// "Exit application" event.
extern CHandle g_hExitEvent;

//////////////////////////////////////////////////////////////////////////


ConversationManager::ConversationManager()
{
	m_hThreadParse.Attach(CreateThread(nullptr, 0, threadProcParse, this, CREATE_SUSPENDED, nullptr));
	if (!m_hThreadParse)
	{
		assert(false); throw EXCEPTION_FMT(L"CreateThread() failed: %u", GetLastError());
	}
}

ConversationManager::~ConversationManager()
{
	if (WAIT_OBJECT_0 != WaitForSingleObject(m_hThreadParse, 500))
	{
		std::wcerr << L"Dialog files parsing thread failed to stop in time\n";
	}
}

bool ConversationManager::parseDialogFiles()
{
	if ((DWORD)-1 == ResumeThread(m_hThreadParse))
	{
		std::wcerr << L"Dialog files parsing: ResumeThread() failed: " << GetLastError() << '\n';
		assert(false); return false;
	}
	
	return true;
}

DWORD WINAPI ConversationManager::threadProcParse(PVOID pParam)
{
	ConversationManager *pMgr = reinterpret_cast<ConversationManager *>(pParam);
	if (!pMgr)
	{
		std::wcerr << L"ConversationManager is NULL\n";
		assert(false); return 1;
	}

	return pMgr->threadProcParse();
}

DWORD ConversationManager::threadProcParse()
{
	// TODO: track state of g_hExitEvent

	// TODO: report progress (directory name or path, etc.)

#if 0
	// TODO: hard-coded
	m_contentLibrary.parseDialogFiles(L"D:\\natProgs\\utilities\\ForeignSpeakerWinApi\\content");
#endif

	// TODO: stub
	return 1;
}

void ConversationManager::playDialog(const Dialog& dlg) const
{
	if (dlg.isEmpty())
	{
		assert(false); return;
	}

	const size_t SentenceCount = dlg.getSentenceCount();

	for (size_t i = {}; i < SentenceCount; ++i)
	{
		Sentence sentence = dlg[i];
		assert(sentence.isValid());

		if (ESpeakerRole::A == sentence.getRole())
		{
			m_speaker.speak(sentence.getText());
		}
		else
		{
			// TODO: wait for the user to answer
			;
		}
	}
}