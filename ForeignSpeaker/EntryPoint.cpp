#include "stdafx.h"
#include "MainWindow.h"

//////////////////////////////////////////////////////////////////////////

using namespace ForeignSpeakerApp;

//////////////////////////////////////////////////////////////////////////


int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpCmdLine, _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// Redirect output from std::cout and std::cerr to the log file.
	std::wofstream out("log.txt");
	std::wcout.rdbuf(out.rdbuf());
	std::wcerr.rdbuf(out.rdbuf());

	int ret = {};

	try
	{
		const int Width  = 400;
		const int Height = 300;

		MainWindow mainWindow(hInstance, nCmdShow, Width, Height);

		ret = mainWindow.runMessageLoop();
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

	return ret;
}
