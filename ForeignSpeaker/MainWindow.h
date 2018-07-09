#pragma once


namespace ForeignSpeakerApp
{
	class MainWindow
	{
	public:
		explicit MainWindow(HINSTANCE hInstance);

		virtual ~MainWindow();

	private:
		static INT_PTR CALLBACK mainDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

		static INT_PTR CALLBACK aboutDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

	private:
		// Controls the main application logic.
		ConversationManager m_conversationMgr;
	};
}
