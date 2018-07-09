#include "stdafx.h"
#include "resource.h"
#include "MainWindow.h"

//////////////////////////////////////////////////////////////////////////

using namespace ForeignSpeakerApp;

//////////////////////////////////////////////////////////////////////////

// "Exit application" event.
extern CHandle g_hExitEvent;

//////////////////////////////////////////////////////////////////////////


MainWindow::MainWindow(HINSTANCE hInstance)
{
	if (!hInstance)
	{
		throw EXCEPTION(L"Application instance is NULL");
	}

	INT_PTR res = DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_MAIN_DIALOG), nullptr, mainDlgProc, (LPARAM)this);
	if (    0 == res
		|| -1 == res)
	{
		throw EXCEPTION_FMT(L"DialogBoxParam() failed: %u", GetLastError());
	}
}

MainWindow::~MainWindow()
{
}

INT_PTR CALLBACK MainWindow::mainDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static MainWindow *pMainWnd = nullptr;

	switch (message)
	{
	case WM_INITDIALOG:
		pMainWnd = (MainWindow *)((LPCREATESTRUCT)lParam)->lpCreateParams;
		if (!pMainWnd)
		{
			std::wcerr << L"WM_CREATE: main window pointer is NULL\n";
			assert(false);
		}
		return (INT_PTR)TRUE;
	case WM_CLOSE:
		EndDialog(hDlg, 1);
		return (INT_PTR)TRUE;
#if 0
	case WM_COMMAND:
		if (   IDOK     == LOWORD(wParam) 
			|| IDCANCEL == LOWORD(wParam))
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
#endif
	}

	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK MainWindow::aboutDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);

	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;
	case WM_COMMAND:
		if (   IDOK     == LOWORD(wParam) 
			|| IDCANCEL == LOWORD(wParam))
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
