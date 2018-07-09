#include "stdafx.h"
#include "MainWindow.h"

//////////////////////////////////////////////////////////////////////////

using namespace ForeignSpeakerApp;

//////////////////////////////////////////////////////////////////////////

// "Exit application" event.
CHandle g_hExitEvent;

//////////////////////////////////////////////////////////////////////////


int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpCmdLine, _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	UNREFERENCED_PARAMETER(nCmdShow);

	// Redirect output from std::cout and std::cerr to the log file.
	std::wofstream out("log.txt");
	std::wcout.rdbuf(out.rdbuf());
	std::wcerr.rdbuf(out.rdbuf());

	g_hExitEvent.Attach(CreateEvent(nullptr, TRUE, FALSE, nullptr));
	if (!g_hExitEvent)
	{
		std::wcerr << L"App exit event: CreateEvent() failed: " << GetLastError() << '\n';
		assert(false); return 1;
	}

	HRESULT hr = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
	if (FAILED(hr))
	{
		std::wcerr << L"CoInitializeEx() failed: 0x" << std::hex << hr << '\n';
		assert(false); return 1;
	}

	int res = 1;

	try
	{
		MainWindow mainWindow(hInstance);

		res = 0;
	}
	catch (const Exception& ex)
	{
		std::wcerr << ex.message() << std::endl;
		assert(false);
	}
	catch (const std::bad_alloc&)
	{
		std::wcerr << L"memalloc failure\n";
		assert(false);
	}

	CoUninitialize();

	return res;
}
