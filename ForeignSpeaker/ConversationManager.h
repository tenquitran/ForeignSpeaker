#pragma once


namespace ForeignSpeakerApp
{
	class ConversationManager
	{
	public:
		ConversationManager();

		virtual ~ConversationManager();

		bool parseDialogFiles();

		void playDialog(const Dialog& dlg) const;

	private:
		static DWORD WINAPI threadProcParse(PVOID pParam);
		DWORD threadProcParse();

	private:
		// Dialog participant simulated by our application.
		Speaker m_speaker;

		// The dialogs that can be played.
		ContentLibrary m_contentLibrary;

		// Thread to parse the dialog files.
		CHandle m_hThreadParse;
	};
}
