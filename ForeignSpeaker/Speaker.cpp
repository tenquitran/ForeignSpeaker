#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace ForeignSpeakerApp;

//////////////////////////////////////////////////////////////////////////


Speaker::Speaker()
{
	HRESULT hr = CoCreateInstance(CLSID_SpVoice, nullptr, CLSCTX_ALL, IID_PPV_ARGS(&m_spVoice));
	if (FAILED(hr))
	{
		throw EXCEPTION_FMT(L"CoCreateInstance() failed: 0x%x", hr);
	}
}

Speaker::~Speaker()
{
}

void Speaker::speak(const std::wstring& phrase) const
{
	HRESULT hr = m_spVoice->Speak(phrase.c_str(), /*0*/ SPF_ASYNC, nullptr);
	assert(SUCCEEDED(hr));
}
